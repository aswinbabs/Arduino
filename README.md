# Arduino Projects

This repository contains several Arduino-based projects. Each program demonstrates a specific functionality with different hardware modules and sensors. Below is a brief overview of each project, including what it does, how it works, and its specifications.

---

## 1. Bluetooth_HC05_module

### Overview:
This project involves using the HC-05 Bluetooth module to control an LED on the Arduino board based on Bluetooth commands. The Arduino reads commands sent via Bluetooth to toggle the state of an LED connected to pin 13.

### What it does:
- It listens for Bluetooth commands ('1' or '0') to turn the LED on or off.

### How it's done:
- The program continuously checks if data is available via Bluetooth (Serial communication).
- Upon receiving '1', it turns the LED on, and upon receiving '0', it turns the LED off.

### Specifications:
- Uses the HC-05 Bluetooth module connected via Serial communication.
- The LED is connected to digital pin 13.

---

## 2. GPS

### Overview:
This project interfaces a GPS module with the Arduino to retrieve and display the latitude and longitude coordinates.

### What it does:
- It reads NMEA sentences from the GPS module and extracts latitude and longitude values to display them in the serial monitor.

### How it's done:
- The program listens for data from the GPS module (via SoftwareSerial).
- When a valid sentence is received, it extracts and prints the latitude and longitude.

### Specifications:
- Uses the GPS module communicating over SoftwareSerial pins 2 and 3.
- The serial monitor displays the latitude and longitude values.

---

## 3. GSM

### Overview:
This project uses a simple pushbutton and an Arduino board to detect button presses. It reads the button's state and outputs it to the serial monitor.

### What it does:
- Detects the button press and sends the state (HIGH or LOW) to the serial monitor.

### How it's done:
- The button is connected to pin 21 of the Arduino board, and the program reads its state in the loop.
- The button's state (pressed or not) is printed on the serial monitor.

### Specifications:
- The button is connected to pin 21.
- Serial monitor outputs the state of the button (pressed = LOW, not pressed = HIGH).

---

## 4. Gas_sensor_FC_22

### Overview:
This project uses the FC-22 gas sensor to detect smoke or gas levels in the environment and triggers an LED and buzzer when the threshold is exceeded.

### What it does:
- The program continuously reads the analog value from the gas sensor.
- If the gas concentration exceeds a predefined threshold, an LED and buzzer are activated.

### How it's done:
- Reads the gas sensor's analog value.
- When the sensor value exceeds the threshold (400), the program turns on the LED and sounds the buzzer.

### Specifications:
- Uses pin A5 for the gas sensor input.
- The LED is connected to pin 13 and the buzzer to pin 10.

---

## 5. RFID_MFRC522 (Reader)

### Overview:
This project interfaces an RFID reader with the Arduino to read RFID tags and control an LED based on the RFID card detected.

### What it does:
- It detects RFID cards and compares the unique ID (UID) of the card to a predefined member card.
- If the UID matches, the program turns on an LED and prints a message on the serial monitor.

### How it's done:
- The RFID reader is initialized and waits for an RFID card to be placed near it.
- Upon detecting a card, it compares the card's UID with the predefined member ID and toggles the LED accordingly.

### Specifications:
- Uses the MFRC522 RFID reader.
- The LED is connected to pin 7, and the RFID reader's SS and RST pins are connected to pins 10 and 9, respectively.

---

## Hardware Requirements:
- **Bluetooth_HC05_module:** HC-05 Bluetooth module, LED.
- **GPS:** GPS module (e.g., NEO-6M).
- **GSM:** Pushbutton, Arduino board.
- **Gas_sensor_FC_22:** FC-22 gas sensor, LED, Buzzer.
- **RFID_MFRC522:** MFRC522 RFID reader, RFID tags, LED.

---

## Usage:
1. Upload the respective Arduino sketch to your Arduino board.
2. Connect the required hardware modules as specified in each project.
3. Open the serial monitor to view outputs or interact with the system.

---

## License:
This project is open-source and free to use. Feel free to modify and experiment with the code as needed.
