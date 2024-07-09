document.addEventListener('DOMContentLoaded', () => {
    fetch('/getWalletBalance')
        .then(response => response.json())
        .then(data => {
            document.getElementById('balance').textContent = `$${data.wallet}`;
        });
});



const walletInput = document.getElementById('walletInput');
const moneyValue = document.getElementById('moneyValue');
const walletMessage = document.getElementById('walletMessage');
let actionType = '';

document.getElementById('addMoney').addEventListener('click', () => {
    actionType = 'add';
    walletInput.style.display = 'block';
    walletMessage.style.display = 'none';
});

document.getElementById('takeMoney').addEventListener('click', () => {
    actionType = 'take';
    walletInput.style.display = 'block';
    walletMessage.style.display = 'none';
});

document.getElementById('submitMoney').addEventListener('click', () => {
    const value = parseFloat(moneyValue.value);
    if (isNaN(value) || value <= 0) {
        walletMessage.textContent = 'Please enter a valid amount.';
        walletMessage.style.display = 'block';
        return;
    }

    fetch(`/wallet/${actionType}`, {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ amount: value })
    })
        .then(response => response.json())
        .then(data => {
            if (data.error) {
                walletMessage.textContent = data.error;
                walletMessage.style.backgroundColor = "#ffcccb";
                walletMessage.style.color = "#d8000c";
            } else {
                document.getElementById('balance').textContent = `$${data.wallet}`;
                walletMessage.textContent = data.message;
            }
            walletMessage.style.display = 'block';
            walletInput.style.display = 'none';
            moneyValue.value = '';
        });
});