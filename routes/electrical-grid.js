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

let egStatus = "ARMED";

router.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, '../html/electrical-grid.html'));
});

router.get('/opeg-status', (req, res) =>{
  res.json({status: egStatus});
  console.log('Sending status: ', egStatus);
});

router.get('/download/malware', (req,res) => {
});

router.get('/auth-eg', (req, res) => {
  const inputText = req.body.textInput.trim();

  if (inputText === "keycode"){
    egStatus = "DISARMED";
    console.log(egStatus);
  } else {
      res.send('Error: Wrong keycode');
      console.log('Error, Wrong Keycode');
  }
});

module.exports = router;
