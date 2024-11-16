# Smart Environmental Monitoring System

The **Smart Environmental Monitoring System** is an innovative project designed to provide real-time monitoring of key environmental conditions such as temperature, humidity, light intensity, and noise levels. It features a dynamic and interactive OLED display that adjusts to environmental changes, making it an efficient and user-friendly solution for both personal and industrial applications.

The system is built with robust I2C communication, ensuring seamless integration of multiple sensors and peripherals. Its power optimization techniques and battery backup capabilities make it ideal for continuous operation, even in power-constrained environments. With its accuracy, adaptability, and future-ready design, this system sets a benchmark for environmental monitoring solutions.

---

## 📝 **System Features**

### Real-Time Clock
- Accurate time display with a drift of less than 1 second/day.
- 24-hour format for international compatibility.
- Battery backup capability for seamless operation during power outages.

### Environmental Monitoring
- **Temperature:** 0°C to 50°C with ±0.5°C accuracy.
- **Humidity:** 20% to 90% RH.
- **Light Intensity:** 1–65,535 lux with a resolution of 1 lux.
- **Noise Level:** 30–130 dB.

### Smart Display
- Dynamic emoji display based on environmental conditions.
- Auto-brightness adjustment for optimal visibility.
- Multi-screen information cycling for displaying different data.

---

## 🔧 **Technical Challenges & Solutions**

### I2C Bus Management
- **Challenge:** Managing multiple devices on the same bus.
- **Solution:** Implemented device addressing and bus arbitration for conflict-free communication.

### Power Optimization
- **Challenge:** Prolonging battery life under continuous monitoring.
- **Solution:** Enabled sleep modes for sensors and adaptive sampling for power efficiency.

### Display Refresh
- **Challenge:** Preventing screen tearing during updates.
- **Solution:** Integrated double-buffering to maintain smooth refresh rates.

---

## 📈 **Results and Performance**

### System Performance
- **Display Refresh Rate:** 1 Hz.
- **Sensor Sampling Rate:** 0.2 Hz.
- **Power Consumption:** ~100 mA at 3.3V.

### Accuracy Metrics
- **Time Drift:** <1 second/day.
- **Temperature Accuracy:** ±0.5°C.
- **Light Sensing Resolution:** 1 lux.

---

## 🚀 **Future Enhancements**

### Hardware Upgrades
- **WiFi Module Integration:** Enable remote data access and control.
- **Additional Environmental Sensors:** Expand to measure air quality, CO2, etc.
- **Expanded Display Capabilities:** Support for larger or multi-line displays.

### Software Features
- **Weather Prediction:** Intelligent algorithms for forecasting.
- **Data Logging Capability:** Record historical data for trend analysis.
- **Mobile App Integration:** Access and monitor data through a companion app.

---

## 🛠️ **Technologies Used**
- **Microcontroller:** STM32F401CCU6.
- **Sensors:** Temperature, humidity, light, and noise sensors.
- **Display:** OLED (I2C interface).
- **Communication:** I2C Protocol.
- **Programming Language:** C.
- **IDE:** Keil µVision 5.

---

## 👥 **Team Members**
- **CB.EN.U4CSE22401** - Aravind Kumar  
- **CB.EN.U4CSE22407** - Aakash  
- **CB.EN.U4CSE22422** - Mugunth Narayanan  
- **CB.EN.U4CSE22447** - Thanus Kumaar A.
