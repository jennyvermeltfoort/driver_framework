
#ifndef __MCP2515_H
#define __MCP2515_H

#include "../spi/spi.h"

spi_port_t *mcp2515_init(spi_port_config_t config);

void mcp2515_sleep(spi_port_t *port);

#endif /* __MCP2515_H */