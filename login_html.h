const char login_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no">
<title>Vault Control — Manager Login</title>
<link href="https://fonts.googleapis.com/css2?family=Share+Tech+Mono&family=Barlow:wght@300;400;600&display=swap" rel="stylesheet">
<style>
  :root {
    --vault-green: #00ff88; --vault-amber: #ffaa00; --vault-red: #ff3344;
    --bg: #0a0c0f; --surface: #111418; --border: #2a2f38; --text: #e8edf5;
    --mono: 'Share Tech Mono', monospace; --sans: 'Barlow', sans-serif;
  }
  * { margin: 0; padding: 0; box-sizing: border-box; }
  body { background: var(--bg); color: var(--text); font-family: var(--sans); display: flex; align-items: center; justify-content: center; min-height: 100vh; padding: 20px; }
  body::before { content: ''; position: fixed; inset: 0; background-image: linear-gradient(var(--border) 1px, transparent 1px), linear-gradient(90deg, var(--border) 1px, transparent 1px); background-size: 40px 40px; opacity: 0.15; pointer-events: none; }
  .login-card { background: var(--surface); border: 1px solid var(--border); padding: 40px; border-radius: 4px; width: 100%; max-width: 400px; text-align: center; position: relative; z-index: 1; box-shadow: 0 8px 32px rgba(0,0,0,0.5); }
  .login-card::before { content: ''; position: absolute; top: 0; left: 0; right: 0; height: 2px; background: var(--vault-amber); }
  h2 { font-family: var(--mono); color: var(--vault-amber); margin-bottom: 24px; text-transform: uppercase; letter-spacing: 0.1em; font-size: 22px; }
  input { width: 100%; background: #1a1e24; border: 1px solid var(--border); padding: 14px; color: var(--text); margin-bottom: 16px; font-family: var(--mono); outline: none; border-radius: 3px; font-size: 14px; text-align: center; letter-spacing: 0.05em; transition: border-color 0.2s; }
  input:focus { border-color: var(--vault-amber); }
  button { width: 100%; background: var(--vault-amber); color: #000; border: none; padding: 14px; font-family: var(--mono); font-size: 14px; font-weight: bold; letter-spacing: 0.1em; cursor: pointer; text-transform: uppercase; border-radius: 3px; transition: background 0.2s; margin-top: 8px; }
  button:hover { background: #ffbc33; }
  #errorMsg { color: var(--vault-red); margin-top: 16px; font-family: var(--mono); font-size: 12px; letter-spacing: 0.05em; min-height: 15px; }
</style>
</head>
<body>
  <div class="login-card">
    <h2>MANAGER GATEWAY</h2>
    <input type="text" id="user" placeholder="USERNAME">
    <input type="password" id="pass" placeholder="PASSWORD">
    <button onclick="attemptLogin()">AUTHENTICATE</button>
    <p id="errorMsg"></p>
  </div>
  <script>
    function attemptLogin() {
      let u = document.getElementById("user").value;
      let p = document.getElementById("pass").value;
      document.getElementById("errorMsg").innerText = "";
      fetch('/auth', {
        method: 'POST',
        headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
        body: 'user=' + encodeURIComponent(u) + '&pass=' + encodeURIComponent(p)
      }).then(response => response.json()).then(data => {
        if(data.ok) { window.location.href = "/manager"; } 
        else { document.getElementById("errorMsg").innerText = "ACCESS DENIED."; }
      }).catch(() => { document.getElementById("errorMsg").innerText = "CONNECTION ERROR."; });
    }
  </script>
</body>
</html>
)rawliteral";