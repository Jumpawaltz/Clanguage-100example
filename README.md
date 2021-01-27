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

## **题目：**有 n个整数，使其前面各数顺序向后移 m 个位置，最后m个数变成最前面的 m 个数。 

```c
#include <stdio.h>

#define length 5

void print_arr(int [], int);

int main(void) {
    int n = 2;
    int arr[length] = {1, 2, 3, 4, 5};
    print_arr(arr, length);
    puts("\n");
    int a[n];
    for (int k = 0; k < n; ++k) {
        a[k] = arr[length - 1 - k];//备份背挤掉的数字;
    }
    for (int i = length - 1; i >= 0; i--) {
        arr[i] = arr[i - 2];//数组移位n;
    }
    for (int j = 0; j < n; ++j) {
        arr[j] = a[2 - 1 - j];//备份的数组存储到arr;
    }
    print_arr(arr, length);
    return 0;
}


void print_arr(int arr[], int len) {
    for (int i = 0; i < len; ++i)
        printf("%d ", arr[i]);
}
```

## **题目：**编写input()和output()函数输入，输出5个学生的数据记录。

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char name[20];
	char sex;
	int age;
}Stu;

void input(Stu *s){
	int i;
	printf("请依次输入每位同学的名字，性别，年龄：\n");
	for(i=0; i<5; i++){
		scanf("%s%s%d", &(s[i].name),&(s[i].sex),&(s[i].age));
		//注意取地址位置！！ 
	}
} 

void output(Stu *s){
	int i;
	printf("五位同学数据记录如下：\n");
	for(i=0; i<5; i++){
		printf("%s  %c  %d\n", s[i].name,s[i].sex,s[i].age);
	}
}
int main() {
	Stu s[5];//注意类型为Stu! 
	input(s);
	output(s);
	return 0;
}
```

## **题目：**输入一个整数，并将其反转后输出。

```c
#include <stdio.h>

int main() {
    int n, reversedNumber = 0, remainder;
    printf("输入一个整数: ");
    scanf("%d", &n);
    while (n != 0) {
        remainder = n % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        n /= 10;
    }
    printf("反转后的整数: %d", reversedNumber);
    return 0;
}
```

## 	**题目：**填空练习（指向指针的指针）。

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[3] = {2, 2, 5};
    int **a;
    for (int i = 0; i < 3; ++i) {
        a = &arr[i];
        printf("%d ", *a);
    }
    return 0;
}
```



## **题目：**找到年龄最大的人，并输出。请找出程序中有什么问题。

```c
#include <stdio.h>
#include <stdlib.h>

struct man {
    char name[12];
    int age;
};
struct man man[3] = {"zhang", 13, "xiao", 14, "wang", 23};

int main() {
    int n = man[0].age;
    for (int i = 0; i < 3; ++i) {
        if (man[i].age > n)
            n = i;
    }
    printf("%d %s",man[n].age,man[n].name);
    return 0;
}
```

## **题目：**海滩上有一堆桃子，五只猴子来分。第一只猴子把这堆桃子平均分为五份，多了一个，这只 猴子把多的一个扔入海中，拿走了一份。第二只猴子把剩下的桃子又平均分成五份，又多了 一个，它同样把多的一个扔入海中，拿走了一份，第三、第四、第五只猴子都是这样做的， 问海滩上原来最少有多少个桃子？

##**题目：**八进制转换为十进制

```c
#include <stdio.h>
#include <math.h>
 
long long convertOctalToDecimal(int octalNumber);
int main()
{
    int octalNumber;
 
    printf("输入一个八进制数: ");
    scanf("%d", &octalNumber);
 
    printf("八进制数 %d  转换为十进制为 %lld", octalNumber, convertOctalToDecimal(octalNumber));
 
    return 0;
}
 
long long convertOctalToDecimal(int octalNumber)
{
    int decimalNumber = 0, i = 0;
 
    while(octalNumber != 0)
    {
        decimalNumber += (octalNumber%10) * pow(8,i);
        ++i;
        octalNumber/=10;
    }
 
    i = 1;
 
    return decimalNumber;
}
```

**题目：**一个偶数总能表示为两个素数之和。

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Isprimer(unsigned int n);

