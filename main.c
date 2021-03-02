#include <stdio.h>

void readFile(FILE *);

void whireFile(FILE *, char *, char *);

int main(void) {
    char path[50] = "C:\\Users\\yuAn\\Desktop\\1.txt";
    FILE *fp = fopen(path, "r");
    char str[100];
    puts("输入写入的内容");
    scanf("%s", str);
    whireFile(fp, path, str);
    readFile(fp);
}

void readFile(FILE *fp) {
    int c;
    if (fp == NULL) {
        puts("path ERROR");
    }
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
    fclose(fp);
}

void whireFile(FILE *fp, char path[], char str[]) {
    fp = fopen(path, "a");
    if (fp == NULL) {
        puts("path ERROR");
    }
    fputs(str, fp);
    fclose(fp);
}