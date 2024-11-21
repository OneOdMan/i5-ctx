const express = require('express');
const router = express.Router();
const path = require('path');

// Serve the login page
router.get('/', (req, res) => {
   res.sendFile(path.join(__dirname, '../html/login.html'));
});

// Handle login POST request
router.post('/auth', (req, res) => {
    const { username, password } = req.body;

    // For now, just a simple check for a hardcoded user (username: "admin", password: "password")
    if (username === 'admin' && password === 'password') {
        res.send('Login successful!');
    } else {
        res.send('Invalid credentials!');
    }
});

module.exports = router;
