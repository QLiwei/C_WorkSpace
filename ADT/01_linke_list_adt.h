#ifndef __LINKED_LIST_ADT__
#define __LINKED_LIST_ADT__

#include <stdbool.h>

#define TSIZE   45

struct film {
    char title[TSIZE];
    int rating;
};
typedef struct film Item;

typedef struct node {
    Item item;
    struct node *next;
} Node;
typedef Node *List;

/* 操作：       初始化一个链表                                                      */
/* 前提条件：   plist指向一个链表                                                   */
/* 后置条件：   链表初始化为空                                                      */
void initialize_list(List *plist);

/* 操作：       确定链表是否为空                                                    */
/* 前提条件：   plist指向一个链表                                                   */
/* 后置条件：   如果链表为空，该函数返回true; 否则返回false                         */
bool list_is_empty(const List *plist);

/* 操作：       确定链表是否已满                                                    */
/* 前提条件：   plist指向一个链表                                                   */
/* 后置条件：   如果链表已满，该函数返回true; 否则返回false                         */
bool list_is_full(const List *plist);

/* 操作：       确定链表中的项数                                                    */
/* 前提条件：   plist指向一个链表                                                   */
/* 后置条件：   该函数返回链表中的项数                                              */
unsigned int list_item_count(const List *plist);

/* 操作：       在链表的末尾添加项                                                  */
/* 前提条件：   item是一个待添加至链表的项，plist指向一个链表                       */
/* 后置条件：   如果可以，该函数在链表末尾添加一项，且返回true; 否则返回false       */
bool add_item(Item item, List *plist);

/* 操作：       把函数作用于链表中的每一次项                                        */
/* 前提条件：   plist指向一个链表                                                   */
/*              pfun指向一个函数，该函数接受一个Item类型的参数，且无返回值          */
/* 后置条件：   pfun指向的函数作用于链表的每一项一次                                */
void traverse(const List *plist, void(pfun)(Item item));

/* 操作：       释放已分配的内存                                                    */
/* 前提条件：   plist指向一个链表                                                   */
/* 后置条件：   释放了为链表分配的所有内存，链表设置为空                            */
void empty_the_list(List *plist);

#endif /* __LINKED_LIST_ADT__ */
