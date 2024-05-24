#include <stdio.h>

int ab (int n){
     if (n < 0){
          int ndouble = 0;
          int i = 0;
          while(i < n){
               ndouble = ndouble + 1;
               i = i + 1;
          }

          ndouble = ndouble + ndouble;
          n = ndouble - n;
     }
     return n;
}

int mult (int x, int y){
     if(x > y){
          printf("Warning: x is larger than y. \n");
     }

     int i = 0;
     int temp = y;
     while(i < x - 1){
          y = y + temp;
          i++;
     }

     return y;
}

int rf (int n){
     if(n == 1){
          return 2;
     }

     else if(n == 0){
          return 1;
     }

     else{
          return mult(rf(n-2), rf(n-1));
          }
}

int main(){
     int input[11] = {-6, 4, 5, -7, 8, 0};

     int temp;
     int num = 0;
     num = input[0];

     int i = 0;
     while(num != 0){
          printf("%7d   %#010x \n", num, num);

          num = ab(num);

          temp = num;
          int j;
          while(temp > 1){
               temp = temp - 2;
               j++;
          }

          if(temp == 1){
               temp = mult(num, num);
               printf("%7d   %#010x \n", temp, temp);
               }

          else{
               temp = rf(num);
               printf("%7d   %#010x \n", temp, temp);
          }

          i++;
          num = input[i];
     }
}