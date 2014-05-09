package mx.ipn.imageanalysis

class ImageAnalysisController {

    static allowedMethods = [index: "GET"]

    def index(Integer max) {
        params.max = Math.min(max ?: 10, 100)
        respond view:"/inicio",Imagen.list(params), model:[imagenInstanceCount: Imagen.count()]
    }
}