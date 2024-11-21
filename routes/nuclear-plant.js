/*
 * Exercise Objective - Get familiar with Web Tools and resending loaded requests
 * Exercise Challenge - Visual trick, button to stop operation is fake. Must send a proper request to API that accepts specific value
 * Exercise Contents - Must submit the key or another value found in electrical-grid problem
 * */

const express = require('express');
const router = express.Router();
const path = require('path');

router.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, '../html/nuclear-plant.html'));  
})

module.exports = router;
