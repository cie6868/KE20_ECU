#include <unity.h>
#include "stm32f1xx_hal.h"
#include <cube.h>
#include <Logger.h>
#include <tim.h>

void setUp(void) {
}

void tearDown(void) {
}

void MafPrintTest(void) {

    Log("Starting test \n");

    // Print MAF timer readings
    while (1)
    {
        uint32_t reading = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_2);

        //uint32_t reading = __HAL_TIM_GET_COUNTER(&htim2);

        Log("Maf Period - %lu\n", reading);

        HAL_Delay(1000); 
    }

    // TODO - Implement MAF sensor reading
    //TEST_ASSERT_EQUAL(5, 5);
}

int main() {
    CubeInit();
    HAL_Delay(1000);    // service delay

    HAL_TIM_Base_Start(&htim2);
    HAL_TIM_IC_Start(&htim2, TIM_CHANNEL_2);

    UNITY_BEGIN();
    RUN_TEST(MafPrintTest);
    UNITY_END(); // stop unit testing

    while(1){}
}

void SysTick_Handler(void) {
    HAL_IncTick();
}