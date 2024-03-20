#include "service.h"
#include "display/display.h"
#include "keyboard/keyboard.h"
#include "SD/sd.h"

void service_setup_main()
{
    // SD must be initialized before display
    SD_setup_main();
    display_setup_main();
    keyboard_setup_main();
}

void service_setup_secondary()
{
    // SD must be initialized before display
    SD_setup_secondary();
    display_setup_secondary();
    keyboard_setup_secondary();
}

// place the service loops that is critical and should be performed in timely manner
void service_loop_main()
{
    display_loop_main();
    keyboard_loop_main();
    SD_loop_main();
}

// place the service loops that doesn't affect the main functionality
void service_loop_secondary()
{
    display_loop_secondary();
    keyboard_loop_secondary();
    SD_loop_secondary();
}
