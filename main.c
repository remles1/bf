#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int pointer = 0;
    int cmd_pointer = 0;
    char* tape = calloc(30000,sizeof(char));

    char command[] = ">>>>++>+[[>[>>]<[>+>]<<[>->>+<<<-]>+[[+>>[<<+>>-]>]+[-<<+<]>-[-[<+>>+<-]++++++[>++++++++<-]+>.[-]<<[>>>[[<<+>+>-]>>>]<<<<[[>+<-]<-<<]>-]>>>[<<-[<<+>>-]<+++++++++<[>[->+>]>>>[<<[<+>-]>>>+>>[-<]<[>]>+<]<<<<<<-]>[-]>+>>[<<<+>>>-]>>>]<<<+[-[+>>]<<<]>[<<<]>]>>>[<[>>>]<<<[[>>>+<<<-]<<<]>>>>>>>-[<]>>>[<<]<<[>+>]<]<<]++>>]<<++++++++.+]";


    while(command[cmd_pointer] != '\0'){
        switch(command[cmd_pointer]) {
            case '>':
                pointer++;
                break;
            case '<':
                pointer--;
                break;
            case '+':
                tape[pointer]++;
                break;
            case '-':
                tape[pointer]--;
                break;
            case '.':
                printf("%c",tape[pointer]);
                break;
            case ',':
                scanf("%c",&(tape[pointer]));
                break;
            case '[':
                if(tape[pointer] == 0){
                    int l = 1;
                    int r = 0;
                    while(l != r){
                        cmd_pointer++;
                        switch(command[cmd_pointer]){
                            case '[':
                                l++;
                                break;
                            case ']':
                                r++;
                                break;
                        }
                    }
                }
                break;
            case ']':
                if(tape[pointer] != 0){
                    int l = 0;
                    int r = 1;
                    while(l != r){
                        cmd_pointer--;
                        switch(command[cmd_pointer]){
                            case '[':
                                l++;
                                break;
                            case ']':
                                r++;
                                break;
                        }
                    }
                }
                break;
        }
        cmd_pointer++;
    }

    return 0;
}
