/**
 * @file 09_array_and_pointer.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2022-12-14
 *
 * @copyright Copyright (c) 2022
 *
 */

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define MONTHS 12
#define COLS   4
#define ROWS   3
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
int sum(const int *array, const int lenght);
int sump(const int *start, const int *end);
void show_array(const double array[], int n);
void mult_array(double array[], int n, double mult);
void sum_rows(int array[][COLS], int rows);
void sum_cols(int array[][COLS], int rows);
int sum2d(int (*array)[COLS], int rows);
int new_sum2d(int rows, int cols, int array[rows][cols]);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main(void) {
    /**
     * @brief array
     *  const声明数组为只读，使用数组前必须先初始化它
     *
     */
#if 0
    int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int index;

    for (index = 0; index < MONTHS; index++) {
        printf("Month %2d has %2d days.\n", index + 1, days[index]);
    }
#endif
/**
 * @brief 指定初始化器 C99
 *  C99增加了一个新特性，指定初始化器（designated initializer）。利用该特性可以初始化指定的数组元素。
 *  C99支持声明变长数组， int array[n];
 */
#if 0
    int days[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};

    int index;

    for (index = 0; index < MONTHS; index++) {
        printf("Month %2d has %2d days.\n", index + 1, days[index]);
    }
#endif

/**
 * @brief 数组下标越界
 * C语言不会检测数组是否越界访问
 *
 */
#if 0
    #define SIZE 4
    int value1 = 44;
    int arr[SIZE];
    int value2 = 88;
    int i;

    printf("value1 = %d, value2 = %d\n", value1, value2);
    for (i = -1; i <= SIZE; i++) {
        arr[i] = 2 * i + 1;
    }

    for (i = -1; i < 7; i++) {
        printf("%2d %d\n", i, arr[i]);
    }
    printf("value1 = %d, value2 = %d\n", value1, value2);
    printf("address of arr[-1]: %p\n", &arr[-1]);
    printf("address of arr[4]: %p\n", &arr[4]);
    printf("address of value1: %p\n", &value1);
    printf("address of value2: %p\n", &value2);
#endif

/**
 * @brief rain
 *
 */
#if 0
    #define MONTHS 12
    #define YEARS  5

    const float rain[YEARS][MONTHS] = {{4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
                                       {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
                                       {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
                                       {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
                                       {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}};
    int year, month;
    float subtot, total;

    printf("  YEAR      RAINFALL    (inches)\n");
    for (year = 0, total = 0; year < YEARS; year++) {
        for (month = 0, subtot = 0; month < MONTHS; month++) {
            subtot += rain[year][month];
        }
        printf("%5d %15.lf\n", 2010 + year, subtot);
        total += subtot;
    }
    printf("\nThe yearly average is %.lf inches.\n\n", total / YEARS);
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  jul  Aug  Sep  Oct ");
    printf(" Nov Dec\n");
    for (month = 0; month < MONTHS; month++) {
        for (year = 0, subtot = 0; year < YEARS; year++) {
            subtot += rain[year][month];
        }
        printf("%4.1f ", subtot / YEARS);
    }
    printf("\n");
#endif

/**
 * @brief array pointer
 *  int array[10];
 *  array == &array[0]
 *  array + 2 == &array[2]
 *  *(array + 2) == array[2]
 *  *array + 2 == (*array) + 2 （*）优先级大于（+）
 */
#if 0

#endif
    /**
     * @brief function, array and pointer
     *
     */
#if 0
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    printf("sum = %d\n", sum(array, 10));
#endif
#if 0
    int marbles[10] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    long answer;

    answer = sump(marbles, marbles + 10);
    printf("The total number of marbles is %ld.\n", answer);
#endif
    /**
     * @brief order 指针运算中的优先级
     *
     */
#if 0
    int data[2] = {100, 200};
    int moredata[2] = {300, 400};

    int *p1, *p2, *p3;

    p1 = p2 = data;
    p3 = moredata;

    printf("  *p1 = %d, *p2 = %d, *p3 = %d\n", *p1, *p2, *p3);
    printf("*p1++ = %d, *++p2 = %d, (*p3)++ = %d\n", *p1++, *++p2, (*p3)++);
    printf("*p1 = %d, *p2 = %d, *p3 = %d\n", *p1, *p2, *p3);
#endif
/**
 * @brief 指针操作
 *
 */
#if 0
    int urn[5] = {100, 200, 300, 400, 500};
    int *ptr1, *ptr2, *ptr3;

    ptr1 = urn;
    ptr2 = &urn[2];

    printf("pointer value, dereferenced pointer, pointer address:\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

    ptr3 = ptr1 + 4;
    printf("\n adding an int to a pointer:\n");
    printf("ptr1 + 4 = %p, *(ptr1 + 4) = %d\n", ptr1 + 4, *(ptr1 + 4));

    ptr1++;
    printf("\nvalues after ptr1++:\n");
    printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

    ptr2--;
    printf("\nvalues after ptr2--:\n");
    printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);

    --ptr1;
    ++ptr2;
    printf("\nPointers reset to original values:\n");
    printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);

    printf("\nsubtracting one pointer from another:\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2 -ptr1 = %td\n", ptr2, ptr1, ptr2 - ptr1);

    printf("\nsubtracting an int from a pointer:\n");
    printf("ptr3 = %p, ptr3 - 2 = %p\n", ptr3, ptr3 - 2);
#endif
    /**
     * @brief 保护数组中的数据
     *
     * const 修饰指针
     *  const int *ptr; == const int const int *ptr -> 修饰 *ptr *ptr的值不能修改
     *                                          ptr指向的值不可以修改
     *  const int * const ptr -> 修饰 ptr 不能改变ptr的指向
     *
     * const 指针变量（形式 const (type) *ptr）可以指向 const 变量和非const变量
     * double rates[5] = {0};
     * const double locked[4] = {0};
     * const double *pc = rates; // 有效
     * pc = locked; // 有效
     * pc = &rates[3]; // 有效
     *
     * 指针变量（形式 (type) * ptr) 不可以指向const修饰的变量
     * double rates[5] = {0};
     * const double locked[4] = {0};
     * double * ptr;
     * ptr = rates;
     * ptr = locked; // 无效
     */
#if 0
    double dip[5] = {20.0, 17.66, 8.2, 15.3, 22.22};

    printf("The original dip array:\n");
    show_array(dip, 5);
    mult_array(dip, 5, 2.5);
    printf("The dip array after calling mult_array():\n");
    show_array(dip, 5);

#endif
/**
 * @brief Pointer and multidimensional array
 *
 *  int zippo[4][2];
 *  zippo数组首元素地址：zippo == &zippo[0]
 */
#if 0
    int zippo[4][2];
    printf("          *zippo address:%p\n", *zippo);
    printf("           zippo address:%p\n", zippo);
    printf("          &zippo address:%p\n", &zippo);
    printf("       &zippo[0] address:%p\n", &zippo[0]);
    printf("    &zippo[0][0] address:%p\n", &zippo[0][0]);

    printf("          *zippo + 1 address:%p\n", *zippo + 1);
    printf("           zippo + 1 address:%p\n", zippo + 1);
    printf("          &zippo + 1 address:%p\n", &zippo + 1);
    printf("       &zippo[0] + 1 address:%p\n", &zippo[0] + 1);
    printf("    &zippo[0][0] + 1 address:%p\n", &zippo[0][0] + 1);
#endif
    /**
     * @brief A pointer to a multidimensional array
     * int zippo[4][2];
     * int (*ptr)[2];
     * ptr = zippo;
     * zippo 类型等价于 ptr
     * zippo[m][n] == *(*(zippo + m) + n);
     * ptr[m][n] == *(*(ptr + m) + n);
     *
     */
#if 0
    int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};
    int(*ptr)[2];
    ptr = zippo;

    printf("    ptr = %p,   ptr + 1 = %p\n", ptr, ptr + 1);
    printf("ptr[0] = %p, ptr[0] + 1 = %p\n", ptr[0], ptr[0] + 1);
    printf("  *ptr = %p,   *ptr + 1 = %p\n", *ptr, *ptr + 1);
    printf("ptr[0][0] = %d\n", ptr[0][0]);
    printf("  *ptr[0] = %d\n", *ptr[0]);
    printf("    **ptr = %d\n", **ptr);
    printf("      ptr[2][1] = %d\n", ptr[2][1]);
    printf("*(*(ptr+2) + 1) = %d\n", *(*(ptr + 2) + 1));
#endif
    /**
     * @brief Pointer compatibility
     *
     * int *pt;
     * int (*pa)[3];
     * int array1[2][3];
     * int array2[2][2];
     * int **p2;
     *
     * pt = &array1[0][0]
     * pt = array[0];       // 都是指向int的指针
     *
     * pt = array1; // 无效
     * pa = array1; // 都是指向内含3个int类型元素的指针
     * pa = array2  // 无效
     * p2 = &pt;    // both pointer-to-int *
     * *p2 = array2[0]; // 都是指向int的指针
     * p2 = array2; // 无效
     *
     */
#if 0
    int n = 5;
    double x;
    int *ptr_int = &n;
    double *ptr_double = &x;
    x = n;  // 隐式类型转换
    // ptr_double = ptr_int;  // 编译报错  warning: assignment to 'double *' from incompatible pointer type 'int *'
    // [-Wincompatible-pointer-types]
#endif

#if 0
    int x = 20;
    const int y = 23;
    int *p1 = &x;
    const int *p2 = &y;
    const int **pp2;

    // warning: assignment discards 'const' qualifier from pointer target type [-Wdiscarded-qualifiers]
    //p1 = p2;  // const 指针赋值给 非const 指针 -- 不安全 （const 指针这里有点表述不清楚，注意区分）
    p2 = p1;  // 非const指针赋值给const指针 -- 安全
    // warning: assignment to 'const int **' from incompatible pointer type 'int **' [-Wincompatible-pointer-types]
    //pp2 = &p1;  // 嵌套指针类型赋值 -- 不安全
                // 分析：**pp2 是const -> p1的地址不能修改
#endif

#if 0
    const int **pp2;
    int *p1;
    const int n = 13;

    // warning: assignment to 'const int **' from incompatible pointer type 'int **' [-Wincompatible-pointer-types]
    pp2 = &p1;
    *pp2 = &n;
    *p1 = 10;

    printf("n = %d\n", n);  // n = 10;
#endif
    /**
     * @brief Function and multidimensional array
     *  int sum(int array[][], int rows); // 错误声明
     *  int sum(int array[][COLS], int rows); //
     *  int sum(int (*array)[COLS], int rows);
     * array[1] -> array + 1; 不指定二维的大小，编译器不知道怎么处理
     *
     * 声明一个指向N维数组的指针时，只能省略最左边方括号中的值
     */
#if 0
    int junk[ROWS][COLS] = {{2, 4, 6, 8}, {3, 5, 7, 9}, {12, 10, 8, 6}};

    sum_rows(junk, ROWS);
    sum_cols(junk, ROWS);

    printf("Sum of all element = %d\n", sum2d(junk, ROWS));

#endif
    /**
     * @brief Variable length array
     * C99 新增变长数组，允许使用变量表示数组的维度（C11把变长数组作为一个可选特性）
     *  在创建数组时可以使用变量指定数组的维度
     *  int quarters = 4;
     *  int regions = 5;
     *  double sales[regions][quarters];
     */
#if 0
    int junk[ROWS][COLS] = {{2, 4, 6, 8}, {3, 5, 7, 9}, {12, 10, 8, 6}};
    printf("Sum of all element = %d\n", new_sum2d(ROWS, COLS, junk));
#endif
    /**
     * @brief Compound literals
     *  C99 新增复合字面量，字面量是除符号外的常量。作用域：{}块作用域
     *      eg. 5是int类型的字面量
     *          81.3是double类型的字面量
     *          'y'是char类型的字面量
     *          "elephant"是字符串的字面量
     *  int diva[2] = {10, 20};
     *  (int [2]){10, 20}; // 复合自面量
     * 复合字面量是匿名的，所有不能先创建后在使用他，必须在创建的同时使用它。
     * 使用指针记录地址就是一种用法：
     *  int * ptr;
     * ptr = (int [2]){10, 20};
     */
#if 0
    printf("Sum of all element = %d\n", new_sum2d(ROWS, COLS, (int[3][4]){{2, 4, 6, 8}, {3, 5, 7, 9}, {12, 10, 8, 6}}));
#endif
    return 0;
}

/**
 * @brief Using the property of mutable arrays, compute the sum of all the elements of a two-dimensional array of int
 * @note C99/C11 Declarative functions can omit parameter names from stereotypes
 *        int new_sum2d(int, int, int [*][*]);
 *        int new_sum2d(int array[rows][cols], int rows, int cols); invalid
 *
 * @param rows Rows The number of columns in a two-dimensional array
 * @param cols Cols The number of columns in a two-dimensional array
 * @param array Two-dimensional array address
 * @return int Sum of two dimensional arrays
 */
int new_sum2d(int rows, int cols, int array[rows][cols]) {
    int row;
    int col;
    int sum = 0;

    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            sum += array[row][col];
        }
    }
    return sum;
}

