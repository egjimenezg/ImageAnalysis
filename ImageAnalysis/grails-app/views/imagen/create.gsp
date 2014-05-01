<!DOCTYPE html>
<html>
	<head>
		<meta name="layout" content="main">
		<g:set var="entityName" value="${message(code: 'imagen.label', default: 'Imagen')}" />
		<title><g:message code="default.create.label" args="[entityName]" /></title>
        <r:require modules="jqueryLibrary, indexResources"/>
	</head>
	<body>
		<a href="#create-imagen" class="skip" tabindex="-1"><g:message code="default.link.skip.label" default="Skip to content&hellip;"/></a>
		<div class="navg" role="navigation">
			<ul>
				<li><g:link class="list" action="index"><g:message code="default.list.label" args="[entityName]" /></g:link></li>
			</ul>
		</div>
		<div id="create-imagen" class="content scaffold-create" role="main">
			<h1><g:message code="default.create.label" args="[entityName]" /></h1>
			<g:if test="${flash.message}">
			<div class="message" role="status">${flash.message}</div>
			</g:if>
			<g:hasErrors bean="${imagenInstance}">
			<ul class="errors" role="alert">
				<g:eachError bean="${imagenInstance}" var="error">
				<li <g:if test="${error in org.springframework.validation.FieldError}">data-field-id="${error.field}"</g:if>><g:message error="${error}"/></li>
				</g:eachError>
			</ul>
			</g:hasErrors>
            <g:uploadForm controller="Imagen" action="save">
            <div style="padding: 10px 10px 10px 10px">

                    <div class="row">
                        <div class="col-lg-3" style="margin-left: 40px;">

                            <div class="fileInputs">
                                <input type="file" class="file" name="file" />
                                <div class="upload">
                                    <input id="fakeInput" disabled/>
                                    <span class="glyphicon glyphicon-search"></span>
                                </div>
                            </div>
                        </div>
                    </div>
            </div>
            <fieldset class="buttons">
                <g:submitButton name="create" class="save" value="${message(code: 'default.button.create.label', default: 'Create')}" />
            </fieldset>
            </g:uploadForm>


		</div>
	</body>
</html>
