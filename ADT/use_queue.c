/**
 * @file use_queue.c
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

#include "02_queue_adt.h"
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
int main(int argc, char *argv[]) {
    Queue line;
    Item temp;
    char ch;

    initialize_queue(&line);
    puts("Testing the Queue interface. Type a to add a value.");
    puts("type d to delete a value, and type q to quit.");
    while ((ch = getchar()) != 'q') {
        if (ch != 'a' && ch != 'd') {
            continue;
        }
        if (ch == 'a') {
            printf("Integer to add: ");
            scanf("%d", &temp);
            if (!queue_is_full(&line)) {
                printf("Putting %d into queue\n", temp);
                enqueue(temp, &line);
            } else {
                puts("queue is full!");
            }
        } else {
            if (queue_is_empty(&line)) {
                puts("Nothing to delete!");
            } else {
                dequeue(&temp, &line);
                printf("Removing %d from queue\n", temp);
            }
        }
        printf("%d items in queue\n", queue_item_count(&line));
        puts("Type a to add, d to delete, q to quit:");
    }
    empty_the_queue(&line);
    puts("Bye!\n");

    return 0;
}