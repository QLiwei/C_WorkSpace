/**
 * @file 07_character_input_and_output.c
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
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);
void display(char ch, int lines, int width);
long get_long(void);
double sum_squares(long a, long b);
bool bad_limits(long begin, long end, long low, long high);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main(void) {
/**
 * @brief echo
 *  用户输入的字符被收集并存储在一个被称为缓冲区（buffer）的临时存储区，按下enter键后，程序才
 * 可以使用输入的字符
 *
 * 为什么要有缓冲区？首先，把若干字符作为一个块进行传输比逐个发送这些字符节约时间。
 *  其次，如果用户打错字符，可以直接通过键盘修正错误，当最后按下enter键时，传输的是正确的输入
 *
 * stdin流表示键盘输入
 * stdout流表示屏幕输出
 * EOF符号标志文件结尾(^Z)
 */
#if 0
    char ch;

    while ((ch = getchar()) != '#') {
        putchar(ch);
    }

#endif
#if 0
    char ch;

    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }
#endif

/**
 * @brief 重定向
 * 重定向输入  <
 * 重定向输出  >
 *
 */
#if 0
    int ch;
    int rows, cols;

    printf("Enter a character an two integers:\n");
    while ((ch = getchar()) != '\n') {
        if (scanf("%d %d", &rows, &cols) != 2) {
            break;
        }
        display(ch, rows, cols);
        while (getchar() != '\n') {
            continue;
        }
        printf("Enter another character and tow integers;\n");
        printf("Enter a newline to quit.\n");
    }
    printf("Bye.\n");

#endif

/**
 * @brief 输入验证
 *
 */
#if 0
    const long MIN = -10000000L;  // 范围的下限
    const long MAX = +10000000L;  // 范围的上限

    long start;  // 用户指定的范围最小值
    long stop;   // 用户指定的范围最大值
    double answer;

    printf(
        "This program computes the sum of the squares of "
        "integers in a range.\n The lower bound should not "
        "be less than -10000000 and\nthe upper bound "
        "should not be more than +10000000.\nEnter the "
        "limits (enter 0 for both limits to quit):\n"
        "lower limit: ");
    start = get_long();
    printf("upper limit: ");
    stop = get_long();
    while (start != 0 || stop != 0) {
        if (bad_limits(start, stop, MIN, MAX)) {
            printf("Please try again.\n");
        } else {
            answer = sum_squares(start, stop);
            printf("The sum of the squares of the integers ");
            printf("from %ld to %ld is %g\n", start, stop, answer);
        }
        printf(
            "Enter the limits (enter 0 for both "
            "limits to quit):\n");
        printf("lower limit: ");
        start = get_long();
        printf("upper limit: ");
        stop = get_long();
    }
    printf("Done.\n");

#endif
/**
 * @brief menuette 菜单程序
 *  Enter the letter of your choice:
 *  a. advice       b. bell
 *  c. coumt        q. quit
 */
#if 1
    int choice;

    while ((choice = get_choice()) != 'q') {
        switch (choice) {
        case 'a':
            printf("Buy low, sell high.\n");
            break;
        case 'b':
            putchar('\a');
            break;
        case 'c':
            count();
            break;

        default:
            printf("Program error!\n");
            break;
        }
    }

#endif
    return 0;
}

/**
 * @brief Get the choice object
 *
 * @return char
 */
char get_choice(void) {
    int ch;
    printf("Enter the letter of your choice:\n");
    printf("a. advice       b. bell\n");
    printf("c. count        q. quit\n");
    ch = get_first();
    while ((ch < 'a' || ch > 'c') && ch != 'q') {
        printf("Please respond with a, b, c, or q.\n");
        ch = get_first();
    }
    return ch;
}

/**
 * @brief Get the first object
 *
 * @return char
 */
char get_first(void) {
    int ch;
    ch = getchar();
    while (getchar() != '\n') {
        continue;
    }
    return ch;
}

void count(void) {
    int n, i;
    printf("Count how far? Enter an integer:\n");
    n = get_int();
    for (i = 1; i <= n; i++) {
        printf("%d\n", i);
    }
    while (getchar() != '\n') {
        continue;
    }
}

int get_int(void) {
    int input;
    char ch;
    while (scanf("%d", &input) != 1) {
        while ((ch = getchar()) != '\n') {
            putchar(ch);
        }
        printf(" is not integer.\n Please enter an ");
        printf("integer value, such as 25, -178, or 3: ");
    }
    return input;
}

/**
 * @brief 打印 lines * width 的字符
 *
 * @param ch 需要打印的字符
 * @param lines 打印的行数
 * @param width 打印的宽度
 */
void display(char ch, int lines, int width) {
    int row, col;

    for (row = 1; row <= lines; row++) {
        for (col = 1; col <= width; col++) {
            putchar(ch);
        }
        putchar('\n');
    }
}

/**
 * @brief Get the long object
 *
 * @return long
 */
long get_long(void) {
    long input;
    char ch;

    while (scanf("%ld", &input) != 1) {
        while ((ch = getchar()) != '\n') {
            putchar(ch);
        }
        printf(" is not integer.\n Please enter an ");
        printf("integer value, such as 25, -178, or 3: ");
    }
    return input;
}

/**
 * @brief 计算a~b之间的整数平方和
 *
 * @param a
 * @param b
 * @return double a~b之间的整数平方和
 */
double sum_squares(long a, long b) {
    double total = 0;
    long i;

    for (i = a; i <= b; i++) {
        total += (double)i * (double)i;
    }

    return total;
}

/**
 * @brief 验证范围的上下限是否有效
 *
 * @param begin 需要验证范围的开始
 * @param end 需要验证范围的结束
 * @param low 范围下限
 * @param high 范围上限
 * @return true 验证范围的上下限无效效
 * @return false 验证范围的上下限有效
 */
bool bad_limits(long begin, long end, long low, long high) {
    bool not_good = false;
    if (begin > end) {
        printf("%ld isn't smaller than %ld.\n", begin, end);
        not_good = true;
    }
    if (begin < low || end < low) {
        printf("Values must be %ld or greater.\n", low);
        not_good = true;
    }
    if (begin > high || end > high) {
        printf("Values must be %ld or less.\n", high);
        not_good = true;
    }
    return not_good;
}
