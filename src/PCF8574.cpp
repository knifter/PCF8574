#include "Arduino.h"
#include <Wire.h>

#include "PCF8574.h"

bool PCF8574::begin()
{
	TwoWireDevice::begin();

	// Testread
	read8();

	return (_wire.lastError == 0);
}

void PCF8574::setPort(const uint8_t value)
{
	write8(value);
}

uint8_t PCF8574::getPort()
{
	return read8();
}

void PCF8574::setPin(const uint8_t nr, const bool high)
{
	uint8_t val = read8();
	if(high)
		val |= (1<<nr);
	else
		val &= ~(1<<nr);

	write8(val);
}

bool PCF8574::getPin(const uint8_t nr)
{
	uint8_t val = read8();
	return val & (1<<nr);
}
