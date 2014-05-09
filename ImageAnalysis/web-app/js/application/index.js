$(document).ready(function(){

    var fileInput = document.getElementsByClassName("file")[0]
    var fake = document.getElementById("fakeInput")

    fileInput.onchange = fileInput.onmouseout =  function(){
        fake.value = this.value
    }

});

