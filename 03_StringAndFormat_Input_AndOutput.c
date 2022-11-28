/**
 * @file 03_StringAndFormat_Input_AndOutput.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2022-11-27
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define DENSITY (62.4)  // 人体密度
#define PRAISE "You are an extraordinary being." //你是一个非凡的人
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main()
{
#if 0
    float weight, volume;
    int size, letters;
    char name[40];

    printf("Hi! What's your first name?\n");
    scanf("%s", name);
    printf("%s, what's your weight in pounds?\n",name);
    scanf("%f", &weight);
    size = sizeof(name);
    letters = strlen(name);
    volume = weight / DENSITY;
    printf("Well, %s, your volums is %2.2f cubic feet.\n", name, volume);
    printf("Also, your first name has %d letters,\n", letters);
#endif

    /**
     * @brief scanf 遇到空格时（空格、制表符、换行符）就不在读取
     *  char = 'x';  字符: x
     *  char = "x";  字符串: x\0
     *
     *  strlen():
     */

#if 0
    char name[40];
    printf("What's your name? ");
    scanf("%s",name);
    printf("Hello, %s. %s\n", name, PRAISE);

    printf("Your name of %d letters occupies %d memory cells.\n", strlen(name), sizeof(name));
    printf("The phrase of praise has %d letters ", strlen(PRAISE));
    printf("and occupies %d memory cells.\n", sizeof(PRAISE));

#endif

    /**
     * @brief constant (quantity)
     *  #define
     *  const :read only
     */
    #define PI 3.1415926
    const char name[20] = "read only";
    printf("PI = %d, name = %s\n", PI, name);


    return 0;
}