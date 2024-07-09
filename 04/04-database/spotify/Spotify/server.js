const express = require('express');
const mysql = require('mysql2');
const bodyParser = require('body-parser');
const session = require('express-session');
const path = require('path');

const app = express();
app.use(express.json());
const port = 3000;


const db = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'dani',
    database: 'spotify'
});

db.connect((err) => {
    if (err) throw err;
    console.log('Connected to database');
});

app.use(bodyParser.urlencoded({ extended: true }));
app.use(session({
    secret: 'secret',
    resave: true,
    saveUninitialized: true
}));

app.use(express.static(path.join(__dirname, 'public')));
app.use('/style', express.static(path.join(__dirname, 'style')));
app.use('/js', express.static(path.join(__dirname, 'js')));


app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'login.html'));
});


// login
app.post('/auth', (req, res) => {
    const username = req.body.username;
    const password = req.body.password;
    if (username && password) {
        db.query('SELECT * FROM users WHERE username = ? AND password = ?', [username, password], (err, results) => {
            if (err) throw err;
            if (results.length > 0) {
                req.session.loggedin = true;
                req.session.username = username;
                res.redirect('/home');
            } else {
                res.redirect('/?error=nouser');
            }
        });
    }
});


app.post('/register', (req, res) => {
    const username = req.body.username;
    const password = req.body.password;
    const email = req.body.email;
    const birthday = req.body.birthday;
    const address = req.body.address;
    const options = req.body.options;

    if (username && password && email && birthday && address) {
        db.query('SELECT * FROM users WHERE username = ? OR email = ?', [username, email], (err, results) => {
            if (err) throw err;
            if (results.length > 0) {
                return res.redirect('/?error=alreadyexistsuser');
            } else {
                db.query('INSERT INTO users (username, password, email, birthday, address) VALUES (?, ?, ?, ?, ?)',
                    [username, password, email, birthday, address], (err, results) => {
                        if (err) throw err;
                        req.session.loggedin = true;
                        req.session.username = username;
                        const userId = results.insertId;

                        if (options === "singer") {
                            db.query('INSERT INTO artist (ArtistID, name) VALUES (?,?)',
                                [userId, username], (err, results) => {
                                    if (err) throw err;
                                    res.redirect('/home');
                                });
                        } else {
                            res.redirect('/home');
                        }
                    });
            }
        });
    }
});


// login

// home

app.get('/home', (req, res) => {
    if (req.session.loggedin) {
        const username = req.session.username;

        db.query('SELECT * FROM users WHERE username = ?', [username], (err, userResults) => {
            if (err) throw err;
            if (userResults.length > 0) {
                const userId = userResults[0].UserID;
                const isPremium = userResults[0].is_premium;

                db.query('SELECT * FROM artist WHERE ArtistID = ?', [userId], (err, artistResults) => {
                    if (err) throw err;

                    let userType = 'normal';
                    if (artistResults.length > 0) {
                        userType = 'artist';
                    } else if (isPremium) {
                        userType = 'premium';
                    }

                    res.sendFile(path.join(__dirname, 'public', 'home.html'));
                    req.session.userType = userType;
                });
            } else {
                res.redirect('/');
            }
        });
    } else {
        res.redirect('/');
    }
});

app.get('/getUserType', (req, res) => {
    if (req.session.loggedin) {
        res.json({ userType: req.session.userType });
    } else {
        res.status(401).json({ error: 'User not logged in' });
    }
});

// home

// wallet

app.get('/wallet', (req, res) => {
    if (req.session.loggedin) {
        res.sendFile(path.join(__dirname, 'public', 'wallet.html'));
    } else {
        res.redirect('/');
    }
});

app.get('/getWalletBalance', (req, res) => {
    if (req.session.loggedin) {
        const username = req.session.username;

        db.query('SELECT wallet FROM users WHERE username = ?', [username], (err, results) => {
            if (err) throw err;
            if (results.length > 0) {
                res.json({ wallet: results[0].wallet });
            } else {
                res.json({ wallet: 0 });
            }
        });
    } else {
        res.status(401).json({ error: 'User not logged in' });
    }
});

app.post('/wallet/add', (req, res) => {
    if (req.session.loggedin) {
        const username = req.session.username;
        const amount = parseFloat(req.body.amount);

        db.query('UPDATE Users SET wallet = wallet + ? WHERE username = ?', [amount, username], (err, results) => {
            if (err) throw err;
            db.query('SELECT wallet FROM Users WHERE username = ?', [username], (err, results) => {
                if (err) throw err;
                res.json({ wallet: results[0].wallet, message: 'Money added successfully.' });
            });
        });
    } else {
        res.status(401).json({ error: 'User not logged in' });
    }
});

app.post('/wallet/take', (req, res) => {
    if (req.session.loggedin) {
        const username = req.session.username;
        const amount = parseFloat(req.body.amount);

        db.query('SELECT wallet FROM Users WHERE username = ?', [username], (err, results) => {
            if (err) throw err;
            if (results[0].wallet < amount) {
                res.json({ error: 'Insufficient funds in wallet.' });
            } else {
                db.query('UPDATE Users SET wallet = wallet - ? WHERE username = ?', [amount, username], (err, results) => {
                    if (err) throw err;
                    db.query('SELECT wallet FROM Users WHERE username = ?', [username], (err, results) => {
                        if (err) throw err;
                        res.json({ wallet: results[0].wallet, message: 'Money taken successfully.' });
                    });
                });
            }
        });
    } else {
        res.status(401).json({ error: 'User not logged in' });
    }
});


// wallet

// buy premium account

app.get('/BuyPremiumAccount', (req, res) => {
    if (req.session.loggedin) {
        res.sendFile(path.join(__dirname, 'public', 'buypremium.html'));
    } else {
        res.redirect('/');
    }
});

app.get('/addToPremium', (req, res) => {
    if (req.session.loggedin) {
        const username = req.session.username;

        db.query('SELECT * FROM Users WHERE username = ?', [username], (err, results) => {
            if (err) throw err;

            if (results.length > 0) {
                const userId = results[0].UserID;

                db.query('INSERT INTO PremiumUsers (PremiumID) VALUES (?)', [userId], (err, results) => {
                    if (err) throw err;

                    db.query('UPDATE Users SET is_premium = 1 WHERE UserID = ?', [userId], (err, results) => {
                        if (err) throw err;
                        res.redirect('/');
                    });
                });
            } else {
                res.redirect('/');
            }
        });
    } else {
        res.redirect('/');
    }
});



// buy premium account


app.listen(port, () => {
    console.log(`Server running on http://localhost:${port}`);
});