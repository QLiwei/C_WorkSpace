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
#include <stdlib.h>
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
void fit(char *string, size_t size);
void stsrt(char *strings[], int num);
void ToUpper(char *string);
int PunctCount(const char *string);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main(int argc, char *argv[]) {
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
    /**
     * @brief Function of string
     *  string.h
     *      strlen()/strcat()/strcmp()/strncmp()/strcpy()/strncpy()
     * stdio.h
     *  sprintf()
     */

    /**
     * @brief strlen()
     *
     */
#if 0
    char mesg[] = "Things should be as simple as possible, but not simpler.";

    puts(mesg);
    fit(mesg, 38);
    puts(mesg);
    puts("Let's look at some more of the string.");
    puts(mesg + 39);
#endif
/**
 * @brief strcat()
 *
 */
#if 0
    char flower[80];
    char addon[] = "s smell like old shoes.";

    puts("What is your favorite flower?");
    if (s_gets(flower, 80)) {
        strcat(flower, addon);
        puts(flower);
        puts(addon);
    } else {
        puts("End of file encountered!");
    }
    puts("bye");
#endif
/**
 * @brief strncat()
 *
 */
#if 0
    char flower[30];
    char addon[] = "s smell like old shoes.";
    char bug[13];
    int available;

    puts("What is your favorite flower?");
    s_gets(flower, 30);
    if ((strlen(addon) + strlen(flower) + 1) <= 30) {
        strcat(flower, addon);
    }
    puts(flower);
    puts("What is your favorite bug?");
    s_gets(bug, 13);
    available = 13 - strlen(bug) - 1;
    strncat(bug, addon, available);
    puts(bug);
#endif
/**
 * @brief strcmp()
 *
 * @retval <0   前字符串 < 后面的字符串
 * @retval 0    相等
 * @retval >0   前字符串 > 后面的字符串
 */
#if 0
    #define ANSWER "Grant"
    #define SIZE   40
    char try[SIZE];

    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE);
    while (strcmp(try, ANSWER) != 0)
    {
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE);
    }
    puts("That's right!");

#endif
#if 0
    #define SIZE 80
    #define LIM  10
    #define STOP "quit"

    char input[LIM][SIZE];
    int ct = 0;

    printf("Enter up to %d lines (type quit to quit):\n", LIM);
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL && strcmp(input[ct], STOP) != 0) {
        ct++;
    }
    printf("%d strings entered\n", ct);

#endif
/**
 * @brief strncmp()
 *
 */
#if 0
    #define LISTSIZE 6
    const char *list[LISTSIZE] = {"astronomy", "astounding", "astrophysics", "ostracize", "asterism", "astrophobia"};
    int count = 0;
    int i;

    for (i = 0; i < LISTSIZE; i++) {
        if (strncmp(list[i], "astro", 5) == 0) {
            printf("Found: %s\n", list[i]);
            count++;
        }
    }
    printf("The list contained %d words beginning with astro.\n", count);
#endif
/**
 * @brief strcpy() strncpy()
 *
 */
#if 0
    #define SIZE 40
    #define LIM  5

    char qwords[LIM][SIZE];
    char temp[SIZE];
    int i = 0;

    printf("Enter %d words beginning with q:\n", LIM);
    while (i < LIM && s_gets(temp, SIZE)) {
        if (temp[0] != 'q') {
            printf("%s doesn't begin with q!\n", temp);
        } else {
            strcpy(qwords[i], temp);
            i++;
        }
    }
    puts("Here are the words accepted:");
    for (i = 0; i < LIM; i++) {
        puts(qwords[i]);
    }
#endif
#if 0
    #define WORDS "beast"
    #define SIZE  40

    const char *orig = WORDS;
    char copy[SIZE] = "Be the best that you can be.";
    char *ps;

    puts(orig);
    puts(copy);
    ps = strcpy(copy + 7, orig);
    puts(copy);
    puts(ps);
#endif
/**
 * @brief strnpy()
 *
 */
#if 0
    #define SIZE     40
    #define TARGSIZE 7
    #define LIM      5

    char qwords[LIM][TARGSIZE];
    char temp[SIZE];

    int i = 0;
    printf("Enter %d words beginning with q:\n", LIM);
    while (i < LIM && s_gets(temp, SIZE)) {
        if (temp[0] != 'q') {
            printf("%s doesn't begin with q!\n", temp);
        } else {
            strncpy(qwords[i], temp, TARGSIZE - 1);
            qwords[i][TARGSIZE - 1] = '\0';
            i++;
        }
    }
    puts("Here are the words accepted:");
    for (i = 0; i < LIM; i++) {
        puts(qwords[i]);
    }
