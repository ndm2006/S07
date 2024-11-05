/*
Author: Nguyễn Đức Mười
Purpose: Assignment 7
b4 S07
*/
#include <stdio.h>
#include <stdlib.h>

void splitFile(const char *inputFile, int maxSize) {
    FILE *file = fopen(inputFile, "rb");
    if (file == NULL) {
        printf("Khong the mo tep %s\n", inputFile);
        return;
    }

    char buffer[1024];
    int fileIndex = 1;
    size_t bytesRead;
    char outputFile[100];

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        snprintf(outputFile, sizeof(outputFile), "%s_part%d.txt", inputFile, fileIndex);
        FILE *outFile = fopen(outputFile, "wb");
        if (outFile == NULL) {
            printf("Khong the tao tep %s\n", outputFile);
            fclose(file);
            return;
        }

        // Ghi dữ liệu vào tệp con
        size_t bytesToWrite = (bytesRead > maxSize) ? maxSize : bytesRead;
        fwrite(buffer, 1, bytesToWrite, outFile);
        fclose(outFile);
        fileIndex++;

        // Nếu đọc được ít hơn maxSize bytes, nghĩa là đã đến cuối tệp
        if (bytesRead < sizeof(buffer)) {
            break;
        }
    }

    fclose(file);
    printf("Da tach tep %s thanh %d tep con.\n", inputFile, fileIndex - 1);
}

int main() {
    char inputFile[100];
    int maxSize;

    printf("Nhap ten tep goc: ");
    scanf("%s", inputFile);

    printf("Nhap kich thuoc toi da cho tung tep con (byte): ");
    scanf("%d", &maxSize);

    splitFile(inputFile, maxSize);

    return 0;
}
