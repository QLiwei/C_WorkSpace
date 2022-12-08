/**
 * @file 05_control_statement_loop.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2022-12-07
 *
 * @copyright Copyright (c) 2022
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-12-07     vector       the first version
 *
 */

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include <math.h>
#include <stdio.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
double my_power(double n, int p);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main(void) {
#if 0
    long num;
    long sum = 0L;
    int status;

    printf("Pleace enter an integer to be summed ");
    printf("(q to quit):");
    #if 0
    status = scanf("%ld", &num);  // status scanf 返回成功读取的项数
    while (status == 1) {
        sum = sum + num;
        printf("Pleace enter next integer (q to quit): ");
        status = scanf("%ld", &num);
    }
    #else
    while (scanf("%ld", &num) == 1) {
        sum = sum + num;
        printf("Pleace enter next integer (q to quit): ");
    }
    #endif
    printf("Those integer sum to %ld.\n", sum);
#endif
/**
 * @brief cmpflt 浮点数比较
 *
 */
#if 0
    const double ANSWER = 3.14159;
    double response;

    printf("What is the value of pi?\n");
    scanf("%lf", &response);
    while (fabs(response - ANSWER) > 0.0001) {
        printf("Try again!\n");
        scanf("%lf", &response);
    }
    printf("Close enough!\n");

#endif

/**
 * @brief
 * @note C99 provide stdbool.h header file, Let bool be an alias for _Bool
 *       true and flase are defined as symbolic constants of 0 and 1, respectively
 */
#if 0
    _Bool input_is_good;  // C99 newly increased
    long num;
    long sum = 0L;

    printf("Please enter an integer to be summed ");
    printf("(q to quit): ");
    input_is_good = (scanf("%ld", &num) == 1);
    while (input_is_good) {
        sum = sum + num;
        printf("Please enter next integer (q to quit): ");
        input_is_good = (scanf("%ld", &num) == 1);
    }
    printf("Those integers sum to %ld.\n", sum);
#endif

    /**
     * @brief for loop
     *
     */
#if 0
    int num;

    printf("n   n cubed\n");
    for (num = 1; num <= 6; num++) {
        printf("%5d %5d\n", num, num * num * num);
    }

    char ch;

    for (ch = 'a'; ch <= 'z'; ch++) {
        printf("The ASCII value for %c is %d.\n", ch, ch);
    }
#endif

#if 0
    #define SIZE 10
    #define PAR  72
    int index, score[SIZE];
    int sum = 0;
    float average;

    printf("Enter %d golf scores:\n", SIZE);
    for (index = 0; index < SIZE; index++) {
        scanf("%d", &score[index]);
    }

    printf("The scores read in are as follows:\n");
    for (index = 0; index < SIZE; index++) {
        printf("%5d", score[index]);
    }
    printf("\n");
    for (index = 0; index < SIZE; index++) {
        sum += score[index];
    }
    average = (float)sum / SIZE;
    printf("Sum of scores = %d, average = %.2f\n", sum, average);
    printf("That's a handicap of %.0f.\n", average - PAR);
#endif

#if 1
    double x, xpow;
    int exp;

    printf("Enter a number and the positive integer power");
    printf(" to which\nthe number will be rasied.Enter q");
    printf(" to quit.\n");
    while (scanf("%lf%d", &x, &exp) == 2) {
        xpow = my_power(x, exp);
        printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");

#endif

    return 0;
}

/* Private function implementations ------------------------------------------*/
/**
 * @brief Compute an integer power of a number
 *
 * @param n The number to be raised to the power
 * @param p Degree of power
 * @return double Power calculation results
 */
double my_power(double n, int p) {
    double pow = 1;
    for (int i = 0; i < p; i++) {
        pow *= n;
    }

    return pow;
}