/**
 * @file 08_function.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2022-12-13
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include <ctype.h>
#include <math.h>
#include <stdbool.h>  // _Bool bool
#include <stdio.h>
#include <string.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define NAME    "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE   "Megapolis, CA 94904"
#define WIDTH   40
#define SPACE   ' '
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void starbar(void);
void show_n_char(char ch, int num);
void up_and_down(int n);
long fact(int n);
long rfact(int n);
void to_binary(unsigned long n);
void mikado(int bah);
unsigned long fibonacci(unsigned long n);
void interchange(int *u, int *v);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main(void) {
#if 0
    starbar();
    printf("%s\n", NAME);
    printf("%s\n", ADDRESS);
    printf("%s\n", PLACE);
    starbar();
#endif

#if 0
    int spaces;

    show_n_char('*', WIDTH);
    putchar('\n');

    show_n_char(SPACE, 12);
    printf("%s\n", NAME);

    spaces = (WIDTH - strlen(ADDRESS)) / 2;
    show_n_char(SPACE, spaces);
    printf("%s\n", ADDRESS);

    show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);
    printf("%s\n", PLACE);

    show_n_char('*', WIDTH);
    putchar('\n');

#endif
    /**
     * @brief 实际参数和形式参数
     *  实际参数是出现在函数调用圆括号中的表达式，形式参数是函数定义的函数头中声明的变量。
     *
     */

    /**
     * @brief 递归
     *
     */
#if 0
    /*
        Level 1: n location 000000000061FE00
        Level 2: n location 000000000061FDD0
        Level 3: n location 000000000061FDA0
        Level 4: n location 000000000061FD70
        LEVEL 4: n location 000000000061FD70
        LEVEL 3: n location 000000000061FDA0
        LEVEL 2: n location 000000000061FDD0
        LEVEL 1: n location 000000000061FE00
    */
    up_and_down(1);
#endif
    /**
     * @brief 尾递归
     *  求阶乘 循环&递归
     *
     */
#if 0
    int num;

    printf("This program calculates factorials.\n");
    printf("Enter a value in the range 0-12 (q to quit):\n");
    while (scanf("%d", &num) == 1) {
        if (num < 0) {
            printf("No negative numbers, please.\n");
        } else if (num > 12) {
            printf("Keep input under 13.\n");
        } else {
            printf("loop:%d factorial = %ld\n", num, fact(num));
            printf("recursion: %d factorial = %ld\n", num, rfact(num));
        }
        printf("Enter a value in the range 0-12 (q to quit):\n");
    }
    printf("Bye.\n");

#endif
/**
 * @brief binary 以二进制形式打印整数
 *
 */
#if 0
    unsigned long number;
    printf("Enter an integer (q to quit):\n");
    while (scanf("%lu", &number) == 1) {
        printf("Binary equivlent: ");
        to_binary(number);
        putchar('\n');
        printf("Enter an integer (q to quit):\n");
    }
    printf("Done.\n");

#endif
/**
 * @brief 求斐波那契数列
 *
 */
#if 0
    unsigned long number;
    printf("Enter an integer (q to quit):\n");
    while (scanf("%ld", &number) == 1) {
        printf("fibonacci sequence : %ld\n", fibonacci(number));
        printf("Enter an integer (q to quit):\n");
    }
    printf("Done.\n");
#endif
    /**
     * @brief &运算符 *运算符
     *  指针（pointer）用于存储变量的地址，主调函数使用return返回的值，则必须通过地址
     * 才能修改主调函数中的值。
     *  (&) 取地址
     * （*）解引用
     */
#if 0
    int pooh = 2, bah = 5;

    printf("In main(), pooh = %d and &pooh = %p\n", pooh, &pooh);
    printf("In main(), bah = %d and &bah = %p\n", bah, &bah);

    mikado(bah);
#endif
    int x = 10, y = 11;
    printf("Originally x = %d and y = %d.\n", x, y);
    interchange(&x, &y);
    printf("Now x = %d and y = %d.\n", x, y);
    return 0;
}

/**
 * @brief 交互两个变量的值
 *
 * @param u
 * @param v
 */
void interchange(int *u, int *v) {
    int temp;
    temp = *u;
    *u = *v;
    *v = temp;
}

void mikado(int bah) {
    int pooh = 10;

    printf("In mikado(), pooh = %d and &pooh = %p\n", pooh, &pooh);
    printf("In mikado(), bah = %d and &bah = %p\n", bah, &bah);
}

/**
 * @brief 斐波那契数列
 *
 * @param n 第n项
 * @return unsigned long
 */
unsigned long fibonacci(unsigned long n) {
    if (n > 2) {
        return fibonacci(n - 1) + fibonacci(n - 2);
    } else {
        return 1;
    }
}

/**
 * @brief 将十进制数转化为二进制数输出
 *
 */
void to_binary(unsigned long n) {
    int r;

    r = n % 2;
    if (n >= 2) {
        to_binary(n / 2);
    }
    putchar(r == 0 ? '0' : '1');
    return;
}

/**
 * @brief 求阶乘 循环方式
 *
 * @param n
 * @return long
 */
long fact(int n) {
    long answer;

    for (answer = 1; n > 1; n--) {
        answer *= n;
    }

    return answer;
}

/**
 * @brief 求阶乘 递归方式
 *
 * @param n
 * @return long
 */
long rfact(int n) {
    long answer;
    if (n > 0) {
        answer = n * rfact(n - 1);
    } else {
        answer = 1;
    }
    return answer;
}

/**
 * @brief
 *
 * @param n
 */
void up_and_down(int n) {
    printf("Level %d: n location %p\n", n, &n);
    if (n < 4) {
        up_and_down(n + 1);
    }
    printf("LEVEL %d: n location %p\n", n, &n);
}

/**
 * @brief 打印星号
 *
 */
void starbar(void) {
    int count;

    for (count = 1; count <= WIDTH; count++) {
        putchar('*');
    }
    putchar('\n');
}

/**
 * @brief Print n characters
 *
 * @param ch A printed character
 * @param num Number of prints
 */
void show_n_char(char ch, int num) {
    for (int i = 0; i < num; i++) {
        putchar(ch);
    }
}