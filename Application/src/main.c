// include
#include "global.h"




// main
int main(void)
{
	GPIO_INIT();
	UART_INIT();
	
	printf("\r\nUART example started.\r\n");
	  
	uint8_t tx_data = 0x31;
	app_uart_put(tx_data);

    while(1)
    {
        uint8_t cr;
        while (app_uart_get(&cr) != NRF_SUCCESS);
        while (app_uart_put(cr) != NRF_SUCCESS);

        if (cr == 'q' || cr == 'Q')
        {
            printf(" \r\nExit!\r\n");
			nrf_gpio_pin_toggle(NRF_GPIO_PIN_MAP(0,13));
			nrf_delay_ms(100);
        }
    }
}


/** @} */
