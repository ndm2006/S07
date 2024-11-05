/*
Author: Nguyễn Đức Mười
Purpose: Assignment 7
b1 S07
*/
#include <stdio.h>
#include <ctype.h>

int countWordsInFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo tep %s\n", filename);
        return -1;
    }

    int wordCount = 0;
    int inWord = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            if (inWord) {
                wordCount++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }

    if (inWord) {
        wordCount++;
    }

    fclose(file);
    return wordCount;
}

int main() {
    char filename[100];
    printf("Nhap ten tep: ");
    scanf("%s", filename);

    int wordCount = countWordsInFile(filename);
    if (wordCount != -1) {
        printf("So tu trong tep %s la: %d\n", filename, wordCount);
    }

    return 0;
}
