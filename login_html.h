const char login_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Manager Login</title>
  <style>
    body { font-family: 'Courier New', Courier, monospace; background-color: #050505; color: #fff; text-align: center; margin: 0; padding: 50px 20px; }
    .login-box { background: #111; padding: 30px; border-radius: 8px; border: 1px solid #333; max-width: 350px; margin: auto; box-shadow: 0px 0px 20px #ff9900; }
    input { padding: 15px; width: 85%; margin: 10px 0; border: none; border-radius: 4px; background: #222; color: #fff; font-size: 16px; text-align: center; }
    button { background-color: #ff9900; color: #000; border: none; padding: 15px; font-size: 18px; font-weight: bold; border-radius: 4px; cursor: pointer; width: 95%; margin-top: 15px; }
    #errorMsg { color: #ff3333; margin-top: 15px; font-weight: bold; }
  </style>
</head>
<body>

  <div class="login-box">
    <h2 style="color: #ff9900;">MANAGER LOGIN</h2>
    <input type="text" id="user" placeholder="Username">
    <input type="password" id="pass" placeholder="Password">
    <button onclick="attemptLogin()">AUTHENTICATE</button>
    <p id="errorMsg"></p>
  </div>

  <script>
    function attemptLogin() {
      let u = document.getElementById("user").value;
      let p = document.getElementById("pass").value;
      
      fetch('/auth', {
        method: 'POST',
        headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
        body: 'user=' + encodeURIComponent(u) + '&pass=' + encodeURIComponent(p)
      }).then(response => response.json()).then(data => {
        if(data.ok) { window.location.href = "/manager"; } 
        else { document.getElementById("errorMsg").innerText = "ACCESS DENIED: Invalid Credentials."; }
      });
    }
  </script>
</body>
</html>
)rawliteral";