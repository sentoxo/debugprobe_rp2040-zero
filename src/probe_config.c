#include "probe_config.h"
#include "pico/binary_info.h"
#include <pico/stdlib.h>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)


void bi_decl_config()
{
#ifdef PROBE_PIN_RESET
    bi_decl(bi_1pin_with_name(PROBE_PIN_RESET, "PROBE RESET"));
#endif

#ifdef PROBE_PIN_SWCLK
    bi_decl(bi_1pin_with_name(PROBE_PIN_SWCLK, "PROBE SWCLK"));
#endif

#ifdef PROBE_PIN_SWDIO
    bi_decl(bi_1pin_with_name(PROBE_PIN_SWDIO, "PROBE SWDIO"));
#endif

#ifdef PROBE_PIN_SWDI
    bi_decl(bi_1pin_with_name(PROBE_PIN_SWDI, "PROBE SWDI"));
#endif

#ifdef PROBE_PIN_SWDIOEN
    bi_decl(bi_1pin_with_name(PROBE_PIN_SWDIOEN, "PROBE SWDIOEN"));
#endif

#ifdef PROBE_CDC_UART
    bi_decl(bi_program_feature("PROBE UART INTERFACE " STR(PROBE_UART_INTERFACE)));
    bi_decl(bi_program_feature("PROBE UART BAUDRATE " STR(PROBE_UART_BAUDRATE)));
    bi_decl(bi_1pin_with_name(PROBE_UART_TX, "PROBE UART TX"));
    bi_decl(bi_1pin_with_name(PROBE_UART_RX, "PROBE UART RX"));
#endif

#ifdef PROBE_UART_CTS
    bi_decl(bi_1pin_with_name(PROBE_UART_CTS, "PROBE UART CTS"));
#endif
#ifdef PROBE_UART_RTS
    bi_decl(bi_1pin_with_name(PROBE_UART_RTS, "PROBE UART RTS"));
#endif
#ifdef PROBE_UART_DTR
    bi_decl(bi_1pin_with_name(PROBE_UART_DTR, "PROBE UART DTR"));
#endif
#ifdef PROBE_PIN_GND
    bi_decl(bi_1pin_with_name(PROBE_PIN_GND, "PROBE GND"));
    bi_decl(bi_1pin_with_name(PROBE_PIN_GND2, "PROBE GND2"));
    bi_decl(bi_1pin_with_name(PROBE_PIN_VCC, "PROBE VCC"));
    gpio_init(PROBE_PIN_GND);
    gpio_init(PROBE_PIN_GND2);
    gpio_init(PROBE_PIN_VCC);
    gpio_set_dir(PROBE_PIN_GND, GPIO_OUT);
    gpio_set_dir(PROBE_PIN_GND2, GPIO_OUT);
    gpio_set_dir(PROBE_PIN_VCC, GPIO_OUT);
    gpio_put(PROBE_PIN_GND, 0);
    gpio_put(PROBE_PIN_GND2, 0);
    gpio_put(PROBE_PIN_VCC, 1);
#endif
}