/**
 * @brief Find the sum of each row of a two-dimensional array
 *
 * @param Two-dimensional array address
 * @param rows The number of columns in a two-dimensional array
 */
void sum_rows(int array[][COLS], int rows) {
    int r;
    int c;
    int tot;

    for (r = 0; r < rows; r++) {
        tot = 0;
        for (c = 0; c < COLS; c++) {
            tot += array[r][c];
        }
        printf("row %d: sum = %d\n", r, tot);
    }
}

/**
 * @brief Find the sum of each column of a two-dimensional array
 *
 * @param Two-dimensional array address
 * @param rows The number of columns in a two-dimensional array
 */
void sum_cols(int array[][COLS], int rows) {
    int r, c, tot;

    for (c = 0; c < COLS; c++) {
        tot = 0;
        for (r = 0; r < rows; r++) {
            tot += array[r][c];
        }
        printf("cols %d: sun = %d\n", c, tot);
    }
}

/**
 * @brief Find the sum of two dimensional arrays
 *
 * @param array Two-dimensional array address
 * @param rows The number of columns in a two-dimensional array
 * @return int Sum of two dimensional arrays
 */
int sum2d(int (*array)[COLS], int rows) {
    int r, c, tot = 0;

    for (r = 0; r < rows; r++) {
        for (c = 0; c < COLS; c++) {
            tot += array[r][c];
        }
    }
    return tot;
}

