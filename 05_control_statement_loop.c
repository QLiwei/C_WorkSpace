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
    long num;
    long sum = 0L;
    int status;

    printf("Pleace enter an integer to be summed ");
    printf("(q to quit):");
    status = scanf("%ld", &num);  // status scanf 返回成功读取的项数

    while (status == 1) {
        sum = sum + num;
        printf("Pleace enter next integer (q to quit): ");
        status = scanf("%ld", &num);
    }
    printf("Those integer sum to %ld.\n", sum);

    return 0;
}