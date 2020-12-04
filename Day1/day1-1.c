#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int values[200];
    ssize_t read;
    size_t len = 0;
    char * line = NULL;
    int total = 0;

    FILE * fileP;
    fileP = fopen("./input.txt", "r");

    while ((read = getline(&line, &len, fileP)) != -1) {
        values[total] = atoi(line);
        total++;
    }

    for(int x = 0; x < total; x++){
        int seeking = 2020 - values[x];
        for(int y = 0; y < total; y++) {
            if(values[y] == seeking){
                printf("Found: %d %d\n", seeking, values[x]);
                printf("Product: %d\n", (seeking * values[x]));
                return 0;
            }
        }
    }
    printf("%d", total);
    printf("\n");
    fclose(fileP);
    exit(EXIT_SUCCESS);
}