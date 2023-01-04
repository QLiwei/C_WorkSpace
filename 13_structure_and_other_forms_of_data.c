/**
 * @file 13_structure_and_other_forms_of_data.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2023-01-04
 *
 * @copyright Copyright (c) 2023
 *
 */
/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define MAXTITL 41  // 书名的最大长度+1
#define MAXAUTL 31  // 作者姓名的最大长度+1
#define LEN     81
#define FUNDLEN 50
#define NLEN    30
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

const char *msgs[5] = {"   Thanks you for the wonderful evening, ", "You certainly prove that a ",
                       "is a special kind of guy. We must get together", "over a delicious ", " and have a few laughs"};

struct names {
    char first[LEN];
    char last[LEN];
};

struct guy {
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};

struct funds {
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

struct namect {
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};

struct name {
    char *fname;
    char *lname;
    int letters;
};

struct flex {
    int count;
    double average;
    double scores[];
};

enum spectrum { red, orange, yellow, green, bule, violet };
const char *colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};

/* Private function prototypes -----------------------------------------------*/
char *s_gets(char *st, int n);
double sum(double, double);
double sum2(const struct funds *money);
double sum3(const struct funds moolah);
void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);

void getinfo2(struct name *);
void makeinfo2(struct name *);
void showinfo2(const struct name *);
void cleanup(struct name *);

void showFlex(const struct flex *p);

char showmenu(void);
void eatline(void);
void show(void (*fd)(char *), char *str);
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);
void Dummy(char *);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main(int argc, char *argv[]) {
#if 0
    struct book library;

    printf("Please enter the book title.\n");
    s_gets(library.title, MAXTITL);
    printf("Now enter the author.\n");
    s_gets(library.author, MAXAUTL);
    printf("Now enter the value.\n");
    scanf("%f", &library.value);

    printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
    printf("%s: \"%s\" ($%.2f)\n", library.title, library.author, library.value);
    printf("Done.\n");
#endif

#if 0
    #define MAXBKS 100
    struct book library[MAXBKS];
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0') {
        printf(" Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n') {
            continue;
        }
        if (count < MAXBKS) {
            printf("Enter the next title.\n");
        }
    }

    if (count > 0) {
        printf("Here is the list of your book:\n");
        for (index = 0; index < count; index++) {
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        }
    } else {
        printf("No book? Too bad.\n");
    }
#endif

#if 0
    struct guy fellow = {
        {"Even", "Villard"},
        "grilled salmon",
        "personality coach",
        68112.00
    };

    printf("Dear %s, \n\n", fellow.handle.first);
    printf("%s%s.\n", msgs[0], fellow.handle.first);
    printf("%s%s\n", msgs[1], fellow.job);
    printf("%s\n", msgs[2]);
    printf("%s%s%s", msgs[3], fellow.favfood, msgs[4]);
    if (fellow.income > 150000.0) {
        puts("!!");
    } else if (fellow.income > 75000) {
        puts("!");
    } else {
        puts(".");
    }
    printf("\n%40s%s\n", " ", "See you soon,");
    printf("%40s%s\n", " ", "Shalala");

#endif

#if 0
    struct guy fellow[2] = {{{"Even", "Villard"}, "grilled salmon", "personality coach", 68112.00},
                            {{"Rodney", "Swillbelly"}, "tripe", "tabloid editor", 432400.00}};

    struct guy *him;

    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    him = &fellow[0];
    printf("pointer #1: %p #2: %p\n", him, him + 1);
    printf("him->income is $%.2f: (*him).income is $%.2f\n", him->income, (*him).income);
    him++;
    printf("him->favfood is %s: him->handle.last is %s\n", him->favfood, him->handle.last);
#endif
#if 0
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };
    printf("Stan has a total of $%.2f.\n", sum(stan.bankfund, stan.savefund));
#endif

#if 0
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };
    printf("Stan has a total of $%.2f.\n", sum2(&stan));
#endif

#if 0
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };
    printf("Stan has a total of $%.2f.\n", sum3(stan));
#endif

#if 0
    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
#endif

#if 0
    struct name person;

    getinfo2(&person);
    makeinfo2(&person);
    showinfo2(&person);
    cleanup(&person);
#endif
/**
 * @brief 伸缩型数组
 *
 */
#if 0
    struct flex *pf1, *pf2;
    int n = 5;
    int i;
    int tot = 0;

    pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
    pf1->count = n;
    for (i = 0; i < n; i++) {
        pf1->scores[i] = 20.0 - i;
        tot += pf1->scores[i];
    }
    pf1->average = tot / n;
    showFlex(pf1);

    n = 9;
    tot = 0;
    pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
    pf2->count = n;
    for (i = 0; i < n; i++) {
        pf2->scores[i] = 20.0 - i / 2.0;
        tot += pf2->scores[i];
    }
    pf2->average = tot / n;
    showFlex(pf2);
#endif

