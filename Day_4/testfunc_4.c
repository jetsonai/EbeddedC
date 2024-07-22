#include "stm32f1xx_hal.h"
#include "testfunc.h"

uint8_t bLedOn = PIN_SET_OFF;
uint8_t bStartBlink = PIN_SET_OFF;
uint8_t bStartShift = PIN_SET_OFF;
uint8_t bStartShiftRound = PIN_SET_OFF;
uint8_t blinkNum = 0;
uint8_t directLeft = 1;
uint8_t bBlock = 0;

uint8_t TestAppMode = TESTAPP_NONE;
uint8_t TestSetMode = APP_TEST_TURNBYBUTTON;

void BlinkStart(uint8_t bStart);

void doTurnOnProc(void);
void doTurnOffProc(void);

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (TestSetMode == APP_TEST_1TIME1MODE) {
    if(GPIO_Pin == GPIO_PIN_7) {
      doTurnOnProc();
    } 
    else if (GPIO_Pin == GPIO_PIN_9) {
      doTurnOffProc();
    }
  }
  else if (TestSetMode == APP_TEST_TURNBYBUTTON) {
    if(GPIO_Pin == GPIO_PIN_7) {
        TestAppMode = TESTAPP_ONOFF_ALL;
        bLedOn = (bLedOn==PIN_SET_OFF)? PIN_SET_ON : PIN_SET_OFF;
        setAllLed(bLedOn); 
    } 
    else if (GPIO_Pin == GPIO_PIN_9) {
      if (bBlock == 0 ) {
        bBlock = 1;
        TestAppMode = (TestAppMode < TESTAPP_SHIFT_ROUND)? TestAppMode+1 : TESTAPP_ONOFF_ALL;
        doTurnOnProc();
      }   
    }
  }
}

void BlinkStart(uint8_t bStart)
{
  bStartBlink = bStart;
  if(bStartBlink == PIN_SET_ON) {
    blinkNum = 0;
  }
  else {
    setAllLed(PIN_SET_OFF);
  }
}

void doBlinkTest(void)
{
   if(bStartBlink == PIN_SET_ON)
   {
     setAllLed(PIN_SET_OFF);
     SetLedOn(blinkNum, PIN_SET_ON);
     blinkNum = (blinkNum < 8)? blinkNum+1: 0;
     
   }
   HAL_Delay(100);
}

static uint8_t bStartToggle = PIN_SET_OFF;

void setAllToggleLed(uint8_t bOn)
{
  setAllLed(PIN_SET_OFF);
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
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, (GPIO_PinState)bOn);
    break;
  case 1:
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, (GPIO_PinState)bOn);
    break;
  case 2:
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, (GPIO_PinState)bOn);
    break;
  case 3:
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (GPIO_PinState)bOn);
    break;   
  case 4:
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, (GPIO_PinState)bOn);
    break;
  case 5:
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, (GPIO_PinState)bOn);
    break;
  case 6:
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, (GPIO_PinState)bOn);
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
      doTurnOnProc();
    }
    uint8_t bBtnOff = ReadButton(TURN_OFF_BTN);
    if(bBtnOff == BTN_STATE_ON)
    {  
      doTurnOffProc();  
    }   

}

void doTurnOnProc(void)
{
    switch (TestAppMode) { 
    case TESTAPP_ONOFF_ALL:
      setAllLed(PIN_SET_ON);
      break;
    case TESTAPP_TOGGLE_ALL:
      setAllToggleLed(PIN_SET_ON);
      break;
    case TESTAPP_STEP_BY_STEP:
      BlinkStart(PIN_SET_ON);
      break;  
    case TESTAPP_SHIFT:
        setLedShiftTest(PIN_SET_ON);
        break;         
    case TESTAPP_SHIFT_ROUND:
        setLedShiftRoundTest(PIN_SET_ON);
        break;         
    default:
        setAllLed(PIN_SET_OFF);
        break;          
    }   
}

void doTurnOffProc(void)
{
    switch (TestAppMode) { 
    case TESTAPP_ONOFF_ALL:
      setAllLed(PIN_SET_OFF);
      break;
    case TESTAPP_TOGGLE_ALL:
      setAllToggleLed(PIN_SET_OFF);
      break;
    case TESTAPP_STEP_BY_STEP:
      BlinkStart(PIN_SET_OFF);
      break;  
    case TESTAPP_SHIFT:
        setLedShiftTest(PIN_SET_OFF);
        break;         
    case TESTAPP_SHIFT_ROUND:
        setLedShiftRoundTest(PIN_SET_OFF);
        break;         
    default:
        setAllLed(PIN_SET_OFF);
        break;          
    }   
}

void doTestProc(void)
{ 
    switch (TestAppMode) { 
    case TESTAPP_ONOFF_ALL:
        setAllLed(bLedOn);
        break;
    case TESTAPP_STEP_BY_STEP:
      doBlinkTest();
      break; 
    case TESTAPP_TOGGLE_ALL:
      doToggleTest();
      break;
     
    case TESTAPP_SHIFT:
        doLedShiftTest();
        break;   
    case TESTAPP_SHIFT_ROUND:
        doLedShiftRoundTest();
        break;           
    default:
        setAllLed(PIN_SET_OFF);
        break;
    }
    
    bBlock=0;

}

uint8_t ledvar = 1;

void printbin(uint8_t input)
{
  int mask;
  for(int i =  7; i >=0 ; i--)
  {
    mask = 1<<i;
    printf("%d", input & mask? 1 : 0);
  }
  printf("\n");
}

void setLedBin(uint8_t input)
{
  int mask;
  setAllLed(PIN_SET_OFF);
  for (int i = 7; i >= 0; i--)
  {
      mask = 1 << i;
      if(input & mask)
        SetLedOn(i, PIN_SET_ON);
  }
  printf("\n");
}
      
void setLedShiftTest(uint8_t bOn)
{ 
  bStartShift = bOn;
  ledvar = 1;
  if(bStartShift == PIN_SET_OFF)
  {
      setAllLed(PIN_SET_OFF);
  }

}

void doLedShiftTest(void)
{
  if(bStartShift == PIN_SET_ON)
  {
      //printf("LED 상태: %d\n", ledvar);
      //printbin(ledvar);
      setLedBin(ledvar);
      
      if (ledvar < 128) {
          ledvar <<= 1;
      }  
      else {
           ledvar = 1; 
      }
      
      //printf("----------------\n");

      HAL_Delay(100);   
  }
}

void setLedShiftRoundTest(uint8_t bOn)
{ 
  bStartShiftRound = bOn;
  ledvar = 1;
  directLeft = 1;
  
  if(bStartShiftRound == PIN_SET_OFF)
  {
      setAllLed(PIN_SET_OFF);
  }

}

void doLedShiftRoundTest(void)
{
    if( bStartShiftRound == PIN_SET_ON ) 
    {  
      //printf("Round LED 상태: %d\n", ledvar);
      //printbin(ledvar);
      setLedBin(ledvar);
      
      if(directLeft == 1) {
        if (ledvar < 128) {
            ledvar <<= 1;
        }  
        else {
             directLeft = 0;
        }
      }
      else if(directLeft == 0) {
         if (ledvar > 1) {
            ledvar >>= 1;
        }  
        else {
             directLeft = 1;
             ledvar = 1;
        }       
      }
      //printf("----------------\n");

      HAL_Delay(100);   
    }
}
  
