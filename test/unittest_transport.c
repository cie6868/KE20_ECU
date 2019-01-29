#include "unittest_transport.h"
#include <usart.h>

void unittest_uart_begin()
{
}

void unittest_uart_putchar(char c)
{
    HAL_UART_Transmit(&huart2, (uint8_t*)(&c), 1, 1000);
}

void unittest_uart_flush(){}

void unittest_uart_end() {
}