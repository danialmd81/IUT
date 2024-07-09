function openTab(tabName) {
    let x = document.getElementsByClassName("tab-content");
    for (let i = 0; i < x.length; i++) {
        x[i].style.display = "none";
    }
    document.getElementById(tabName).style.display = "block";
}

document.addEventListener('DOMContentLoaded', () => {
    openTab('login')
    const urlParams = new URLSearchParams(window.location.search);
    const error = urlParams.get('error');
    const errorMessageRegister = document.getElementById('error-message-register');
    const errorMessageLogin = document.getElementById('error-message-login');

    if (error) {
        if (error === 'alreadyexistsuser') {
            errorMessageRegister.textContent = 'Username or Email already exists!';
            openTab('register');
        }
        else if (error == 'nouser') {
            errorMessageLogin.textContent = 'You don\'t have an account. Please register.';
            openTab('login');
        }
    }
});