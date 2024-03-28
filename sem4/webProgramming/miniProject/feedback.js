document.addEventListener("DOMContentLoaded", function() {

    star = document.querySelectorAll("#rating-star");
    
    star.forEach(function(star) {
        star.addEventListener("click", function() {
            if (star.classList.contains("far")) {
                star.classList.remove("far");
                star.classList.add("fas");
            } else {
                star.classList.remove("fas");
                star.classList.add("far");
            }
        });
    });
});