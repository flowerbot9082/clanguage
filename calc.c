/* 
Jake Kim
Mar 26, 2024
CSCI 304

A program that converts between different 
bases of numbers based on user input and
does binary operations.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"
/* no global variables */

void convert_to_binary (short val, bin_str bin){
     char bits[20];

     unsigned short q = val;
     short i = 0;

     while (q != 0){
          short tmp = q % 2;
          if(tmp == 0){bits[i] = '0';}
          else if(tmp == 1){bits[i] = '1';}
          q /= 2;
          i++;
     }
     short length = i;

     char flip_bin[] = "0000 0000 0000 0000";
     short a = 0;
     for(short r = 0; r < 19; ++r){
          if((r + 1) % 5 == 0){
               flip_bin[r] = ' ';
          }
          else{
               if(a == length){
                    flip_bin[r] = '0';
                    }
               else{
                    flip_bin[r] = bits[a];
                    a++;
                    }
          }
     }

     short b = 18;
     for(int j = 0; j < 19; j++){
          bin[j] = flip_bin[b];
          b--;
     }
}

unsigned short get_binary_op (bin_str bin){
     short sum_val;
     double exp = 15;
     for(short i = 0; i < 19; i++){
          if(bin[i] == '1'){
               short partial = 1;

               for(int rand = 1; rand <= exp; rand++){
                    partial *= 2;
               }
               
               sum_val += partial;
          }
          else if (bin[i] == '0'){continue;}
          exp--;
     }
     return sum_val;
}

void add (short *val, char mode){
     char mmode = mode;
     signed short value = *val;
     signed short altval = 0;
    
     switch (mode) {
          case 'B': {
               bin_str str;
               printf("Enter binary value: ");
               scanf("%s", str);
               altval = (signed)get_binary_op(str);
               break;
          }
          case 'O':
               printf("Enter octal value: ");
               scanf("%ho", &altval);
               break;
          case 'H':
               printf("Enter hex value: ");
               scanf("%hx", &altval);
               break;
          case 'D':
               printf("Enter decimal value: ");
               scanf("%hd", &altval);
               break;
     }
    
     *val = value + altval;
    
     if ((value < 0) && (altval < 0) && (*val > 0)) {
          printf("Negative overflow\n");
     } else if ((value > 0) && (altval > 0) && (*val < 0)) {
          printf("Positive overflow\n");
     }
}

void subtract(short *val, char mode) {
    char mmode = mode;
     signed short value = *val;
     signed short altval = 0;
    
     switch (mode) {
          case 'B': {
               bin_str str;
               printf("Enter binary value: ");
               scanf("%s", str);
               altval = (signed)get_binary_op(str);
               break;
          }
          case 'O':
               printf("Enter octal value: ");
               scanf("%ho", &altval);
               break;
          case 'H':
               printf("Enter hex value: ");
               scanf("%hx", &altval);
               break;
          case 'D':
               printf("Enter decimal value: ");
               scanf("%hd", &altval);
               break;
     }
    
     *val = value - altval;
    
     if ((value < 0) && (altval < 0) && (*val > 0)) {
          printf("Negative overflow\n");
     } else if ((value > 0) && (altval > 0) && (*val < 0)) {
          printf("Positive overflow\n");
     }
}

short get_operand(char mode){
     bin_str bin = "0000000000000000";
     short val;
     char m = mode;
     switch(m){
          case 'O':
               printf("Enter octal value: \n");
               scanf("%ho", &val);
               break;
          case 'H':
               printf("Enter hexadecimal value: \n");
               scanf("%hX", &val);
               break;
          case 'D':
               printf("Enter decimal value: \n");
               scanf("%hd", &val);
               break;
          case 'B':
               printf("Enter binary value: \n");
               scanf("%s", bin);
               val = get_binary_op(bin);
               break;
     }
     return val;
}

void print_bases(short val, char mode){
     char mmode = mode;
     short mval = val;
     bin_str dbin = "0000 0000 0000 0000";
     char str[4]; 
     switch(mmode){
          case 'O':
               strcpy(str, "Oct");
               break;
          case 'H':
               strcpy(str, "Hex");
               break;
          case 'D':
               strcpy(str, "Dec");
               break;
          case 'B':
               strcpy(str, "Bin");
               break;
     }
     
     if(mval != 0){
          convert_to_binary(val, dbin);
          }
     else{
          bin_str dbin = "0000 0000 0000 0000";
     }

     printf("****************************************\n"); //line 1
     printf("* Base Values:         Input Mode: %s *\n", str); //line 2
     printf("*   Binary  :  %-20s    *\n", dbin);
     printf("*   Hex     :  %-10hX              *\n", (signed short)mval);
     printf("*   Octal   :  %-10ho              *\n", (signed short)mval);
     printf("*   Decimal :  %-10hd              *\n", (signed short)mval);
     printf("****************************************\n\n");
}
     
