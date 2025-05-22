# smart-inhaler-ai-iot


# Smart Inhaler – AI-Enabled IoT for Asthma & COPD Monitoring

A smart, portable IoT inhaler system that monitors asthma/COPD patients' usage patterns, detects air quality and environmental triggers, and uses AI to predict attack risks.

---

## 🌟 Key Features
- Detects inhaler usage via flow sensor
- Monitors air quality, temperature, and humidity
- Sends real-time alerts to patients
- AI-based attack prediction using environmental and usage trends
- Cloud data logging and doctor dashboard

---

## 🔧 Hardware Components & Pinouts

### Microcontroller: ESP32 DevKit
| Component             | Sensor/Module        | ESP32 Pin      |
|----------------------|----------------------|----------------|
| Flow Sensor (Analog) | e.g., Honeywell      | GPIO34 (ADC1)  |
| PM2.5 Sensor         | PMS5003 (UART)       | RXD - GPIO16, TXD - GPIO17 |
| Temp & Humidity      | DHT22                | GPIO25         |
| Buzzer               | Passive Buzzer       | GPIO27         |
| Status LED           | Indicator            | GPIO2          |

> Note: Ensure 3.3V logic compatibility for sensors; use level shifter if needed.

---

## 🧠 AI Model
- Input: Air quality + usage frequency + environmental stats
- Model: Logistic Regression / Decision Tree
- Output: Risk Score (0–100%)

---

## 📱 App Interface (Flutter)
- BLE/WiFi sync
- Shows usage log, attack predictions
- Doctor's panel for review

---

## 📊 Data Flow
