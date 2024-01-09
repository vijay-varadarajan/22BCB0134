const scheduleBtnDivText = document.querySelector("#schedule-btn-div-text")

function updateScheduleBtnDivText() {
    if (window.innerWidth < 768) {
        scheduleBtnDivText.innerHTML = "<i class=\"fa fa-angle-double-down\"></i>"
    } else {
        scheduleBtnDivText.innerHTML = "Schedule"
    }
}

updateScheduleBtnDivText()

window.addEventListener("resize", updateScheduleBtnDivText)


const scrollToTopBtn = document.querySelector(".scroll-to-top-btn")

function updateScrollToTopBtn() {
    if (window.scrollY > 150) {
        scrollToTopBtn.style.display = "block";
    } else {
        scrollToTopBtn.style.display = "none";
    }
}
window.addEventListener("scroll", updateScrollToTopBtn)


// reduce opacity of navbar on scroll
const navbar = document.querySelector("#navbar")

function updateNavbar() {
    if (window.scrollY > 600 || (window.innerWidth < 772 && window.scrollY > 1)) {
        navbar.style.backgroundColor = "black";
        navbar.style.opacity = "0.9";
        navbar.style.borderBottom = "1px solid rgb(255, 255, 255, 0.922)";
    } else {
        navbar.style.backgroundColor = "transparent";
        navbar.style.opacity = "1";
        navbar.style.borderBottom = "none";
    }
}

window.addEventListener("scroll", updateNavbar)

