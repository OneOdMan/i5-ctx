/* 
 *
 * Exercise Objective - Focus on reverse engineering
 * Exercise Challenge - Capture-the-flag, must inspect malware deployed on electrical grid that holds the key to de-activating this page
 * Exercise Contents - Text field to submit flag, Submit button, Button to download fake-malware
 *
 * */

const express = require('express');
const router = express.Router();
const path = require('path');

router.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, '../html/electrical-grid.html'));
})

module.exports = router;
