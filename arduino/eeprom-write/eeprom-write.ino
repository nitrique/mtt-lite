#include <Wire.h>

#define EEPROM_ADDR 0x50

// Données binaires à écrire
const byte donneesBinaires[] = {
    0x03, 0x05, 0x0E, 0x02, 0x09, 0x03, 0x05, 0x00, 0x04, 0x05, 0x0C, 0x05, 0x03, 0x0F, 0x0D, 0x00, 0x09, 0x0E, 0x03, 0x0E, 0x0C, 0x00, 0x08, 0x04, 0x03, 0x0C, 0xA3, 0x79, 0x57, 0x65, 0x03, 0x06, 0x04, 0x09, 0x09, 0x00, 0xA3, 0x01, 0x0E, 0x01, 0x01, 0x0E, 0x00, 0x00, 0xA3, 0x0B, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x70, 0x60, 0x70, 0x60, 0x70, 0x60, 0x20, 0x50, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x20, 0x40, 0x60, 0x60, 0x20, 0x20, 0x20, 0x70, 0x40, 0x50, 0x40, 0xA3, 0x01, 0x7D, 0x51, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0xA3, 0x30, 0x20, 0x30, 0x30, 0x20, 0x30, 0x30, 0xA3, 0x79, 0x49, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

void setup() {
  Wire.begin();
  Serial.begin(115200);
  
  // Écriture sans écraser les octets existants
  for (unsigned int i = 0; i < sizeof(donneesBinaires); i++) {
    // Lire d'abord le contenu existant
    byte existant = lireOctetEEPROM(i);
    
    // N'écrire que si différent
    if (existant != donneesBinaires[i]) {
      ecrireOctetEEPROM(i, donneesBinaires[i]);
      delay(5);
    }
  }
  
  Serial.println("Écriture terminée");
}

void loop() {}

void ecrireOctetEEPROM(unsigned int adresse, byte donnee) {
  Wire.beginTransmission(EEPROM_ADDR);
  Wire.write(adresse >> 8);    // Octet haut
  Wire.write(adresse & 0xFF);  // Octet bas
  Wire.write(donnee);
  Wire.endTransmission();
}

byte lireOctetEEPROM(unsigned int adresse) {
  Wire.beginTransmission(EEPROM_ADDR);
  Wire.write(adresse >> 8);    // Octet haut
  Wire.write(adresse & 0xFF);  // Octet bas
  Wire.endTransmission();
  
  Wire.requestFrom(EEPROM_ADDR, 1);
  if (Wire.available()) {
    return Wire.read();
  }
  return 0xFF;  // Valeur par défaut si lecture impossible
}