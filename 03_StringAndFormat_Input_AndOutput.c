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
#define PI (3.1415926)
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
#if 0

    const char name[20] = "read only";
    printf("PI = %d, name = %s\n", PI, name);
#endif

    /**
     * @brief printf()
     * %a %A :浮点数 十六进制
     * %c : 单个字符
     * %d : 有符号的十进制数
     * %e %E : 浮点数 e记法
     * %f : 浮点数 十进制计数法
     * %g %G: 根据值的不同自动选择%f %e\%E %e\%E格式用于指数小于-4或者大于或等于精度时
     * %i : 有符号十进制整数 同%d
     * %o : 无符号八进制整数
     * %p : 指针
     * %s : 字符串
     * %u : 无符号十进制数
     * %x : 无符号十六进制数 0 f
     * %X : 无符号十六进制数 0 F
     * %% ：打印一个百分比号
     *
     * %n.md n：最小字段宽度 m:精度
     * h : %hd: short
     * hh %hhu signed char
     * l: long
     * ll: long long
     * L : long double
     * t:
     * z size_t sizeof 的返回的类型
     * - 左对齐
     * + 值为正显示+ 负显示 -
     * 空格 ：值为正显示空格 负显示 -
     * # ：把结果转化成另一种格式 %o 以0开始 %x %X 以0x 0X 开始
     * 0 : 对数值格式 用前导符 0 代替空格填充字段宽度
     *
     */
#if 0
    int number = 7;
    float pies = 12.75;
    int cost = 7800;

    printf("The %d contestants ate %f betty pies.\n", number, pies); // %d个选手吃了%f个贝蒂派。
    printf("The value of pi is %f.\n", PI);
    printf("Farewell! thou art too dear for my possessing,\n"); //告别!你太珍贵，我无法拥有，
    printf("%c%d\n", '$', 2 * cost);

    const double RENT = 3852.99;
    printf("*%f*\n", RENT);
    printf("*%e*\n", RENT);
    printf("*%4.2f*\n", RENT);
    printf("*%3.1f*\n", RENT);
    printf("*%10.3f*\n", RENT);
    printf("*%10.3E*\n", RENT);
    printf("*%+4.2f*\n", RENT);
    printf("*%010.2f*\n", RENT);

    printf("Here's one way to print a ");
    printf("long strings.\n");
    printf("Here's another way to printf a \
long string.\n");
    printf("Here's the newset way to print a "
            "long string.\n");
#endif

/**
 * @brief scanf()
 * %c : 输入解释成字符
 * %d : 输入解释成有符号的十进制整数
 * %e %f %g %a : 输入解释成浮点数 C99 %a
 * %E %F %G %A : 输入解释成浮点数 C99 %A
 * %i : 输入解释成有符号十进制整数
 * %o : 输入解释成有符号八进制整数
 * %p ：输入解释成指针
 * %s ：输入解释成字符串
 * %u ：输入解释成无符号的十进制整数
 * %x %X ：输入解释成有符号的十六进制整数
 *
 * * 抑制赋值 %*d
 * 数字 %10s 最大字段宽度
 * hh 整数作为char类型读取 %hhd %hhu
 * ll 整数作为long long 类型读取 %llu %lld
 * h l L
 * z
 * t
 *
 * @return 返回成功读取的项数 文件结尾返回 EOF
 */
#if 1
    int age;
    float assets; // 资产
    char pet[30];

    printf("Enter your age, assets, and favorite pet.\n");
    scanf("%d %f", &age, &assets);
    scanf("%s",pet);
    printf("%d $%.2f %s\n", age, assets, pet);
#endif

    return 0;
}