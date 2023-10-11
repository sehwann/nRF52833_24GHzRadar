#ifndef _GLOBAL_H_
#define _GLOBAL_H_
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "nrf_gpio.h"

#include "nordic_common.h"
#include "nrf_delay.h"


#include "app_uart.h"
#include "bsp.h"
#include "nrf_uart.h"

#include "nrf_drv_spi.h"


void uart_error_handle(app_uart_evt_t * p_event);
void GPIO_INIT(void);
void UART_INIT(void);



#endif


/** @} */
