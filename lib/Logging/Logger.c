#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include <usart.h>

#define PRINT_BUFFER_SIZE 100
#define HAL_PRINT_UART huart2

void HAL_printf_valist(const char *fmt, va_list argp);

void Log(const char* fmt, ...)
{
  va_list argp;

	va_start(argp, fmt);
	HAL_printf_valist(fmt, argp);
	va_end(argp);
}

/** Custom printf function in order to use HAL_UART_Transmit()
 * @param *fmt String to print
 * @param argp Parameters list
 */
void HAL_printf_valist(const char *fmt, va_list argp) {
  char string[PRINT_BUFFER_SIZE];

  if (vsprintf(string, fmt, argp) > 0) {
    HAL_UART_Transmit(&HAL_PRINT_UART, (uint8_t*)string, strlen(string), HAL_MAX_DELAY); // send message via UART
  } else {
	HAL_UART_Transmit(&HAL_PRINT_UART, (uint8_t*)"E - Print\n", 14, HAL_MAX_DELAY);
  }
}