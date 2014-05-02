
<%@ page import="mx.ipn.imageanalysis.Imagen" %>
<!DOCTYPE html>
<html>
	<head>
		<meta name="layout" content="main">
		<title><g:message code="default.show.label" args="[entityName]" /></title>
        <g:set var="entityName" value="${message(code: 'imagen.label', default: 'Imagen')}" />
        <r:require modules="jqueryLibrary, indexResources"/>
	</head>
	<body>
    <div style="padding:0 15px;">
            <div class="row">
                <div class="col-lg-3">
                    <g:uploadForm controller="Imagen" action="upload">
                        <div class="list-group">
                            <span class="list-group-item active">
                                Operaciones sobre im&aacutegen
                            </span>
                            <div class="btn-group-vertical">

                                <div class="btn-group">
                                    <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown">
                                        Operaciones puntuales
                                        <span class="caret"></span>
                                    </button>
                                    <ul class="dropdown-menu" style="width: 100%">
                                        <li><a href="#" class="subMenu">Negativo de una im&aacutegen</a></li>
                                        <li><a href="#" class="subMenu">Conversi&oacuten a nivel de gris</a></li>
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
                    </g:uploadForm>
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
                    <g:if test="${imagenProcesada}">
                        <div>
                            <img src="${createLink(controller:'imagen',action:'showImageFromDatabase',params:[id:imagenProcesada?.id])}"/>
                        </div>
                    </g:if>
                </div>

            </div>
    </div>
	</body>
</html>
