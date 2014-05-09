<%@ page import="mx.ipn.imageanalysis.Imagen" %>



<div class="fieldcontain ${hasErrors(bean: imagenInstance, field: 'myFile', 'error')} required">
	<label for="myFile">
		<g:message code="imagen.myFile.label" default="My File" />
		<span class="required-indicator">*</span>
	</label>
	<input type="file" id="myFile" name="myFile" />
</div>

