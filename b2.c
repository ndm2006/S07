/*
Author: Nguyễn Đức Mười
Purpose: Assignment 7
b2 S07
*/
#include <stdio.h>

int countCharactersInFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo tep %s\n", filename);
        return -1;
    }

    int charCount = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        // Không đếm ký tự xuống dòng
        if (ch != '\n') {
            charCount++;
        }
    }

    fclose(file);
    return charCount;
}

int main() {
    char filename[100];
    printf("Nhap ten tep: ");
    scanf("%s", filename);

    int charCount = countCharactersInFile(filename);
    if (charCount != -1) {
        printf("So ky tu trong tep %s (khong tinh ky tu ket thuc dong) la: %d\n", filename, charCount);
    }

    return 0;
}
