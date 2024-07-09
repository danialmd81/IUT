const getStartedBtn = document.querySelector(".btn-primary");

getStartedBtn.addEventListener("click", () => {
    fetch('/wallet/take', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ amount: 9.99 })
    })
        .then(response => response.json())
        .then(data => {
            const walletMessage = document.getElementById("walletMessage");
            if (data.error) {
                walletMessage.textContent = data.error;
                walletMessage.style.backgroundColor = "#ffcccb";
                walletMessage.style.color = "#d8000c";
            } else {
                walletMessage.textContent = data.message;
                window.location.href = '/addToPremium';
            }
            walletMessage.style.display = 'block';
        });
});