/**
 * @brief Prints an array of doubles
 *
 * @param array Array
 * @param n Array length
 */
void show_array(const double array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%8.3f ", array[i]);
    }
    putchar('\n');
}

/**
 * @brief Expands the array elements by n times
 *
 * @param array Array
 * @param n Array
 * @param mult Multiple of expansion
 */
void mult_array(double array[], int n, double mult) {
    for (int i = 0; i < n; i++) {
        array[i] *= mult;
    }
}

/**
 * @brief 求数组的和
 * @note int sum(int array[], int n) -> 指针array指向的不仅仅一个int类型值，还是一个int类型数组元素
 *  函数原型可以省略参数名,以下4种形式都是等价
 *  int sum(int *array, int n);
 *  int sum(int *, int);
 *  int sum(int array[], int n);
 *  int sum(int [], int);
 *  函数定义中不能省略参数名,以下两种形式等价
 *  int sum(int *array, int n){}
 *  int sum(int array[], int n){}
 * @note Modify the parameter with const
 *
 * @param array 数组
 * @param lenght array lenght
 * @return int Sum of arrays
 */
int sum(const int *array, const int lenght) {
    int sum = 0;
    for (int i = 0; i < lenght; i++) {
        sum += *(array + i);
    }
    return sum;
}

/**
 * @brief Find the start pointer to end pointer data sum
 * @note Modify the parameter with const
 * @param start Start pointer
 * @param end End pointer
 * @return int Data sum
 */
int sump(const int *start, const int *end) {
    int sum = 0;

    while (start < end) {
        sum += *start++;  // (*) (++) 优先级相同，结合律从右往左，start++先求值，*start后，
                          // 先把指针指向位置上的值加到total，然后再递增指针
    }
    return sum;
}