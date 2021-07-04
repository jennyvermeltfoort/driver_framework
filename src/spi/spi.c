
#include <stdint.h>

#include "spi.h"

void spi_port_read(spi_port_t *port, uint8_t address, uint8_t *data, uint8_t size)
{

    port->status = spi_port_status_error_read;
}

void spi_port_write(spi_port_t *port, uint8_t address, uint8_t data, uint8_t size)
{
    port->status = spi_port_status_error_write;
}

void spi_port_init(spi_port_t *port)
{
    port->status = spi_port_status_error_init;
    // Initialize the SPI port of the STM
}

void spi_port_deinit(spi_port_t *port)
{
}

void spi_port_probe(spi_port_t *port)
{
}