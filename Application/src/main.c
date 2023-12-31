// include
#include "global.h"


#define SPI_INSTANCE_0  0 /**< SPI0 instance index. */
static const nrf_drv_spi_t spi0 = NRF_DRV_SPI_INSTANCE(SPI_INSTANCE_0);  /**< SPI0 instance. */
#define SPI_INSTANCE_1  1 /**< SPI1 instance index. */
static const nrf_drv_spi_t spi1 = NRF_DRV_SPI_INSTANCE(SPI_INSTANCE_1);  /**< SPI1 instance. */

#define TEST_STRING "1"
static uint8_t       m_tx_buf[] = TEST_STRING;           /**< SPI_TX buffer. */
static uint8_t       m_rx_buf[sizeof(TEST_STRING) + 1];    /**< SPI_RX buffer. */
static const uint8_t m_length = sizeof(m_tx_buf);        /**< SPI_Transfer length. */


// main
int main(void)
{
	GPIO_INIT();
	UART_INIT();
	SPI_INIT();
	
	// test uart
	printf("start\r\n");
	uint8_t tx_data = 0x31;
	app_uart_put(tx_data);

	
	
    while(1)
    {
		// test spi0
		nrf_drv_spi_transfer(&spi0, m_tx_buf, m_length, m_rx_buf, m_length);
		// test spi1
		nrf_drv_spi_transfer(&spi1, m_tx_buf, m_length, m_rx_buf, m_length);
		
		
		//NRF_LOG_HEXDUMP_INFO(m_rx_buf, strlen((const char *)m_rx_buf));
		
		nrf_delay_ms(500);
#if 0		
        uint8_t cr;
        while (app_uart_get(&cr) != NRF_SUCCESS);
        while (app_uart_put(cr) != NRF_SUCCESS);

        if (cr == 't' || cr == 'T')
        {
            printf("LED Toggle\r\n");
			nrf_gpio_pin_toggle(NRF_GPIO_PIN_MAP(0,13));
			nrf_delay_ms(100);
        }
#endif		
    }
}


/** @} */
