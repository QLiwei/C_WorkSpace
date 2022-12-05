/**
 * @file 04_OperatorExpressionStatement.c
 * @author vector (1719569290@qq.com)
 * @brief
 * @version V1.0.1
 * @date 2022-12-05
 *
 *
 */

/* Includes ------------------------------------------------------------------*/
#include "01_C_StyleOfAnnotation.h"

/* Private includes ----------------------------------------------------------*/
#include <stdio.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define ADJUST (7.31)
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main() {
/**
 * @brief 把鞋码转化成英寸
 *
 */
#if 0
    const double SCALE = 0.333;
    double shoe, foot;

    shoe = 9.0;
    foot = SCALE * shoe + ADJUST;

    printf("Shoe size (men's)   foot length\n");
    printf("%10.1f %15.2f inches\n", shoe, foot);
#endif

/**
 * @brief 计算不同鞋码对应的脚长
 *
 */
#if 0
    const double SCALE = 0.333;
    double shoe, foot;

    printf("Shoe size (men's)   foot length\n");
    shoe = 3;
    while (shoe < 18.5)
    {
        foot = SCALE * shoe + ADJUST;
        printf("%10.1f %15.2f inches\n", shoe, foot);
        shoe++;
    }
    printf("If the shoe fits, wear it.\n"); // 如果鞋子合适，就穿吧。
#endif

/**
 * @brief 运算符
 *
 * 赋值运算符： =
 *            数据对象，左值，右值和运算符
 *  数据对象：把值存储到内存位置上，存储值的数据存储器统称为数据对象（data object）
 *  左值：用于标识特定数据对象的名称或表达式（指定一个对象，赋值运算的左侧）
 *      const 限定符-> 有些左值不能用于赋值运算符的左侧 -> 可修改的左值
 *  右值：指能赋值给可修改的左值的量（right 常量,变量或者其他可求值的表达式）
 *
 * 加法运算符： +
 * 减法运算符： -
 * 符号运算符： -和+    -12 +12 一元运算符
 * 乘法运算符： *
 * 除法运算符： / 整数除法只会保持整数部分不会四舍五入
 *               浮点数，混合整数 计算结果为浮点数
 *
 * 运算符优先级：
 *
 * sizeof运算符：size_t类型：以字节为单位返回运算对象的大小
 * 求模运算符： %   用于整数运算
 * 递增运算符：++       ++a , a++
 *                  前缀：使用之前，递增a   a_pre = ++a;
 *                  后缀：使用之后，递增a   a_post = a++;
 * 递减运算符： --
 */
#if 0
    int jane, tarzan, cheeta;

    cheeta = tarzan = jane = 68;

    printf("                cheeta      tarzan  jane\n");
    printf("First round score %4d %8d %8d\n", cheeta, tarzan, jane);
#endif
#if 0  //    指数增长
    #define SQUAERS (64)

    const double CROP = 2E16; // 世界小麦年产谷粒数
    double current, total;
    int count = 1;

    printf("square      grains      total   ");
    printf("fraction of \n");
    printf("            added       grains  ");
    printf("world total\n");
    total = current = 1.0;  /* 从一粒谷粒开始 */
    printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);

    while (count < SQUAERS)
    {
        count = count + 1;
        current = 2.0 * current;
        total = total + current;
        printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
    }
    printf("That's all.\n");

#endif

#if 0  //  sizeof size_t
    int n = 0;
    size_t intsize;

    intsize = sizeof(int);
    printf("n = %d, n has %zd bytes; all ints have %zd bytes.\n", n, sizeof(n), intsize);
#endif

/**
 * @brief 类型转换
 *  1.当类型转换出现表达式时：unsigned signed char short 自动转换成int
 *  2.两种运算符的运算，两个值被分别转换成两种类型的更高级别
 *  3.类型的级别从高至低排序：long double/ double / float/ unsigned long long / long long /unsigned long
 *                          long / unsigned int / int
 *  4.赋值表达式语句中，计算的最终结果会被转换成赋值变量的类型 （类型的升级和降级）
 *  5.当作参数传递时，char  short 别转换成int, float 被转换成double
 *
 *  强制类型转换  (类型名)
 *
 */
#if 1
    const int S_PER_M = 60;          // 1分钟的秒数
    const int S_PER_H = 3600;        // 1小时的分钟数
    const double M_PER_K = 0.62137;  // 1公里的英里数

    double distk, distm;  // 跑过的距离 （分别以公里和英里为单位）
    double rate;          // 平均速度 （单位：英里/小时）
    int min, sec;         // 跑步用时（以分钟和秒为单位）
    int time;             // 跑步用时（以秒为单位）
    double mtime;         // 跑1英里需要的时间 （单位：秒）
    int mmin, msec;       // 跑1英里需要的时间 （分钟和秒单位）

    printf("This porgram converts your time for a metric race\n");  // 这个程序将您的时间转换为公制比赛
    printf("to a time for running a mile and to your average\n");   // 到跑一英里的时间和你的平均时间
    printf("spead in miles per hour.\n");                           // 以英里每小时为单位。
    printf("Please enter, in kilometers, the distance run.\n");     // 请输入，以公里为单位的跑步距离
    scanf("%lf", &distk);
    printf("Next  enter the time in minutes and seconds.\n");  // 接下来以分和秒为单位输入时间。
    printf("Begin by entering the minutes.\n");
    scanf("%d", &min);
    printf("Now enter the seconds.\n");                        // 现在输入秒数。
    scanf("%d", &sec);

    time = S_PER_M * min + sec;
    distm = M_PER_K * distk;
    rate = distm / time * S_PER_H;
    mtime = (double)time / distm;
    mmin = (int)mtime / S_PER_M;
    msec = (int)mtime % S_PER_M;

    printf("You ran %1.2f km (%1.2f miles) in %d min, %d sec.\n", distk, distm, min, sec);
    printf("That pace corresponds to running a mile in %d min, ", mmin);
    printf("%d sec.\nYour average speed was %1.2f mph.\n", msec, rate);
#endif
    return 0;
}