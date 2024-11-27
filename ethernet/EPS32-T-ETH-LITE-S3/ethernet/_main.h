#include "libs.h"
#include "vars.h"
#include "eth_pins.h"
#include "eth_callback.h"

class ETHERNET_ESP
{
public:
    void setup()
    {
        WiFi.onEvent(WiFiEvent);

        if (!ETH.begin(ETH_PHY_W5500, 1, ETH_CS_PIN, ETH_INT_PIN, ETH_RST_PIN, SPI3_HOST, ETH_SCLK_PIN, ETH_MISO_PIN, ETH_MOSI_PIN))
        {
            Serial.println("ETH start Failed!");
            ESP.restart();
        }

        if (dhcp)
            return;

        if (!ETH.config(staticIP, gateway, subnet, dns, dns))
        {
            Serial.println("Configuration failed.");
            ESP.restart();
        }
    }
};
