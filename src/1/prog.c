#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[255];
    
    fp = fopen("inputs/1.txt", "r");

    if (fp == NULL) {
        printf("Error opening file \n");
        return 1;
    }


    while(fgets(buffer, 255, fp) != NULL) {
        printf("%s", buffer);
    }


    fclose(fp);

    return 0;
    
}
