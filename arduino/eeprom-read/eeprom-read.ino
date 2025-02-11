#include <Wire.h>

// Adresse I2C de l'EEPROM 24LC32A (A0, A1, A2 à la masse)
#define EEPROM_ADDR 0x50

// Taille totale de l'EEPROM en octets (32 Kbits = 4 KBytes)
#define EEPROM_SIZE 4096

void setup() {
  Wire.begin();
  Serial.begin(115200);
  while (!Serial) {
    ; // Attente de la connexion du port série
  }
  
  Serial.println("Début de la lecture de l'EEPROM 24LC32A");
  
  // Lecture de toute l'EEPROM
  for (int address = 0; address < EEPROM_SIZE; address++) {
    if (address % 16 == 0) {
      // Nouvelle ligne tous les 16 octets
      if (address != 0) Serial.println();
      // Affiche l'adresse en hexadécimal
      if (address < 0x10) Serial.print("000");
      else if (address < 0x100) Serial.print("00");
      else if (address < 0x1000) Serial.print("0");
      Serial.print(address, HEX);
      Serial.print(": ");
    }
    
    // Lecture d'un octet
    byte data = readEEPROMByte(address);
    
    // Affichage en hexadécimal
    if (data < 0x10) Serial.print("0");
    Serial.print(data, HEX);
    Serial.print(" ");
  }
  
  Serial.println("\nLecture terminée");
}

void loop() {
  // Rien à faire dans la boucle principale
}

byte readEEPROMByte(unsigned int address) {
  byte data = 0;
  
  // Envoi de l'adresse de lecture
  Wire.beginTransmission(EEPROM_ADDR);
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xFF)); // LSB
  Wire.endTransmission();
  
  // Lecture de la donnée
  Wire.requestFrom(EEPROM_ADDR, 1);
  if (Wire.available()) {
    data = Wire.read();
  }
  
  return data;
}