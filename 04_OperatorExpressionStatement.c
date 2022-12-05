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
 * @brief ��Ь��ת����Ӣ��
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
 * @brief ���㲻ͬЬ���Ӧ�Ľų�
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
    printf("If the shoe fits, wear it.\n"); // ���Ь�Ӻ��ʣ��ʹ��ɡ�
#endif

/**
 * @brief �����
 *
 * ��ֵ������� =
 *            ���ݶ�����ֵ����ֵ�������
 *  ���ݶ��󣺰�ֵ�洢���ڴ�λ���ϣ��洢ֵ�����ݴ洢��ͳ��Ϊ���ݶ���data object��
 *  ��ֵ�����ڱ�ʶ�ض����ݶ�������ƻ���ʽ��ָ��һ�����󣬸�ֵ�������ࣩ
 *      const �޶���-> ��Щ��ֵ�������ڸ�ֵ���������� -> ���޸ĵ���ֵ
 *  ��ֵ��ָ�ܸ�ֵ�����޸ĵ���ֵ������right ����,����������������ֵ�ı��ʽ��
 *
 * �ӷ�������� +
 * ����������� -
 * ����������� -��+    -12 +12 һԪ�����
 * �˷�������� *
 * ����������� / ��������ֻ�ᱣ���������ֲ�����������
 *               ��������������� ������Ϊ������
 *
 * ��������ȼ���
 *
 * sizeof�������size_t���ͣ����ֽ�Ϊ��λ�����������Ĵ�С
 * ��ģ������� %   ������������
 * �����������++       ++a , a++
 *                  ǰ׺��ʹ��֮ǰ������a   a_pre = ++a;
 *                  ��׺��ʹ��֮�󣬵���a   a_post = a++;
 * �ݼ�������� --
 */
#if 0
    int jane, tarzan, cheeta;

    cheeta = tarzan = jane = 68;

    printf("                cheeta      tarzan  jane\n");
    printf("First round score %4d %8d %8d\n", cheeta, tarzan, jane);
#endif
#if 0  //    ָ������
    #define SQUAERS (64)

    const double CROP = 2E16; // ����С�����������
    double current, total;
    int count = 1;

    printf("square      grains      total   ");
    printf("fraction of \n");
    printf("            added       grains  ");
    printf("world total\n");
    total = current = 1.0;  /* ��һ��������ʼ */
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
 * @brief ����ת��
 *  1.������ת�����ֱ��ʽʱ��unsigned signed char short �Զ�ת����int
 *  2.��������������㣬����ֵ���ֱ�ת�����������͵ĸ��߼���
 *  3.���͵ļ���Ӹ���������long double/ double / float/ unsigned long long / long long /unsigned long
 *                          long / unsigned int / int
 *  4.��ֵ���ʽ����У���������ս���ᱻת���ɸ�ֵ���������� �����͵������ͽ�����
 *  5.������������ʱ��char  short ��ת����int, float ��ת����double
 *
 *  ǿ������ת��  (������)
 *
 */
#if 1
    const int S_PER_M = 60;          // 1���ӵ�����
    const int S_PER_H = 3600;        // 1Сʱ�ķ�����
    const double M_PER_K = 0.62137;  // 1�����Ӣ����

    double distk, distm;  // �ܹ��ľ��� ���ֱ��Թ����Ӣ��Ϊ��λ��
    double rate;          // ƽ���ٶ� ����λ��Ӣ��/Сʱ��
    int min, sec;         // �ܲ���ʱ���Է��Ӻ���Ϊ��λ��
    int time;             // �ܲ���ʱ������Ϊ��λ��
    double mtime;         // ��1Ӣ����Ҫ��ʱ�� ����λ���룩
    int mmin, msec;       // ��1Ӣ����Ҫ��ʱ�� �����Ӻ��뵥λ��

    printf("This porgram converts your time for a metric race\n");  // �����������ʱ��ת��Ϊ���Ʊ���
    printf("to a time for running a mile and to your average\n");   // ����һӢ���ʱ������ƽ��ʱ��
    printf("spead in miles per hour.\n");                           // ��Ӣ��ÿСʱΪ��λ��
    printf("Please enter, in kilometers, the distance run.\n");     // �����룬�Թ���Ϊ��λ���ܲ�����
    scanf("%lf", &distk);
    printf("Next  enter the time in minutes and seconds.\n");  // �������Էֺ���Ϊ��λ����ʱ�䡣
    printf("Begin by entering the minutes.\n");
    scanf("%d", &min);
    printf("Now enter the seconds.\n");                        // ��������������
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