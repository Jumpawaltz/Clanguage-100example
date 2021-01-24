# C语言习题100例

[TOC]





---
## 题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            for (int k = 1; k <= 4; ++k) {
                if (i != j && i != k && j != k) {
                    printf("%d %d %d \n", i, j, k);
                }
            }
        }
    }
    return 0;
}

```

## 题目：企业发放的奖金根据利润提成。

   利润(I)低于或等于10万元时，奖金可提10%；
   利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
   20万到40万之间时，高于20万元的部分，可提成5%；   
   40万到60万之间时高于40万元的部分，可提成3%；
   60万到100万之间时，高于60万元的部分，可提成1.5%；
   高于100万元时，超过100万元的部分按1%提成。
   从键盘输入当月利润I，求应发放奖金总数？


```c
#include <stdio.h>

int main() {
    double profit;
    double bonus1, bonus2, bonus4, bonus6, bonus100, bonun = 0;
    bonus1 = 100000 * 0.1;
    bonus2 = bonus1 + 100000 * 0.075;
    bonus4 = bonus2 + 200000 * 0.05;
    bonus6 = bonus4 +200000 * 0.03;
    bonus100 = bonus6 + 400000 * 0.015;
    printf("请输入利润:");
    scanf("%lf", &profit);
    if (profit <=100000) {
        bonun = profit * 0.1;
    } else if (profit <=200000) {
        bonun = bonus1 + (profit - 100000) * 0.075;
    } else if (profit <=400000) {
        bonun = bonus2 + (profit - 200000) * 0.05;
    } else if (profit <=600000) {
        bonun = bonus4 + (profit - 400000) * 0.03;
    } else if (profit <=1000000) {
        bonun = bonus6 + (profit - 600000) * 0.15;
    } else if (profit > 1000000) {
        bonun = bonus100 + (profit - 1000000) * 0.01;
    }
    printf("您的奖金为 %lf", bonun);
    return 0;
}

```

## 题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
```c
#include <stdio.h>
#include <math.h>

int main() {
    long square1, square2;
    for (long i = 0; i < 10000; ++i) {
        square1 = sqrtf(i + 100);
        square2 = sqrtf(i + 100 + 169);
        if ((square1 * square1 == i + 100) && (square2 * square2 == i + 100 + 168)) {
           printf("%d + 100 = %d * %d \n",i,square1,square1);
           printf("%d + 268= %d * %d \n",i,square2,square2);
        }
    }
    return 0;
}

```
## 输入某年某月某日，判断这一天是这一年的第几天？
```c
#include <stdio.h>
#include <math.h>

int main() {
    printf("请输入年 月 日 例如:2000 11 10\n");
    int year, month, day, sum;
    scanf("%d %d %d", &year, &month, &day);
    int allMonth[11] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        allMonth[1] = 29;
    } else {
        allMonth[1] = 28;
    }
    for (int i = 0; i < month; ++i) {
        sum = sum + allMonth[i];
    }
    sum += day;
    printf("%d年%d月%d日 共有%d天", year, month, day,sum);
    return 0;
}

```

## 题目：输入三个整数x,y,z，请把这三个数由小到大输出
```c
#include <stdio.h>

int main() {
    int x, y, z, t;
    printf("\n请输入三个数字:\n");
    scanf("%d%d%d", &x, &y, &z);
    if (x > y) { 
        t = x;
        x = y;
        y = t;
    }
    if (x > z) { 
        t = z;
        z = x;
        x = t;
    }
    if (y > z) { 
        t = y;
        y = z;
        z = t;
    }
    printf("从小到大排序: %d %d %d\n", x, y, z);
}
```

## 题目：用*号输出字母C的图案。
```c
#include <stdio.h>

int main() {
    printf("*****\n");
    printf("*\n");
    printf("*\n");
    printf("*\n");
    printf("*****");
    return 0;
}
```

## 题目：输出9*9口诀。
```c
#include<stdio.h>

