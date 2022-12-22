/**
 * @file 11_storage_categories_links_and_memory_management.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2022-12-22
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
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void trystat(void);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main(int argc, char *argv[]) {
    /* Storage categories */
    /**
     * @brief Action scope
     *  C变量的作用域可以是块作用域、函数作用域、函数原型作用域或文件作用域
     * 1.块作用域：定义在块中的变量具有块作用域(block scope)
     *  块作用域变量的可见范围是从定义处到包含该定义的块的结尾。函数的形式参数声明在函数的左花括号前，但是他们也具有块作用域，属于函数体这个块
     * 2.函数作用域（function
     * scope）：仅用于goto语句标签。即使一个标签首次出现在函数的内层块中，它的作用域也延伸至整个函数。
     * 3.函数原型作用域(function prototype scope)：用于函数原型中的形参名
     *     int mighty(int mouse, double large);
     *      函数原型作用域的范围是从形参定义处到原型声明结束。编译器在处理函数原型中的形参是只关心它的类型，而形参名通常无关紧要
     *      而且，即使有形参名，也不必与函数定义中的形参名相匹配，只有在变长数组中，形参名才有用。
     *      void use_a_vla(int n, int m, ar[n][m]);
     * 4.文件作用域：变量定义在函数的外面，从它的定义处到该定义所在文件的末尾均可见
     *      也称为全局变量（global variable）
     */

    /**
     * @brief Links
     *  C变量有3种链接属性：外部链接、内部链接或无链接
     * 具有块作用域、函数作用域或函数原型作用域的变量都是无链接变量。这些变量属于定义他们的块、函数或原型私有。
     * 具有文件作用域的变量可以是外部链接或内部链接。外部链接变量可以在多文件程序种使用，内部链接变量只能在一个翻译单元中使用
     *  C标准用“内部链接的文件作用域”描述仅限于一个翻译单元（即一个源代码文件和它所包含的头文件）的作用域
     *  用“外部链接的文件作用域”描述可延伸至其他翻译单元的作用域。
     *  “内部链接的文件作用域” -> “文件作用域”
     *  “外部链接的文件作用域” -> “全局作用域” “程序作用域”
     *     static:
     *  int giants = 5;         //  文件作用域，外部链接
     *  static int dodgers = 3; //  文件作用域，内部链接
     */

    /**
     * @brief Storage duration
     *  C对象有4种存储期：静态存储期、线程存储期、自动存储期、动态分配存储期
     *  1·静态存储期：在程序的执行期间一直存在。文件作用域具有静态存储期
     *              对于文件作用域变量，关键字static表明了期链接属性，而非存储期。以static声明的文件作用域变量具有内部链接。
     *              但是无论是内部链接还是外部链接，所有文件作用域变量都具有静态存储期
     *  2.线程存储期：用于并发程序设计，程序执行可被分为多个线程。具有线程存储期的对象，从被声明时到线程结束一直存在
     *          以关键字_Thread_local声明一个对象时，每个线程都获得该变量的私有备份
     *  3.自动存储期：块作用域的变量通常都具有自动存储期，当程序进入定义这些变量的块时，为这些变量分配内存；
     *              当退出这个块时，释放刚才为变量分配的内存。这种做法相当于把变量占用的内存视为一个可重复使用的工作区或暂存区。
     *              一个函数调用结束后，期变量占用的内存可用于存储下一个被调用函数的变量。
     *               变长数组稍有不同，他们的存储期从声明处到块末尾。而不是从块开始到块末尾
     *              块作用域变量也能具有静态存储期，声明时加上关键字 static
     *
     * 存储类别     存储期      作用域      链接        声明方式
     * 自动         自动        块          无          块内
     * 寄存器       自动        块          无          块内，使用关键字register
     * 静态外部链接 静态        文件        外部        所有函数外
     * 静态内部链接 静态        文件        内部        所有函数外，使用关键字static
     * 静态无链接   静态        块          无          块内，使用关键字static
     */

    /**
     * @brief Automatic variable
     *  自动存储期 块作用 无链接
     *  默认情况下，声明在块或函数头中的任何变量都属于自动存储类别，
     *      关键字 auto 是存储类别说明符(storage-class speifier)
     *      auto关键字在c++中用法完全不同
     *  块作用域和无链接意味着只能定义在的块中才能通过变量名访问该变量
     *  自动存储类型 程序在进入改变量声明所在的块时变量存在，程序在退出该块时变量消失。
     */
#if 0
    int x = 30;
    printf("x in outer block: %d at %p\n", x, &x);
    {
        int x = 77;
        printf("x in inner block: %d at %p\n", x, &x);
    }
    printf("x in outer block: %d at %p\n", x, &x);
    while (x++ < 33) {
        int x = 100;
        x++;
        printf("x in while loop: %d at %p\n", x, &x);
    }
    printf("x in outer block: %d at %p\n", x, &x);

