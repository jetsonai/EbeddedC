
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

