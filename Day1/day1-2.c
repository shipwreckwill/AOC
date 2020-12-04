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
    
    for(int x = 0; x<total; x++){
        for(int y = 0; y < total; y++){
            for(int z = 0; z < total; z++){
                int result = values[x] + values[y] + values[z];
                // printf("%d", result);
                if(result == 2020) {
                    printf("Found: %d + %d + %d = %d\n", values[x], values[y], values[z], result);
                    printf("%d\n", values[x] * values[y] * values[z]);
                    return 0;
                }
            }
        }
    }
    printf("%d", total);
    printf("\n");
    fclose(fileP);
    exit(EXIT_SUCCESS);
}