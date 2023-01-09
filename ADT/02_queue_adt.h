#ifndef __02_QUEUE_ADT_H__
#define __02_QUEUE_ADT_H__

#include <stdbool.h>

typedef struct item {
    long arrive;       // 一位顾客加入队列的时间
    int processtime;   // 该顾客咨询时花费的时间
} Item;

#define MAXQUEUE 10

typedef struct node {
    Item item;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;  // 指向队列首项的指针
    Node *rear;   // 指向队列尾项的指针
    int items;    // 队列中的项数
} Queue;

/* 操作：       初始化队列                                                      */
/* 前提条件：   pq指向一个队列                                                  */
/* 后置条件：   队列初始化为空                                                  */
void initialize_queue(Queue *pq);

/* 操作：       检测队列是否已满                                                */
/* 前提条件：   pq指向之前初始化的队列                                          */
/* 后置条件：   如果队列已满则返回true，否则返回false                           */
bool queue_is_full(const Queue *pq);

/* 操作：       检测队列是否为空                                                */
/* 前提条件：   pq指向之前初始化的队列                                          */
/* 后置条件：   如果队列为空则返回true，否则返回false                           */
bool queue_is_empty(const Queue *pq);

/* 操作：       确认队列中的项数                                                */
/* 前提条件：   pq指向之前初始化的队列                                          */
/* 后置条件：   返回队列中的项数                                                */
int queue_item_count(const Queue *pq);

/* 操作：       在队列末尾添加项                                                */
/* 前提条件：   pq指向之前初始化的队列                                          */
/*              item 是要被添加在队列末尾的项                                   */
/* 后置条件：   如果队列不为空，item将被添加在队列的末尾                        */
/*              该函数返回true；否则，队列不改变，该函数返回false               */
bool enqueue(Item item, Queue *pq);

/* 操作：       从队列开头删除项                                                */
/* 前提条件：   pq指向之前初始化的队列                                          */
/* 后置条件：   如果队列不为空，队列首端的item将被拷贝在*pitem中                */
/*              并被删除，且函数返回true                                        */
/*              如果该操作使得队列为空，则重置队列为空                          */
/*              如果队列在操作前为空，该函数返回false                           */
bool dequeue(Item *pitem, Queue *pq);

/* 操作：       清空队列                                                        */
/* 前提条件：   pq指向之前初始化的队列                                          */
/* 后置条件：   队列被清空                                                      */
void empty_the_queue(Queue *pq);

#endif /* __02_QUEUE_ADT_H__ */
