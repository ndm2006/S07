/*
Author: Nguyễn Đức Mười
Purpose: Assignment 7
b3 S07
*/
#include <stdio.h>
#include <stdlib.h>

void splitFile(const char *inputFile, const char *outputFile1, const char *outputFile2) {
    FILE *file = fopen(inputFile, "r");
    if (file == NULL) {
        printf("Khong the mo tep %s\n", inputFile);
        return;
    }

    FILE *file1 = fopen(outputFile1, "w");
    FILE *file2 = fopen(outputFile2, "w");
    if (file1 == NULL || file2 == NULL) {
        printf("Khong the tao tep %s hoac %s\n", outputFile1, outputFile2);
        fclose(file);
        return;
    }

    char line[256];
    int lineCount = 0;

    // Đếm số dòng trong tệp
    while (fgets(line, sizeof(line), file)) {
        lineCount++;
    }

    // Reset con trỏ về đầu tệp để đọc lại
    fseek(file, 0, SEEK_SET);

    int halfLines = (lineCount + 1) / 2; // Số dòng cho tệp thứ nhất

    // Ghi vào tệp con
    for (int i = 0; fgets(line, sizeof(line), file); i++) {
        if (i < halfLines) {
            fputs(line, file1);
        } else {
            fputs(line, file2);
        }
    }

    fclose(file);
    fclose(file1);
    fclose(file2);
    printf("Da tach tep %s thanh %s va %s\n", inputFile, outputFile1, outputFile2);
}

int main() {
    char inputFile[100], outputFile1[100], outputFile2[100];

    printf("Nhap ten tep goc: ");
    scanf("%s", inputFile);

    printf("Nhap ten tep con 1: ");
    scanf("%s", outputFile1);

    printf("Nhap ten tep con 2: ");
    scanf("%s", outputFile2);

    splitFile(inputFile, outputFile1, outputFile2);

    return 0;
}
