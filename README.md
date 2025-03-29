# README.md

# Multiple Interrupts with Arduino Nano 33 IoT

This project demonstrates handling multiple interrupt sources using the Arduino Nano 33 IoT board. The implementation uses a push button and LDR (Light Dependent Resistor) to control two LEDs through different triggering mechanisms.

## Features

- Hardware interrupt handling for push button on D2
- LDR analog interrupt handling on A0
- LED control based on button press and light threshold
- Serial monitoring for event logging

## Components Required

## Schematic

![Circuit Schematic](images/interrupts_schem.jpg)

- Arduino Nano 33 IoT
- Push Button with 10kΩ pull-down resistor
- LDR with 10kΩ voltage divider resistor
- 2x LEDs with 220Ω resistors
- Breadboard and connecting wires

The system toggles LED1 through button press interrupts and LED2 based on analog interrupts from the LDR when light levels change significantly.