int main() {
    unsigned int n, i;
    do {
        printf("请输入一个偶数:\n");
        scanf("%d", &n);
    } while (n % 2 != 0);
    for (i = 1; i < n; i++)
        printf("n:%d n-1:%d \n", i, n - i);
    if (Isprimer(i) && Isprimer(n - i)) {

    }

    return 0;
}

int Isprimer(unsigned int n) {
    int i;
    if (n < 4)return 1;
    else if (n % 2 == 0)return 0;
    else
        for (i = 3; sqrt(n) + 1 > i; i++)
            if (n % i == 0)return 0;

    return 1;
}
```

## **题目：**判断一个素数能被几个9整除。

```c
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int p,i;
    long int sum=9;
    printf("请输入一个素数:\n");
    scanf("%d",&p);
    for(i=1;;i++)
        if(sum%p==0)break;
        else sum=sum*10+9;
    
    printf("素数%d能整除%d个9组成的数%ld\n",p,i,sum);
    return 0;
}
```

## **题目：**判断一个素数能被几个9整除。

```c
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int p,i;
    long int sum=9;
    printf("请输入一个素数:\n");
    scanf("%d",&p);
    for(i=1;;i++)
        if(sum%p==0)break;//9不是质数,且这个数是可以被9的合数整除的,所以要反过来.
        else sum=sum*10+9;
    
    printf("素数%d能整除%d个9组成的数%ld\n",p,i,sum);
    return 0;
}
```

## **题目：**两个字符串连接程序 。

```c
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
 
char* strconnect(char *str1,char *str2);
 
int main()
{
    char str1[20],str2[20];
    char *str;
    puts("请输入两个字符串，用回车分开:");
    scanf("%s%s", str1, str2);
    str=strconnect(str1,str2);
    puts("连接后的字符串为:");
    puts(str);
    return 0;
}
char* strconnect(char *str1,char *str2)
{
    char*str;
    str=(char*)malloc(strlen(str1)+strlen(str2)+1);
    str[0]='\0';
    strcat(str,str1);
    strcat(str,str2);
    return str;
}
```

## **题目：**回答结果（结构体变量传递）。

```c
#include <stdio.h>

struct student {
    char name[20];
    int age;
};
struct student stu = {
        .name = "xiaoming",
        .age = 23
};

void printINfo(struct student);

int main(void) {
    printINfo(stu);
    return 0;
}

void printINfo(struct student stu) {
    printf("name:%s \nage:%3d", stu.name, stu.age);
}
```

## **题目：**某个公司采用公用电话传递数据，数据是四位的整数，在传递过程中是加密的，加密规则如下： 每位数字都加上5,然后用和除以10的余数代替该数字，再将第一位和第四位交换，第二位和第三位交换。

```c
#include<stdio.h>
#include<stdlib.h>

void swap(int *, int *);

