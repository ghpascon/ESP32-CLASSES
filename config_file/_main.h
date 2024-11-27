#include "vars.h"

class CONFIG_FILE
{
private:
	void writeFile(String to_write)
	{
		File file_config = LittleFS.open(config_file, "a");
		if (!file_config)
		{
			Serial.println("#E_SAVE_CONFIG");
			return;
		}

		file_config.print("\n" + to_write);
		file_config.close();

		Serial.println("Escrita concluída: '" + to_write + "' foi adicionado ao arquivo");
	}

	void clearFile()
	{
		File file_config = LittleFS.open(config_file, "w"); // Abre o arquivo em modo de escrita (trunca o arquivo)

		if (!file_config)
		{
			Serial.println("Falha ao abrir o arquivo para limpar");
			return;
		}

		file_config.close();

		Serial.println("Arquivo limpo com sucesso");
	}

	void save_parameter(String parameter)
	{
		//bool
		if (parameter.startsWith("var_1="))
		{
			parameter.replace("var_1=", "");
			var_1 = parameter == "on";
		}

		// int
		else if (parameter.startsWith("var_2="))
		{
			parameter.replace("var_2=", "");
			var_2 = parameter.toInt();
		}

		// String
		else if (parameter.startsWith("var_3="))
		{
			parameter.replace("var_3=", "");
			var_3 = parameter;
		}
	}

	bool check_save()
	{
		static bool first_time = true;
		static String last_string;
		const String current_string = String(var_1) + String(var_2) + String(var_3) ;

		if (last_string == current_string)
			return false;

		last_string = current_string;

		if (first_time)
		{
			first_time = false;
			return false;
		}

		return true;
	}

public:
	void save_config()
	{
		const int save_time = 10000;
		static unsigned long current_save_time = 0;

		if (millis() - current_save_time < save_time)
			return;

		if (!check_save())
			return;

		current_save_time = millis();

		clearFile();

		writeFile("var_1=" + String(var_1 ? "on" : "off"));
		writeFile("var_2=" + String(var_2));
		writeFile("var_3=" + String(var_3));
	}

	void get_config()
	{
		if (!LittleFS.begin())
		{
			Serial.println("Failed to mount file system");
			return;
		}

		File file_config = LittleFS.open(config_file, "r");

		if (!file_config)
		{
			Serial.println("Falha ao abrir o arquivo para leitura");
			return;
		}

		Serial.println("Conteúdo do arquivo:");
		while (file_config.available())
		{
			String line = file_config.readStringUntil('\n');
			line.toLowerCase();
			line.replace("\n", "");
			line.replace("\r", "");
			line.replace(" ", "");
			Serial.println(line);
			save_parameter(line);
		}

		file_config.close();
	}
};
