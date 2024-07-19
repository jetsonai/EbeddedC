#include "stm32f1xx_hal.h"
#include "testcode2.h"
#include "testfunc.h"
#include <stdio.h>

void pointerTest(void)
{
    uint16_t num;
    uint16_t *pnum;
     uint32_t num32;
    uint32_t *pnum32;   
      uint8_t num8;
    uint8_t *pnum8;   
    

}

void pointerArrayTest1(void)
{
   int arr[3] = {1, 2, 3};
   printf("Address of Array  (Name of Array) : %p \n", arr);
     
    
}

void pointerArrayTest2(void)
{
   uint8_t * ptr8 = 0;
   uint16_t * ptr16 = 0;
   uint32_t * ptr32 = 0;
    
  
}
   
void pointerArrayTest3(void)
{
   

   
}