/**
 * @file use_hotel.c
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

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main(void) {
    int nights;
    double hotel_rate;
    int code;

    while ((code = menu()) != QUIT) {
        switch (code) {
        case 1:
            hotel_rate = HOTEL1;
            break;

        case 2:
            hotel_rate = HOTEL2;
            break;

        case 3:
            hotel_rate = HOTEL3;
            break;

        case 4:
            hotel_rate = HOTEL4;
            break;

        default:
            hotel_rate = 0.0;
            printf("Oops!\n");
            break;
        }
        nights = get_nights();
        show_price(hotel_rate, nights);
    }
    printf("Thanks you and goodbye.\n");

    return 0;
}