IPAddress staticIP(192, 168, 10, 2);
IPAddress gateway(192, 168, 10, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(8, 8, 8, 8);

bool eth_connected = false;

String esp_hostname = "esp32-ethernet";

bool dhcp = true;