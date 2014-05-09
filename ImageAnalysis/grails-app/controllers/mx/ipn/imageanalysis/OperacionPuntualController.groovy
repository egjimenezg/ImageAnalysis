package mx.ipn.imageanalysis

import sun.misc.BASE64Encoder
import javax.imageio.ImageIO
import java.awt.Color
import java.awt.image.BufferedImage
import java.awt.image.DataBufferByte

class OperacionPuntualController {

    static allowedMethods = [getGrayScaleImage: "POST"]

    def index() {}

    def getGrayScaleImage(){

        if(session.imageBytes){

            def bytesIn = new ByteArrayInputStream(session.imageBytes)
            BufferedImage outputImage = ImageIO.read(bytesIn)

            outputImage.getHeight().times{ i ->
                outputImage.getWidth().times { j ->
                    def c = new Color(outputImage.getRGB(j,i))
                    int green = c.green
                    outputImage.setRGB(j,i,new Color(green,green,green).getRGB())
                }
            }
            def bos = new ByteArrayOutputStream()
            def data = ""
            try{
                ImageIO.write(outputImage,"bmp",bos)
                byte[] imageBytes = bos.toByteArray()

                def encoder =  new BASE64Encoder()
                data = encoder.encode(imageBytes)
            }
            catch (IOException e){
                e.printStackTrace()
            }

            render(template:"/imagen/imagenProcesada" ,model: [data:data])
        }
        else
            render("There's a problem with the image")
    }

    def getNegativeImage(){
        if(session.imageBytes){
            def bytesIn = new ByteArrayInputStream(session.imageBytes)
            BufferedImage outputImage = ImageIO.read(bytesIn)

            outputImage.getHeight().times{ i ->
                outputImage.getWidth().times { j ->
                    def c = new Color(outputImage.getRGB(j,i))
                    int green = 255 - c.green
                    int blue = 255 - c.blue
                    int red = 255 -c.red
                    outputImage.setRGB(j,i,new Color(red,green,blue).getRGB())
                }
            }
            def bos = new ByteArrayOutputStream()
            def data = ""
            try{
                ImageIO.write(outputImage,"bmp",bos)
                byte[] imageBytes = bos.toByteArray()

                def encoder =  new BASE64Encoder()
                data = encoder.encode(imageBytes)
            }
            catch (IOException e){
                e.printStackTrace()
            }

            render(template:"/imagen/imagenProcesada" ,model: [data:data])

        }
        else
            render("There's a problem with the image")
    }


    def getBinaryImage(){
        if(session.imageBytes){
            def bytesIn = new ByteArrayInputStream(session.imageBytes)
            BufferedImage outputImage = ImageIO.read(bytesIn)

            outputImage.getHeight().times{ i ->
                outputImage.getWidth().times { j ->
                    def c = new Color(outputImage.getRGB(j,i))
                    int green = c.green > 127 ? 255 : 0
                    outputImage.setRGB(j,i,new Color(green,green,green).getRGB())
                }
            }
            def bos = new ByteArrayOutputStream()
            def data = ""
            try{
                ImageIO.write(outputImage,"bmp",bos)
                byte[] imageBytes = bos.toByteArray()

                def encoder =  new BASE64Encoder()
                data = encoder.encode(imageBytes)
            }
            catch (IOException e){
                e.printStackTrace()
            }

            render(template:"/imagen/imagenProcesada" ,model: [data:data])

        }
        else
            render("There's a problem with the image")
    }
}
