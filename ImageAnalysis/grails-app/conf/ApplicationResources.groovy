import org.codehaus.groovy.grails.web.context.ServletContextHolder as SCH

modules = {
    application {
        resource url:'js/application.js'
    }

    bootstrapFiles {
        getFilesFromPath('css/bootstrap').each{
            resource url: it
        }
        getFilesFromPath('js/bootstrap').each{
            resource url: it
        }
    }

    jqueryLibrary {
        dependsOn('jquery')
    }

    indexResources {
        resource url:'css/application/index.css'
        resource url:'js/application/index.js'
    }

    showImageLibraries{
        resource url:'js/application/imagen.js'
    }

}

def getFilesFromPath(def path){

    /*Lista de direcciones de los archivos*/
    def filePaths=[]

    def servletContext = SCH.getServletContext()
    if(!servletContext)
        return filePaths

    def realPath = servletContext.getRealPath('/')
    def last = new Character(realPath.charAt(realPath.length()-1)).toString()

    realPath = realPath.substring(0,realPath.length())

    def appDir = new File("$realPath$path")

    appDir.eachFile{File f ->
        if(f.isDirectory() || f.isHidden())
            return
        filePaths << f.path.replace(realPath,'').replace('\\','/')
    }

    filePaths
}