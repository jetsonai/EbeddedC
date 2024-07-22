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

//---------------------------------------

int increasenumber(void)
{
  int num = 0;
  printf("num : %d \n", num);
  num++;
}

void increaseNumTest(void)
{
   increasenumber();
   increasenumber();
   increasenumber();
   increasenumber();
  
}

int printnumber(int a, int b)
{
  a++;
  b++;
  printf("[printnumber] a : %d b : %d \n", a, b);
}

void printNumTest(void)
{
  int a = 30;
  int b = 40;
  printf("[printNumTest]  a :%d b : %d \n", a, b);
  printnumber(a, b);
  printf("[printNumTest]  a :%d b : %d \n", a, b);
    
}

int globalvar;

void add(void)
{
  globalvar += 100;
  printf("[add] globalvar : %d \n", globalvar);
}

void globalvarAddTest(void)
{
  int globalvar;
  printf("[globalvarAddTest] globalvar : %d \n", globalvar);
  add();
  printf("[globalvarAddTest] globalvar : %d \n", globalvar);
}

//---------------------------------

int * foofunc(int ival)
{
  static int * aval;
  ival = ival++;
  //printf("ival : %d \n", ival);
  aval = &ival;
  return &ival;
}

void fooFuncTest(void)
{
  int32_t *var1 = foofunc(100);
  printf("var1 : %d \n", *var1);
  int32_t *var2 = foofunc(200);
  printf("var2 : %d \n", *var2);  
}

//------------------------------



int32_t fibNI(int32_t n) 
{
   int32_t previous = -1;
   int32_t result = 1;
   int32_t i=0;
   int32_t sum=0;
   for (i = 0; i <= n; i++) 
   {
      sum = result + previous;
      previous = result;
      result = sum;
      //printf("i:%d result:%d\n", i, result); 
   } 
   return result;
}



int32_t fibN(int32_t n) {

}

void dofibNITest(void)
{
   int32_t fibNum = fibNI(5);
   printf("fibNum:%d\n", fibNum);
}


struct strTemp
{
  uint8_t data8;
  uint16_t data16;
  uint32_t data32;
};

union unTemp
{
  uint8_t data8;
  uint16_t data16;
  uint32_t data32; 
};

void structunionTest(void)
{
   struct strTemp st1;
   union unTemp un1;
   
   st1.data8 = 0xa1;
   printf("st1.data8] addr:%p size:%d val:%x \n",  &(st1.data8), sizeof(st1.data8), st1.data8);
   st1.data16 = 0xa1b1;
   printf("st1.data16] addr:%p size:%d val:%x \n", &(st1.data16) , sizeof(st1.data16) , st1.data16);
   st1.data32 = 0xa1b1c1d1;
   printf("st1.data32] addr:%p size:%d val:%x \n",  &(st1.data32) , sizeof(st1.data32) , st1.data32);
   printf("st1.data8] addr:%p size:%d val:%x \n", &(st1.data8) , sizeof(st1.data8) , st1.data8);
   printf("=====\n");
}


union EndianConverter {
    uint16_t value16;
    uint8_t value8[2];
};

void EndianConverterTestU(void) {
   uint16_t littleEndian16 = 0xABCD;

    union EndianConverter converter;

    converter.value16= littleEndian16;
    
    printf(" little Endian 16bit: 0x%x\n", littleEndian16);

    //converter.value16 = myhtons(littleEndian16);
    printf(" bin Endian 16bit: 0x%02x%02x\n", converter.value8[0], converter.value8[1]);
    //printf(" bin Endian 8bit: 0x%02x\n", converter.value8[1]);
}
