/**
 * @file mall.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2023-01-09
 *
 * @copyright Copyright (c) 2023
 *
 */
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "02_queue_adt.h"
/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define MIN_PER_HR 60.0
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
bool newcustomer(double x);
Item customertime(long when);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main(int argc, char *argv[]) {
    Queue line;
    Item temp;               // 新顾客数据
    int hours;               // 模拟的小时数
    int perhour;             // 每小时平均多少位顾客
    long cycle, cyclelimit;  // 循环计数器，计数器上限
    long turnaways = 0;      // 因队列已满被拒的顾客数量
    long customers = 0;      // 加入队列的顾客数量
    long served = 0;         // 在模拟期间咨询过sigmund的顾客数量
    long sum_line = 0;       // 累计的队列总长
    int wait_time = 0;       // 从当前到sigmund空闲所需的时间
    double min_per_cust;     // 顾客到来的平均时间
    long line_wait = 0;      // 队列累计的等待时间

    initialize_queue(&line);
    srand((unsigned int)time(0));
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) {
            if (queue_is_full(&line)) {
                turnaways++;
            } else {
                customers++;
                temp = customertime(cycle);
                enqueue(temp, &line);
            }
        }
        if (wait_time <= 0 && queue_is_empty(&line)) {
            dequeue(&temp, &line);
            wait_time = temp.processtime;
            line_wait += cycle - temp.processtime;
            served++;
        }
        if (wait_time > 0) {
            wait_time--;
        }
        sum_line += queue_item_count(&line);
    }
    if (customers > 0) {
        printf("customers accepted: %ld\n", customers);
        printf("  customers served: %ld\n", served);
        printf("      turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f minutes\n", (double)sum_line / cyclelimit);
        printf(" average wait time: %.2f minutes\n", (double)line_wait / served);
    } else {
        puts("No custormers!");
    }
    empty_the_queue(&line);
    puts("Bye!");
    return 0;
}

bool newcustomer(double x) {
    if (rand() * x / RAND_MAX < 1) {
        return true;
    } else {
        return false;
    }
}

Item customertime(long when) {
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}