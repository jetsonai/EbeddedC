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

void ShiftOpTest(void)
{
    int8_t sresrval1;
    int8_t sresrval2;
    int8_t sreslval1;
    int8_t sreslval2;
    int8_t stestnum = 0x31;
    uint8_t uresrval1;
    uint8_t uresrval2;
    uint8_t ureslval1;
    uint8_t ureslval2;
    uint8_t utestnum = 0x31U;
	
    sresrval1 = stestnum / 2;
    sresrval2 = stestnum >> 1;
    sreslval1 = stestnum * 2;
    sreslval2 = stestnum << 1;
    uresrval1 = utestnum / 2;
    uresrval2 = utestnum >> 1;
    ureslval1 = utestnum * 2;
    ureslval2 = utestnum << 1;  
  
   printf("stestnum / 2  : %d   \n", sresrval1 );
   printbin(sresrval1);    
   printf("stestnum >> 1  : %d   \n", sresrval2 );
   printbin(sresrval2);     
   printf("stestnum * 2  : %d   \n", sreslval1 );
   printbin(sreslval1);    
   printf("stestnum >> 1  : %d   \n", sreslval2 );
   printbin(sreslval1);  
   printf("---\n");
}

//---------------------------
void printMonth(int year, int month);
void printMonthTitle(int year, int month);
void printMonthName(int month);
void printMonthBody(int year, int month);
int getStartDay(int year, int month);
int getTotalNumberOfDays(int year, int month);
int getNumberOfDaysInMonth(int year, int month);
int isLeapYear(int year);

//year와 month를 전달 받아 해당 월을 출력 -> title, body
void printMonth(int year, int month) {
	printMonthTitle(year, month);
	printMonthBody(year, month);
}

//월과 년도를 출력
void printMonthTitle(int year, int month) {
	printMonthName(month);
	printf(" %d\n", year);
	printf("-----------------------------\n");
	printf(" Sun Mon Tue Wed Thu Fri Sat\n");
}

//month를 전달 받아 해당 달의 영어 이름을 출력
void printMonthName(int month) {
	switch (month) {
	case 1: printf("January"); break;
	case 2: printf("February"); break;
	case 3: printf("March"); break;
	case 4: printf("April"); break;
	case 5: printf("May"); break;
	case 6: printf("June"); break;
	case 7: printf("July"); break;
	case 8: printf("August"); break;
	case 9: printf("September"); break;
	case 10: printf("October"); break;
	case 11: printf("November"); break;
	case 12: printf("December"); break;
	}
}



//year와 month를 전달 받아 요일과 일을 출력
void printMonthBody(int year, int month) {
	int startday = getStartDay(year, month);
	int numberofdaysinmonth = getNumberOfDaysInMonth(year, month);

	for (int i = 0; i < startday; i++) printf("    ");
        int date = 1;
        //date가 numberofdaysinmonth 보다 작은 동안
        // date 를 "%4d" 서식으로 출력
        //  단 date+startday 값이 7로 나누어지면 개행
        //TODO1

}

// 해당 월의 시작하는 날이 몇 요일인지 찾는 함수
int getStartDay(int year, int month) {
	int startday1800 = 3;
	int totalnumberofdays = getTotalNumberOfDays(year, month);
	return (startday1800 + totalnumberofdays) % 7;
}

// 1800년 1월 1일 부터 며칠이 되는지 계산
int getTotalNumberOfDays(int year, int month) {
	int total = 0;
	for (int i = 1800; i < year; i++) {
		if (isLeapYear(i)) total += 366;
		else total += 365;
	}
	for (int i = 1; i < month; i++) 
           total = total + getNumberOfDaysInMonth(year, i);
	return total;
}


int getNumberOfDaysInMonth(int year, int month) {
	//TODO2 교재 참조

}

int isLeapYear(int year) {
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) return 1;
	else return 0;
}

int MyCalanda(void) 
{
	int year = 2024; 
        
        for (int month = 1; month <= 12; month++) {
              printMonth(year, month);
              printf("\n");
        }
	return 0;
}

