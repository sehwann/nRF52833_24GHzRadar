// Include
#include "global.h"

#define MAX_TEST_DATA_BYTES     (15U)                /**< max number of test bytes to be used for tx and rx. */
#define UART_TX_BUF_SIZE 256                         /**< UART TX buffer size. */
#define UART_RX_BUF_SIZE 256                         /**< UART RX buffer size. */

#define SPI_INSTANCE_0  0 /**< SPI0 instance index. */
static const nrf_drv_spi_t spi0 = NRF_DRV_SPI_INSTANCE(SPI_INSTANCE_0);  /**< SPI0 instance. */
#define SPI_INSTANCE_1  1 /**< SPI1 instance index. */
static const nrf_drv_spi_t spi1 = NRF_DRV_SPI_INSTANCE(SPI_INSTANCE_1);  /**< SPI1 instance. */


void spi_event_handler(nrf_drv_spi_evt_t const * p_event,
                       void *                    p_context)
{
	
}

void SPI_INIT(void)
{
	nrf_drv_spi_config_t spi0_config = NRF_DRV_SPI_DEFAULT_CONFIG;
    spi0_config.ss_pin   = SPI0_SS_PIN;
    spi0_config.miso_pin = SPI0_MISO_PIN;
    spi0_config.mosi_pin = SPI0_MOSI_PIN;
    spi0_config.sck_pin  = SPI0_SCK_PIN;
	nrf_drv_spi_init(&spi0, &spi0_config, spi_event_handler, NULL);
	
	nrf_drv_spi_config_t spi1_config = NRF_DRV_SPI_DEFAULT_CONFIG;
    spi1_config.ss_pin   = SPI1_SS_PIN;
    spi1_config.miso_pin = SPI1_MISO_PIN;
    spi1_config.mosi_pin = SPI1_MOSI_PIN;
    spi1_config.sck_pin  = SPI1_SCK_PIN;
	nrf_drv_spi_init(&spi1, &spi1_config, spi_event_handler, NULL);
}



void GPIO_INIT(void)
{
	nrf_gpio_cfg_output(NRF_GPIO_PIN_MAP(0,13));
}

void UART_INIT(void)
{
	uint32_t err_code;

    const app_uart_comm_params_t comm_params =
      {
          RX_PIN_NUMBER,
          TX_PIN_NUMBER,
          RTS_PIN_NUMBER,
          CTS_PIN_NUMBER,
          APP_UART_FLOW_CONTROL_DISABLED,	// UART_HWFC
          false,
          NRF_UART_BAUDRATE_115200
      };

    APP_UART_FIFO_INIT(&comm_params,
                         UART_RX_BUF_SIZE,
                         UART_TX_BUF_SIZE,
                         uart_error_handle,
                         APP_IRQ_PRIORITY_LOWEST,
                         err_code);
	APP_ERROR_CHECK(err_code);
}


void uart_error_handle(app_uart_evt_t * p_event)
{
    if (p_event->evt_type == APP_UART_COMMUNICATION_ERROR)
    {
        APP_ERROR_HANDLER(p_event->data.error_communication);
    }
    else if (p_event->evt_type == APP_UART_FIFO_ERROR)
    {
        APP_ERROR_HANDLER(p_event->data.error_code);
    }
}
/** @} */
