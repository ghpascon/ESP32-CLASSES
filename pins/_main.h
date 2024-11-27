#include "vars.h"
#include "input_func.h"
#include "output_func.h"

class PINS : public input_func, public output_func
{
public:
	void setup()
	{
		pinMode(sensor_npn_pin, INPUT_PULLUP);
		pinMode(sensor_pnp_pin, INPUT_PULLDOWN);

		pinMode(output_pin, OUTPUT);
	}
};
