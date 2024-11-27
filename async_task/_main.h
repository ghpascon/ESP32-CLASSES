#include "vars.h"

class ESP_ASYNC_TASK
{
public:
	void start_task_1()
	{
		xTaskCreatePinnedToCore(
			async_task_1,			   // Função da tarefa
			"Task_without_parameters", // Nome da tarefa
			4096,					   // Tamanho da pilha
			NULL,					   // Parâmetros para a tarefa
			1,						   // Prioridade da tarefa
			NULL,					   // Handle da tarefa
			1						   // Núcleo (Core 1)
		);
	}

	void start_task_2(bool state, int step)
	{
		task_2_params *params = new task_2_params{state, step};

		// Cria a tarefa e passa os parâmetros
		xTaskCreatePinnedToCore(
			async_task_2,
			"Task_with_parameters",
			4096,
			params, // Passando a estrutura com os parâmetros
			1,
			NULL,
			1);
		}

private:
	static void async_task_1(void *pvParameters)
	{
		// Funções da Tarefa 1
		Serial.println("Executing Task 1");

		vTaskDelete(NULL); // Finaliza a tarefa
	}

	static void async_task_2(void *pvParameters)
	{
		// Recebe a estrutura com os parâmetros
		task_2_params *params = (task_2_params *)pvParameters;

		// Acessa os valores de state e step
		Serial.println("State: " + String(params->state) + ", Step: " + String(params->step));

		// Após a execução, libera a memória da estrutura
		delete params;

		vTaskDelete(NULL); // Finaliza a tarefa
	}
};