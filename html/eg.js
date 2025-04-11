import { IP_ADDR_VPN } from '../server.js';

// Function to fetch data and display it
function fetchData() {
  // Fetch data from the API
  fetch(`${IP_ADDR_VPN}/electricalGrid/opeg-status`)
    .then(response => {
      // Check if the response is OK (status code 200)
      if (!response.ok) {
        throw new Error('Network response was not ok');
      }
      // Parse the response data as JSON
      return response.json();
    })
    .then(data => {
      // If the fetch is successful, inject the data into the div
      dataContainer.innerHTML = JSON.stringify(data, null, 2); // This formats the JSON for readability
    })
    .catch(error => {
      // Handle any errors that occur during the fetch
      dataContainer.innerHTML = 'Error fetching data: ' + error.message;
    });
}

// Call the function to fetch and display the data
fetchData();
