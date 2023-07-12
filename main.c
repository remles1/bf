#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int pointer = 0;
    int cmd_pointer = 0;
    int current_bracket = -1;
    int* bracket_pointers = calloc(1000,sizeof(int));
    int* tape = calloc(3000,sizeof(int));

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
                tape[pointer] += 1;
                break;
            case '-':
                tape[pointer] -= 1;
                break;
            case '.':
                printf("%d",tape[pointer]);
                break;
            case ',':
                scanf("%c",&(tape[pointer]));
                break;
            case '[':
                if(tape[pointer]!=0){
                    current_bracket++;
                    bracket_pointers[current_bracket] = cmd_pointer;
                }
                else{
                    while(command[cmd_pointer] != ']'){
                        cmd_pointer++;
                    }
                }

                break;
            case ']':
                if(tape[pointer] != 0){
                    cmd_pointer = bracket_pointers[current_bracket] - 1; // moze -1?
                }
                else{
                    current_bracket--;
                }
                break;
        }
        cmd_pointer++;
    }

    return 0;
}