#if 0
    #define MAXBKS 10
    struct book library[MAXBKS];
    int count = 0;
    int index, filecount;
    FILE *pbooks;
    int size = sizeof(struct book);

    if ((pbooks = fopen("book.dat", "a+b")) == NULL) {
        fputs("Can't open book.dat file\n", stderr);
        exit(EXIT_FAILURE);
    }

    rewind(pbooks); // 定位到文件开始
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
        if (count == 0) {
            puts("Current contents of book.dat:");
        }
        printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
        count++;
    }
    filecount = count;
    if (count == MAXBKS) {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }

    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");

    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0') {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n') {
            continue;
        }
        if (count < MAXBKS) {
            puts("Enter the next title.");
        }
    }

    if (count > 0) {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++) {
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        }
        fwrite(&library[filecount], size, count - filecount, pbooks);
    }

#endif
/**
 * @brief union
 * struct owner {
 *      char socsecurity[12];
 * ...
 * }
 *
 * struct leasecompany {
 *      char name[40];
 *      char headquarters[40];
 * ...
 * }
 *
 * union data {
 *      struct owner owncar;
 *      struct leasecompany leasecar;
 * }
 * struct car_data {
 *      char make[15];
 *      int status; // 私有为0 租赁为1
 *      union data ownerinfo;
 *      ....
 * }
 *
 */

/**
 * @brief enumerated type
 * enum常量是int类型
 *
 */
#if 0
    char choice[LEN];
    enum spectrum color;
    bool color_is_found = false;

    puts("Enter a color (empty line to quit):");
    while (s_gets(choice, LEN) != NULL && choice[0] != '\0') {
        for (color = red; color <= violet; color++) {
            if (strcmp(choice, colors[color]) == 0) {
                color_is_found = true;
                break;
            }
        }
        if (color_is_found) {
            switch (color) {
            case red:
                puts("Roses are red.");
                break;
            case orange:
                puts("Poppies are orange.");
                break;
            case yellow:
                puts("Grase is green.");
                break;
            case green:
                puts("Grass is green.");
                break;
            case bule:
                puts("Bluebells are blue.");
                break;
            case violet:
                puts("Violets are violet.");
                break;

            default:
                break;
            }
        } else {
            printf("I don't know about the color %s.\n", choice);
        }
        color_is_found = false;
        puts("Next color, please (empty line to quit):");
    }
    puts("Goodbye!");
#endif

/**
 * @brief 函数指针
 *
 *
 */
#if 1
    char line[LEN];
    char copy[LEN];
    char choice;
    void (*pFun)(char *);

    puts("Enter a string (empty line to quit):");
    while (s_gets(line, LEN) != NULL && line[0] != '\0') {
        while ((choice = showmenu()) != 'n') {
            switch (choice) {
            case 'u':
                pFun = ToUpper;
                break;
            case 'l':
                pFun = ToLower;
                break;
            case 't':
                pFun = Transpose;
                break;
            case 'o':
                pFun = Dummy;
                break;
            default:
                break;
            }
            strcpy(copy, line);
            show(pFun, copy);
        }
        puts("Enter a string (empty line to quit):");
    }
    puts("Bye!");
#endif
    return 0;
}

char showmenu(void) {
    char ans;
    puts("Enter menu choice:");
    puts("u) uppercase      l) lowercase");
    puts("t) transposed case o) original case");
    puts("n) next string");
    ans = getchar();
    ans = tolower(ans);
    eatline();
    while (strchr("ulton", ans) == NULL) {
        puts("Please enter a u, l, t, o or n:");
        ans = tolower(getchar());
        eatline();
    }

    return ans;
}

void eatline(void) {
    while (getchar() != '\n') {
        continue;
    }
}

void ToUpper(char * str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

void ToLower(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

void Transpose(char *str) {
    while (*str) {
        if (islower(*str)) {
            *str = toupper(*str);
        } else if (isupper(*str)) {
            *str = tolower(*str);
        }
        str++;
    }
}

void Dummy(char *str) {

}

void show(void (*fp)(char *), char *str) {
    (*fp)(str);
    puts(str);
}

void showFlex(const struct flex *p) {
    int i;
    printf("Scores:");
    for (i = 0; i < p->count; i++) {
        printf("%g ", p->scores[i]);
    }
    printf("\n Average: %g\n", p->average);
}

void getinfo2(struct name *pst) {
    char temp[NLEN];
    printf("Please enter your first name.\n");
    s_gets(temp, NLEN);
    pst->fname = (char *)malloc(strlen(temp) + 1);
    strcpy(pst->fname, temp);
    printf("Please enter your last name.\n");
    s_gets(temp, NLEN);
    pst->lname = (char *)malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);
}

void makeinfo2(struct name *pst) {
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo2(const struct name *pst) {
    printf("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters);
}

void cleanup(struct name *pst) {
    free(pst->fname);
    free(pst->lname);
}

void getinfo(struct namect *pst) {
    printf("Please enter your first name.\n");
    s_gets(pst->fname, NLEN);
    printf("Please enter your last name.\n");
    s_gets(pst->lname, NLEN);
}

void makeinfo(struct namect *pst) {
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect *pst) {
    printf("%s %s, your name contains %d letters.\n", pst->fname, pst->lname, pst->letters);
}

/**
 * @brief Take the sum of two numbers
 *
 * @param x
 * @param y
 * @return double
 */
double sum(double x, double y) {
    return (x + y);
}

/**
 * @brief
 *
 * @param money
 * @return double
 */
double sum2(const struct funds *money) {
    return (money->bankfund + money->savefund);
}

double sum3(const struct funds moolah) {
    return (moolah.bankfund + moolah.savefund);
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
