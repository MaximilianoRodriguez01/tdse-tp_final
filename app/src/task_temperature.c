/* Project includes. */
#include "main.h"


/* Demo includes. */
#include "logger.h"
#include "dwt.h"

/* Application & Tasks includes. */
#include "app.h"
#include "task_temperature.h"

/********************** macros and definitions *******************************/

#define AVG_SLOPE 4.3
#define V25 1.43

/********************** internal functions declaration ***********************/

HAL_StatusTypeDef ADC_Poll_Read(uint16_t *value);

/********************** external data declaration *****************************/

extern ADC_HandleTypeDef hadc1;

/********************** external functions declaration ***********************/

float ADC_Int_Temperature(void)
{
    uint16_t value;
    ADC_ChannelConfTypeDef sConfig = {0};

    sConfig.Channel = ADC_CHANNEL_TEMPSENSOR;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;

    if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
    	Error_Handler();
    	LOGGER_LOG("ERROR CONFIG CANAL TEMP INT");
    	return ERROR;
    }

    if (HAL_OK == ADC_Poll_Read(&value)) {
    	float delta_v = (((float)value * 3.3 / 4096.0) - V25);
        float temperature =  (delta_v / AVG_SLOPE) + 25.0;
        return temperature;
    }

    Error_Handler();
    LOGGER_LOG("ERROR CONFIG LEYENDO TEMP INT");
    return ERROR;
}

float ADC_Ext_Temperature(void)
{
    uint16_t value;
    ADC_ChannelConfTypeDef sConfig = {0};

    sConfig.Channel = ADC_CHANNEL_0;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;

    if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
    	Error_Handler();
    	LOGGER_LOG("ERROR CONFIG CANAL TEMP EXT");
    	return ERROR;
    }

    if (HAL_OK == ADC_Poll_Read(&value)) {
        float temperature = ((float)value * 3.3 / 4096.0) * 100.0;
        return temperature;
    }

    Error_Handler();
    LOGGER_LOG("ERROR CONFIG LEYENDO TEMP EXT");
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
