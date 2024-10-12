#include "WakeUp.h"
#include "../../display_EPD.h"

//
#include "app/app.h"
#include "display/display.h"
#include "keyboard/keyboard.h"

bool wakeup = true;
bool stop = false;

//
void WakeUp_setup()
{
    app_log("Wakup Screen Setup\n");
    
    //
    wakeup = true;

    //
    stop = false;
}

//
void WakeUp_render()
{
    // Turn on the display
    epd_poweron();

    // Clear Screen
    epd_clear();

    // RENDER TEXT
    int32_t x = 18;
    int32_t y = 50;
    write_string((GFXfont *)&FiraSans, "Starting Up", &x, &y, NULL);

    // Turn off the display
    epd_poweroff();

    //
    delay(3000);
    wakeup = true;

    // just play once at the start up
    if (wakeup)
    {
        // move to word processor
        JsonDocument &app = app_status();
        app["screen"] = WORDPROCESSOR;
    }
}

//
void WakeUp_keyboard(char key)
{
    app_log("wakeup stop keyboard\n");

    //
    wakeup = true;
    stop = true;
}
