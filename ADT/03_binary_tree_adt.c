/**
 * @file 03_binary_tree_adt.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2023-01-10
 * @note
 *  类型名：    二叉查找树
 *  类型属性：  二叉树要么是空节点的集合（空树），要么是有一个根节点的节点集合
 *              每个节点都有两个子树，叫做左子树和右子树
 *              每个子树本身也是一个二叉树，也有可能是空树
 *              二叉查找树是一个有序的二叉树，每个节点包含一个项
 *              左子树的所有项都在根节点的前面，右子树的所有项都在根节点项的后面
 *  类型操作：  初始化树为空
 *              确定树是否为空
 *              确定树是否已满
 *              确定树中的项数
 *              在树中添加一个项
 *              在树中删除一个项
 *              在树中查找一个项
 *              在树种访问一个项
 *              清空树
 * @copyright Copyright (c) 2023
 *
 */
/* Includes ------------------------------------------------------------------*/
#include "03_binary_tree_adt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
typedef struct pair {
    Trnode *parent;
    Trnode *child;
} Pair;
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static Trnode *make_node(const Item *pi);
static bool to_left(const Item *i1, const Item *i2);
static bool to_right(const Item *i1, const Item *i2);
static void add_node(Trnode *new_node, Trnode *root);
static void in_order(const Trnode *root, void (*pfun)(Item item));
static Pair seek_item(const Item *pi, const Tree *ptree);
static void delete_node(Trnode **ptr);
static void delete_all_nodes(Trnode *ptr);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief initialize tree
 *
 * @param ptree Point to a tree
 */
void initialize_tree(Tree *ptree) {
    ptree->root = NULL;
    ptree->size = 0;
}

/**
 * @brief Detects whether the tree is empty
 *
 * @param ptree Point to a tree
 * @return true Tree empty
 * @return false Tree not empty
 */
bool tree_is_empty(const Tree *ptree) {
    if (ptree->root == NULL) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Detects whether the tree is full
 *
 * @param ptree Point to a tree
 * @return true Tree full
 * @return false Tree not full
 */
bool tree_is_full(const Tree *ptree) {
    if (ptree->size == MAXITEMS) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Confirm the number of items in the tree
 *
 * @param ptree Point to tree
 * @return int Returns the number of items in the tree
 */
int tree_item_count(const Tree *ptree) {
    return ptree->size;
}

/**
 * @brief Add an item to the tree
 *
 * @param pi Points to the item to be added
 * @param ptree Point to tree
 * @return true Successfully added
 * @return false Fail to add
 */
bool add_item(const Item *pi, Tree *ptree) {
    Trnode *new_node;
    if (tree_is_full(ptree)) {
        fprintf(stderr, "Tree is full.\n");
        return false;
    }
    new_node = make_node(pi);
    if (new_node == NULL) {
        fprintf(stderr, "Couldn't create node.\n");
        return false;
    }
    ptree->size++;

    if (ptree->root == NULL) {
        ptree->root = new_node;
    } else {
        add_node(new_node, ptree->root);
    }
    return true;
}

/**
 * @brief Look for an item in the tree
 *
 * @param pi Point to the item to be found
 * @param ptree Point to tree
 * @return true Successfully found
 * @return false Fail to found
 */
bool in_tree(const Item *pi, const Tree *ptree) {
    return (seek_item(pi, ptree).child == NULL) ? false : true;
}

/**
 * @brief Delete an item in the tree
 *
 * @param pi Points to the item to be delete
 * @param ptree Point to tree
 * @return true Successfully delete
 * @return false Fail to delete
 */
bool delete_item(const Item *pi, Tree *ptree) {
    Pair look;

    look = seek_item(pi, ptree);
    if (look.child == NULL) {
        return false;
    }

    if (look.parent == NULL) {
        delete_node(&ptree->root);
    } else if (look.parent->left == look.child) {
        delete_node(&look.parent->right);
    } else {
        delete_node(&look.parent->left);
    }
    ptree->size--;

    return true;
}

/**
 * @brief Apply the function to every entry in the tree
 *
 * @param ptree Point to tree
 * @param pfun Points to a function that takes an argument of type Item and returns no value
 */
void traverse(const Tree *ptree, void (*pfun)(Item item)) {
    if (ptree != NULL) {
        in_order(ptree->root, pfun);
    }
}

/**
 * @brief Delete everything in the tree
 *
 * @param ptree Point to tree
 */
void delete_all(Tree *ptree) {
    if (ptree != NULL) {
        delete_all_nodes(ptree->root);
    }
    ptree->root = NULL;
    ptree->size = 0;
}

/**
 * @brief Generate a node
 *
 * @param pi Point to the item
 * @return Trnode* Return a node
 */
static Trnode *make_node(const Item *pi) {
    Trnode *new_node;

    new_node = (Trnode *)malloc(sizeof(Trnode));
    if (new_node != NULL) {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}

/**
 * @brief
 *
 * @param i1
 * @param i2
 * @return true
 * @return false
 */
static bool to_left(const Item *i1, const Item *i2) {
    int comp1;

    if ((comp1 = strcmp(i1->petname, i2->petname)) < 0) {
        return true;
    } else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) < 0) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief
 *
 * @param i1
 * @param i2
 * @return true
 * @return false
 */
static bool to_right(const Item *i1, const Item *i2) {
    int comp1;
    if ((comp1 = strcmp(i1->petname, i2->petname)) > 0) {
        return true;
    } else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) > 0) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Add a new node in the tree
 *
 * @param new_node New node
 * @param root The following node of the tree
 */
static void add_node(Trnode *new_node, Trnode *root) {
    if (to_left(&new_node->item, &root->item)) {
        if (root->left == NULL) {
            root->left = new_node;
        } else {
            add_node(new_node, root->left);
        }
    } else if (to_right(&new_node->item, &root->item)) {
        if (root->right == NULL) {
            root->right = new_node;
        } else {
            add_node(new_node, root->right);
        }
    } else {
        fprintf(stderr, "location error in addnode().\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Apply the function to each entry of the tree
 *
 * @param root The following node of the tree
 * @param pfun Functions that act on each node
 */
static void in_order(const Trnode *root, void (*pfun)(Item item)) {
    if (root != NULL) {
        in_order(root->left, pfun);
        (*pfun)(root->item);
        in_order(root->right, pfun);
    }
}

/**
 * @brief Look for the current item in the tree
 *
 * @param pi Point to item
 * @param ptree Point to a tree
 * @return Pair
 */
static Pair seek_item(const Item *pi, const Tree *ptree) {
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL) {
        return look;
    }

    while (look.child != NULL) {
        if (to_left(pi, &(look.child->item))) {
            look.parent = look.child;
            look.child = look.child->left;
        } else if (to_right(pi, &(look.child->item))) {
            look.parent = look.child;
            look.child = look.child->right;
        } else {
            break;
        }
    }

    return look;
}

/**
 * @brief Delete a node
 *
 * @param ptr Point to tree node
 */
static void delete_node(Trnode **ptr) {
    Trnode *temp;

    if ((*ptr)->left == NULL) {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    } else if ((*ptr)->right == NULL) {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    } else {
        /* 找到重新连接右子树的位置 */
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right) {
            continue;
        }
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
}

/**
 * @brief Delete all nodes
 *
 * @param ptr Point to tree node
 */
static void delete_all_nodes(Trnode *ptr) {
    Trnode *pright;

    if (ptr != NULL) {
        pright = ptr->right;
        delete_all_nodes(ptr->left);
        free(ptr);
        delete_all_nodes(pright);
    }
}
