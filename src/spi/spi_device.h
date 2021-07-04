
#ifndef __SPI_DEVICE_H
#define __SPI_DEVICE_H

#include <stdint.h>

#include "spi.h"

typedef void (*spi_device_read_t)(spi_port_t *port, uint8_t address, uint8_t *data);
typedef void (*spi_device_write_t)(spi_port_t *port, uint8_t address, uint8_t data);
typedef void (*spi_device_init_t)(spi_port_t *port);
typedef void (*spi_device_deinit_t)(spi_port_t *port);
typedef void (*spi_device_probe_t)(spi_port_t *port);

typedef struct
{
    spi_device_read_t read;
    spi_device_write_t write;
    spi_device_init_t init;
    spi_device_deinit_t deinit;
    spi_device_probe_t probe;
} spi_device_operations_t;

typedef struct
{
    spi_port_t port;
    spi_device_operations_t *ops;

} spi_device_t;

spi_device_t *spi_device_get_from_port(spi_port_t *port);

void spi_device_read(spi_port_t *port, uint8_t address, uint8_t *data);

void spi_device_write(spi_port_t *port, uint8_t address, uint8_t data);

void spi_device_init(spi_port_t *port);

void spi_device_deinit(spi_port_t *port);

void spi_device_probe(spi_port_t *port);

#endif /* __SPI_DEVICE_H */