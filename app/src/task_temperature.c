/* Project includes. */
#include "main.h"


/* Demo includes. */
#include "logger.h"
#include "dwt.h"

/* Application & Tasks includes. */
#include "app.h"
#include "task_temperature.h"

/********************** macros and definitions *******************************/

/********************** internal functions declaration ***********************/

HAL_StatusTypeDef ADC_Poll_Read(uint16_t *value);

/********************** external data declaration *****************************/

extern ADC_HandleTypeDef hadc1;

/********************** external functions declaration ***********************/

float ADC_Temperature()
{
	uint16_t value;

	if (HAL_OK == ADC_Poll_Read(&value)) {
		float temperature = ((float)value * 3.3 * 100.0) / 4096.0;
    	return temperature;
	}

	LOGGER_LOG("ERROR TEMPERATURE");
	return ERROR;
}

/*
float ADC_Temperature(uint16_t value)
{
	float temperature = 2 + value * 100;

	return temperature;
}*/

/********************** internal functions definition ************************/

//	Requests start of conversion, waits until conversion done
HAL_StatusTypeDef ADC_Poll_Read(uint16_t *value)
{
	HAL_StatusTypeDef res;

	res = HAL_ADC_Start(&hadc1);
	if (HAL_OK == res) {
		res = HAL_ADC_PollForConversion(&hadc1, 0);
		if (HAL_OK == res) {
			*value = HAL_ADC_GetValue(&hadc1);
		}
	}
	return res;
}

/********************** end of file ******************************************/
