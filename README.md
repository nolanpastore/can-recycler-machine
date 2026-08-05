# Arduino Can Recycler Machine

An Arduino-controlled can recycling machine created in collaboration with engineering students.

## What it does

- Detects a can using an ultrasonic sensor
- Confirms the can remains in position for two seconds
- Activates relays to crush the can to approximately 1.5 inches
- Triggers the disposal mechanism
- Uses a servo motor to reset the counter/pull mechanism after crushing

## Technologies

- Arduino / C++
- HC-SR04 ultrasonic sensor
- Servo motor
- Relay modules
- 3D-printed components designed and produced using Bambu Lab

## Hardware connections

| Component | Arduino pin |
|---|---:|
| Ultrasonic trigger pin | 12 |
| Ultrasonic echo pin | 13 |
| Relay 1 | 8 |
| Relay 2 | 7 |
| Rapid/disposal relay | 6 |
| Servo motor | 5 |

## Running the project

1. Open `can_recycler.ino` in the Arduino IDE.
2. Install the built-in `Servo` library if needed.
3. Connect the listed components to the corresponding Arduino pins.
4. Select the correct board and serial port.
5. Upload the sketch to the Arduino.

## Notes

This project controls physical machinery. Test carefully and disconnect power before adjusting wiring or the crushing mechanism.
