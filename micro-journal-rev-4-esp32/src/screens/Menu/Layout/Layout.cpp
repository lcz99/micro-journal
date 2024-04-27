#include "Layout.h"
#include "../Menu.h"
#include "app/app.h"
#include "app/config/config.h"
#include "service/display/display.h"
#include "screens/WordProcessor/WordProcessor.h"

//
void Layout_setup(TFT_eSPI *ptft, U8g2_for_TFT_eSPI *pu8f)
{
    // when entering the screen
    // clear the screen
    Menu_clear();
}

//
void Layout_render(TFT_eSPI *ptft, U8g2_for_TFT_eSPI *pu8f)
{
    //
    JsonDocument &app = app_status();

    ptft->setCursor(0, 30, 2);
    ptft->setTextColor(TFT_WHITE, TFT_BLACK);
    ptft->println(" - Choose Keyboard Layout");
    ptft->println();

    ptft->println("[c] Canadian Multiligual");
    ptft->println("[i] Italian");
    ptft->println("[u] US");
}

//
void Layout_keyboard(char key)
{
    //
    JsonDocument &app = app_status();

    if (key == 'c')
    {
        // canadian multiligual
        app["config"]["keyboard_layout"] = "CA";
        config_save();
        // go back to the word processor
        app["screen"] = WORDPROCESSOR;
    }

    else if (key == 'i')
    {
        // italian
        app["config"]["keyboard_layout"] = "IT";
        config_save();
        // go back to the word processor
        app["screen"] = WORDPROCESSOR;
    }

    else if (key == 'u')
    {
        // us
        app["config"]["keyboard_layout"] = "US";
        config_save();
        // go back to the word processor
        app["screen"] = WORDPROCESSOR;
    }

    //
    // go back to home menu
    app["menu"]["state"] = MENU_HOME;
}
