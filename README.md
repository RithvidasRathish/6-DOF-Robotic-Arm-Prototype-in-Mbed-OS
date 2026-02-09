# 6-DOF Robotic Arm Prototype using Mbed OS

This repository contains the firmware implementation for a **6-Degree-of-Freedom (6-DOF) Robotic Arm Prototype** developed using **Mbed OS**.  
The project demonstrates **synchronized multi-axis motion control** using stepper motors and a servo motor, enabling precise and coordinated robotic arm movement.

---

## 📖 Project Overview

Modern robotic manipulators require multiple joints to move **in coordination** to achieve accurate positioning and linear motion.  
This project focuses on controlling **multiple stepper motors simultaneously** so that all joints reach their target positions **at the same time**, which is critical for robotic arm kinematics.

The firmware leverages:
- `AccelStepper` for stepper motor control
- `MultiStepper` for synchronized multi-axis movement
- `Servo` for end-effector or auxiliary joint control

---

## ✨ Key Features

- Coordinated control of multiple stepper motors  
- Synchronous linear motion using `MultiStepper`  
- Configurable speed and pulse width for reliable stepper driving  
- Servo motor support for additional degree of freedom  
- Deterministic, blocking motion execution for testing and calibration  

---

## 🧠 Motion Control Strategy

1. Each stepper motor is initialized with a maximum speed and minimum pulse width.
2. All stepper motors are registered with the `MultiStepper` object.
3. Target positions for all motors are stored in a single array.
4. `moveTo()` ensures synchronized motion.
5. `runSpeedToPosition()` blocks execution until all motors reach their target.

This approach ensures:
- Linear 2D/3D motion
- Accurate joint synchronization
- Predictable robotic arm behavior

---

## 🧩 Hardware Requirements

- Mbed-compatible microcontroller board  
- Stepper motor drivers (STEP/DIR interface)  
- 3 × Stepper motors  
- 1 × Servo motor  
- External power supply for motors (recommended)  

---

## 🔌 Pin Configuration

| Component        | Function | Pin |
|------------------|----------|-----|
| Stepper Motor 1  | STEP     | D2  |
| Stepper Motor 1  | DIR      | D3  |
| Stepper Motor 2  | STEP     | D4  |
| Stepper Motor 2  | DIR      | D5  |
| Stepper Motor 3  | STEP     | D6  |
| Stepper Motor 3  | DIR      | D7  |
| Servo Motor      | Signal   | D8  |

---

## 📚 Software & Libraries Used

- **Mbed OS**
- **AccelStepper Library**
- **MultiStepper Library**
- **Servo Library**

Ensure all libraries are installed and compatible with your target board.

---

## ⚙️ Example Motion Code

```cpp
long positions[3];

positions[0] = 3000 / a;
positions[1] = -4600 / a;
positions[2] = 1600 / a;

steppers.moveTo(positions);
steppers.runSpeedToPosition(); // Blocks until all motors reach target