int main() {
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("%d*%d=%-3d", i, j, i * j);
        }
       printf("\n");
    }
    return 0;
}
```

## 题目：输出特殊图案，请在c环境中运行，看一看，Very Beautiful!
```c
#include<stdio.h>

int main() {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++)
            if ((i + j) % 2 == 0)
                printf("x");
            else
                printf("  ");
        printf("\n");
    }
    return 0;
}
```

## 变长参数
```c
#include <stdio.h>
#include <stdarg.h>

int add(int, ...);


int main() {
    int a = add(6, 234, 23, 423, 42, 342, 234);
    printf("%d",add(3,3,1,4));
    return 0;
}

int add(int n, ...) {
    va_list vl;
    int result=0;
    va_start(vl, n);
    for (int i = 0; i < n; i++)
        result += va_arg(vl, int);
    va_end(vl);
    return result;
}
```
## 题目：古典问题（兔子生崽）：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？（输出前40个月即可）
[题解](https://blog.csdn.net/SakuraA6/article/details/105927931?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-5.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-5.control)
 ```c
#include<stdio.h>

int main() {
    int f1 = 1, f2 = 1, i;
    for (i = 1; i <= 20; i++) {
        printf("%12d%12d", f1, f2);
        if (i % 2 == 0) printf("\n");
        f1 = f1 + f2;
        f2 = f1 + f2;
    }

    return 0;
}
 ```

## 题目：判断101到200之间的素数。
```c
#include <stdio.h>

int main() {
    int i, j;
    for (i = 101; i <= 200; i++) {
        for (j = 2; j < i; j++) {
            if (i % j == 0)          //只要除到一个数让 i 能被整除就跳出该循环。
                break;
            else {
                if (j == i - 1)          //除完最后一个数后还不跳出循环，就可以判断该数为素数。
                    printf("%d ", i);
            }
        }
    }
    return 0;
}
```
## 判断素数
```c
#include <stdio.h>

int main() {
    int a;
    printf("请输入一个数:");
    scanf("%d", &a);
    for (int i = 2; i < a; ++i) {
        if (a % i == 0) {
            int s = a % i;
            printf("他是合数:%d %% %d == %d", a, i, s);
            break;
        } else {
            if (i == a - 1) {
                printf("他是素数:%d", a);
            }
        }
    }
    return 0;
}
```

## ** 题目：**打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数 本身。例如：153是一个"水仙花数"，因为153=1的三次方＋5的三次方＋3的三次方。

```c
#include <stdio.h>

int main() {
    for (int i = 100; i < 1000; i++) {
        int x = i / 100;
        int y = i % 100 / 10;
        int z = i % 100 % 10;
        if (i == ((x * x * x) + (y * y * y) + (z * z * z))) {
            printf("%d \t", i);
        }
    }
    return 0;
}
```

## 拆分数字将1 2 3,倒序321输出

```c
#include <stdio.h>

int main() {
    int a = 123;
    int x = a / 100;
    int y = a % 100 / 10;
    int z = a % 100 % 10;
    printf("%d %d %d ", z, y, x);
    return 0;
}
```

## **题目：**将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5。

```c
#include <stdio.h>

int main() {
    int n;
    printf("输入一个数字\n");
    scanf("%d", &n);
    printf("%d = ", n);
    for (int i = 2; i < n; ++i) {
        while (n != i) {
            if (n % i == 0) {
                printf("%d*", i);
                n /= i;
            } else
                break;
        }
    }
    printf("%d", n);
    return 0;
}
```

## **题目：**利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60-89分之间的用B表示，60分以下的用C表示。

```c
#include <stdio.h>

int main() {
    int score;
    char grade;
    printf("请输入分数:");
    scanf("%d", &score);
    grade = score > 60 ? score >= 90 ? 'A' : 'B' : 'C';
    printf("%c\n", grade);
    return 0;
}
```

## **题目：**输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。

```c
#include <stdio.h>

