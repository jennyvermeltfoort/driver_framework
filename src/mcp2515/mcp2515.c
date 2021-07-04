
#include <stdlib.h>

#include "mcp2515.h"

#include "../common/common.h"
#include "../spi/spi_device.h"
#include "../spi/ports/mcp2515_port.h"

#define REG_CANCTRL 0X0FU
#define REG_CANSTAT 0X0EU

typedef enum
{
    device_operation_normal = 0X0,
    device_operation_sleep = 0X1,
    device_operation_loopback = 0X2,
    device_operation_listen_only = 0X3,
    device_operation_config = 0X4,
} device_operation_e;

spi_port_t *mcp2515_init(spi_port_config_t config)
{
    spi_device_t *device = malloc(sizeof(spi_device_t));

    mcp2515_port_init(&device->port);

    device->port.config = config;

    spi_device_init(&device->port);

    return &device->port;
}

void mcp2515_deinit(spi_port_t *port)
{
    spi_device_t *device = spi_device_get_from_port(port);

    spi_device_deinit(port);

    free(device);
}

void mcp2515_sleep(spi_port_t *port)
{
}