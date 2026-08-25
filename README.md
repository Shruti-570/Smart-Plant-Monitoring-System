# Smart-Plant-Monitoring-System
IoT-based plant monitoring system using Arduino, DHT11, soil moisture and PIR sensors, that tracks **soil moisture**, **temperature**, **humidity**, and **motion**, syncing data to the **Arduino IoT Cloud** in real time through Arduino IoT Cloud.

---

## 📷 Features

- 🌡️ Temperature & humidity monitoring via DHT11
- 💧 Soil moisture reading mapped to a 0–100% scale
- 🚶 Motion detection with PIR sensor
- ☁️ Live sync with Arduino IoT Cloud dashboard
- 🌐 Built-in web page for local moisture monitoring

---

## 🛠️ Hardware Requirements

| Component | Pin |
|---|---|
| DHT11 Temperature & Humidity Sensor | D4 |
| Capacitive Soil Moisture Sensor | A0 |
| PIR Motion Sensor | D5 |
| ESP8266 / Arduino MKR WiFi board | — |

---

## 📦 Libraries Required

Install these via **Arduino IDE → Library Manager**:

- [`ArduinoIoTCloud`](https://github.com/arduino-libraries/ArduinoIoTCloud)
- [`Arduino_ConnectionHandler`](https://github.com/arduino-libraries/Arduino_ConnectionHandler)
- [`DHT sensor library`](https://github.com/adafruit/DHT-sensor-library) by Adafruit

---

## 🚀 Setup & Usage

### 1. Clone the repository

```bash
git clone https://github.com/your-username/SMartPlant.git
cd SMartPlant
```

### 2. Create your secrets file

The file `arduino_secrets.h` is intentionally excluded from this repo (see `.gitignore`).  
Create it manually in the project folder:

```cpp
// arduino_secrets.h
#define SECRET_SSID          "your_wifi_ssid"
#define SECRET_OPTIONAL_PASS "your_wifi_password"
#define SECRET_DEVICE_KEY    "your_arduino_iot_device_key"
```

> ⚠️ **Never commit this file.** Your real credentials must stay local.

### 3. Set your Device UUID

In `thingProperties.h`, replace the placeholder with your actual device UUID from the [Arduino IoT Cloud](https://create.arduino.cc/iot/devices):

```cpp
const char DEVICE_LOGIN_NAME[] = "your-device-uuid-here";
```

### 4. Upload

Open `SMartPlant.ino` in Arduino IDE, select your board and port, then click **Upload**.

---

## 📁 File Structure

```
SMartPlant/
├── SMartPlant.ino        # Main sketch
├── thingProperties.h     # Arduino IoT Cloud property setup
├── arduino_secrets.h     # ⚠️ Local only — not in repo
├── html.h                # Embedded web UI for local access
├── .gitignore
└── README.md
```

---

## ☁️ Arduino IoT Cloud

This project integrates with [Arduino IoT Cloud](https://create.arduino.cc/iot).  
Tracked cloud variables:

| Variable | Type | Direction |
|---|---|---|
| `humidity` | `float` | Read/Write |
| `soilMoisture` | `float` | Read/Write |
| `temperature` | `float` | Read/Write |
| `motionDetected` | `bool` | Read/Write |

---
## 👥 Team

This project was collaboratively developed by a team of 4 members. All members contributed equally to the research, development, and testing of the pipeline.

| Name | GitHub |
|------|--------|
| Shruti Khisa | [@Shruti-570](https://github.com/Shruti-570) |
| Shaira Akhter Diba | [@ShairaDiba](https://github.com/ShairaDiba) |
| Farhan Tanvir | [@Tanvir868X](https://github.com/Tanvir868X) |
| Farhan Noor | [@frnoor](https://github.com/frnoor) |

> **Note:** This project was developed collaboratively offline and committed to GitHub after completion. All team members contributed equally to the codebase.

## 📄 License

MIT License — free to use, modify, and distribute.
