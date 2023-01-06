/**
 * @file films.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2023-01-06
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
void showmovies(Item item);
char *s_gets(char *st, int n);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main(int argc, char *argv[]) {
    List movies;
    Item temp;

    initialize_list(&movies);
    if (list_is_full(&movies)) {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(EXIT_FAILURE);
    }

    puts("Enter first movie title:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0') {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        while (getchar() != '\n') {
            continue;
        }
        if (add_item(temp, &movies) == false) {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        if (list_is_full(&movies)) {
            puts("The list is mow full.");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }

    if (list_is_empty(&movies)) {
        printf("No data entered. ");
    } else {
        printf("Here is the movie list:\n");
        traverse(&movies, showmovies);
    }
    printf("You entered %d movies.\n", list_item_count(&movies));

    empty_the_list(&movies);
    printf("Bye!\n");
    return 0;
}

void showmovies(Item item) {
    printf("Movie: %s Rating: %d\n", item.title, item.rating);
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
