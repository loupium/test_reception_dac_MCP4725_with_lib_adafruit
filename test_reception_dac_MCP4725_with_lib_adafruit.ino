/**************************************************************************/
/*! 
    @author   Loupium
    @license  BSD (see license.txt)

    Teste de reception du module MCP4725.   

    This is an example sketch for the Adafruit MCP4725 breakout board
    ----> http://www.adafruit.com/products/935
*/
/**************************************************************************/

#include <Wire.h>
#include "Adafruit_MCP4725.h"

Adafruit_MCP4725 dac;

// Connection I2C :
  // Arduino nano   =>  MCP4725
  // A5             =>  SCL
  // A4             =>  SDA
  // 5V ou 3V3      =>  Vcc
  // GND            =>  GND

// Broche ADDR ;
  // resistance de 10k de tirage a la masse.

// Pour ADDR_I2C, lire le marquage du CI :
  // MCP4725A0T-E/CH A0 (00) <= Marquage AJNN
  // MCP4725A1T-E/CH A1 (01) <= Marquage APNN
  // MCP4725A2T-E/CH A2 (10) <= Marquage AQNN
  // MCP4725A3T-E/CH A3 (11) <= Marquage ARNN
  // Codage du type de l'adresse I2C : 1100 + Code Marquage + Niveau logique de la broche ADDR du CI
  // Le Niveau logique de la broche ADDR du CI vaut 1 pour VCC et 0 pour GND (ou N.C. = non connecte)
  // Exemple 1 Marquage AP21 sur le boitier avec la broche ADDR a GND 
  // donc 1100 + (01) + 0
  // et donne 1100010 soit 0x62 pour l'aadresse I2C
  // Exemple 2 Marquage AJ21 et ADDR à GND donne 1100000 soit 0x60 pour l'adresse I2C
#define ADDR_I2C 0x60

void setup(void) {
  Serial.begin(9600);
  Serial.println("Hello!");
  
  dac.begin(ADDR_I2C);
}

void loop(void) {
  while (1) {
    dac.setVoltage(1000, false);
    Serial.println("Valeur ADC : " + 1000);
    delay(3000);
    dac.setVoltage(2000, false);
    Serial.println("Valeur ADC : " + 2000);
    delay(3000);
    dac.setVoltage(3000, false);
    Serial.println("Valeur ADC : " + 3000);
    delay(3000);
    dac.setVoltage(4095, false);
    Serial.println("Valeur ADC : " + 4095);
    delay(3000);
    dac.setVoltage(0, false);
    Serial.println("Valeur ADC : " + 0);
    delay(3000);
  }
}
