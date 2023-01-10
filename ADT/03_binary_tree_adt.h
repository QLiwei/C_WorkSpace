#ifndef __03_BINARY_TREE_ADT_H__
#define __03_BINARY_TREE_ADT_H__

#include <stdbool.h>

#define SLEN 20
typedef struct item {
    char petname[SLEN];
    char petkind[SLEN];
} Item;

#define MAXITEMS 10

typedef struct trnode {
    Item item;
    struct trnode *left;
    struct trnode *right;
} Trnode;

typedef struct tree {
    Trnode *root; /* 指向根节点指针 */
    int size;
} Tree;

/* 操作：       把树初始化为空                                                      */
/* 前提条件：   ptree指向一个树                                                     */
/* 后置条件：   树被初始化为空                                                      */
void initialize_tree(Tree *ptree);

/* 操作：       确定树是否为空                                                      */
/* 前提条件：   ptree指向一个树                                                     */
/* 后置条件：   如果树为空，该函数返回true，否则，返回false                         */
bool tree_is_empty(const Tree *ptree);

/* 操作：       确定树是否已满                                                      */
/* 前提条件：   ptree指向一个树                                                     */
/* 后置条件：   如果树已满，该函数返回true，否则，返回false                         */
bool tree_is_full(const Tree *ptree);

/* 操作：       确定树的项数                                                        */
/* 前提条件：   ptree指向一个树                                                     */
/* 后置条件：   返回树的项数                                                        */
int tree_item_count(const Tree *ptree);

/* 操作：       在树中添加一项                                                      */
/* 前提条件：   pi是待添加项的地址                                                  */
/*              ptree指向一个已初始化的树                                           */
/* 后置条件：   添加成功，该函数返回true，否则，返回false                           */
bool add_item(const Item *pi, Tree *ptree);

/* 操作：       在树中查找一项                                                      */
/* 前提条件：   pi指向一个项                                                        */
/*              ptree指向一个已初始化的树                                           */
/* 后置条件：   查找成功，该函数返回true，否则，返回false                           */
bool in_tree(const Item *pi, const Tree *ptree);


/* 操作：       在树中删除一项                                                      */
/* 前提条件：   pi是待删除项的地址                                                  */
/*              ptree指向一个已初始化的树                                           */
/* 后置条件：   删除成功，该函数返回true，否则，返回false                           */
bool delete_item(const Item *pi, Tree *ptree);

/* 操作：       把函数应用于树中的每一项                                            */
/* 前提条件：   ptree指向一个已初始化的树                                           */
/*              pfun指向一个函数                                                    */
/*              该函数接受一个Item类型的参数，并无返回值                            */
/* 后置条件：   pfun指向的这个函数为树中的每一项执行一次                            */
void traverse(const Tree *ptree, void (*pfun)(Item item));


/* 操作：       删除树中的所有内容                                                  */
/* 前提条件：   ptree指向一个已初始化的树                                           */
/* 后置条件：   树为空                                                              */
void delete_all(Tree *ptree);


#endif /* __03_BINARY_TREE_ADT_H__ */