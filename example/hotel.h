/**
 * @file hotel.h
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2022-12-14
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HOTEL_H__
#define __HOTEL_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Private defines -----------------------------------------------------------*/
#define QUIT     5
#define HOTEL1   180.00
#define HOTEL2   225.00
#define HOTEL3   255.00
#define HOTEL4   355.00
#define DISCOUNT 0.95
#define STARS    "*******************************"
/* Exported functions prototypes ---------------------------------------------*/
int menu(void);
int get_nights(void);
void show_price(double rate, int nights);

#ifdef __cplusplus
}
#endif

#endif /* __HOTEL_H__ */