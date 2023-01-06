/**
 * @file 16_advanced_data_representation.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2023-01-05
 *
 * @copyright Copyright (c) 2023
 *
 */

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define TSIZE 45
#define FMAX  5
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
struct film {
    char title[TSIZE];
    int rating;
};

struct film_link {
    char title[TSIZE];
    int rating;
    struct film_link *next;
};
/* Private function prototypes -----------------------------------------------*/
char *s_gets(char *st, int n);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main(int argc, char *argv[]) {
#if 0
    struct film movies[FMAX];
    int i = 0;
    int j;

    puts("Enter first movie title:");
    while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL && movies[i].title[0] != '\0') {
        puts("Enter your rating <0-10>:");
        scanf("%d", &movies[i++].rating);
        while (getchar() != '\n') {
            continue;
        }
        puts("Enter next movie title (empty line to stop):");
    }
    if (i == 0) {
        printf("No data entered. ");
    } else {
        printf("Here is the movie list:\n");
    }
    for (j = 0; j < i; j++) {
        printf("Movie: %s Rating: %d\n", movies[j].title, movies[j].rating);
    }
    printf("Bye!\n");
#endif

#if 0
    struct film_link *head = NULL;
    struct film_link *prev, *current;
    char input[TSIZE];

    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {
        current = (struct film_link *)malloc(sizeof(struct film_link));
        if (head == NULL) {
            head = current;
        } else {
            prev->next = current;
        }
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your tating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n') {
            continue;
        }
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }

    /* 显示链表 */
    if (head == NULL) {
        printf("No data entered. ");
    } else {
        printf("Here is the movie list:\n");
    }
    current = head;
    while (current != NULL) {
        printf("Movie: %s Rating: %d\n", current->title, current->rating);
        current = current->next;
    }

    /* 释放内存 */
    current = head;
    while (current != NULL) {
        current = head;
        head = current->next;
        free(current);
    }
    printf("Bye!\n");

#endif
    return 0;
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
