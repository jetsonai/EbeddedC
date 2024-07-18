#include "stm32f1xx_hal.h"
#include "testfunc.h"

uint8_t bStartBlink = PIN_SET_OFF;
uint8_t blinkNum = 0;
uint8_t TestSetMode;
uint8_t TestAppMode = TESTAPP_TOGGLE_ALL;
uint8_t bLedOn = PIN_SET_OFF;

void BlinkStart(uint8_t bStart);

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{


}

void BlinkStart(uint8_t bStart)
{

}

void doBlinkTest(void)
{
 
}

static uint8_t bStartToggle = PIN_SET_OFF;

void setAllToggleLed(uint8_t bOn)
{
  bStartToggle = bOn;
}

void doToggleTest(void)
{
  if(bStartToggle == PIN_SET_ON) {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_4);
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_10);
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0); 
  }
  else if (bStartToggle == PIN_SET_OFF) {
    setAllLed(PIN_SET_OFF);
  }
  
  HAL_Delay(500);
}

void setBlinkTest(void)
{

}

void setAllLed(uint8_t bOn)
{
  SetLedOn(0, bOn);
  SetLedOn(1, bOn);
  SetLedOn(2, bOn);
  SetLedOn(3, bOn);
  SetLedOn(4, bOn);
  SetLedOn(5, bOn);
  SetLedOn(6, bOn);
  SetLedOn(7, bOn);
}


uint8_t ReadButton(uint32_t Btn_Pin)
{
  uint8_t ret = BTN_STATE_OFF;
  switch(Btn_Pin)
  {
    case TURN_ON_BTN:
      ret = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7);
      break;
    case TURN_OFF_BTN:
      ret = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9);
      break; 
  }
   return ret;
}

void SetLedOn(uint32_t LED_Pin, uint8_t bOn )
{
  switch(LED_Pin)
  {
  case 0:
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, bOn);
    break;
  case 1:
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, bOn);
    break;
  case 2:
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, bOn);
    break;
  case 3:
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, bOn);
    break;   
  case 4:
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, bOn);
    break;
  case 5:
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, bOn);
    break;
  case 6:
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, bOn);
    break;
  case 7:
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, bOn);
    break;     
  }
}

void setBtnTest_AllLedOn(void)
{
    uint8_t bBtnOn = ReadButton(TURN_ON_BTN);
    if(bBtnOn == BTN_STATE_ON)
    {  
        setAllLed(PIN_SET_ON);
    }
    uint8_t bBtnOff = ReadButton(TURN_OFF_BTN);
    if(bBtnOff == BTN_STATE_ON)
    {  
        setAllLed(PIN_SET_OFF);
    }    
}

void doBtnProc(void)
{
    uint8_t bBtnOn = ReadButton(TURN_ON_BTN);
    if(bBtnOn == BTN_STATE_ON)
    {  
      switch (TestAppMode) { 
      case TESTAPP_ONOFF_ALL:
        setAllLed(PIN_SET_ON);
        break;
      case TESTAPP_TOGGLE_ALL:
        setAllToggleLed(PIN_SET_ON);
        break;
      }
    }
    uint8_t bBtnOff = ReadButton(TURN_OFF_BTN);
    if(bBtnOff == BTN_STATE_ON)
    {  
      switch (TestAppMode) { 
      case TESTAPP_ONOFF_ALL:
        setAllLed(PIN_SET_OFF);
        break;
      case TESTAPP_TOGGLE_ALL:
        setAllToggleLed(PIN_SET_OFF);
        break;
      }   
    }    
}

uint8_t ledvar = 1;

void printbin(uint8_t input)
{

}

void setLedBin(uint8_t input)
{

}
      
void setLedShiftTest(void)
{
 
}