int main() {
    int nun[4] = {1, 2, 3, 4};
    int bak[4];
    for (int i = 0; i < 4; ++i)
        bak[i] = nun[i] + 5;
    for (int j = 0; j < 4; ++j)
        bak[j] = bak[j] % 10;
    swap(&bak[0], &bak[3]);
    swap(&bak[1], &bak[2]);
    for (int k = 0; k < 4; ++k) {
        printf("%d ", bak[k]);
    }
    return 0;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

```

## 题目:利用指针交换数字;

```c
#include<stdio.h>
#include<stdlib.h>

#define M 5
int main()
{
    int a[M]={1,2,3,4,5};
    int i,j,t;
    i=0;j=M-1;
    while(i<j)
    {
        t=*(a+i);
        *(a+i)=*(a+j);
        *(a+j)=t;
        i++;j--;
    }
    for(i=0;i<M;i++) {
        printf("%d\n",*(a+i));
    }
    
}
```

## 获取当前时间和日期并转换为本地时间

```c
#include <stdio.h>
#include <time.h>

int main ()
{
    time_t rawtime; //这是一个适合存储日历时间类型。
    struct tm * timeinfo;//这是一个用来保存时间和日期的结构。
    time ( &rawtime );  //此函数会返回从公元 1970 年1 月1 日的UTC 时间从0 时0 分0 秒算起到现在所经过的秒数。
    timeinfo = localtime ( &rawtime );//获取当前时间和日期并转换为本地时间
    printf ( "当前本地时间为: %s", asctime (timeinfo) );
    return 0;
}
```



## 做10000000次空循环需要的时间为

```c
#include <stdio.h>
#include <time.h>

int main() {
    long i = 10000000L;
    clock_t start, finish;
    double Thetimes;
    printf("做%ld次空循环需要的时间为: ", i);
    start = clock();
    int a = 1;
    while (i--)
        finish = clock();
    Thetimes = (double) (finish - start) / CLOCKS_PER_SEC;//表示一秒钟内CPU运行的时钟周期数，
    printf("%lf 秒", Thetimes);
    return 0;
}
```

## 猜数游戏

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand((unsigned int) time(NULL));
    int v = (rand() & 100 + 1);
    int n;
    printf("请输入一个数字: \n");
    scanf("%d", &n);
    while (v != n) {
        if (n < v) {
            printf("数字小了\n");
            printf("重新输入:");
            scanf("%d", &n);
        } else if (n > v) {
            printf("数字大了\n");
            printf("重新输入:");
            scanf("%d", &n);
        }
    }
    printf("你猜对了\n");
    return 0;
}
```

## **题目：**简单的结构体应用实例。

```c
#include <stdio.h>
#include <stdlib.h>

struct student {
    float age;
    char *tel;
};

int main() {
    char phone[] = "12341234";
    int age = 32;
    struct student stu = {
            .age = age,
            .tel = phone
    };
    printf("%.2f\n", stu.age);
    printf("%s", stu.tel);
    return 0;
}
```

## **题目：**从键盘输入一些字符，逐个把它们送到磁盘上去，直到输入一个#为止。

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char path[100];
    printf("输入地址:");
    scanf("%s", &path);
    FILE *fp = fopen(path, "a");
    char c;
    if (fp == NULL) {
        puts("path 有误");
        return 0;
    }
    while ((c = getchar()) != '#') {
        fputc(c, fp);
    }
    fclose(fp);
    return 0;
}
```

## **题目：**从键盘输入一个字符串，将小写字母全部转换成大写字母，然后输出到一个磁盘文件"test"中保存。 输入的字符串以！结束。

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char path[100];
    printf("输入地址:");
    scanf("%s", &path);
    FILE *fp = fopen(path, "a");
    char c;
    if (fp == NULL) {
        puts("path 有误");
        return 0;
    }
    while ((c = getchar()) != '!') {
        if (c >= 97 && c <= 122)
            fputc(c -= 32, fp);
        else
            fputc(c, fp);
    }
    fclose(fp);
    return 0;
}
```

## **题目：**有两个磁盘文件A和B,各存放一行字母，要求把这两个文件中的信息合并（按字母顺序排列），输出到一个新文件C中。

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE*fa,*fb,*fc;
    int i,j,k;
    char str[100],str1[100];
    char tem;
    if((fa=fopen("A.txt","r"))==NULL) // A.txt 文件需要存在
    {
        printf("error: cannot open A file!\n");
        exit(0);
    }
    fgets(str,99,fa);
    fclose(fa);
    if((fb=fopen("B.txt","r"))==NULL)  // B.txt 文件需要存在
    {
        printf("error: cannot open B file!\n");
        exit(0);
    }
    fgets(str1,100,fb);
    fclose(fb);
    strcat(str,str1);
    for(i=strlen(str)-1;i>1;i--)
        for(j=0;j<i;j++)
            if(str[j]>str[j+1])
            {
                tem=str[j];
                str[j]=str[j+1];
                str[j+1]=tem;
            }
    
    if((fc=fopen("C.txt","w"))==NULL)  // 合并为 C.txt
    {
        printf("error: cannot open C file!\n");
        exit(0);
    }
    fputs(str,fc);
    fclose(fc);
    system("pause");
    return 0;
} 	 	
```

## **题目：**有五个学生，每个学生有3门课的成绩，计算出平均成绩，况原有的数据和计算出的平均分数存放在磁盘文件"stud"中

```c
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
```

