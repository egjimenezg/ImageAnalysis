<!DOCTYPE html>
<!--[if lt IE 7 ]> <html lang="en" class="no-js ie6"> <![endif]-->
<!--[if IE 7 ]>    <html lang="en" class="no-js ie7"> <![endif]-->
<!--[if IE 8 ]>    <html lang="en" class="no-js ie8"> <![endif]-->
<!--[if IE 9 ]>    <html lang="en" class="no-js ie9"> <![endif]-->
<!--[if (gt IE 9)|!(IE)]><!--> <html lang="en" class="no-js"><!--<![endif]-->
	<head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
		<title><g:layoutTitle default="Tratamiento de Imagenes"/></title>
		<!-- Etiqueta para la versión móvil -->
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="stylesheet" type="text/css" href="${resource(dir: 'css',file: 'main.css')}" />
        <r:require module="bootstrapFiles" />
        <g:layoutHead/>
        <r:layoutResources/>
	</head>
	<body>
        <nav class="navbar navbar-inverse navbar-static-top" role="navigation">
            <div class="container-fluid">
                <div class="navbar-header">
                    <a class="navbar-brand" href="${createLink(uri: '/')}">Inicio</a>
                </div>
                <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                    <ul class="nav navbar-nav">
                        <li><g:link controller="imagen" action="create">Nueva im&aacutegen</g:link></li>
                    </ul>
                </div>
            </div>
        </nav>
        <g:layoutBody />
		<r:layoutResources />
	</body>
</html>
