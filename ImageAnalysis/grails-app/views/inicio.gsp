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