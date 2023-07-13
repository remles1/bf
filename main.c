#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[])
{
    if(argc < 2) {
        printf("no file to read\n");
        return -1;
    }
    if(argc > 2){
        printf("too many arguments");
        return -2;
    }

    FILE* ptr;
    char ch;

    ptr = fopen(argv[1], "r");

    if (NULL == ptr) {
        printf("file can't be opened\n");
        return -3;
    }


    fseek(ptr, 0, SEEK_END);
    int size = ftell(ptr);
    fseek(ptr, 0, SEEK_SET);

    int malloc_size = (size+1) * sizeof(char);
    char* command = malloc(malloc_size);
    int i = 0;

    do {
        ch = fgetc(ptr);
        command[i] = ch;
        i++;
    } while (ch != EOF);
    command[size] = '\0';
    fclose(ptr);


    int pointer = 0;
    int cmd_pointer = 0;
    char* tape = calloc(30000,sizeof(char));


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

    free(command);
    free(tape);
    return 0;
}
