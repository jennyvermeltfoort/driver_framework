
#ifndef __SPI_H
#define __SPI_H

#include <stdint.h>

typedef struct
{

} spi_port_config_t;

typedef enum
{
    spi_port_status_ok,
    spi_port_status_busy,
    spi_port_status_error_init,
    spi_port_status_error_read,
    spi_port_status_error_write,
    spi_port_status_error_probe,
} spi_port_status_e;

typedef struct
{
    spi_port_status_e status;
    spi_port_config_t config;
} spi_port_t;

void spi_port_read(spi_port_t *port, uint8_t address, uint8_t *data, uint8_t size);

void spi_port_write(spi_port_t *port, uint8_t address, uint8_t data, uint8_t size);

void spi_port_init(spi_port_t *port);

void spi_port_deinit(spi_port_t *port);

void spi_port_probe(spi_port_t *port);

#endif /* __SPI_H */