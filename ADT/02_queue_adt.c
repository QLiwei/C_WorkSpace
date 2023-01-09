/**
 * @file 02_queue_adt.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2023-01-09
 *
 * @note
 *  类型名：    队列
 *  类型属性：  可以存储一系列项
 *  类型操作：  初始化队列为空
 *              确定队列为空
 *              确定队列已满
 *              确认队列中的项数
 *              在队列末尾添加项
 *              在队列开头删除或恢复项
 *              清空队列
 *
 * @copyright Copyright (c) 2023
 *
 */
/* Includes ------------------------------------------------------------------*/
#include "02_queue_adt.h"

#include <stdio.h>
#include <stdlib.h>

/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void copy_to_node(Item item, Node *pn);
static void copy_to_item(Node *pn, Item *pi);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief Initialize queue
 *
 * @param pq Point to a queue
 */
void initialize_queue(Queue *pq) {
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

/**
 * @brief Detects whether the queue is full
 *
 * @param pq Point to a queue
 * @return true Queue full
 * @return false Queue not full
 */
bool queue_is_full(const Queue *pq) {
    return pq->items == MAXQUEUE;
}

/**
 * @brief Detects whether the queue is empty
 *
 * @param pq Point to a queue
 * @return true Queue empty
 * @return false Queue not empty
 */
bool queue_is_empty(const Queue *pq) {
    return pq->items == 0;
}

/**
 * @brief Confirm the number of items in the queue
 *
 * @param pq Point to a queue
 * @return int Returns the number of items in the queue
 */
int queue_item_count(const Queue *pq) {
    return pq->items;
}

/**
 * @brief Adds an item to the end of the queue
 *
 * @param item Is the item to be added to the end of the queue
 * @param pq Point to a queue
 * @return true Successfully added
 * @return false Fail to add
 */
bool enqueue(Item item, Queue *pq) {
    Node *pnew;

    if (queue_is_full(pq)) {
        return false;
    }
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL) {
        fprintf(stderr, "Unable to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    copy_to_node(item, pnew);
    pnew->next = NULL;

    if (queue_is_empty(pq)) {
        pq->front = pnew;
    } else {
        pq->rear->next = pnew;
    }
    pq->rear = pnew;
    pq->items++;

    return true;
}

/**
 * @brief Removes an item from the beginning of the queue
 *
 * @param pitem The item at the top of the queue will be copied in *pitem
 * @param pq Point to a queue
 * @return true Successfully delete
 * @return false Fail to delete
 */
bool dequeue(Item *pitem, Queue *pq) {
    Node *pt;

    if (queue_is_empty(pq)) {
        return false;
    }
    copy_to_item(pq->front, pitem);
    pt = pq->front;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if (pq->items == 0) {
        pq->rear = NULL;
    }

    return true;
}

/**
 * @brief Clear the queue
 *
 * @param pq Point to a queue
 */
void empty_the_queue(Queue *pq) {
    Item dummy;
    while (!queue_is_empty(pq)) {
        dequeue(&dummy, pq);
    }
}

/**
 * @brief Replication node
 *
 * @param item Points to a item
 * @param pn Points to a node
 */
static void copy_to_node(Item item, Node *pn) {
    pn->item = item;
}

/**
 * @brief Replication item
 *
 * @param pn Points to a node
 * @param pi Points to a item
 */
static void copy_to_item(Node *pn, Item *pi) {
    *pi = pn->item;
}