#endif
/**
 * @brief C99 作用域规则
 *
 */
#if 0
    int n = 8;
    printf("    Initially, n = %d at %p\n", n, &n);
    for (int n = 1; n < 3; n++) {
        printf("    loop 1: n = %d at %p\n", n, &n);
    }
    for (int n = 1; n < 3; n++) {
        printf(" loop2 index n = %d at %p\n", n, &n);
        int n = 6;
        printf("    loop2: n = %d at %p\n", n, &n);
        n++;
    }
    printf(" After loop2, n = %d at %p\n", n, &n);
#endif
/**
 * @brief Automatic variable initialization
 *  Automatic variables are not automatically initialized
 * int main() {
 *      int repid;
 *      int tents = 5;
 * }
 * tents变量被初始化为5，repid变量的值时之前占有分配给repid的空间的任意值
 */
#if 0
    int repid;
    int tents = 5;
    printf("%d %d", repid, tents);
#endif
    /**
     * @brief Register variable
     *    变量通常存储在计算机内存中，如果幸运的话，寄存器存储在CPU中的寄存器中，或者概括地说，存储在最快的可用内存中。
     *  比普通变量相比，访问和处理这些变量的速度更快。由于寄存器变量存储在寄存器而非内存中，所有无法获取寄存器变量的地址。
     * 绝大多数方面，寄存器变量和自动变量一样。也就是说，他们有块作用域，无链接和自动存储期，
     * 使用说明符register便可声明寄存器变量
     *  register int num;
     * &num (X)
     *  register类别与直接命令相比更像是一种请求。编译器必须根据寄存器或最快可用内存的数量衡量你的请求或者直接忽略你的请求，
     * 所有可能不会如你所愿，在这种情况下，寄存器变量就变成普通的自动变量，即使时这样，任然不能对该变量使用地址运算符
     * 在函数头中使用关键字register，便可请求形参是寄存器变量
     * 可声明的register的数据类型有限，处理器中的寄存器没有足够大的空间存储double类型的值
     */

    /**
     * @brief Block-scoped static variables
     *  静态变量(static variable): 静态的意思是该变量在内存中原地不动，并不是说它的值不变。
     * 具有块作用域、无链接、具有静态存储期，在多次函数调用之间会记录他们的值。
     */
#if 0
    int count;

    for (count = 1; count <= 3; count++) {
        printf("Here comes iteratione %d:\n", count);
        trystat();
    }
#endif
    /**
     * @brief Static variables for external links
     *  外部链接的静态变量具有文件作用域，外部链接合静态存储期。也称为外部存储类别(external storage class)
     * 属于该类别的变量称为外部变量(external variable).把变量的定义性声明（defining
     * declaration）放在所有函数的外面便创建了外部变量
     * 为了指明函数使用了外部变量，可以再函数中关键字extern再次声明。如果一个源代码文件使用的外部变量定义再另一个源代码文件中，则必须用
     * extern再该文件中声明该变量
     *
     * int Errupt;
     * double Up[100];
     * extern char Coal; /* 定义再另一个文件
     * void next(void);
     * int main(void) {
     *  extern int Errupt;
     *  extern double Up[]; // 可选的声明，在这声明是不需要指明数组大小
     * }
     *
     * 外部变量具有静态存储期
     * 1. 初始化外部变量
     * 外部变量合自动变量类似，也可以被显式初始化，与自动变量不同的是，如果为初始化外部变量，她们
     * 被自动初始化为0，只能使用常量表达式初始化文件作用域变量
     * 2.使用外部变量
     * 3.外部名称
     * C99 C11标准都要求编译器识别局部标识符的前63个字符合外部标识符的前31个字符。
     * 4.定义和声明
     * int tern = 1;
     * // 引用式声明（referening declaration)
     * extern int tern;
     */

    /**
     * @brief Static variables that are internally linked
     *  static int svil = 1; // 静态变量，内部链接
     * int traveler = 1; // 外部链接
     *
     */

    /**
     * @brief multifile
     * 复杂的C程序通常由多个单独的源代码文件组成，有时这些文件可能共享一个外部变量，C通过在一个文件
     * 中进行定义式声明，然后再其他文件中进行引用式声明来实现共享。
     * 除一个定义式声明外，其他声明都要使用extern关键字。而且只有定义式声明才能初始化变量。
     *
     */
    return 0;
}

void trystat(void) {
    int fade = 1;
    static int stay = 1;

    printf("fade = %d and stay = %d\n", fade++, stay++);
}