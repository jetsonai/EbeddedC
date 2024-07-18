#include "stm32f1xx_hal.h"
#include "testcode1.h"
#include "testfunc.h"
#include <stdio.h>

#define BTN_ON          100
#define BTN_OFF         101
#define BTN_LEFT        103
#define BTN_RIGHT       104


// Make up and Understand

void booleanTest(void) 
{
  printf("%d\n", 3 == 3);
  printf("%d\n", 7 != 4);
  printf("%d\n", 2 > 6);
  printf("%d\n", 6 <= 9);
  printf("%d\n", 1 && (3 != 2));
  printf("1 && (3 != 3) : %d\n", 1 && (3 != 3));
  printf("1 || (3 != 3) : %d\n\n", 1 || (3 != 3));
  printf("%d\n", !1 );
  printf("%d\n", !0 );
  printf("%d\n", !7 );
  printf("%d\n", !(2 + 7 > 9));

}

void bitOpTest(void)
{
   int a = 6;
   int b = 3;
   printf("6 -> ");
   printbin(6);
    printf("3 -> ");
   printbin(3);  
   
   printf("a & b  : %d   \n", a & b );
   printbin(a & b);
   printf("a | b  : %d   \n", a | b );
   printbin(a | b);   
    printf("a ^ b  : %d   \n", a ^ b );
   printbin(a ^ b);
   printf("a << 1  : %d   \n", a << 1 );
   printbin(a << 1);    
    printf("b >> 3  : %d   \n", b >> 3 );
   printbin(b >> 3);   
   printf("a >> 1  : %d   \n", a >> 1 );
   printbin(a >> 1);     
}

void incdecOpTest(void)
{
   int a = 3;
   int b = 2;
   printf("a : %d, b : %d  \n", a, b); 
   printf("a + b  : %d   \n", a + b );
   printf("a++ * b++  : %d   \n", a++ * b++  );
   printf("a : %d, b : %d  \n", a, b);
   printf("++a * b++  : %d   \n", ++a * b++  );
   printf("a : %d, b : %d  \n", a, b); 
}

void threeOpTest(void)
{
   int a = 6;
   int b = 3;  
   printf("(a>b)? a : b : %d \n", (a>b)? a : b);
}
  
void referenceOpTest(void)
{
    uint32_t a = 6; 
    printf("Address : %d \n", &a);
    printf("Address : %x \n", &a);    
    printf("variable value *&a : %d, a : %d\n", *&a, a);
}


//===================
void ifelseTest(void)
{

  
}

void switchTest(void)
{

  
}

void whileTest(void)
{

  
}
//=========================================

// Modification Exercise

uint8_t ReadButton2(uint32_t Btn_Pin)
{
  uint8_t ret = BTN_STATE_OFF;
    switch(Btn_Pin) {
    case BTN_ON:
      ret = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7);
      break;
    case BTN_OFF:
      ret = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9);
      break;  
    default:
      ret = BTN_STATE_OFF;
      break;
    }   
   return ret;
}

void setBtnTest_1(void)
{
  uint8_t bBtnOn = ReadButton2(BTN_ON);
  if(bBtnOn == BTN_STATE_ON) {
    setAllLed(PIN_SET_ON); 
  }
  uint8_t bBtnOff = ReadButton2(BTN_OFF); 
  if(bBtnOff == BTN_STATE_ON) {
    setAllLed(PIN_SET_OFF); 
  }
  HAL_Delay(10); 
}

#define C_OFFSET  (-9.7118)
#define C_FACTOR  0.02525

float interpreteByte2Short_1(uint16_t u16, float offset, float factor)
{

    float fval = (float)u16 * factor;
    float checkfval = fval + offset;

    return checkfval;
}

uint16_t msgdata = 390;

void callInterprete_1(void)
{
  msgdata++;
  float Result = interpreteByte2Short_1(msgdata, C_OFFSET, C_FACTOR);
        
  printf("Result:%f\n", Result);
  HAL_Delay(500); 
   
}

uint32_t setVarRangeTest_1(uint16_t aval1)
{
  uint32_t bval1;
  printf("aval1 :%d\n", aval1);
  bval1 = (uint16_t)aval1 + 32768;
  printf("bval1 :%d\n", bval1);
  return bval1;
}

uint16_t aval = 32760;

void callSetVarRangeTest_1(void)
{
  aval++;
  uint32_t Result1 = setVarRangeTest_1(aval);
  printf("Result1:%d\n============\n", Result1);
  HAL_Delay(500); 
}

int8_t bStartBlink1 = 0;


void doBlinkTest_1(void)
{
  static int8_t blinkNum1 = 0;
  if (bStartBlink1 == PIN_SET_ON)
  {
      blinkNum1 =  blinkNum1 % 8;
      blinkNum1++;
  }
  
  printf("blinkNum1 : %d\n", blinkNum1);
  
  HAL_Delay(100); 
}

void BlinkStart_1(uint8_t bStart)
{
    bStartBlink1 = bStart;
    if( bStartBlink1 == PIN_SET_ON ) 
    {
      printf("blink start !! \n");
      //blinkNum1 = 0;
    }
    else
    {
      printf("blink end !! \n");
    }
}

void setBlinkTest_1(void)
{
  uint8_t bBtnOn = ReadButton(TURN_ON_BTN);
  if(bBtnOn == BTN_STATE_ON) {
    if(bStartBlink1 == PIN_SET_OFF) {
       BlinkStart_1(PIN_SET_ON);
    }
  }
  uint8_t bBtnOff = ReadButton(TURN_OFF_BTN); 
  if(bBtnOff == BTN_STATE_ON) {
    if(bStartBlink1 == PIN_SET_ON) {
      BlinkStart_1(PIN_SET_OFF);
    }
  } 
}

//==========================================================
