
#include "../../common/common.h"
#include "../spi_device.h"
#include "mcp2515_port.h"

#define MCP2515_DATA_SIZE 8

static void mcp2515_init(spi_port_t *port)
{
    hw_error("test");
}

static void mcp2515_deinit(spi_port_t *port)
{
    hw_error("test");
}

static void mcp2515_probe(spi_port_t *port)
{
    hw_error("test");
}

static void mcp2515_read(spi_port_t *port, uint8_t address, uint8_t *data)
{
    spi_port_read(port, address, data, MCP2515_DATA_SIZE);
}

static void mcp2515_write(spi_port_t *port, uint8_t address, uint8_t data)
{
    spi_port_write(port, address, data, MCP2515_DATA_SIZE);
}

static spi_device_operations_t spi_device_operations = {
    .deinit = mcp2515_deinit,
    .init = mcp2515_init,
    .read = mcp2515_read,
    .write = mcp2515_write,
    .probe = mcp2515_probe,
};

void mcp2515_port_init(spi_port_t *port)
{
    spi_device_t *device = spi_device_get_from_port(port);

    device->ops = &spi_device_operations;
}