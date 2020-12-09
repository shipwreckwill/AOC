#include <stdio.h>
#include <string.h>

void moveHorizontal(int length, int *xPos) {
    for(int x = 3; x > 0; x--){
        ++*xPos;
        if(*xPos == length-1){
            *xPos = 0;
        }
        printf("%d\n", *xPos);
    }
}

void checkForTree(int *xPos, char * line, int *totalTrees){
    printf("Pos: %d: %c\n",*xPos, line[*xPos]);
    if(line[*xPos] == '#') {
        ++*totalTrees;
    }
}

int main(void) {
    FILE * fp;
    fp = fopen("index.txt", "r");
    ssize_t read;
    size_t len = 0;
    char * line = NULL;
    int totalTrees, xPos = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        checkForTree(&xPos, line, &totalTrees);
        moveHorizontal(strlen(line), &xPos);
    }

    printf("Total Trees: %d\n", totalTrees);
    return 0;
}