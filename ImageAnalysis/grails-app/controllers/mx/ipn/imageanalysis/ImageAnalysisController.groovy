package mx.ipn.imageanalysis

class ImageAnalysisController {

    def index() {
        params.max = Math.min(max ?: 10, 100)
        //respond view:"inicio",Imagen.list(params), model:[imagenInstanceCount: Imagen.count()]
    }
}
