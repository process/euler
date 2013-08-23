#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char isPandigitalTriplet(int i, int j, int k) {
   char iStr[10], jStr[10], kStr[10], digitString[11];
   int n;

   // This string is treated like an array of
   // booleans. '1' means the digit at that
   // position has appeared, while '0' means
   // it hasn't.
   for (n = 0; n < 10; ++n) {
      digitString[n] = '0';
   }
   digitString[10] = '\0';

   sprintf(iStr, "%d", i);
   sprintf(jStr, "%d", j);
   sprintf(kStr, "%d", k);

   // To be pandigital it must have 9 digits
   if (strlen(iStr) + strlen(jStr) + strlen(kStr) != 9)
      return 0;

   // Update a string array of boolean digits that
   // mark whether a digit has appeared.
   for (n = 0; n < strlen(iStr); ++n)
      digitString[iStr[n]-'0'] = '1';

   for (n = 0; n < strlen(jStr); ++n)
      digitString[jStr[n]-'0'] = '1';

   for (n = 0; n < strlen(kStr); ++n)
      digitString[kStr[n]-'0'] = '1';

   // Do a string compare on the array
   if(strcmp(digitString, "0111111111") == 0)
      return 1;
   else
      return 0;
}

int main(int argc, char* argv[]) {
   int i, j;
   int sum = 0;

   for (i = 1; i < 10000; ++i) {
      for (j = i+1; j < 10000; ++j) {
         if (isPandigitalTriplet(i, j, i*j)) 
            // TODO: Add check to make sure product has not already
            // been added.
            sum += i*j; // Add the product to the total
      }
   }

   printf("Sum: %d\n", sum);

   return 0;
}
