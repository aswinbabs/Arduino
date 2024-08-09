#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_PIN 7 // Define the pin for the LED

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key; 

// Init array that will store new NUID 
byte nuidPICC[4];
byte member[4]= {0xA3,0x67,0x87,0x1A};
void setup() { 
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 

  pinMode(LED_PIN, OUTPUT); // Set the LED pin as output
  digitalWrite(LED_PIN, LOW); // Make sure LED is off at start

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }

 
  
}
 
void loop() {

  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been read
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  if (rfid.uid.uidByte[0] != nuidPICC[0] || 
    rfid.uid.uidByte[1] != nuidPICC[1] || 
    rfid.uid.uidByte[2] != nuidPICC[2] || 
    rfid.uid.uidByte[3] != nuidPICC[3] ) {
    Serial.println(F("A new card has been detected."));

    // Store NUID into nuidPICC array
    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }
   
    
    // Check if the detected card is the specific one
    if (rfid.uid.uidByte[0] == member[0] || 
    rfid.uid.uidByte[1] == member[1] || 
    rfid.uid.uidByte[2] == member[2] || 
    rfid.uid.uidByte[3] == member[3] ) {
      digitalWrite(LED_PIN, HIGH); // Turn on the LED
      Serial.println("Aswin Checkin");
    } 
    else {
      digitalWrite(LED_PIN, LOW); // Turn off the LED
    }
  }
  else Serial.println(F("Card read previously."));

  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
}




  