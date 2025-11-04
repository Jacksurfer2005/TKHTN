#include "spi_init.h"

void SPI_MasterInit(void) {
	DDR_SPI |= (1<<DD_MOSI) | (1<<DD_SCK) | (1<<DD_SS);
	SPCR = (1<<SPE) | (1<<MSTR) | (1<<SPR0); // Enable SPI, Master mode, f/16
}
