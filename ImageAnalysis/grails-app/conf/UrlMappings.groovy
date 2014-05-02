class UrlMappings {

	static mappings = {
        "/$controller/$action?/$id?(.$format)?"{
            constraints {
                // apply constraints here
            }
        }

        //"/"(view:"/inicio")
        "/"(controller: 'imageAnalysis',action:'index')
        "500"(view:'/error')
	}
}
