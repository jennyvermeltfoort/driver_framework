#include <stdio.h>
#include <stdlib.h>

#include "common/common.h"
#include "mcp2515/mcp2515.h"

spi_port_t *mcp2515_port;

int main(void)
{
    spi_port_config_t config = {

    };
    mcp2515_port = mcp2515_init(config);
}