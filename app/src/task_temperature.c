/* Project includes. */
#include "main.h"


/* App includes. */
#include "logger.h"

/* Application includes. */


/********************** macros and definitions *******************************/

#define SAMPLES_COUNTER (100)
#define AVERAGER_SIZE (16)

/********************** external data declaration *****************************/

extern ADC_HandleTypeDef hadc1;

/********************** external functions definition ************************/



/********************** internal data declaration ****************************/
uint32_t tickstart;
uint16_t sample_idx;

/********************** internal data definition *****************************/

/********************** internal functions definitions ***********************/
bool test1_tick();
bool test2_tick();
bool test3_tick();
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef ADC_Poll_Read(uint16_t *value);

/********************** internal functions declaration ***********************/



void app_init(void)
{
	sample_idx = 0;
	LOGGER_LOG ("Test #%u starts\n", TEST_NUMBER);
	tickstart = HAL_GetTick();
}

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

float ADC_Temperature(uint16_t value)
{
    float voltage = (value * 3.3) / 4096.0;
    float temperature = voltage * 100;
    return temperature;
}


/*
float ADC_Temperature(uint16_t value)
{
	float temperature = 2 + value * 100;

	return temperature;
}*/













/********************** end of file ******************************************/
