class input_func
{
public:
	void check_inputs()
	{

		static unsigned long current_sensor_npn_time = 0;
		input_debounce(sensor_npn, !digitalRead(sensor_npn_pin), current_sensor_npn_time);

		static unsigned long current_sensor_pnp_time = 0;
		input_debounce(sensor_pnp, digitalRead(sensor_pnp_pin), current_sensor_pnp_time);
	}

	void input_debounce(bool &state, bool current_state, unsigned long &last_time, int debounce_time = 50)
	{
		if (current_state != state)
		{
			if (millis() - last_time > debounce_time)
			{
				state = !state;
			}
		}
		else
		{
			last_time = millis();
		}
	}
};