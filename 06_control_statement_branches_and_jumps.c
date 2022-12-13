/**
 * @file 06_control_statement_branches_and_jumps.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2022-12-08
 *
 * @copyright Copyright (c) 2022
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-12-08     vector       the first version
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
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main(void) {
/**
 * @brief colddays 找出0`C以下的天气占总天数的百分比
 *
 */
#if 0
    const int FREEZING = 0;
    float temperature;
    int cold_days = 0;
    int all_days = 0;

    printf("Enter the list of daily low temperatures.\n");
    printf("Use Celsius, and enter q to quit.\n");  // celsius 摄氏度
    while (scanf("%f", &temperature) == 1) {
        all_days++;
        if (temperature < FREEZING) {
            cold_days++;
        }
    }
    if (all_days != 0) {
        printf("%d days total:%.1f%% were below freezing.\n", all_days, 100.0 * (float)cold_days / all_days);
    } else {
        printf("No data entered!\n");
    }
#endif
    /**
     * @brief getchar() putchar()
     * @note getchar() 函数不带任何参数，他从输入队列中返回下一个字符
     *         eg. ch = getchar(); <-> scanf("%c", &ch);
     *       putchar() 函数打印参数
     *              putchar(ch); <-> printf("%c",ch);
     *      #include <stdio.h> 只能处理字符
     *
     */
#if 0
    char ch;

    ch = getchar();
    while (ch != '\n') {
        if (ch == ' ') {
            putchar(ch);
        } else {
            putchar(ch + 1);
        }

        ch = getchar();
    }
    putchar(ch);
#endif

/**
 * @brief ctype.h header file
 * @note 处理字符的库函数
 *      isalnum()   字符数字->true
 *      isalpha()   字母
 *      isblank()   标准空白字符（空格、水平制表符或换行符）或任何其他本地化指定为空白的字符
 *      iscntrl()   控制字符 eg. Ctrl+B
 *      isdigit()   数字
 *      isgraph()   除空格之外的任意可打印字符
 *      islower()   小写字母
 *      isprint()   可打印字符
 *      ispunct()   标点符号（除空格或字母数字字符以外的任何可打印字符）
 *      isspace()   空白字符
 *      isupper()   大小字母
 *      isxdigit()  十六进制数字符
 *          字符映射函数
 *      tolower()   如果参数是大写字符，该函数返回小写字符；否则，返回原始参数
 *      toupper()   如果参数是小写字符，该函数返回大写字符；否则，返回原始参数
 */
#if 0
    char ch;

    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) {
            putchar(ch + 1);
        } else {
            putchar(ch);
        }
    }
    putchar(ch);
#endif
    /**
     * @brief electric 计算电费
     *  首 360kWh:      $0.13230/kWh
     *  续 108kWh:      $0.15040/kWh
     *  续 252kWh:      $0.30025/kWh
     *  超过 720kWh:    $0.34025/kWh
     */
#if 0
    #define RATE1  0.13230
    #define RATE2  0.15040
    #define RATE3  0.30025
    #define RATE4  0.34025
    #define BREAK1 360.0
    #define BREAK2 468.0
    #define BREAK3 720.0
    // 使用360kWh的费用
    #define BASE1  (RATE1 * BREAK1)
    // 使用468kWh的费用
    #define BASE2  (BASE1 + (RATE2 * (BREAK2 - BREAK1)))
    // 使用720kWh的费用
    #define BASE3  (BASE2 + (RATE3 * (BREAK3 - BREAK2)))

    double kWh;
    double bill;

    printf("Please enter the kWh used.\n");
    scanf("%lf", &kWh);
    if (kWh <= BREAK1) {
        bill = RATE1 * kWh;
    } else if (kWh <= BREAK2) {
        bill = BASE1 + (RATE2 * (kWh - BREAK1));
    } else if (kWh <= BREAK3) {
        bill = BASE2 + (RATE3 * (kWh - BREAK2));
    } else {
        bill = BASE3 + (RATE4 * (kWh - BREAK3));
    }

    printf("The charge for %.1f kWh is $%1.2f.\n", kWh, bill);
#endif
    /**
     * @brief 求约数
     *
     */
#if 0
    int num;
    int div;
    while (scanf("%d", &num) == 1) {
        for (div = 2; (div * div) <= num; div++) {
            if (num % div == 0) {
                if (div * div != num) {
                    printf("%d is divisible by %d and %d.\n", num, div, num / div);
                } else {
                    printf("%d is divisible by %d.\n", num, div);
                }
            }
        }
    }
#endif
#if 0
    unsigned long num;
    unsigned long div;
    bool isPrime;  // #include <stdbool.h>

    printf("Please enter an integer for analysis; ");
    printf("Enter q to quit.\n");

    while (scanf("%lu", &num) == 1) {
        for (div = 2, isPrime = true; (div * div) <= num; div++) {
            if (num % div == 0) {
                if (div * div != num) {
                    printf("%lu is divisible by %lu and %lu.\n", num, div, num / div);
                } else {
                    printf("%lu is divisible by %lu.\n", num, div);
                }
                isPrime = false;
            }
        }

        if (isPrime) {
            printf("%lu is prime.\n", num);
        }
        printf("Plese enter another integer for analysis; ");
        printf("Enter q to quit.\n");
    }
    printf("Bye.\n");

