#include <stdio.h>
#include <math.h>

int len(long value){
   int count = 0;
   while (value > 0) {
      count++;
      value /= 10;
   }
   return count;
}

int max(int a, int b){
   return a > b ? a : b;
}

long karatsuba(long x, long y){
   if (x < 10 && y < 10)
      return x * y;

   int size = max(len(x), len(y));
   size = (size/2) + (size%2);
   long multiplier = pow(10, size);
   long b = x/multiplier;
   long a = x - (b * multiplier);
   long d = y / multiplier;
   long c = y - (d * multiplier);
   long u = karatsuba(a, c);
   long v = karatsuba(b, d);
   long z = karatsuba(a + b, c + d);
   return u + ((z - u - v) * multiplier) + (v * (long)(pow(10, 2 * size)));
}

int main(){
   long x, y;
   printf("Enter two numbers: ");
   scanf("%ld%ld", &x, &y);
   printf("The final product is: %ld\n", karatsuba(x, y));
   return 0;
}