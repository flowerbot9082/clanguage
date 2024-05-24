/*
Jake Kim
Apr 3
CSCI 304
A program that computes the repeated sum for formula: 5i - 2 
('i' starts at 0) through different ranges. 
*/

#include <stdio.h>

int summation (int n){

     int sum_val = 0;
     int rpt = 0;

     for(int i = 0; i <= n; i++){ //start loop for summation

          for(int j = 0; j < i; j++){ //add 5s

               sum_val += 5;

          }

          sum_val -= 2; //subtract two

     }

     return sum_val; //end loop and return sum val

}

int main(){
     int n = 10; //change n value here
     for(int i = 0; i <= n; i++){

          int pval = summation(i); //assign pval to the returned value of summation at i 
          printf("%-2d : %6d   %08x\n", n, pval, pval); //print answers

     }

}