int main() {
    int Letters = 0, blank = 0, number = 0, other = 0;
    char str;
    printf("请输入字符:\n");
    while ((str = getchar()) != '\n') {
        if ((str <= 'Z' && str >= 'A') || (str >= 'a' && str <= 'z')) {
            Letters++;
        } else if (str == ' ') {
            blank++;
        } else if (str >= '0' && str <= '9') {
            number++;
        } else
            other++;
    }
    printf("letters:%d number:%d blank:%d other:%d", Letters, number, blank, other);
    return 0;
}
```

## **题目：**求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字。例如2+22+222+2222+22222(此时共有5个数相加)，几个数相加有键盘控制。

```c
#include <stdio.h>

int main() {
    int init;
    int n;
    int result;
    printf("请输入数字:");
    scanf("%d %d", &init, &n);
    int fixed = init;
    while (n != 0) {
        result += init;
        init = init * 10 + fixed;
        n--;
    }
    printf("result=%d ", result);
    return 0;
}
```

## **题目：**一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？

```c
#include <stdio.h>

int main() {
    float s, h;
    s = h = 100.0;
    h = h / 2;//第一次反弹高度
    for (int i = 2; i <= 10; i++) {
        s = s + (2 * h);
        h = h / 2;
    }

    printf("十次反弹共经过%fm,\n第十次反弹: %f", s, h);
    return 0;
}
```

## **题目：**两个乒乓球队进行比赛，各出三人。甲队为a,b,c三人，乙队为x,y,z三人。已抽签决定比赛名单。有人向队员打听比赛的名单。a说他不和x比，c说他不和x,z比，请编程序找出三队赛手的名单。

```c
#include <stdio.h>

int main() {
    for (char i = 'x'; i <= 'z'; ++i) {
        for (char j = 'x'; j <= 'z'; ++j)
            if (i != j)
                for (char k = 'x'; k <= 'z'; ++k) {
                    if (i != k && j != k) {
                        if (i != 'x' && k != 'x' && k != 'z')
                            printf("对决名单:a-%c b-%c c-%c", i, j, k);
                    }
                }
    }
    return 0;
}
```

## **题目：**打印出如下图案（菱形）。

```c
#include <stdio.h>