char print_menu(void){
     char menu[] = "Please select one of the following options: \n\n"

                    "B  Binary Mode            &  AND with Value         +  Add to Value\n"
                    "O  Octal Mode             |  OR  with Value         -  Subtract from Value\n"  
                    "H  Hexadecimal Mode       ^  XOR with Value         N  Negate Value\n"  
                    "D  Decimal Mode           ~  Complement Value\n\n"

                    "C  Clear Value            <  Shift Value Left\n"  
                    "S  Set Value              >  Shift Value Right\n\n"

                    "Q  Quit\n\n"
                    
                    "Option: ";

     char opt;
     char ava[] = {'B','O','H','D','C','S','Q','&',
                    '|','^','~','+','-','N','<','>'};
     short v = 0;
     while(v == 0){
          char mode[10];
          printf("%s", menu);
          scanf("%s", mode);
          printf("\n");
          if(mode[1] == '\0'){
               short i;
               for(i = 0; i < 15; i++){
                    if(toupper(mode[0]) == ava[i]){
                         opt = toupper(mode[0]);
                         v = 1;
                         break;
                    }
               }
          }
          else{
               printf("Invalid option: %s\n\n", mode);
          }
     }
     return opt;
}                

int main(){
     short value = 0;
     char md = 'D';
     char opt;
     short shiftv, altval;
     short *ptr = &value;

     print_bases(value, md);
     while(opt != 'Q'){
          opt = print_menu();
          switch(opt){
               case 'B':
                    printf("Mode: Binary\n\n");
                    md = 'B';
                    print_bases(value, md);
                    break;
               case 'O':
                    printf("Mode: Octal\n\n");
                    md = 'O';
                    print_bases(value, md);
                    break;
               case 'H':
                    printf("Mode: Hexadecimal\n\n");
                    md = 'H';
                    print_bases(value, md);
                    break;
               case 'D':
                    printf("Mode: Decimal\n\n");
                    md = 'D';
                    print_bases(value, md);
                    break;
               case 'C':
                    value = 0;
                    print_bases(value, md);
                    break;
               case 'S':
                    value = get_operand(md);
                    print_bases(value, md);
                    break;
               case '&':
                    altval = 0;
                    char xar = md;
                    switch (xar) {
                         case 'B': {
                              bin_str str;
                              printf("Enter binary value: \n");
                              scanf("%s", str);
                              altval = get_binary_op(str);
                              break;
                         }
                         case 'O':
                              printf("Enter octal value: \n");
                              scanf("%ho", &altval);
                              break;
                         case 'H':
                              printf("Enter hex value: \n");
                              scanf("%hx", &altval);
                              break;
                         case 'D':
                              printf("Enter decimal value: \n");
                              scanf("%hd", &altval);
                              break;
                    }
                    value = value & altval;
                    print_bases(value, md);
                    break;
               case '|':
                    altval = 0;
                    char bar = md;
                    switch (bar) {
                         case 'B': {
                              bin_str str;
                              printf("Enter binary value: \n");
                              scanf("%s", str);
                              altval = get_binary_op(str);
                              break;
                         }
                         case 'O':
                              printf("Enter octal value: \n");
                              scanf("%ho", &altval);
                              break;
                         case 'H':
                              printf("Enter hex value: \n");
                              scanf("%hx", &altval);
                              break;
                         case 'D':
                              printf("Enter decimal value: \n");
                              scanf("%hd", &altval);
                              break;
                         }
                    value = value | altval;
                    print_bases(value, md);
                    break;
               case '^':
                    altval = 0;
                    char foo = md;
                    switch (foo) {
                         case 'B': {
                              bin_str str;
                              printf("Enter binary value: \n");
                              scanf("%s", str);
                              altval = get_binary_op(str);
                              break;
                         }
                         case 'O':
                              printf("Enter octal value: \n");
                              scanf("%ho", &altval);
                              break;
                         case 'H':
                              printf("Enter hex value: \n");
                              scanf("%hx", &altval);
                              break;
                         case 'D':
                              printf("Enter decimal value: \n");
                              scanf("%hd", &altval);
                              break;
                         }
                    value = value ^ altval;
                    print_bases(value, md);
                    break;
               case '+':
                    add(ptr, md);
                    printf("\n");
                    print_bases(value, md);
                    break;
               case '-':
                    subtract(ptr, md);
                    printf("\n");
                    print_bases(value, md);
                    break;
               case '<':
                    shiftv = 0;
                    printf("Enter number of positions to left shift value: \n");
                    scanf("%hd", &shiftv);
                    value = value << shiftv;
                    break;
               case '>':
                    shiftv = 0;
                    printf("Enter number of positions to right shift value: \n");
                    scanf("%hd", &shiftv);
                    value = value >> shiftv;
                    break;
               case '~':
                    value = ~value;
                    break;
               case 'N':
                    value = -value;
                    break;
               case 'Q':
                    break;
          }
     }
}