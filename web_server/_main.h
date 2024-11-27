#include "vars.h"

class WEB_SERVER
{
public:
    void setup()
    {
        if (!LittleFS.begin())
        {
            Serial.println("Failed to mount file system");
            return;
        }
        
        config_web_server();
        web_server_css();
        web_server_routes();
        web_server_func();
        server.begin();
    }

private:
    void config_web_server()
    {
        const char *ssid = "NOME";
        const char *password = "SENHA";
        WiFi.softAP(ssid, password);
    }

    void web_server_css()
    {
        server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request)
                  { request->send(LittleFS, "/html/style.css", "text/css"); });
    }

    void web_server_routes()
    {
        server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
                  { request->send(LittleFS, "/html/home.html", "text/html"); });
    }

    void web_server_func()
    {
        server.on("/time", HTTP_GET, [](AsyncWebServerRequest *request)
                  { request->send(200, "text/plain", "CURRENT TIME: " + String(millis() / 1000)); });
    }
};