int main() {
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 2 - i; j++)
            printf(" ");
        for (int k = 0; k <= 2 * i; k++)
            printf("*");
        printf("\n");
    }
    for (int l = 0; l <= 2; ++l) {
        for (int i = 0; i <= l; ++i) {
            printf(" ");
        }
        for (int k = 0; k <= 4 - 2 * l; k++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
```

## **题目：**有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。

```c
#include <stdio.h>

int main() {
    float sum = 0;
    int x, y;
    float a = 2, b = 1;
    for (x = 1; x <= 20; ++x) {
        sum = sum + a / b;
        y = a;
        a = a + b;
        b = y;
    }
    printf("%9.6f\n", sum);
}
```

## **题目：**求1+2!+3!+...+20!的和。

```c
#include <stdio.h>
 
int main()
{
    int i;
    long double sum,mix;
    sum=0,mix=1;
    for(i=1;i<=20;i++)
    {
        mix=mix*i;
        sum=sum+mix;
    }  
    printf("%Lf\n",sum);  
}
```

## **题目：**利用递归方法求5!

```c
#include <stdio.h>

int fact(int);

int main() {
    for (int i = 0; i <= 5; ++i) {
        printf("!%d=%d\n", i, fact(i));
    }
}

int fact(int j) {
    int sum;
    if (j == 0)return 1;
    else sum = j * fact(j - 1);
    return sum;
}
```

## **题目：**给一个不多于5位的正整数，要求：一、求它是几位数，二、逆序打印出各位数字。

```c
	#include <stdio.h>

int main() {
    int length;
    int n = 12312;
    int a = n / 10000;
    int b = n % 10000 / 1000;
    int c = n % 1000 / 100;
    int d = n % 100 / 10;
    int e = n % 10;
    if (a != 0)
        length = 5;
    else if (b != 0)
        length = 4;
    else if (c != 0)
        length = 3;
    else if (d != 0)
        length = 2;
    else if (e != 0)
        length = 1;
    else
        length = 0;
    printf("长度为:%d \n", length);
    printf("%d %d %d %d %d ", e, d, c, b, a);
    return 0;
}
```

## **题目：**一个5位数，判断它是不是回文数。即12321是回文数，个位与万位相同，十位与千位相同。

```c
#include <stdio.h>

int main() {
    int n = 12321;
    int a = n / 10000;
    int b = n % 10000 / 1000;
    int c = n % 1000 / 100;
    int d = n % 100 / 10;
    int e = n % 10;
    if (a == e && d == b)
        puts("是回文数");
    else
        puts("不是回文数");
    return 0;
}
```

## **题目：**请输入星期几的第一个字母来判断一下是星期几，如果第一个字母一样，则继续判断第二个字母。



<details>  撒大声地所    </details>

```C

    char i,j;
    printf("请输入
        case 'f':
            printf("friday\n");
            break;
        case 't':
            printf("请输入下一个字母\n");
            scanf("%c",&j);
            if (j=='u') {printf("tuesday\n");break;}
            if (j=='h') {printf("thursday\n");break;}
        case 's':
            printf("请输入下一个字母\n");
            scanf("%c",&j);
            if (j=='a') {printf("saturday\n");break;}
            if (j=='u') {printf("sunday\n"); break;}
        default :
            printf("error\n"); break;
    }
    return 0;
}
```

## **题目：**字符串删除指定字符🤪🤪🤪🤪🤪

```c
#include<stdio.h>

int main() {
    char s[80] = "abcdefg", c = 'd';
    int j, k;
    for (j = k = 0; s[j] != '\0'; j++)
        if (s[j] != c) {
//            printf("s[j] = %c\n", s[j]);
//            printf("\tk=%d j=%d\n", k,j);
            s[k++] = s[j];
        }
    s[k] = '\0';
    printf("%s", s);
    return 0;
}
```

## 输出斐波那契数列

## **题目：**判断一个数字是否为质数。

```c
#include<stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    for (int i = 2; i < a; ++i) {
        if (a % i == 0) {
            puts("他不是一个素数");
            break;
        } else if (i == a - 1)
            printf("他是一个素数");
    }
    return 0;
}
```

## 题目:使用函数调用

```c
#include<stdio.h>
#include <stdbool.h>

_Bool judge(int);

int main() {
    for (int i = 1; i <= 20; ++i) {
        _Bool a = judge(i);
        if (a) {
            printf("%d ", i);
        }


    }
    return 0;
}

_Bool judge(int a) {
    if (a % 2 == 0) {
        return true;
    } else {
        return false;
    }
}
```

## 字符串反转，如将字符串 "www.runoob.com" 反转为 "moc.boonur.www"。

```c
#include<stdio.h>

#define length 14

int main() {
    char str[length] = "www.runoob.com";
    for (int i = 0; i < length / 2; ++i) {
        char c = str[length - i - 1];
        str[length - i - 1] = str[i];
        str[i] = c;
    }
    for (int i = 0; i < length; ++i) {
        printf("%c", str[i]);
    }
    return 0;
}


```

## **题目：**求100之内的素数。

```c
#include<stdio.h>

int main() {
    int i, j;
    for (i = 2; i <= 100; i++) {
        for (j = 2; j < i; j++)
            if (i % j == 0)
                break;
        if (j == i)
            printf("%d ", i);
    }
    return 0;
}
```

## **题目：**对10个数进行排序。

```c
#include<stdio.h>

