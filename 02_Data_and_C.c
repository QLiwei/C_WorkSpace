/**
 * @file 02_Data_and_C.c
 * @author vector (1719569290@qq.com)
 * @brief C language learning
 *          keyword: int short long unsigned char float double _Bool _Complex _Imaginary
 *          operator: sizeof()
 *          funciont: scanf() printf()
 *          The difference between integer types and floating point numbers
 *          Declaration of variables
 *
 * @version V1.0.1
 * @date 2022-11-19
 *
 *
 */

/* Includes ------------------------------------------------------------------*/
#include <stdint.h> // 变量类型重定义
#include <inttypes.h>
#include <stdio.h>

/* Private includes ----------------------------------------------------------*/

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
/// @brief
/// @return
int main()
{
    /**
     * @brief Number type keyword
     *      K&R: int    long    short   unsigned    char    float   double
     *      C90: signed void
     *      C99: _Bool  _Complex   _Imaginary
     *
     * @brief bit byte and word
     *      bit: 0 1
     *      byte: 8bits
     *      word: The number of bits in the computer determines
     *
     * @brief integer type - float type
     *      float type: Floating point numbers are divided into fractional parts and exponential parts
     *
     */

    // Define and initialize Variable of type int
    int ten = 10, two = 2;

    /**
     * @brief  octal and hex
     *      octal:  prefix 0        eg:010 = 8
     *      hex: prefix 0x 0X       eg:0xA = 10
     */
#if 0
    int x = 100;

    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
    printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x); //Display prefixes
#endif

    /**
     * @brief Other integer Types
     *      short int
     *      long int
     *      long long int
     *      unsigned int
     *      unsigned long int
     *      unsigned long long int
     *
     * @brief print short/ long / longlong /unsigned type
     *      unsigned: %u
     *      long: %ld
     *      int = long: %d
     *      octal long: %lo
     *      hex long: %lx
     *      short: %hd\
     *      long long: %lld %llu
     */
#if 0
    long int estine = 100L;
    long johns = 10000L;
    short int rens;
    short ribs;
    unsigned int s_count;
    unsigned players;
    unsigned long headcount;
    unsigned short yesvotes;
    long long ago;

    unsigned int un = 3000000000; // int 32bits short 16bits
    short end = 200;
    long big = 65537;
    long long verybig = 12345678908642;

    printf("un = %u, and not %d\n", un, un);
    printf("end = %hd, and %d\n", end, end);
    printf("big = %ld and not %hd\n", big, big);
    printf("verybig = %lld and not %ld\n", verybig, verybig);
#endif

    /**
     * @brief char type
     *
     * @brief Transfer character
     *      \a: 报警
     *      \b: 退格
     *      \f: 换页
     *      \n: 换行
     *      \r: 回车
     *      \t: 水平制表符
     *      \v: 垂直制表符
     *      \\: 反斜杠
     *      \': 单引号
     *      \": 双引号
     *      \?: 问号
     *      \0oo: 八进制值 o 0~7
     *      \xhh: 十六进制 h 0~f
     *
     */
#if 0
    // Define and initialize Variable of type char
    char broiled = 'T';

    char ch;
    printf("Please enter a character: ");
    scanf("%c", &ch);
    printf("The code for %c is %d.\n", ch, ch);
#endif
    /**
     * @brief _Bool type
     *      true: 1
     *      false: 0
     *  #include <stdint.h>
     */
#if 0
    _Bool flag = true; // C99

    if (flag)
    {
        printf("true!");
    }
    else
    {
        printf("false!");
    }
#endif
/**
 * @brief stdint.h inttypes.h
 *  int32_t
 *  最小宽度类型：
 * int_fast8_t
 *
 */

    /**
     * @brief float double
     *
     *
     */
#if 1
    float noah, jonah;
    double trouble;
    float planck = 6.63e-34F;
    // long double gnp;  log double not support

    noah = jonah = 3.1415926F;
    trouble = 3.14;
    // gnp = 2.9;

    printf("%f can be weitten %e\n", noah, noah);
    printf("And it's %a in hexadecimal. powers of 2 notation\n", jonah);
    printf("%f can be written %e\n", trouble, trouble);
    // printf("%f can be wirtten %e\n", gnp, gnp);

#endif

    /**
     * @brief _Complex   _Imaginary
     *
     *      #include <complex.h>
     *
     */


    return 0;
}