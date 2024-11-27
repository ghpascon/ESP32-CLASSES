#include "vars.h"

class SERIAL_COMMANDS
{
public:
    void setup()
    {
        Serial.begin(115200);
        Serial2.begin(115200, SERIAL_8N1, rx_2, tx_2);
    }

    void check_commands()
    {
        if (!Serial.available())
            return;
        String cmd = Serial.readStringUntil('\n');
        cmd.toLowerCase();
        cmd.replace(" ", "");
        cmd.replace("\r", "");
        cmd.replace("\n", "");

        cmd_handler(cmd);
    }

private:
    void cmd_handler(String cmd)
    {
        if (cmd == "led_on")
            Serial.println("led_on");
        else if (cmd == "led_off")
            Serial.println("led_off");

        else if (cmd.startsWith("#cx:"))
        {
            cmd.replace("#cx", "");
            Serial.println(cmd);
        }
    }
};
