# ♿ Smart Voice-Controlled Wheelchair

An upgraded Arduino-based smart wheelchair prototype controlled through Bluetooth voice commands, with obstacle detection and safety-focused control features.

> ⚠️ **Prototype / educational project:** This project is intended for learning and prototype development. It must not be used to control a real wheelchair carrying a person without professional-grade motor controllers, redundant safety systems, testing, and qualified engineering review.

## ✨ Features

- 🎙️ Bluetooth voice command control using HC-05
- ↔️ Forward, backward, left, right and stop movement
- 🚧 Ultrasonic obstacle detection
- 🛑 Physical emergency-stop button
- ⚡ Three speed levels
- 🔊 Buzzer feedback and safety alerts
- ⏱️ Command timeout that stops motors after inactivity

## 🧰 Components

| Component | Quantity |
|---|---:|
| Arduino UNO | 1 |
| HC-05 Bluetooth Module | 1 |
| L298N Motor Driver | 1 |
| DC Motors | 2 |
| HC-SR04 Ultrasonic Sensor | 1 |
| Push Button | 1 |
| Buzzer | 1 |
| Battery / suitable regulated power system | 1 |

## 🎮 Commands

| Command | Action |
|---|---|
| F | Forward |
| B | Backward |
| L | Left |
| R | Right |
| S | Stop |
| 1 | Slow |
| 2 | Medium |
| 3 | Fast |

## 🔌 Pin Connections

### L298N → Arduino UNO

| L298N | Arduino |
|---|---|
| ENA | D5 |
| IN1 | D6 |
| IN2 | D7 |
| IN3 | D8 |
| IN4 | D9 |
| ENB | D10 |

### HC-SR04 → Arduino

| Sensor | Arduino |
|---|---|
| TRIG | D11 |
| ECHO | D12 |
| VCC | 5V |
| GND | GND |

### Additional

- Emergency Stop Button → D4 and GND
- Buzzer → D13 and GND
- HC-05 TX → Arduino RX
- Arduino TX → HC-05 RX through appropriate level shifting

## 🧠 Safety Logic

When moving forward, the controller checks the ultrasonic sensor. If an obstacle is detected within the configured safe distance, the motors stop and the buzzer alerts the user.

A command timeout also stops the motors after 3 seconds without a new command.

## 🚀 Getting Started

1. Connect the components according to the pin table.
2. Upload `Smart_Voice_Controlled_Wheelchair.ino` using Arduino IDE.
3. Pair the HC-05 module with a compatible Bluetooth controller.
4. Configure the controller to send the listed commands.
5. Test using a small unloaded prototype first.

## 📁 Project Structure

```
Voice-Controlled-Wheelchair/
├── Smart_Voice_Controlled_Wheelchair.ino
├── Voice_Controlled_Wheelchair.ino
├── components.txt
└── README.md
```

## 👨‍💻 Author

**M. Srihari**
