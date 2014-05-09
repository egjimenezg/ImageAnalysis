<%@ page import="org.apache.commons.codec.binary.Base64; mx.ipn.imageanalysis.Imagen" %>

<!DOCTYPE html>
<html>
	<head>
		<meta name="layout" content="main">
        <g:set var="entityName" value="${message(code: 'imagen.label', default: 'Imagen')}" />
        <title><g:message code="default.show.label" args="[entityName]" /></title>
        <r:require modules="jqueryLibrary,showImageLibraries"/>
	</head>
	<body>
    <div style="padding:0 15px;">
            <div class="row">
                <div class="col-lg-3" style="padding: 0">
                    <div class="list-group">
                        <span class="list-group-item active" style="width:100%;">
                            Operaciones sobre im&aacutegen
                        </span>
                        <div class="btn-group-vertical">          
                            <div class="btn-group">
                                    <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown" >
                                        Operaciones puntuales
                                        <span class="caret"></span>
                                    </button>
                                    <ul class="dropdown-menu operacionPuntual" style="width: 100%">
                                        <li><a href="#" id="getNegativeImage">Negativo de una im&aacutegen</a></li>
                                        <li><a href="#" id="getGrayScaleImage">Conversi&oacuten a nivel de gris</a></li>
                                        <li><a href="#" id="getBinaryImage">Im&oacutegen binaria</a></li>
                                    </ul>
                                </div>

                                <div class="btn-group">
                                    <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown" style="width: 325px;">
                                        Mejoramiento de la im&aacutegen
                                        <span class="caret"></span>
                                    </button>
                                    <ul class="dropdown-menu" style="width: 100%">
                                        <li><a href="#">Dropdown link</a></li>
                                        <li><a href="#">Dropdown link</a></li>
                                    </ul>
                                </div>
                            </div>
                    </div>                    
                </div>
                <div class="col-md-4">
                    <p>Im&aacutegen original</p>
                    <g:if test="${flash.message}">
                        <div class="message" role="status">${flash.message}</div>
                    </g:if>
                    <g:if test="${imagenInstance?.id}">
                        <div>
                            <img class="imagen" src="${createLink(controller:'imagen',action:'showImageFromDatabase',params:[id:imagenInstance?.id])}"  />
                        </div>
                    </g:if>
                </div>

                <div class="col-md-4">
                    <p>Im&aacutegen procesada</p>
                    <div id="imagenProcesada">

                    </div>
                </div>

            </div>
    </div>
	</body>
</html>
