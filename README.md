# 🎨 RGB LED Controller with Potentiometers (ESP32)

This project is an **RGB LED light controller** built using an **ESP32** and **three potentiometers**. Each potentiometer independently controls the intensity of the **red, green, and blue** channels of an RGB LED.

The controller uses PWM output, smoothing, and gamma correction to produce smooth and visually accurate color transitions.

---

## ✨ Features

- 🎛️ Independent control of Red, Green, and Blue channels  
- 🔄 Smooth brightness transitions using exponential smoothing  
- 👁️ Gamma correction for human-perceived brightness  
- ⚡ Hardware PWM using ESP32 LEDC  
- 🎚️ 12-bit ADC resolution for precise potentiometer input  

---

## 🧰 Hardware Requirements

- ESP32 development board  
- RGB LED  
- 3 × Potentiometers  
- 3 × Resistors connected to the RGB lights (220 ohm)
- Breadboard and jumper wires

---

## 🔌 Pin Configuration

### Potentiometers (ADC Inputs)

| Color | GPIO |
|------|------|
| Red  | 34 |
| Green | 35 |
| Blue | 36 |

### RGB LED (PWM Outputs)

| Color | GPIO |
|------|------|
| Red  | 21 |
| Green | 22 |
| Blue | 23 |

---

## ⚙️ How It Works

1. Reads analog input from three potentiometers (0–4095)
2. Maps values to an 8-bit range (0–255)
3. Applies exponential smoothing to reduce flicker
4. Applies gamma correction for natural brightness perception
5. Outputs PWM signals to the RGB LED

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/rgb-led-controller.git
```

### 2. Open in Arduino IDE

Install ESP32 board support
Select your ESP32 board and COM port

### 3. Upload the Code
Connect your ESP32 and upload the sketch.

---

## 🛠️ Adjustable Parameters

You can modify these values in the code to change behavior:
```cpp
const float SMOOTHING = 0.08; // Higher = faster response
const float GAMMA = 2.2; // Brightness correction, do not recommend to change
```

---

🔮 **Possible Improvements**

1. Save last color using EEPROM or flash memory
2. Add color presets with buttons
3. Control via Bluetooth or Wi-Fi
4. Add HSV color control
5. Support addressable LEDs (WS2812, SK6812)
6. Add remote controller

---

📄 License

This project is licensed under the MIT License.
