#include "myTaskHeader.h"
#include"utils.h"
#include "../../UnitTestsForSep4/Sep4UnitTestGoogleTests/FreeRTOS.h"
#include "../../UnitTestsForSep4/Sep4UnitTestGoogleTests/task.h"
#include "../../UnitTestsForSep4/Sep4UnitTestGoogleTests/semphr.h"
#include <stdio.h>
#include "utils.h"

static SemaphoreHandle_t _resultReadySemaphore = NULL;

inline void myTask_init() {
	utils_initialise();
}

inline void myTask_run(void) {
	vTaskDelay(pdMS_TO_TICKS(200));
	int8_t result = utils_add(20, 56);
	utils_storeValue(result);
	xSemaphoreGive(_resultReadySemaphore);

}

void taskMyTask(void* pvParameters) {
	_resultReadySemaphore = (SemaphoreHandle_t)pvParameters;
	myTask_init();
	for (;;) {
		myTask_run();
	}
}