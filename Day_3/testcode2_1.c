#include "stm32f1xx_hal.h"
#include "testcode2.h"
#include "testfunc.h"
#include <stdio.h>

void pointerArrayTest1(void)
{
   uint8_t arr8[3] = {1, 2, 3};
   printf("Address of Array8  (Name of Array) : %p \n", arr8);
   
   printf ("First Arry Index : %p\n", &arr8[0]);
   printf ("Second Arry Index : %p\n",  &arr8[1]);
   printf ("Third Arry Index : %p\n", &arr8[2]);    
   
   uint32_t arr32[3] = {1, 2, 3};
   printf("Address of Array32  (Name of Array) : %p \n", arr32);
   
   printf ("First Arry Index : %p\n", &arr32[0]);
   printf ("Second Arry Index : %p\n",  &arr32[1]);
   printf ("Third Arry Index : %p\n", &arr32[2]);      
}


void pointerArrayTest2(void)
{
   uint8_t * ptr8 = 0;
   uint16_t * ptr16 = 0;
   uint32_t * ptr32 = 0;
    
   uint8_t var8;
   uint16_t var16;
   uint32_t var32;

   ptr8 = &var8;
   ptr16 = &var16; 
   ptr32 = &var32;
   
  printf("Address of ptr8 :  %p  ptr16 : %p   ptr32 : %p \n", ptr8, ptr16, ptr32);
   
   ptr8++;
   ptr16++;
   ptr32++;
   
   printf("After ++ oftr8 :    %p  ptr16 : %p   ptr32 : %p \n", ptr8, ptr16, ptr32);   
}

   
void pointerArrayTest3(void)
{
    uint16_t arr[5] = {101, 102, 103, 104, 105};

   uint16_t *ptr = arr;
 //   uint16_t *ptr = &arr[0];

    for(int i=0; i< 5; i++) {
            printf("arr[%d] : %d\n", i, arr[i]);
    }
    printf("\n");

    for(int i=0; i< 5; i++) {
            printf("*(ptr+%d) : %d\n", i, *(ptr+i) );
    }
    printf("\n");

    for(int i=0; i< 5; i++) {
            printf("*(ptr++) : %d\n", *ptr++ );
    }
    printf("\n");  
    
   
}