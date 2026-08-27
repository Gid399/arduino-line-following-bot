# Arduino Line Following Robot

## Overview

This project is an Arduino-based autonomous line-following robot designed to detect and follow a marked path using three infrared (IR) sensors.

The robot continuously reads the values from the left, middle, and right sensors. Based on which sensor detects the line, the Arduino controls the speed of the two motors to keep the robot following the path.

This project was developed to gain practical experience in sensor integration, motor control, Arduino programming, and basic autonomous robotic systems.

## Features

* Autonomous line following
* Three IR sensors for line detection
* Analog sensor readings
* PWM-based motor speed control
* Left and right steering
* Serial Monitor feedback for debugging
* Arduino-based control system

## Components Used

* Arduino
* 3 × IR sensors
* L293D motor driver
* 4 × DC motors
* Robot chassis
* Wheels
* Battery/power supply
* Jumper wires

## System Overview

The robot uses three IR sensors positioned at the front of the robot:

* **Left sensor** — detects the line on the left side
* **Middle sensor** — detects the line directly ahead
* **Right sensor** — detects the line on the right side

The Arduino reads the sensor values and determines how the robot should move.

The basic system flow is:

**IR Sensors → Arduino → Motor Driver → DC Motors**

## How It Works

The three IR sensors continuously provide analog readings to the Arduino.

A threshold value of **500** is used to determine whether a sensor has detected the line.

If the sensor reading is greater than the threshold, the Arduino considers that sensor to be detecting the line.

The robot uses the following basic logic:

| Sensor Detection | Robot Response |
| ---------------- | -------------- |
| Middle sensor    | Move forward   |
| Right sensor     | Turn right     |
| Left sensor      | Turn left      |
| No sensor        | Stop           |

The Arduino checks the sensors continuously in the `loop()` function and changes the motor speeds according to the detected position of the line.

## Motor Control

The robot uses two DC motors controlled through a motor driver.

The motor driver receives signals from the Arduino that determine the direction and speed of each motor.

PWM is used to control the motor speeds.

The main motor speeds used in the program are:

* **Straight speed:** 150
* **Turning speed:** 80

When moving straight, both motors operate at the normal speed.

When turning, one motor is slowed down while the other continues at the normal speed. This difference in motor speeds causes the robot to change direction.

For example, during a left turn:

* Motor 1 operates at the slower turning speed.
* Motor 2 operates at the normal speed.

During a right turn:

* Motor 1 operates at the normal speed.
* Motor 2 operates at the slower turning speed.

## Sensor Configuration

The three IR sensors are connected to the Arduino's analog input pins:

| Sensor        | Arduino Pin |
| ------------- | ----------- |
| Left sensor   | A0          |
| Middle sensor | A1          |
| Right sensor  | A2          |

The sensor readings are obtained using `analogRead()`.

The threshold used to determine line detection is:

```cpp
int threshold = 500;
```

This value can be adjusted depending on the surface, line color, sensor characteristics, and lighting conditions.

## Motor Pin Configuration

The motor control pins used in the project are:

| Function             | Arduino Pin |
| -------------------- | ----------- |
| Motor 1 Enable (ENA) | 10          |
| Motor 2 Enable (ENB) | 9           |
| Motor 1 Forward      | 6           |
| Motor 1 Reverse      | 5           |
| Motor 2 Forward      | 4           |
| Motor 2 Reverse      | 3           |

The enable pins are used with PWM to control motor speed.

## Control Logic

The robot follows a simple decision-making process:

```text
Read the three IR sensors
        ↓
Is the middle sensor detecting the line?
        ↓
      YES → Move forward
        ↓
      NO
        ↓
Is the right sensor detecting the line?
        ↓
      YES → Turn right
        ↓
      NO
        ↓
Is the left sensor detecting the line?
        ↓
      YES → Turn left
        ↓
      NO
        ↓
Stop the robot
```

This process repeats continuously while the robot is operating.

## Serial Monitor

Serial communication is also included in the program to help monitor the robot's decisions during testing.

The Arduino displays messages such as:

* `FORWARD`
* `RIGHT`
* `LEFT`
* `STOP`

This makes it easier to understand how the robot is responding to the sensor readings and helps with debugging and calibration.

## Project Demonstration

A photograph of the completed line-following robot can be included in this repository.

A demonstration video can also be provided to show the robot following a line during testing.

## What I Learned

Through this project, I gained practical experience in:

* Reading analog sensor values
* Interfacing IR sensors with an Arduino
* Using threshold-based decision making
* Controlling DC motors using a motor driver
* Using PWM for motor speed control
* Implementing basic autonomous robot behavior
* Debugging using the Serial Monitor
* Integrating sensors, programming, electronics, and mechanical components into a working robotic system

## Challenges

One of the main challenges in this project was determining an appropriate sensor threshold for reliable line detection.

The robot also required testing and adjustment of the motor speeds to achieve effective turning. Different speeds were tested to allow one motor to slow down while the other maintained its normal speed during turns.

This process helped demonstrate the importance of testing and calibration when developing physical robotic systems.

## Future Improvements

Possible improvements to the robot include:

* Implementing PID control for smoother and more accurate line following
* Using more IR sensors for improved line detection
* Adding adjustable sensor calibration
* Improving the chassis and sensor positioning
* Optimizing motor speeds for faster line following
* Adding obstacle detection
* Improving the control algorithm to handle sharp turns and intersections

## Conclusion

This project provided practical experience in developing a simple autonomous robotic system. By combining IR sensors, an Arduino, a motor driver, and DC motors, the robot can detect a line and adjust its movement accordingly.

The project provided a foundation for exploring more advanced robotic control techniques, including PID control, sensor fusion, and autonomous navigation.
