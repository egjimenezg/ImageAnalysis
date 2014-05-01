package mx.ipn.imageanalysis

import javax.imageio.ImageIO
import java.awt.Color
import java.awt.image.BufferedImage

import static org.springframework.http.HttpStatus.*
import grails.transaction.Transactional

@Transactional(readOnly = true)
class ImagenController {

    static allowedMethods = [save: "POST", update: "PUT", delete: "DELETE"]

    def index(Integer max) {
        params.max = Math.min(max ?: 10, 100)
        respond Imagen.list(params), model:[imagenInstanceCount: Imagen.count()]
    }

    def showImageFromDatabase(){
        println "Id " + params.id
        def imagen = Imagen.findById(new Integer(params.id))
        def imageBytes = imagen.file
        response.outputStream << imageBytes
    }

    def show(Imagen imagenInstance) {
        respond imagenInstance
    }

    def create() {
        respond new Imagen(params)
    }

    @Transactional
    def save(Imagen imagenInstance) {
        if (imagenInstance == null) {
            notFound()
            return
        }

        if (imagenInstance.hasErrors()) {
            respond imagenInstance.errors, view:'create'
            return
        }

        imagenInstance.save flush:true

        request.withFormat {
            form {
                flash.message = message(code: 'default.created.message', args: [message(code: 'imagenInstance.label', default: 'Imagen'), imagenInstance.id])
                redirect imagenInstance
            }
            '*' { respond imagenInstance, [status: CREATED] }
        }

        redirect(action:'show',params: [id:imagenInstance.id])
    }

    def edit(Imagen imagenInstance) {
        respond imagenInstance
    }

    @Transactional
    def update(Imagen imagenInstance) {
        if (imagenInstance == null) {
            notFound()
            return
        }

        if (imagenInstance.hasErrors()) {
            respond imagenInstance.errors, view:'edit'
            return
        }

        imagenInstance.save flush:true

        request.withFormat {
            form {
                flash.message = message(code: 'default.updated.message', args: [message(code: 'Imagen.label', default: 'Imagen'), imagenInstance.id])
                redirect imagenInstance
            }
            '*'{ respond imagenInstance, [status: OK] }
        }
    }

    @Transactional
    def delete(Imagen imagenInstance) {

        if (imagenInstance == null) {
            notFound()
            return
        }

        imagenInstance.delete flush:true

        request.withFormat {
            form {
                flash.message = message(code: 'default.deleted.message', args: [message(code: 'Imagen.label', default: 'Imagen'), imagenInstance.id])
                redirect action:"index", method:"GET"
            }
            '*'{ render status: NO_CONTENT }
        }
    }

    protected void notFound() {
        request.withFormat {
            form {
                flash.message = message(code: 'default.not.found.message', args: [message(code: 'imagenInstance.label', default: 'Imagen'), params.id])
                redirect action: "index", method: "GET"
            }
            '*'{ render status: NOT_FOUND }
        }
    }

    def upload = {
        def file = request.getFile('file')
        /*if(f.empty){
            flash.message
        } */
        //file.transferTo(new File('/users/gamaliel/Documents/Imagen.bmp'))
        def entrada = new ByteArrayInputStream(file.getBytes())
        def image = ImageIO.read(entrada)
        byte[] matrizBinaria = new byte[image.getHeight()*image.getWidth()*3]
        int x = 0

        image.getHeight().times{ i->
            image.getWidth().times{ j->
                def c = new Color(image.getRGB(j,i))
                int green = c.green
                int red = c.red
                int blue = c.blue

                /*
                if(green <= 128 && red <= 128 && blue <= 128){
                    image.setRGB(j,i,new Color(0,0,0).getRGB())
                }
                else{
                    image.setRGB(j,i,new Color(255,255,255).getRGB())
                }

                int gray = (c.alpha << 8) + c.green
                gray = (gray << 8) + c.green
                gray = (gray << 8) + c.green
                */

                image.setRGB(j,i,new Color(green,green,green).getRGB())
            }
        }

        def imageOutput = new BufferedImage(image.getHeight(),image.getWidth(),BufferedImage.TYPE_BYTE_BINARY)

         //InputStream entrance = new ByteArrayInputStream(matrizBinaria)
         //image = ImageIO.read(entrance)
         ImageIO.write(image,"bmp",new File('/users/gamaliel/Documents/Imagen.bmp'))
         def img = new Imagen(params)


        render 'Ya esta lo primero'
    }


}
