# NodeMCU-based Automatic Lamp Using ThingSpeak

An IoT-enabled automatic lamp system using an infrared (IR) sensor and NodeMCU ESP8266 to detect presence and switch on a lamp accordingly. The system uploads sensor data to the ThingSpeak cloud for real-time monitoring and analytics.

## Project Overview

This project implements a smart lamp control system using the NodeMCU microcontroller and an IR sensor. The sensor detects infrared radiation emitted by objects or people. Upon detection, the NodeMCU toggles an LED (representing the lamp) and sends sensor data to ThingSpeak IoT platform, enabling remote data monitoring. It is energy-efficient, affordable, and suitable for smart home automation.

## Features

- Automatic lamp activation based on IR sensor detection.
- Real-time status monitoring on ThingSpeak platform.
- Low power consumption with Wi-Fi enabled NodeMCU.
- Easy integration with IoT cloud for data visualization.
- Simple hardware setup with minimal components.

## Hardware Components

- NodeMCU ESP8266 Wi-Fi microcontroller.
- Infrared (IR) sensor module (IR emitter and receiver).
- LED or relay module for lamp control.
- Resistors, jumper wires, and breadboard for prototyping.

## Software Components

- Arduino IDE for NodeMCU programming.
- ESP8266WiFi and ThingSpeak libraries.
- ThingSpeak cloud platform for data logging and visualization.

## Circuit Connections

- IR sensor VCC → NodeMCU VIN.
- IR sensor GND → NodeMCU GND.
- IR sensor OUT → NodeMCU digital pin D1 (GPIO5).
- LED positive leg → NodeMCU digital pin D5 (GPIO14) via 220Ω resistor.
- LED negative leg → NodeMCU GND.

## Setup Instructions

1. Assemble the circuit following the above connections.
2. Configure your Wi-Fi SSID and password in the code.
3. Enter your ThingSpeak channel API Write key.
4. Upload the code to NodeMCU using Arduino IDE.
5. Monitor LED activity locally and sensor data remotely on ThingSpeak.

## Operation

- The IR sensor continuously detects infrared radiation indicating presence.
- When presence is detected, the LED turns ON.
- If no presence is detected, the LED remains OFF.
- Sensor data is periodically uploaded to ThingSpeak for remote monitoring.

## Benefits

- Automates lighting control, reducing energy consumption.
- Enables remote IoT monitoring and control.
- Low-cost implementation for smart home applications.



