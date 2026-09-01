# ♿ Voice Controlled Wheelchair

An Arduino-based prototype for controlling wheelchair movement using smartphone voice commands sent over Bluetooth.

## Features
- Voice-command control from a smartphone
- Wireless communication using HC-05 Bluetooth
- Arduino UNO command processing
- L298N motor driver control
- Forward, backward, left, right and stop commands

## Hardware
- Arduino UNO
- HC-05 Bluetooth module
- L298N motor driver
- 2 DC geared motors
- Wheelchair/chassis platform
- Battery pack
- Jumper wires
- Smartphone with a voice-command application

## Control Mapping

| Command | Character | Action |
|---|---|---|
| Forward | `F` | Move forward |
| Backward | `B` | Move backward |
| Left | `L` | Turn left |
| Right | `R` | Turn right |
| Stop | `S` | Stop motors |

## Arduino Connections

### L298N → Arduino UNO
| L298N | Arduino |
|---|---|
| ENA | D5 |
| IN1 | D6 |
| IN2 | D7 |
| IN3 | D8 |
| IN4 | D9 |
| ENB | D10 |
| GND | GND |

### HC-05 → Arduino UNO
| HC-05 | Arduino |
|---|---|
| VCC | 5V |
| GND | GND |
| TXD | RX (D0) |
| RXD | TX (D1) through a suitable voltage divider |

## How It Works
1. A voice-command app on the smartphone converts speech into a control character.
2. The character is transmitted to the HC-05 Bluetooth module.
3. Arduino UNO reads the serial command.
4. Arduino drives the L298N motor driver.
5. The motors move according to the received command.

## Important Safety Note
This repository contains a prototype control system. It should be tested with the drive wheels safely lifted or at very low speed before any human use. A real mobility device requires additional safety features such as emergency stop, fault detection, protected power electronics, braking, obstacle sensing and thorough supervised testing.

## Files
```text
Voice-Controlled-Wheelchair/
├── Voice_Controlled_Wheelchair.ino
├── components.txt
└── README.md
```

## Author
**M. Srihari**
