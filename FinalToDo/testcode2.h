#ifndef _TEST_CODE2
#define _TEST_CODE2


// Make up and Understand 1
void pointerTest(void);
void pointerArrayTest1(void);
void pointerArrayTest2(void);
void pointerArrayTest3(void);

void increaseNumTest(void);
void printNumTest(void);
void globalvarAddTest(void);

void fooFuncTest(void);

void dofibNITest(void);

void EndianConverterTestU(void) ;

void EndianConverterTestS(void);

union EndianConverter {
    uint16_t value16;
    uint8_t value8[2];
};

int32_t fibNI(int32_t n);
uint16_t swap16(uint16_t value);

#endif //_TEST_CODE2