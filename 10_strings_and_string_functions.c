/**
 * @file 10_strings_and_string_functions.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2022-12-16
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
#include <string.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define MSG       "I am a symbolic string constant."
#define MAXLENGTH 81
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
     * @brief puts() -> #include <stdio.h>
     * puts()函数只显示字符串，而且自动在显示的字符串末尾加上换行符
     *  用双引号括起来的内容成为字符串字面量(string literal),也叫字符串常量(string constant).
     * 双引号中的字符和编译器自动加入末尾的\0字符，都做为字符串存储在内存中
     * 从ANSI C标准起，如果字符串字面量之间没有间隔或者用空白字符分隔，C会将其视为串联起来的字符串字面量
     * char greeting[50] = "hello, and"" how are" "you"
     *                      " today!";
     * 字符串常量属于静态存储类别(static storage class)
     *  在函数中使用字符串常量，该字符串只会被存储一次，在整个程序的生命期内存在，即使函数被调用多次
     * 用双引号括起来的内容被视为指向该字符串存储位置的指针。
     */
#if 0
    char words[MAXLENGTH] = "I am a string in an array.";
    const char *ptr1 = "Something is pointing at me.";
    puts("Here are some strings:");
    puts(MSG);
    puts(ptr1);
    words[8] = 'p';
    puts(words);
    char greeting[50] =
        "hello, and"
        " how are "
        "you"
        " today!";
    puts(greeting);
#endif

#if 0
    printf("%s, %p, %c", "We", "are", *"space farers");
#endif

/**
 * @brief String array and initialization
 *  const char ptr[] = "strings";
 *  const char *ptr = "strings";
 */
#if 0
    const char str1[40] = "Limit yourself to one line's worth.";
    const char str2[40] = {'L', 'i', 'm', 'i', 't', ' ', 'y', 'o', 'u', 'r',
                           's', 'e', 'l', 'f', ' ', '.', '.', '.', '\0'};
    puts(str1);
    puts(str2);
#endif
    /**
     * @brief array and pointer
     * 通常，字符串都作为可执行文件的一部分存储在数据段中。当程序载入内存时，也载入了程序中的字符串。
     * 字符串存储在静态存储区中。程序在开始运行时才会为该数字分配内存。此时，才将字符串拷贝到数组中。
     * 此时字符串有两个副本。一个时在静态内存中字符串字面量，另一个是存储在ar1数组中的字符串。
     *
     * 初始化数组把静态存储区的字符串拷贝到数组中，而初始化指针直把字符串的地址拷贝给指针
     */
#if 0
/*
  address of "I'm special": 0000000000404000
                address ar: 000000000061FE0C
                address pt: 0000000000404000
            address of MSG: 0000000000404000
  address of "I'm special": 0000000000404000
*/
    #define MESSAGE "I'm special"

    char ar[] = MESSAGE;
    const char *pt = MESSAGE;

    printf("address of \"I'm special\": %p \n", "I'm special");
    printf("            address ar: %p\n", ar);
    printf("            address pt: %p\n", pt);
    printf("        address of MSG: %p\n", MESSAGE);
    printf("address of \"I'm special\": %p \n", "I'm special");
#endif

/**
 * @brief array The difference between arrays and Pointers
 *
 */
#if 0
    char heart[] = "I love Tillie!";
    const char *head = "I love Millie!";
    puts("-----------------Array notation-------------");
    for (int i = 0; i < 6; i++) {
        putchar(heart[i]);  // I love
    }
    putchar('\n');

    for (int i = 0; i < 6; i++) {
        putchar(head[i]);  // I love
    }
    putchar('\n');

    puts("-----------------Pointer addition operation-------------");
    for (int i = 0; i < 6; i++) {
        putchar(*(heart + i));  // I love
    }
    putchar('\n');

    for (int i = 0; i < 6; i++) {
        putchar(*(head + i));  // I love
    }
    putchar('\n');

    puts("--------Only pointer notation can be incremented-----");
    while (*(head) != '\0') {
        putchar(*head++);
    }
#endif
#if 0
    /* 编译器不支持这种操作 */
    char *p1 = "Klingon";
    p1[0] = 'F';
    printf("Klingon");
    printf(": Beware the %s!\n", "Klingon");
#endif
/**
 * @brief String array
 * pointer array： *str_table[LIM]
 * Two-dimensional character array： your_table[LIM][SLEN]
 * @note Pointer arrays are efficient, but the literals to which the pointer points cannot be changed
 *
 */
#if 0
    #define SLEN 40
    #define LIM  5

    const char *str_table[LIM] = {"Adding numbers swiftly", "Multiplying accurately", "Stashing data",
                                  "Follwing instructions to the letter", "Understanding the C language"};
    char your_table[LIM][SLEN] = {"Walking in a straight line", "Sleeping", "Watching television", "Mailing letters",
                                  "Reading email"};
    int i;
    puts("Let's compare talents.");
    printf("%-36s %-25s\n", "My Talents", "Your Talents");
    for (i = 0; i < LIM; i++) {
        printf("%-36s %-25s\n", str_table[i], your_table[i]);
    }
    printf("\nsizeof str_table: %zd, sizeof your_table: %zd\n", sizeof(str_table), sizeof(your_table));

#endif
/**
 * @brief p_and_s.c
 *
 */
#if 1
    const char *mesg = "Don't be a fool!";
    const char *copy;

    copy = mesg;
    printf("%s\n", copy);
    printf("mesg = %s; &mesg = %p' value = %p\n", mesg, &mesg, mesg);
    printf("copy = %s; &copy = %p; value = %p\n", copy, &copy, copy);
#endif
    return 0;
}