# EbeddedC Day2


## 2-1 예제 ~ 2-4 예제 함수를 설명을 듣고 용도를 이해합니다.


=============================================

## 변수와 연산자 실습 테스트 방법 (2-5 ~ 2-7)


### testcode.c 에 아래의 테스트 코드를 이해하며 작성하고 main 함수에서 호출해보세요 (while 문 시작 전)

### 2-5 boolean 테스트 코드 작성 및 응용 연습

   booleanTest();

### 2-6-1 비트 연산 테스트 코드 작성 및 응용 연습

   bitOpTest();

### 2-6-2 비트 연산 테스트 코드 작성 및 응용 연습
 
   incdecOpTest();

### 2-7-1 3항 연산 테스트 코드 작성 및 응용 연습

   threeOpTest();

### 2-7-2 참조 연산자 테스트 코드 작성 및 응용 연습
 
   referenceOpTest();

#########################

## 응용 실습 테스트 방법 : 2-1 예제 ~ 2-4 예제 함수를 메인 함수의 while 문 안 에서 호출해본 후 

## 아래의 요구에 맞추어 수정해보세요.


### 2-1 변수 초기화 예제 : LED 가 켜져야합니다.

setBtnTest_1();

### 2-2 변수 Type 예제 : terminal 에 0.16~ 숫자가 보여야합니다.

setBtnTest_1();

### 2-3 변수 최대 최소 범위 예제 I : terminal 에 0.16 이 정도 작은 범위의 숫자로 시직해

setVarRangeTest_1();

### 2-4 변수 최대 최소 범위 예제 II : terminal 에 음수가 보이지 않도록 해주세요.

    setBlinkTest_1(); 
    doBlinkTest_1();    

=============================================  

##   8개의 LED 가 차례로 BLINK 되는 실습

=============================

## header 파일에 추가

#define TESTAPP_SHIFT           203

#define TESTAPP_SHIFT_ROUND     204

## c 파일에 추가

void doTestProc(void)
{ 
    switch (TestAppMode) { 
    case TESTAPP_TOGGLE_ALL:    
      doToggleTest();      
      break;      
    case TESTAPP_STEP_BY_STEP:   
      doBlinkTest();     
      break;           
    case TESTAPP_SHIFT:    
        doLedShiftTest();     
        break;          
    case TESTAPP_SHIFT_ROUND:      
    
        break;            
    }    
}



    
