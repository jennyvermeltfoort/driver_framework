#include "spi_device.h"
#include "../common/common.h"

spi_device_t *spi_device_get_from_port(spi_port_t *port)
{
    return container_of(port, spi_device_t, port);
}

void spi_device_read(spi_port_t *port, uint8_t address, uint8_t *data)
{
    spi_device_t *device = spi_device_get_from_port(port);

    device->ops->read(port, address, data);
}

void spi_device_write(spi_port_t *port, uint8_t address, uint8_t data)
{
    spi_device_t *device = spi_device_get_from_port(port);

    device->ops->write(port, address, data);
}

void spi_device_init(spi_port_t *port)
{
    spi_device_t *device = spi_device_get_from_port(port);

    spi_port_init(port);

    device->ops->init(port);
}

void spi_device_deinit(spi_port_t *port)
{
    spi_device_t *device = spi_device_get_from_port(port);

    spi_port_deinit(port);

    device->ops->deinit(port);
}

void spi_device_probe(spi_port_t *port)
{
    spi_device_t *device = spi_device_get_from_port(port);

    spi_port_probe(port);

    device->ops->probe(port);
}