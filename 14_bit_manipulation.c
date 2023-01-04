/**
 * @file 14_bit_manipulation.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2023-01-04
 *
 * @copyright Copyright (c) 2023
 *
 */
/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
/* 线的样式 */
#define SOLID  0
#define DOTTED 1
#define DASHED 2
/* 3原色 */
#define BLUE  4
#define GREEN 2
#define RED   1
/* 混合色 */
#define BLACK   0
#define YELLOW  (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN    (GREEN | BLUE)
#define WHITE   (RED | GREEN | BLUE)
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
struct box_props {
    bool opaque : 1;  // 0:透明 1：不透明
    unsigned int fill_color : 3;
    unsigned int : 4;
    bool show_border : 1;
    unsigned int border_color : 3;
    unsigned int border_style : 2;
    unsigned int : 2;
};

const char *colors[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};
/* Private function prototypes -----------------------------------------------*/
char *itobs(int, char *);
void show_bstr(const char *);
void show_settings(const struct box_props *pb);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main(int argc, char *argv[]) {
    /**
     * @brief Bitwise logical operator
     *  按位取反：~
     *  按位与：&
     *  按位或：|
     *  按位异或：^
     *
     */
    /* 用法1：掩码 */
#if 0

    #define MASK (1 << 1)
    char flag = 0b10010110;
    flag &= MASK;
    printf("%d", flag);
#endif
/* 用法2：设置位*/
#if 0
    #define MASK (1 << 1)
    char flag = 0b0000101;
    flag |= MASK;
    printf("%d", flag);
#endif
/* 用法3：清空位*/
#if 0
    #define MASK (1 << 1)
    char flag = 0b0000111;
    flag &= ~MASK;
    printf("%d", flag);
#endif
/* 用法4：切换位 */
#if 0
    #define MASK (1 << 1)
    char flag = 0b0000111;
    flag ^= MASK;
    printf("%d", flag);
#endif
/* 用法5：检测位的值 */
#if 0
    #define MASK (1 << 1)
    char flag = 0b0000101;

    if ((flag & MASK) == MASK) {
        printf("WOW\n");
    } else {
        printf("OvO\n");
    }
#endif
/**
 * @brief 移位运算符
 *  左移 <<
 *  右移 >>
 *
 */
#if 0
    /* number << n number 乘以2的n次幂 */
    /* number >> n number 除以2的n次幂 number非负*/
    #define BYTE_MASK 0xff
    unsigned long color = 0x002a162f;
    unsigned char blue, green, red;
    red = color & BYTE_MASK;
    green = (color >> 8) & BYTE_MASK;
    blue = (color >> 16) & BYTE_MASK;
    printf("R:0x%x G:0x%x B:0x%x", red, green, blue);
#endif

#if 0
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    int number;

    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates progrom.");
    while (scanf("%d", &number) == 1) {
        itobs(number, bin_str);
        printf("%d is ", number);
        show_bstr(bin_str);
        putchar('\n');
    }
    puts("Bye!");
#endif

#if 0
    struct box_props box = {true, YELLOW, true, GREEN, DASHED};

    printf("Original box settings:\n");
    show_settings(&box);

    box.opaque = false;
    box.fill_color = WHITE;
    box.border_color = MAGENTA;
    box.border_style = SOLID;
    printf("\nModified box settings:\n");
    show_settings(&box);

#endif

#if 1
    double dx;
    char ca;
    char cx;
    double dz;
    char cb;
    char _Alignas(double) cz;

    printf("char alignment:     %zd\n", _Alignof(char));
    printf("double alignment:   %zd\n", _Alignof(double));
    printf("&dx: %p\n", &dx);
    printf("&ca: %p\n", &ca);
    printf("&cx: %p\n", &cx);
    printf("&dz: %p\n", &dz);
    printf("&cb: %p\n", &cb);
    printf("&cz: %p\n", &cz);
#endif
    return 0;
}

void show_settings(const struct box_props *pb) {
    printf("Box is %s.\n", pb->opaque == true ? "opaque" : "transparent");
    printf("The fill color is %s.\n", colors[pb->fill_color]);
    printf("Border %s. \n", pb->show_border == true ? "shown" : "not shown");
    printf("The border color is %s.\n", colors[pb->border_color]);
    printf("The border style is ");
    switch (pb->border_style) {
    case SOLID:
        printf("solid.\n");
        break;
    case DOTTED:
        printf("dotted.\n");
        break;
    case DASHED:
        printf("dashed.\n");
        break;
    default:
        printf("unknown type.\n");
        break;
    }
}

char *itobs(int n, char *ps) {
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1) {
        ps[i] = (01 & n) + '0';
    }
    ps[size] = '\0';

    return ps;
}

void show_bstr(const char *str) {
    int i = 0;

    while (str[i]) {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i]) {
            putchar(' ');
        }
    }
}