function validate(event){
    // prevent default form submission and perform validation
    event.preventDefault();
    var form = document.getElementById("registerForm");
    var name = form.name.value;
    var dob = form.dob.value;
    var email = form.email.value;
    var gender = form.gender.value;
    var phone = form.phone.value;
    
    var qualification = form.qualification.value;
    var position = form.position.value;
    var institute = form.institution.value;
    
    var address = form.address.value;
    var city = form.city.value;
    var state = form.state.value;
    var country = form.country.value;
    var pincode = form.pincode.value;
    
    var linkedin = form.linkedin.value;
    var github = form.github.value;

    var interest = form.interest.value;
    var payment = form.payment.value;

    if (name === "") {
        alert("Please enter your name.");
        return false;
    }

    if (dob === "") {
        alert("Please enter your date of birth.");
        return false;
    }

    if (email === "") {
        alert("Please enter your email address.");
        return false;
    }

    if (gender === "") {
        alert("Please select your gender.");
        return false;
    }

    if (phone === "") {
        alert("Please enter your phone number.");
        return false;
    }

    if (qualification === "") {
        alert("Please enter your qualification.");
        return false;
    }

    if (position === "") {
        alert("Please enter your position.");
        return false;
    }

    if (institute === "") {
        alert("Please enter your institute.");
        return false;
    }

    if (address === "") {
        alert("Please enter your address.");
        return false;
    }

    if (city === "") {
        alert("Please enter your city.");
        return false;
    }

    if (state === "") {
        alert("Please enter your state.");
        return false;
    }

    if (country === "") {
        alert("Please enter your country.");
        return false;
    }

    if (pincode === "") {
        alert("Please enter your pincode.");
        return false;
    }

    if (linkedin === "") {
        alert("Please enter your LinkedIn profile URL.");
        return false;
    }

    if (github === "") {
        alert("Please enter your GitHub profile URL.");
        return false;
    }

    if (interest === "") {
        alert("Please enter your interest.");
        return false;
    }

    if (payment === "") {
        alert("Please enter your payment method.");
        return false;
    }

    var emailRegex = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,6}$/;
    if (!emailRegex.test(email)){
        alert("Invalid email address");
        return false;
    }

    var phoneRegex = /^[0-9]+$/;
    if (!phoneRegex.test(phone)){
        alert("Phone number should contain only digits");
        return false;
    }

    if (phone.length != 10){
        alert("Phone number should be 10 digits");
        return false;
    }

    if (!phoneRegex.test(pincode)){
        alert("Pincode should contain only digits");
        return false;
    }

    if (pincode.length != 6){
        alert("Pincode should be 6 digits");
        return false;
    }

    // separate regex for linkedin and github links
    var linkedinRegex = /^https:\/\/www.linkedin.com\/.*$/;
    if (!linkedinRegex.test(linkedin)){
        alert("Invalid LinkedIn profile URL");
        return false;
    }

    var githubRegex = /^https:\/\/www.github.com\/.*$/;
    if (!githubRegex.test(github)){
        alert("Invalid GitHub profile URL");
        return false;
    }


    alert("Login successful!");
    window.location.href = "http://127.0.0.1:5500/sem4/webProgramming/miniProject/course.htm";
}