int main() {
    int arr[10] = {3, 8, 1, 6, 5, 4, 7, 2, 9, 0};
    for (int i = 0; i < 10 - 1; ++i) {
        for (int j = 0; j < 10 - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
    for (int k = 0; k < 10; ++k) {
        printf("%d ", arr[k]);

    }
    return 0;
}
```

## **题目：**求一个3*3矩阵对角线元素之和

```c
#include<stdio.h>

int main() {
    int result=0;
    int result1=0;
    int arr[3][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};
    for (int i = 0; i < 3; ++i) {
        result += arr[i][i];
        result1 += arr[i][2 - i];
    }
    printf("%d %d ", result, result1);
    return 0;
}
```

## **题目：**有一个已经排好序的数组。现输入一个数，要求按原来的规律将它插入数组中。

## **题目：**将一个数组逆序输出。

```c
#include<stdio.h>

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    for (int j = 0; j < 10; ++j) {
        printf("%d ",arr[10-1-j]);
    }
    return 0;
}
```

##  **题目：**学习static定义静态变量的用法。

```c
#include<stdio.h>

void aa();

int main() {
    for (int i = 0; i < 5; ++i)
        aa();

    return 0;
}

void aa(void) {
    static int a = 1;
    int b = 2;
    printf("static:%d ", a);
    printf("b:%d\n", b);
    a++, b++;
}
```

​	

## **题目：**宏#define命令练习。

```c
#include<stdio.h>

#define a "123"
#define A "ABCD"
#define TRUE 1
#define FALSE 0
#define x(x)(x)*(x)

int main() {
    puts(a);
    puts(A);
    printf("%d", x(9));
    return 0;
}
```

## **题目：**学习使用按位与 &

```c
#include<stdio.h>

int main() {
    int a = 7;
    int b = 3;
    int c = 8;
    printf("%d ",a&b);
    printf("%d ",a&c);
    return 0;
}
```

## **题目：**学习使用按位或 |。



```c
#include<stdio.h>

int main() {
    int a = 7;
    int b = 3;
    int c = 8;
    printf("%d ",a|b);
    printf("%d ",a|c);
    return 0;
}
```

## **题目：**学习使用按位取反~。

## **题目：**打印出杨辉三角形（要求打印出10行）。

```c
#include <stdio.h>

int main() {
    int arr[10][10] = {0};
    for (int i = 1; i < 10; ++i) {
        for (int j = 2; j < 10; ++j) {
            for (int k = 0; k < j; ++k) {
                arr[j][k] = arr[j - 1][k - 1] + arr[j - 1][k];
            }
        }
        arr[i][0] = 1;
        arr[i][i - 1] = 1;
        putchar('\n');
    }
    for (int k = 0; k < 10; ++k) {
        for (int i = 0; i < k; ++i) {
            printf("%2d ", arr[k][i]);
        }
        putchar('\n');
    }
    return 0;
}
```

## **题目：**输入3个数a,b,c，按大小顺序输出。

```c
#include <stdio.h>

void swap(int *, int *);d

int main(void) {
    int a, b, c;
    printf("输入 a, b ,c:\n");
    scanf("%d %d %d", &a, &b, &c);
    int *x = &a;
    int *y = &b;
    int *z = &c;
    if (a > b)
        swap(x, y);
    if (a > c)
        swap(x, z);
    if (b > c)
        swap(y, z);
    printf("%d %d %d ", a, b, c);
    return 0;
}

void swap(int *a, int *b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
```

## **题目：**输入数组，最大的与第一个元素交换，最小的与最后一个元素交换，输出数组。

```c
#include <stdio.h>

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int i, j, n, a[50];
	int  max, min, max_index, min_index;
	printf("请输入数组个数：");
	scanf("%d",&n); 
	printf("请依次输入数组：\n");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
		

//找出最大的元素下标max_index 
	max = a[0];//哨兵 
	for(i=1; i<n; i++){
		if(max < a[i]){
			max = a[i];
			max_index = i;
		}
	}
	if(max != a[0])
		swap(&a[0], &a[max_index]);
		
//找出最小的元素下标min_index 		
	min = a[n-1];//哨兵	
	for(j=0; j<n-1; j++){
		if(min > a[j]){
			min = a[j];
			min_index = j;
		}
	}
	if(min != a[n-1])
		swap(&a[n-1], &a[min_index]);
	
	printf("处理后：\n");
	for(i=0; i<n; i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;	
}
```

