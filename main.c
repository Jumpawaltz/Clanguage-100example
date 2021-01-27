#include <stdio.h>
#include <stdlib.h>
struct student {
    int id;
    char name[10];
    int subject1;
    int subject2;
    int subject3;
    int avg;
};

int main(void) {
    struct student stu[5] = {
            {1, "xiaoming",    12, 67, 90},
            {2, "xiaohong",    87, 67, 84},
            {3, "zhangming",   27, 65, 90},
            {4, "wangyanming", 12, 67, 95},
            {5, "lihao",       23, 45, 90},
    };
    char path[100];
    printf("输入文件地址:");
    scanf("%s", &path);

    FILE *fp = fopen(path, "w");
    if (fp == NULL) {
        puts("文件地址有误!");
        return 0;
    }
    for (int i = 0; i < 5; ++i) {
        stu[i].avg = (stu[i].subject1 + stu[i].subject2 + stu[i].subject3) / 3;
        fprintf(fp, "%d\n %s\n %d\n %d\n %d\n %d", stu[i].id, stu[i].name, stu[i].subject1, stu[i].subject2, stu[i].subject3,
                stu[i].avg);
    }
    fclose(fp);
    return 0;
}