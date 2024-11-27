#include "vars.h"

class ESP_WDT
{
public:
	void setup()
	{
		esp_task_wdt_init(WATCHDOG_TIMEOUT, true);
		esp_task_wdt_add(NULL);
	}

	void att()
	{
		esp_task_wdt_reset();
	}
};
