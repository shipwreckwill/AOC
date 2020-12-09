#include <stdio.h>
#include <string.h>

void moveHorizontal(int length, int *xPos, int slopeX) {
    for(int x = slopeX; x > 0; x--){
        ++*xPos;
        if(*xPos == length-1){
            *xPos = 0;
        }
        // printf("%d\n", *xPos);
    }
}

void checkForTree(int *xPos, char * line, int *totalTrees){
    // printf("Pos: %d: %c\n",*xPos, line[*xPos]);
    if(line[*xPos] == '#' ) {
        ++*totalTrees;
    }
}

int main(void) {
    int FILELENGTH = 232;
    FILE * fp;
    ssize_t read;
    size_t len = 0;
    char * line = NULL;
    int xPos = 0;
    int slopes[] = {1, 3, 5, 7, 1};
    int results[5];
    for(int x = 0; x < 5; x++){
        int totalTrees = 0;
        fp = fopen("index.txt", "r");
        if(x != 4){
            while ((read = getline(&line, &len, fp)) != -1) {
                checkForTree(&xPos, line, &totalTrees);
                moveHorizontal(strlen(line), &xPos, slopes[x]);
            }  
        }else{
            int counter = 0;
            while ((read = getline(&line, &len, fp)) != -1) {
                if(counter % 2 ==0){
                    checkForTree(&xPos, line, &totalTrees);
                    moveHorizontal(strlen(line), &xPos, slopes[x]);
                    // printf("Position %d\n", counter);
                }
                counter++;
            }
        }
        fclose(fp);
        xPos = 0;
        line = NULL;
        len = 0;
        results[x] = totalTrees;
        printf("Slope: %d\nTotal Trees: %d\n", slopes[x], totalTrees);
    }
    double final = 1;
    for(int x =0; x < sizeof(results) / sizeof(results[0]); x++) {
        final = final * results[x];
    }
    printf("Result: %f\n", final);

    return 0;
}