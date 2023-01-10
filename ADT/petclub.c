/**
 * @file petclub.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2023-01-10
 *
 * @copyright Copyright (c) 2023
 *
 */
/* Includes ------------------------------------------------------------------*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "03_binary_tree_adt.h"
/* Private includes ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
char meun(void);
void add_pet(Tree *pt);
void drop_pet(Tree *pt);
void show_pets(const Tree *pt);
void find_pet(const Tree *pt);
void printf_item(Item item);
void uppercase(char *str);
char *s_gets(char *st, int n);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main(int argc, char *argv[]) {
    Tree pets;
    char choice;

    initialize_tree(&pets);
    while ((choice = meun()) != 'q') {
        switch (choice) {
        case 'a':
            add_pet(&pets);
            break;
        case 'l':
            show_pets(&pets);
            break;
        case 'f':
            find_pet(&pets);
            break;
        case 'n':
            printf("%d pets is club\n", tree_item_count(&pets));
            break;
        case 'd':
            drop_pet(&pets);
            break;
        default:
            puts("Switching error");
            break;
        }
    }
    delete_all(&pets);
    puts("Bye.");

    return 0;
}

char meun(void) {
    int ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet          l) show list of pets");
    puts("n) number of pets     f) find pets");
    puts("d) delete a pet       q) quit");

    while ((ch = getchar()) != EOF) {
        while (getchar() != '\n') {
            continue;
        }
        ch = tolower(ch);
        if (strchr("alrfndq", ch) == NULL) {
            puts("Please enter an a, l, f, n, d, or q:");
        } else {
            break;
        }
    }
    if (ch == EOF) {
        ch = 'q';
    }

    return ch;
}

void add_pet(Tree *pt) {
    Item temp;

    if (tree_is_full(pt)) {
        puts("No room in the club!");
    } else {
        puts("Please enter name of pet:");
        s_gets(temp.petname, SLEN);
        puts("Please enter pet kind:");
        s_gets(temp.petkind, SLEN);
        uppercase(temp.petname);
        uppercase(temp.petkind);
        add_item(&temp, pt);
    }
}

void drop_pet(Tree *pt) {
    Item temp;

    if (tree_is_empty(pt)) {
        puts("No entries!");
        return ;
    }

    puts("Please enter name of pet you wish to delete:");
    s_gets(temp.petname, SLEN);
    puts("Please enter pet kind:");
    s_gets(temp.petkind, SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s ", temp.petname, temp.petkind);
    if (delete_item(&temp, pt)) {
        printf("is dropped from the club.\n");
    } else {
        printf("is not a member.\n");
    }
}

void show_pets(const Tree *pt) {
    if (tree_is_empty(pt)) {
        puts("No entries!");
    } else {
        traverse(pt, printf_item);
    }
}

void find_pet(const Tree *pt) {
    Item temp;

    if (tree_is_empty(pt)) {
        puts("No entries!");
        return ;
    }

    puts("Please enter name of pet you wish to find:");
    s_gets(temp.petname, SLEN);
    puts("Please enter pet kind:");
    s_gets(temp.petkind, SLEN);
    uppercase(temp.petname);
    uppercase(temp.petkind);
    printf("%s the %s ", temp.petname, temp.petkind);
    if (in_tree(&temp, pt)) {
        printf("is a menber.\n");
    } else {
        printf("is not a member.\n");
    }
}

void printf_item(Item item) {
    printf("Pet: %-19s Kind: %-19s\n", item.petname, item.petkind);
}
void uppercase(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

/**
 * @brief Gets the input character and converts it to a string
 *
 * @param st String pointer
 * @param n String length
 * @return char* String pointer
 */
char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find) {
            *find = '\0';
        } else {
            while (getchar() != '\n') {
                continue;
            }
        }
        return ret_val;
    }
}
