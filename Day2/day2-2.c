#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void tokenize(char line[], int *pos1, int *pos2, char *check, char *password[]) {
    char *ptr = strtok(line, " -:");
    *pos1 = atoi(ptr);
    *pos2 = atoi(strtok(NULL, " -:"));
    *check = * strtok(NULL, " -:");
    *password = strtok(NULL, " -:");
}

int validatePW(char line[]) {
    int pos1, pos2;
    char check;
    char * password;
    tokenize(line, &pos1, &pos2, &check, &password);
    printf("Pos1: %d\nPos2: %d\nCheck: %c\nPassword: %s\n", pos1, pos2, check, password);
    if(password[pos1-1] == check && password[pos2-1] == check) {
        printf("Not Valid\n");
        return 0;
    }else if(password[pos1-1] != check && password[pos2-1] != check) {
        printf("Not Valid\n");
        return 0;
    }else{
        printf("Valid\n");
        return 1;
    }
}

int main(void) {

    FILE * fp;
    fp = fopen("input.txt", "r");
    int total = 0;
    ssize_t read;
    size_t len = 0;
    char * line = NULL;

    printf("Getting ready");
    while ((read = getline(&line, &len, fp)) != -1) {
        total += validatePW(line);
    }
    printf("Total: %d", total);
    return 0;
}
