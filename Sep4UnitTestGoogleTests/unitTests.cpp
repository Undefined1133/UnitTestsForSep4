#include "gtest/gtest.h"
#include "fff.h"
DEFINE_FFF_GLOBALS

extern "C" {
#include <myTaskHeader.h>
#include <utils.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"


}

FAKE_VOID_FUNC(utils_initialise);
FAKE_VALUE_FUNC(int8_t, utils_add, int8_t, int8_t);
FAKE_VOID_FUNC(utils_storeValue, int8_t);

FAKE_VOID_FUNC(vTaskDelay, TickType_t);
FAKE_VALUE_FUNC(BaseType_t, xSemaphoreGive, SemaphoreHandle_t);

class UnitTests : public ::testing::Test {
protected:
	void SetUp() override {

		RESET_FAKE(utils_initialise);
		RESET_FAKE(utils_add);
		RESET_FAKE(utils_storeValue);
		RESET_FAKE(vTaskDelay);
		RESET_FAKE(xSemaphoreGive);
		FFF_RESET_HISTORY();
	}
	void TearDown() override{}
};
TEST_F(UnitTests, utils_initialise_calledDuringInitialisation) {

	myTask_init();

  EXPECT_EQ(1, utils_initialise_fake.call_count);

}
TEST_F