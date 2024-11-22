const express = require('express');
const path = require('path');
const app = express();

// Constants 
const PORT = 3000;
const IP_ADDR_VPN = '10.20.0.1';

// Middleware to parse incoming form data
app.use(express.urlencoded({ extended: true }));

// Import route files
const loginRoute = require('./routes/login.js');
const eletricalGrid = require('./routes/electrical-grid.js');
const nuclearPlant = require('./routes/nuclear-plant.js');

// Using the routes
app.use('/login', loginRoute);
app.use('/electricalGrid', eletricalGrid);
app.use('/nuclearPlant', nuclearPlant);

// Start the server
app.listen(PORT, IP_ADDR_VPN, () => {
    console.log(`Server is running on http://${IP_ADDR_VPN}:${PORT}`);
});

module.exports = IP_ADDR_VPN;
