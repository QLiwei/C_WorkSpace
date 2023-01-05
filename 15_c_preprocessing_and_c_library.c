/**
 * @file 15_c_preprocessing_and_c_library.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2023-01-05
 *
 * @copyright Copyright (c) 2023
 *
 */

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void sign_off(void);
void too_bad(void);
void fillarray(double ar[], int n);
void showarray(const double ar[], int n);
void show_array(const int ar[], int n);
int mycmp(const void *p1, const void *p2);
double sum(int, ...);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main(int argc, char *argv[]) {
/**
 * @brief #define 明示常量
 *   记号 记号型字符串 字符型字符串
 *   带参宏
 *
 */
#if 0
    // #define SQUARE(X) X * X
    #define SQUARE(X) ((X) * (X))
    #define PR(X)     printf("The result is %d.\n", X);

    int x = 5;
    int z;

    printf("x = %d\n", x);
    z = SQUARE(x);
    printf("Evaluating SQUARE(x):");
    PR(z);
    z = SQUARE(2);
    printf("Evaluating SQUARE(2):");
    PR(z);

    printf("Evaluating SQUARE(2 + x):");
    PR(SQUARE(2 + x));

    printf("Evaluating 100/SQUARE(2):");
    PR(100 / SQUARE(2));

    printf("x is %d.\n", x);
    printf("Evaluating SQUARE(++x):");
    PR(SQUARE(++x));
    printf("After incrementing, x is %x.\n", x);

#endif
/**
 * @brief 用宏参数创建字符串：#运算符
 *
 */
#if 0
    #define PSQR(x) printf("The square of " #x " is %d.\n", ((x) * (x)))

    int y = 5;
    PSQR(y);
    PSQR(2 + 4);
#endif

/**
 * @brief 预处理器粘合剂： ##运算符
 *
 */
#if 0
    #define XNAME(n)    x##n
    #define PRINT_XN(n) printf("x" #n " = %d\n", x##n)

    int XNAME(1) = 14;
    int XNAME(2) = 20;
    int x3 = 30;
    PRINT_XN(1);
    PRINT_XN(2);
    PRINT_XN(3);

#endif
/**
 * @brief 变参宏 ... 和 __VA_ARGS__
 *
 */
#if 0
    #define PR(x, ...) printf("Message " #x ": " __VA_ARGS__)

    double x = 48;
    double y;

    y = sqrt(x);
    PR(1, "x = %g\n", x);
    PR(2, "x = %.2f, y = %.4f\n", x, y);
#endif

/**
 * @brief 文件包含 #include
 *
 * #include <stdio.h>   -> 告诉预处理器在标准系统目录中查找该文件
 * #include "mystuff.h"  -> 告诉预处理器首先在当前目录中查找该文件，如果未找到在查找标准系统目录
 *
 *
 */

/**
 * @brief 其他指令
 *  #undef 用于取消已定义的#define指令
 *
 *  条件编译
 * 1. #ifdef #else #endif指令
 * 2. ifndef
 * 3. #if #elif
 *  预定义宏
 *  __DATE__ 预处理的日期
 *  __FILE__ 表示当前源代码文件名的字符串字面量
 *  __LINE__ 表示当前源代码文件中行号的整型常量
 *  __STDC__ 设置为1，表明实现遵循C标准
 *  __STDC_HOSTED__ 本机环境设置为1；否则设置为0
 *  __STDC_VERSION__ 支持C99标准，设置为199901L 支持C11标准设置为201112L
 *  __TIME__ 翻译代码的时间 格式为 "hh:mm:ss"
 *
 *
 *  #line #error
 *  #line 指令重置__LINE__ 和 __FILE__ 宏报告的行号和文件名
 *  #line 1000 //把当前行号重置为1000
 *  #line 10 "cool.c" // 把行号重置为10 把文件名重置围为cool.c
 *
 * #error 指令让编译器发出一条错误消息
 *  #if __STDC_VERSION__ != 201112L
 *  #error Not C11
 *  #endif
 *
 * #pragma 修改编译器的一些设置
 */

/**
 * @brief 内联函数 C99
 *  inline
 *
 */

/**
 * @brief exit() atexit()
 *
 * atexit() 至少可以放32个函数，执行顺序与列表中的函数相反，最后添加的函数先执行
 */
#if 0
    int n;

    atexit(sign_off); // 注册sign_off()函数
    puts("Enter an integer:");
    if (scanf("%d", &n) != 1) {
        puts("That's no integer!");
        atexit(too_bad);
        exit(EXIT_FAILURE);
    }
    printf("%d is %s.\n", n, (n % 2 == 0) ? "even" : "odd");

#endif

/**
 * @brief qsort()
 *
 */
#if 0
    #define NUM 40

    double vals[NUM];
    fillarray(vals, NUM);
    puts("Rondom list:");
    showarray(vals, NUM);
    qsort(vals, NUM, sizeof(double), mycmp);
    puts("\nSorted list:");
    showarray(vals, NUM);
#endif

/**
 * @brief assert
 *
 */
#if 0
    double x, y, z;

    puts("Enter a pair of number (0 0 to quit): ");
    while (scanf("%lf%lf", &x, &y) == 2 && (x !=0 || y != 0)) {
        z = x * x - y * y;
        assert(z >= 0);
        printf("answer is %f\n", sqrt(z));
        puts("Next pair of number:");
    }
    puts("Done");
#endif

/**
 * @brief memcoy() memmove()
 *
 */
#if 0
    #define SIZE 10
    int values[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target[SIZE];

    double curious[SIZE / 2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30};

    puts("memcpy() used:");
    puts("value (original data): ");
    show_array(values, SIZE);
    memcpy(target, values, SIZE * sizeof(int));
    puts("target (copy of values):");
    show_array(target, SIZE);

    puts("\nUsing memmove() with overlapping ranges:");
    memmove(values + 2, values, 5 * sizeof(int));
    puts("values -- elements 0-4 copied to 2-6");
    show_array(values, SIZE);

    puts("\nUsing memcpy() to copy double to int:");
    memcpy(target, curious, (SIZE / 2) * sizeof(double));
    puts("target -- 5 doubles into 10 int positions:");
    show_array(target, SIZE / 2);
    show_array(target + 5, SIZE / 2);
#endif

/**
 * @brief stdarg.h
 * 可变参
 */
#if 1
    double s, t;

    s = sum(3, 1.1, 2.5, 13.3);
    t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
    printf("return value for"
            "sum(3, 1.1, 2.5, 13.3):                %g\n", s);
    printf("return value for"
            "sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1): %g\n", t);
#endif
    return 0;
}

double sum(int lim, ...) {
    va_list ap;
    double tot = 0;
    int i;

    va_start(ap, lim);
    for (i = 0; i < lim; i++) {
        tot += va_arg(ap, double);
    }
    va_end(ap);

    return tot;
}

/**
 * @brief Show array
 *
 * @param ar array opinter
 * @param n size of the array
 */
void show_array(const int ar[], int n) {
    int index;

    for (index = 0; index < n; index++) {
        printf("%d ", ar[index]);
        if (index % 6 == 5) {
            putchar('\n');
        }
    }
    if (index % 6 != 0) {
        putchar('\n');
    }
}

/**
 * @brief Fill array
 *
 * @param ar array pointer
 * @param n size of the array
 */
void fillarray(double ar[], int n) {
    int index;

    for (index = 0; index < n; index++) {
        ar[index] = (double)rand() / ((double)rand() + 0.1);
    }
}

/**
 * @brief Show array
 *
 * @param ar array opinter
 * @param n size of the array
 */
void showarray(const double ar[], int n) {
    int index;

    for (index = 0; index < n; index++) {
        printf("%9.4f ", ar[index]);
        if (index % 6 == 5) {
            putchar('\n');
        }
    }
    if (index % 6 != 0) {
        putchar('\n');
    }
}

/**
 * @brief In order of smallest to largest
 *
 * @param p1
 * @param p2
 * @return int
 */
int mycmp(const void *p1, const void *p2) {
    const double *a1 = (const double *)p1;
    const double *a2 = (const double *)p2;

    if (*a1 < *a2) {
        return -1;
    } else if (*a1 == *a2) {
        return 0;
    } else {
        return 1;
    }
}

void sign_off(void) {
    puts("Thus terminates another magnificent program from");
    puts("SeeSaw Software!");
}

void too_bad(void) {
    puts("SeeSaw Software extends its heartfelt condolences");
    puts("to you upon the failure of your progrom.");
}