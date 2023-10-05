
// Include ***************
#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "boards.h"


int main(void)
{
    nrf_gpio_cfg(
			NRF_GPIO_PIN_MAP(0,13),
			NRF_GPIO_PIN_DIR_OUTPUT,
			NRF_GPIO_PIN_INPUT_DISCONNECT,
			NRF_GPIO_PIN_NOPULL,
			NRF_GPIO_PIN_S0S1,
			NRF_GPIO_PIN_NOSENSE);
	
    while(1)
    {
		nrf_gpio_pin_toggle(NRF_GPIO_PIN_MAP(0,13));
		nrf_delay_ms(500);
    }
}

