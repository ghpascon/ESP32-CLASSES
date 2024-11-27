#include <WiFi.h>
#include <AsyncHTTPRequest_Generic.h>
AsyncHTTPRequest *request = new AsyncHTTPRequest();

String rede = "NOME";
String senha = "SENHA";
String url = "http:192.168.0.100/exemplo";

bool online = false;

bool posted = false;
