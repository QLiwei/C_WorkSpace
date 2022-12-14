/**
 * @file hotel.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2022-12-14
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes ------------------------------------------------------------------*/
#include "hotel.h"

/* Private includes ----------------------------------------------------------*/
#include <stdio.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/
int menu(void) {
    int code, status;

    printf("\n%s%s\n", STARS, STARS);
    printf("Enter the number of the desired hotel:\n");
    printf("1) Fairfield Arms   2) Hotel Olympic\n");
    printf("3) Chertwothy Plaza 4) The Stookton\n");
    printf("5) quit\n");
    printf("\n%s%s\n", STARS, STARS);

    while ((status = scanf("%d", &code)) != 1 || (code < 1 || code > 5)) {
        if (status != 1) {
            scanf("%*s");  // 处理非整数输入
        }
        printf("Enter an integer from 1 to 5, please.\n");
    }

    return code;
}

int get_nights(void) {
    int nights;

    printf("How mary nights are needed? ");
    while (scanf("%d", &nights) != 1) {
        scanf("%*s");  // 处理非整数输入
        printf("Please enter an integer, such as 2.\n");
    }

    return nights;
}

void show_price(double rate, int nights) {
    int n;
    double total = 0.0;
    double factor = 1.0;

    for (n = 1; n <= nights; n++, factor *= DISCOUNT) {
        total += rate * factor;
    }
    printf("The total cost will be $%0.2f.\n", total);
}