#endif

#if 0
    #define PERIOD '.'
    char ch;
    int char_count = 0;

    while ((ch = getchar()) != PERIOD) {
        if (ch != '"' && ch != '\'') {
            char_count++;
        }
    }
    printf("There are %d non-quote characters.\n", char_count);

#endif

#if 0
    #define STOP '|'
    char ch;
    char prev;
    long n_chars = 0L;
    int n_lines = 0;
    int n_words = 0;
    int p_lines = 0;  // 不完整的行数
    bool inword = false;

    printf("Enter text to be analyzed (| to terminate):\n");
    prev = '\n';  // 用于识别完整行
    while ((ch = getchar()) != STOP) {
        n_chars++;
        if (ch == '\n') {
            n_lines++;
        }

        if (!isspace(ch) && !inword) {
            inword = true;  // 开始一个新的单词
            n_words++;
        }
        if (isspace(ch) && inword) {
            inword = false;
        }

        prev = ch;  // 保存字符的值
    }

    if (prev != '\n') {
        p_lines = 1;
    }

    printf("characters = %ld, words = %d, lines = %d, ", n_chars, n_words, n_lines);

    printf("partial lines = %d\n", p_lines);

#endif
    /**
     * @brief 条件运算符
     *   expression1 ? expression2 : expression2
     *
     */
#if 0
    #define COVERAGE 350  // 每灌油漆可刷的面积 （单位：平方英尺）

    int sq_feet;
    int cans;

    printf("Enter number of square feet to be painted:\n");
    while (scanf("%d", &sq_feet) == 1) {
        cans = sq_feet / COVERAGE;
        cans += ((sq_feet % COVERAGE == 0)) ? 0 : 1;
        printf("You need %d %s of paint.\n", cans, cans == 1 ? "can" : "cans");
        printf("Enter next value (q to quit):\n");
    }

#endif
    /**
     * @brief continue语句
     *      在循环语句内，执行到continue语句时，会跳过本次迭代的剩余部分，并开始下一轮迭代
     */

#if 0
    const float MIN = 0.0f;
    const float MAX = 100.0f;

    float score;
    float total = 0.0f;
    int n = 0;
    float min = MAX;
    float max = MIN;

    printf("Enter the first score (q to quit): ");
    while (scanf("%f", &score) == 1) {
        if (score < MIN || score > MAX) {
            printf("%0.1f is an invalid value. Try again: ", score);
            continue;
        }
        printf("Accpting %0.1f:\n", score);
        min = (score < min) ? score : min;
        max = (score > max) ? score : max;
        total += score;
        n++;
        printf("Enter next score (q to quit):");
    }
    if (n > 0) {
        printf("Average of %d scores is %0.1f\n", n, total / n);
        printf("Low = %0.1f, high = %0.1f\n", min, max);
    } else {
        printf("No valid scores were entered.\n");
    }
#endif
/**
 * @brief break语句
 *  程序执行到break语句时，会终止包含他的循环，并继续执行下一个阶段
 */
#if 0
    float length, width;

    printf("Enter the length of the rectangle:\n");
    while (scanf("%f", &length) == 1) {
        printf("Length = %0.2f:\n", length);
        printf("Enter its width:\n");
        if (scanf("%f", &width) != 1) {
            break;
        }
        printf("Width = %0.2f:\n", width);
        printf("Area = %0.2f:\n", length * width);
        printf("Enter the length of the rectangle:\n");
    }
    printf("Done.\n");

#endif
/**
 * @brief switch语句
 *  程序根据expression的值跳转至相应的case标签处，然后，执行剩下的所有语句，除非执行到break语句
 * 进行重定向。expression和case标签都必须是整数值（包括char类型），标签必须是常量或完全由常量组成
 * 的表达式。如果没有case标签与expression的值匹配，控制则转至标由defaul的语句*如果有的话;否则，将
 * 转至执行紧跟在switch语句后面的语句
 */
#if 0
    char ch;
    printf("Give me a letter of the alphabet, and I will give ");
    printf("an animal name\nbeginning with that letter.\n");
    printf("Please type in a letter; type # to end my act.\n");
    while ((ch = getchar()) != '#') {
        if ('\n' == ch) {
            continue;
        }
        if (islower(ch)) {
            switch (ch) {
            case 'a':
                printf("argali, a wild sheep of Asia\n");
                break;

            case 'b':
                printf("babirusa, a wild pig of Malay\n");
                break;
            case 'c':
                printf("coati, racoonlike mammal\n");
                break;
            case 'd':
                printf("desman, aquatic, molelike critter\n");
                break;
            case 'e':
                printf("echidna, the apiny anteater\n");
                break;
            case 'f':
                printf("fisher, brownish marten\n");
                break;
            default:
                printf("That's a stumper!\n");
            }
        } else {
            printf("I recognize only lowercase letters.\n");
        }
        while (getchar() != '\n') {
            continue;
        }
        printf("Please type another letter or a #.\n");
    }
    printf("Bye!\n");
#endif
    /**
     * @brief goto 语句
     *
     */
#if 0
    
#endif

    return 0;
}