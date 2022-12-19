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
char *s_gets(char *str, int n);
void put1(const char *string);
int put2(const char *string);
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
#if 0
    const char *mesg = "Don't be a fool!";
    const char *copy;

    copy = mesg;
    printf("%s\n", copy);
    printf("mesg = %s; &mesg = %p' value = %p\n", mesg, &mesg, mesg);
    printf("copy = %s; &copy = %p; value = %p\n", copy, &copy, copy);
#endif
    /**
     * @brief gets()
     *  gets()读取整行输入，直到遇到换行符，存储其余字符，并在这些字符末尾添加一个空字符使其变成一个C字符串
     *  gets() 只有一个参数，无法检查数组是否装得下输入行 有些编译器会报警告
     *         输入字符串过长，会导致缓冲区溢出（buffer overflow）
     */
#if 0
    #define STLEN 81

    char words[STLEN];

    puts("Enter a string, please.");
    gets(words);
    printf("Your string twice:\n");
    printf("%s\n", words);
    puts(words);
    puts("Done.");

#endif
    /**
     * @brief fgets() fputs()
     *  fgets()
     *     The second parameter: Specifies the maximum number of characters to read
     *                          fgets()Will read in n-1 characters, or read to the first newline character encountered
     *     The third parameter: Specifies the file to read
     *                  If you're reading from keyboard input. Takes stdin (standard input) as the parameter
     *
     */
#if 0
    char words[14];

    puts("Enter a string, please.");
    fgets(words, 14, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Enter anther string, please.");
    fgets(words, 14, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Done.");
#endif
/**
 * @brief
 *
 */
#if 0
    #define STLEN 10
    char words[STLEN];

    puts("Enter string (empty line to quit):");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n') {
        fputs(words, stdout);
    }
    puts("Done.");

#endif

#if 0
    #define STRING_LENGTH 10
    char words[STRING_LENGTH];
    int i;

    puts("Enter strings (empty line to quit):");
    while (fgets(words, STRING_LENGTH, stdin) != NULL && words[0] != '\0') {
        i = 0;
        while (words[i] != '\n' && words[i] != '\0') {
            i++;
        }

        if (words[i] == '\n') {
            words[i] = '\0';
        } else {
            while (getchar() != '\n') {
                continue;
            }
        }
        puts(words);
    }
    puts("done");
#endif
    /**
     * @brief gets_s()
     * C11新增gets()
     * gets_s只从标准输入中读取数据
     * gets_s()读到换行符，会丢弃它而不是存储它
     * gets_s()读到最大字符数都没有读到换行符，会执行以下几步
     *  1.把目标数组中的首字符设置为空字符，读取并丢弃随后输入直至读到换行符或文件结尾，返回空指针
     *  2.调用依赖实现的“处理函数”，可能会终止或退出程序
     */

    /**
     * @brief s_gets()
     * fgets()函数的一种用法
     *
     */
#if 0
    char str[10];
    puts(s_gets(str, 10));
#endif
/**
 * @brief scanf()
 *  确认输入结束：1.第一个非空白字符作为字符串的开始，以空白字符作为结束
 *                2.指定长度（%10s）读取10个字符或空白字符
 */
#if 0
    char name1[11], name2[11];
    int count;

    printf("Please enter 2 names.\n");
    count = scanf("%5s %10s", name1, name2);
    printf("I read the %d names %s and %s.\n", count, name1, name2);
#endif
/**
 * @brief puts()
 *
 */
#if 0
    #define DEF "I am a #define string"
    char str1[80] = "An array was initialized to me.";
    const char *str2 = "A pointer was initialized to me.";

    puts("I'm an argument to puts().");
    puts(DEF);
    puts(str1);
    puts(str2);
    puts(&str1[5]);
    puts(str2 + 4);
#endif
/**
 * @brief fputs()
 *
 */
#if 0
    char line[81];
    while (fgets(line, 81, stdin)) {
        fputs(line, stdout);
    }

#endif

/**
 * @brief printf()
 *
 */
#if 0
    const char string[20] = "i love you!";
    printf("%s\n", string);
    puts(string);
#endif

    /**
     * @brief Customize input and output functions
     *
     */
#if 0
    put1("If I'd as much money");
    put1(" as I could spend,\n");
    printf("I count %d characters.\n", put2("I never would cry chairs to mend."));
#endif
    return 0;
}

/**
 * @brief Print a string
 *
 * @param string String pointer
 */
void put1(const char *string) {
    while (*string) {
        putchar(*string++);
    }
}

/**
 * @brief Print a string and break the line
 *
 * @param string string String pointer
 * @return int Number of character
 */
int put2(const char *string) {
    int count = 0;
    while (*string) {
        putchar(*string++);
        count++;
    }
    putchar('\n');

    return count;
}
/**
 * @brief If a newline character appears in the string, replace it with a space. When a null character occurs, the
 * remaining characters on the line to be entered are discarded
 *
 * @param str String pointer
 * @param n Reading string length
 * @return char*
 * @retval NULL Read to end of file or a read error occurred
 */
char *s_gets(char *str, int n) {
    char *ret_val;
    int i = 0;

    ret_val = fgets(str, n, stdin);
    if (ret_val) {
        while (str[i] != '\n' && str[i] != '\0') {
            i++;
        }
        if (str[i] == '\0') {
            str[i] = '\0';
        } else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}
