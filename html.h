// html.h — Webpage for displaying soil moisture data

const char html_page[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Smart Plant Monitoring System</title>
  <style>
    body { font-family: Arial; background: #e9f7ef; text-align: center; margin-top: 50px; }
    h1 { color: #2e7d32; }
    .box {
      display: inline-block; padding: 20px; background: #fff;
      border-radius: 12px; box-shadow: 0 0 10px rgba(0,0,0,0.2);
      width: 300px;
    }
    #moistureValue {
      font-size: 32px; color: #1565c0; margin: 20px 0;
    }
    button {
      padding: 10px 20px; background: #2e7d32; color: white;
      border: none; border-radius: 6px; cursor: pointer;
    }
    button:hover { background: #43a047; }
  </style>
  <script>
    function getData() {
      fetch("/readMoisture")
      .then(response => response.text())
      .then(data => {
        document.getElementById("moistureValue").innerHTML = data + "%";
      });
    }
    setInterval(getData, 2000);
  </script>
</head>
<body>
  <h1>🌱 Smart Plant Monitoring System</h1>
  <div class="box">
    <h2>Soil Moisture Level</h2>
    <div id="moistureValue">--%</div>
    <button onclick="getData()">Refresh Now</button>
  </div>
</body>
</html>
)rawliteral";
