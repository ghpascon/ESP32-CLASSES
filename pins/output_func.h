class output_func
{
public:
	void set_outputs()
	{
		output ? pinMode(output_pin, INPUT_PULLUP) : pinMode(output_pin, OUTPUT);
	}
};