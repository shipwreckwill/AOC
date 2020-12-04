#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int countChars(char c, const char * pass) {
    int count = 0;
    for(int x = 0; x < strlen(pass); x++){
        printf("%c", pass[x]);
        if(pass[x] == c){
            count++;
        }
    }
    return count;
}

void tokenize(char line[], int *min, int *max, char *check, char *password[]) {
    char *ptr = strtok(line, " -:");
    *min = atoi(ptr);
    *max = atoi(strtok(NULL, " -:"));
    *check = * strtok(NULL, " -:");
    *password = strtok(NULL, " -:");

    // while(ptr != NULL) {
    //     printf("%s", ptr);
    //     ptr = strtok(NULL, " -:");
    // }
}

int validatePW(char line[]) {
    int min, max, count, total;
    char check;
    char * password;
    tokenize(line, &min, &max, &check, &password);
    count = countChars(check, password);
    printf("Min: %d\nMax: %d\nCheck: %c\nPassword: %s\n", min, max, check, password);
    if(count >= min && count <= max) {
        printf("Valid\n");
        return 1;
    }else{
        printf("Invalid\n");
        return 0;
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
