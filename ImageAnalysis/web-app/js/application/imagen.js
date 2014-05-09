$(document).ready(function(){

    $(".operacionPuntual a").click(function(event){
        event.preventDefault();

        $.ajax({
            type:"post",
            url:"../../operacionPuntual/"+$(this).attr("id"),
            success: function(data){
                $("#imagenProcesada").html(data);
            }
        });

    });


});
