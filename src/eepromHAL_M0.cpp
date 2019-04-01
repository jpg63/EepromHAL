/*********************************************************************************/
/*                                                                               */
/*                           Libraries eepromHal_M0                              */
/*                                                                               */
/*  version    Date     Description                                              */
/*    1.0    05/02/19                                                            */
/*                                                                               */
/*********************************************************************************/

#include "eepromHAL.h"
#include "eepromHAL_M0.h"
#include <Arduino.h>

#if defined(ARDUINO_ARCH_SAMD)
#include "FlashAsEEPROM.h"

#if not defined(VARIO_SETTINGS_H)
//Monitor Port 
#define SerialPort SerialUSB

#define EEPROM_DEBUG

#endif //VARIO_SETTINGS_H

uint8_t EepromHal_zero::read(int address)
{
  return EEPROM.read(address);
}

void EepromHal_zero::update(int address, uint8_t value)
{
  EEPROM.update(address, value);
}

void EepromHal_zero::write(int address, uint8_t value)
{
  EEPROM.write(address, value);
}

bool EepromHal_zero::isValid()
{
  return EEPROM.isValid();
}

void EepromHal_zero::commit()
{
  EEPROM.commit();
}

EepromHal_zero EEPROMHAL;
#endif //ARDUINO_ARCH_SAMD
