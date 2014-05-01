package mx.ipn.imageanalysis

class Imagen {

    byte[] file

    static constraints = {
        file maxSize: 1024 * 1024 * 2
    }

    static mapping = {
        version false
        file column: 'imagen',sqlType: "longblob"
    }
}
