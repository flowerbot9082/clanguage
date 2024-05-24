/* 
Jake Kim
Feb 27, 2024
CSCI 304

A program that converts between different 
bases of numbers based on user input. 
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* no global variables */

short get_operand(char mode){
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
     }
     return val;
}

void print_bases(short val, char mode){
     char mmode = mode;
     short mval = val;

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
     }
          
     printf("****************************************\n"); //line 1
     printf("* Base Values:         Input Mode: %s *\n", str); //line 2
     printf("*   Hex     :  %-10hX              *\n", mval);
     printf("*   Octal   :  %-10ho              *\n", mval);
     printf("*   Decimal :  %-10hd              *\n", mval);
     printf("****************************************\n\n");
}
     
char print_menu(void){
     char menu[] = "Please select one of the following options: \n\n"

                    "O  Octal Mode\n"  
                    "H  Hexadecimal Mode\n"  
                    "D  Decimal Mode \n\n"

                    "C  Clear Value \n"  
                    "S  Set Value \n\n"

                    "Q  Quit\n\n"
                    
                    "Option: ";

     char opt;
     char ava[] = {'O','H','D','C','S','Q'};
     short v = 0;
     while(v == 0){
          char mode[10];
          printf("%s", menu);
          scanf("%s", mode);
          printf("\n");
          if(mode[1] == '\0'){
               short i;
               for(i = 0; i < 6; i++){
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

     print_bases(value, md);
     while(opt != 'Q'){
          opt = print_menu();
          switch(opt){
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
               case 'Q':
                    break;
          }
     }
}