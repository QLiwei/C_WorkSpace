/**
 * @file 01_linkd_list_adt.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2023-01-06
 *  @note
 *     链表操作：
 *  1.初始化一个空链表
 *  2.在链表末尾添加一个新项
 *  3.确认链表是否为空
 *  4.确认链表是否已满
 *  5.确认链表中的项数
 *  6.访问链表中的每一项执行某些操作，如显示该项
 *
 *  7.在链表的任意位置插入一个项
 *  8.移除链表中的一个项
 *  9.在链表中检索一个项
 *  10.用另一个项替换链表中的一个项
 *  11.在链表中搜索一个项
 *
 * 类型名：     简单链表
 * 类型属性：   可以存储一系列项
 * 类型操作：   初始化链表为空
 *              确认链表为空
 *              确认链表已满
 *              在链表末尾添加项
 *              遍历链表，处理链表中的项
 *              清空链表
 *
 * @copyright Copyright (c) 2023
 *
 */
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#include "01_linke_list_adt.h"

/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void copy_to_node(Item item, Node *pnode);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief Initialize linke list
 *
 * @param plist Linked list pointer
 */
void initialize_list(List *plist) {
    *plist = NULL;
}

/**
 * @brief Whether the list is empty
 *
 * @param plist Points to a linked list
 * @return true The linked list is empty
 * @return false The list is not empty
 */
bool list_is_empty(const List *plist) {
    if (*plist == NULL) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Whether the linked list is full
 *
 * @param plist Points to a linked list
 * @return true The linked list is full
 * @return false The list is not full
 */
bool list_is_full(const List *plist) {
    Node *pt;
    bool full;

    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL) {
        full = true;
    } else {
        full = false;
    }
    free(pt);

    return full;
}

/**
 * @brief The number of entries in the list
 *
 * @param plist Points to a linked list
 * @return unsigned int The number of entries in the list
 */
unsigned int list_item_count(const List *plist) {
    unsigned int count = 0;
    Node *pnode = *plist;

    while (pnode != NULL) {
        ++count;
        pnode = pnode->next;
    }
    return count;
}

/**
 * @brief Want to add an item to the list
 *
 * @param item
 * @param plist Points to a linked list
 * @return true successfully added
 * @return false fail to add
 */
bool add_item(Item item, List *plist) {
    Node *pnew;
    Node *scan = *plist;

    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL) {
        return false;
    }

    copy_to_node(item, pnew);
    pnew->next = NULL;
    if (scan == NULL) {
        *plist = pnew;
    } else {
        while (scan->next != NULL) {
            scan = scan->next;
        }
        scan->next = pnew;
    }
    return true;
}

/**
 * @brief Manipulate an item in a linked list
 *
 * @param plist Points to a linked list
 * @param pfun operating function
 */
void traverse(const List *plist, void(pfun)(Item item)) {
    Node *pnode = *plist;

    while (pnode != NULL) {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

/**
 * @brief Clear linked list
 *
 * @param plist Points to a linked list
 */
void empty_the_list(List *plist) {
    Node *psave;

    while (*plist != NULL) {
        psave = (*plist)->next;
        free(*plist);
        *plist = psave;
    }
}

/**
 * @brief Replication node
 *
 * @param item
 * @param pnode Points to a linked list
 */
static void copy_to_node(Item item, Node *pnode) {
    pnode->item = item;
}