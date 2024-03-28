function validate(event){
    // prevent default form submission and perform validation
    event.preventDefault();
    var form = document.getElementById("loginForm");
    var username = form.username.value;
    var password = form.password.value;

    if (username === "") {
        alert("Please enter your username.");
        return false;
    }

    if (password === "") {
        alert("Please enter your password.");
        return false;
    }

    alert("Login successful!");
    window.location.href = "http://127.0.0.1:5500/sem4/webProgramming/miniProject/course.htm";
}