#endif
/**
 * @brief sprintf()
 *
 */
#if 0
    #define MAX 20

    char first[MAX];
    char last[MAX];
    char formal[2 * MAX + 10];
    double prize;

    puts("Enter your first name:");
    s_gets(first, MAX);
    puts("Enter your last name:");
    s_gets(last, MAX);
    puts("Enter your prize money:");
    scanf("%lf", &prize);
    sprintf(formal, "%s, %-19s: $%6.2f\n", last, first, prize);
    puts(formal);
#endif
/**
 * @brief String sorting
 *
 */
#if 0
    #define SIZE 81
    #define LIM  20
    #define HALT " "

    char input[LIM][SIZE];
    char *ptstr[LIM];
    int ct = 0;
    int k;

    printf("Input up to %d lines, and I will sort them.\n", LIM);
    printf("To stop, press the Enter key at a line's start.\n");
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0') {
        ptstr[ct] = input[ct];
        ct++;
    }
    stsrt(ptstr, ct);
    puts("\nHere's the sorted list:\n");
    for (k = 0; k < ct; k++) {
        puts(ptstr[k]);
    }

#endif
/**
 * @brief ctype.h character functions and strings
 *
 */
#if 0
    #define LIMIT 81

    char line[LIMIT];
    char *find;

    puts("Please enter a line:");
    fgets(line, LIMIT, stdin);
    find = strchr(line, '\n');
    if (find) {
        *find = '\0';
    }
    ToUpper(line);
    puts(line);
    printf("That line has %d punctuation characters.\n", PunctCount(line));
#endif
/**
 * @brief Command line parameter
 *  int main(int argc, char *argv[]){}
 *  int main(int argc, char **argv){}
 * @param argc Number of strings in the command line (argument count)
 * @param argv A pointer to a pointer(argument value)
 *  argv[0] Representing the program itself
 */
#if 0
    int count;

    printf("The command line has %d arguments:\n", argc - 1);
    for (count = 1; count < argc; count++) {
        printf("%d: %s\n", count, argv[count]);
    }
    printf("\n");
#endif
/**
 * @brief Converts a string to a number
 *
 */
#if 0
    int i, times;

    if (argc < 2 || (times = atoi(argv[1])) < 1) {
        printf("Usage: %s positive-number\n", argv[0]);
    } else {
        for (i = 0; i < times; i++) {
            puts("Hello, good looking!");
        }
    }
#endif

#if 1
    #define LIM 30
    char number[LIM];
    char *end;
    long value;

    puts("Enter a number (empty line to quit):");
    while (s_gets(number, LIM) && number[0] != '\0') {
        value = strtol(number, &end, 10);  // 10进制
        printf("base 10 input, base 10 output: %ld, stopped at %s (%d)\n", value, end, *end);

        value = strtol(number, &end, 16);  // 16进制
        printf("base 16 input, base 10 output: %ld, stopped at %s (%d)\n", value, end, *end);

        puts("Next number:");
    }
    puts("Bye!\n");

#endif
    return 0;
}

/**
 * @brief Converts a string to uppercase
 *
 * @param string String opinter
 */
void ToUpper(char *string) {
    while (*string) {
        *string++ = toupper(*string);
    }
}

/**
 * @brief Count the number of punctuation marks in a string
 *
 * @param string String opinter
 * @return int The number of punctuation marks in a string
 */
int PunctCount(const char *string) {
    int ct = 0;
    while (*string) {
        if (ispunct(*string)) {
            ct++;
        }
        string++;
    }
    return ct;
}

/**
 * @brief String selection sort
 *
 * @param strings String array pointer
 * @param num Number of strings
 */
void stsrt(char *strings[], int num) {
    char *temp;
    int top, seek;

    for (top = 0; top < num - 1; top++) {
        for (seek = top + 1; seek < num; seek++) {
            if (strcmp(strings[top], strings[seek]) > 0) {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
    }
}

/**
 * @brief Changing the string Length
 *
 * @param string String pointer
 * @param size Set string length
 */
void fit(char *string, size_t size) {
    if (strlen(string) > size) {
        string[size] = '\0';
    }
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
        if (str[i] == '\n') {
            str[i] = '\0';
        } else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}
