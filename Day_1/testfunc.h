#ifndef _TEST_FUNC
#define _TEST_FUNC


#define PIN_SET_ON  GPIO_PIN_SET
#define PIN_SET_OFF GPIO_PIN_RESET

#define BTN_STATE_ON  GPIO_PIN_RESET
#define BTN_STATE_OFF GPIO_PIN_SET

#define TURN_ON_BTN    10
#define TURN_OFF_BTN   11
#define CHANGE_STATE_BTN   12

extern uint8_t TestSetMode;

#define TESTSET_BTN_INTER       100  /*must set btn pin GPIO_INTERRUPT and regenerate code!!"*/
#define TESTSET_BTN_READ        101  /*must set btn pin GPIO_IN andd regenerate code!!"*/

extern uint8_t TestAppMode;

extern uint8_t bStartBlink;

#define TESTAPP_NONE          199    
#define TESTAPP_ONOFF_ALL    200 
#define TESTAPP_STEP_BY_STEP 201  
#define TESTAPP_TOGGLE_ALL   202

#define LED_CNT 8


void SetLedOn(uint32_t LED_Pin, uint8_t bOn );

uint8_t ReadButton(uint32_t Btn_Pin);

void setBlinkStart(uint8_t bStart);

void BlinkTest(void);

void setAllLed(uint8_t bOn);

void setAllToggleLed(uint8_t bOn);

void doToggleTest(void);

void setBtnTest_AllLedOn(void);

void setBlinkTest(void);

void doBlinkTest(void);

void setLedShiftTest(void);

void doBtnProc(void);


#endif //_TEST_FUNC