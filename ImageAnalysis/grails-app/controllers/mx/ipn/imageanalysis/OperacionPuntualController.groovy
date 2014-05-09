package mx.ipn.imageanalysis

import sun.misc.BASE64Encoder
import javax.imageio.ImageIO
import java.awt.Color
import java.awt.image.BufferedImage
import java.awt.image.DataBufferByte

class OperacionPuntualController {

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
            //byte[] imageBytes = ((DataBufferByte) outputImage.getData().getDataBuffer()).getData();

            render(view: "/imagen/show",model: [data:data])
        }
        else
            render("The image has not been processed")

    }

}
