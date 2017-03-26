//using GET via fetch API
var token = "YOUR_TOKEN_";

var temp;

//get temperature data from thinger.io using fatch API

$(function temperature(){
var url = "YOUR_API_LINK";
        
fetch(url,
      {headers: {Authorization: token}})
      .then(  
    function(response) {  
      if (response.status !== 200) {  
        console.log('Looks like there was a problem. Status Code: ' +  
          response.status);  
        return;  
      }

      // Examine the text in the response  
      response.json().then(function(data) {  
          temp = data.out;
          console.log(temp);
          
      });  
    }  
  )  
  .catch(function(err) {  
    console.log('Fetch Error :-S', err);  
  });
    setTimeout(temperature, 1000);  // automatically call this function after 1 sec 
});