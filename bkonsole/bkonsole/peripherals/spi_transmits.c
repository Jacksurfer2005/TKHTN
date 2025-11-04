#include "spi_transmits.h"

void SPI_MasterTransmit(uint8_t cData) {
	SPDR = cData;
	while(!(SPSR & (1<<SPIF)));
}

