<%--
  Author: Gamaliel Jiménez
  Date: 25/04/14
  Time: 13:26
--%>
<!DOCTYPE html>
<%@ page contentType="text/html;charset=UTF-8" %>
<html lang="en">
<head>
    <meta name="layout" content="main"/>
    <title>Image Processing WebApp</title>
    <g:set var="entityName" value="${message(code: 'imagen.label', default: 'Imagen')}" />
    <r:require modules="jqueryLibrary, indexResources"/>
</head>
<body>
<div style="padding:0 15px;"><!-- offset row negative padding -->
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
        <div class="col-md-6">
            <div id="list-imagen" class="content scaffold-list" role="main">
                <h1 class="grails"><g:message code="default.list.label" args="[entityName]" /></h1>
                <g:if test="${flash.message}">
                    <div class="message" role="status">${flash.message}</div>
                </g:if>

                <table>
                    <thead>
                    <tr>
                        <g:sortableColumn property="id" title="${message(code: 'imagen.id.label', default: 'Id')}" />
                        <th>Im&aacutegen</th>
                    </tr>
                    </thead>
                    <tbody>
                    <g:each in="${imagenInstanceList}" status="i" var="imagenInstance">
                        <tr class="${(i % 2) == 0 ? 'even' : 'odd'}">
                            <td><g:link controller="imagen" action="show" id="${imagenInstance.id}">${imagenInstance.id}</g:link></td>
                            <td>
                                <img class="imagen" src="${createLink(controller:'imagen',action:'showImageFromDatabase',params:[id:imagenInstance?.id])}" />
                            </td>
                        </tr>
                    </g:each>
                    </tbody>
                </table>
                <div class="paginationg">
                    <g:paginate total="${imagenInstanceCount ?: 0}" />
                </div>
            </div>
        </div>
    </div>
</div>

<script>

</script>
</body>
</html>