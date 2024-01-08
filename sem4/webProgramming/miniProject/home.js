const scheduleBtnDivText = document.querySelector("#schedule-btn-div-text")

function updateScheduleBtnDivText() {
    if (window.innerWidth < 768) {
        scheduleBtnDivText.innerHTML = "="
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