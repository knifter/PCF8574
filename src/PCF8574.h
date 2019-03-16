#ifndef __PCF8574_H
#define __PCF8574_H

#include <Arduino.h>
#include <TwoWireDevice.h>

#define PCF8574_ADDRESS_DEFAULT              (0x40)

class PCF8574: public TwoWireDevice {
    public:
        PCF8574(TwoWire& wire, const uint8_t addr = PCF8574_ADDRESS_DEFAULT) : TwoWireDevice(wire, addr) {};
        PCF8574(const uint8_t addr = PCF8574_ADDRESS_DEFAULT) : TwoWireDevice(addr) {};

        bool 	begin();
		void 	setPort(const uint8_t value);
		uint8_t getPort();
		void 	setPin(const uint8_t nr, const bool high);
		bool 	getPin(const uint8_t nr);

    protected:

    private:
        PCF8574(const PCF8574&);
        PCF8574& operator=(const PCF8574&);
};

#endif // __PCF8574_H
