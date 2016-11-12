$(document).ready(function(){
    $(".btn-more-services").click(function(){
        $(".more-services-arrow").toggleClass("glyphicon-circle-arrow-up");
        $(".more-services-arrow").toggleClass("glyphicon-circle-arrow-down");
    });
 
});

function highlightInfo(identifier) {
    $(".moreInfoWell").addClass("well-sm");
    $(".highlight").removeClass("highlight");
    $('#'+identifier).addClass('highlight');
    $('#'+identifier).removeClass('well-sm');
    $(".moreInfo").addClass("hide");
    $('#'+identifier).children(".moreInfo").removeClass("hide");
} 