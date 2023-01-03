/**
 * @file 12_file_input_output.c
 * @author your name (you@domain.com)
 * @brief
 * @version V1.0.0
 * @date 2023-01-03
 *
 * @copyright Copyright (c) 2023
 *
 */
/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define BUFSIZE 4096
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void append(FILE *source, FILE *dest);
char *s_gets(char *st, int n);
/* Private user code ---------------------------------------------------------*/

/**
 * @brief The application entry point.
 *
 * @return int
 */
int main(int argc, char *argv[]) {
#if 0
    int ch;
    FILE *fd;
    unsigned long count = 0;
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fd = fopen(argv[1], "r")) == NULL) {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fd)) != EOF) {
        putc(ch, stdout);
        count++;
    }
    fclose(fd);
    printf("\nFile %s has %lu characters\n", argv[1], count);
#endif
/**
 * @brief
 *
 */
#if 0
    #define LEN 40
    FILE *in, *out;
    int ch;
    char name[LEN];
    int count = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((in = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    strncpy(name, argv[1], LEN - 5);
    name[LEN - 5] = '\0';
    strcat(name, ".red");
    if ((out = fopen(name, "w")) == NULL) {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    while((ch = getc(in)) != EOF) {
        if (count++ % 3 == 0) {
            putc(ch, out);
        }
    }
    if (fclose(in) != 0 || fclose(out) != 0) {
        fprintf(stderr, "Error in closing files\n");
    }

    return 0;
#endif
/**
 * @brief fprintf() fscanf()
 *
 */
#if 0
    #define MAX 41
    FILE *fp;
    char words[MAX];

    if ((fp = fopen("wordy", "a+")) == NULL) {
        fprintf(stdout, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#')) {
        fprintf(fp, "%s\n", words);
    }
    puts("File contents:");
    rewind(fp);  // 回到文件开始处
    while (fscanf(fp, "%s", words) == 1) {
        puts(words);
    }
    puts("Done!");
    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file\n");
    }

#endif
/**
 * @brief fgets() fputs()
 * fgets(buf, STLEN, fp);
 * fputs(buf, fp);
 *
 */

/**
 * @brief fseek() ftell()
 *
 */
#if 0
    #define CNTL_Z '\032'
    #define SLEN   81

    char file[SLEN];
    char ch;
    FILE *fp;
    long count, last;

    puts("Enter the name of the file to be processed:");
    scanf("%80s", file);
    if ((fp = fopen(file, "rb")) == NULL) {
        printf("reverse can't open %s\n", file);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);
    last = ftell(fp); // 返回当前位置
    for (count = 1L; count <= last; count++) {
        fseek(fp, -count, SEEK_END);
        ch = getc(fp);
        if (ch != CNTL_Z && ch != '\r') {
            putchar(ch);
        }
    }
    putchar('\n');
    fclose(fp);
#endif

/**
 * @brief fgetpos() fsetpos()
 *
 */
#if 0
    #define BUFSIZE 4096
    #define SLEN    81

    FILE *fa, *fs;  // fa指向目标文件 fs指向源文件
    int files = 0;
    char file_app[SLEN];
    char file_src[SLEN];
    int ch;

    puts("Enter name of destination file:");
    s_gets(file_app, SLEN);
    if ((fa = fopen(file_app, "a+")) == NULL) {
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Enter name of first source file (empty line to quit):");
    while (s_gets(file_src, SLEN) && file_src[0] != '\0') {
        if (strcmp(file_src, file_app) == 0) {
            fputs("Can't append file to itself\n", stderr);
        } else if ((fs = fopen(file_src, "r")) == NULL) {
            fprintf(stderr, "Can't open %s\n", file_src);
        } else {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0) {
                fprintf(stderr, "Error in reading file %s.\n", file_src);
            }
            if (ferror(fa) != 0) {
                fprintf(stderr, "Error in writing file %s.\n", file_app);
            }
            fclose(fs);
            files++;
            printf("File %s appended.\n", file_src);
            puts("Next file (empty line to quit):");
        }
    }
    printf("Done appending. %d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n", file_app);
    while ((ch = getc(fa)) != EOF) {
        putchar(ch);
    }
    puts("Done displaying.");
    fclose(fa);

#endif

#if 1
    #define ARSIZE 1000

    double value;
    double numbers[ARSIZE];
    const char *file = "number.dat";
    int i;
    long pos;
    FILE *iofile;

    for (i = 0; i < ARSIZE; i++) {
        numbers[i] = 100.0 * i + 1.0 / (i + 1);
    }

    if ((iofile = fopen(file, "wb")) == NULL) {
        fprintf(stderr, "Could not open %s for output.\n", file);
        exit(EXIT_FAILURE);
    }
    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);

    if ((iofile = fopen(file, "rb")) == NULL) {
        fprintf(stderr, "Could not open %s for random access.\n", file);
        exit(EXIT_FAILURE);
    }
    printf("Enter an index in the range 0-%d.\n", ARSIZE - 1);
    while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE) {
        pos = (long)i * sizeof(double);
        fseek(iofile, pos, SEEK_SET);
        fread(&value, sizeof(double), 1, iofile);
        printf("The value there is %f.\n", value);
        printf("Next index (out of range to quit):\n");
    }
    fclose(iofile);
    puts("Bye!");

#endif
    return 0;
}

/**
 * @brief Append the contents of the source file to the destination file.
 *
 * @param source Source file pointer
 * @param dest Dest file pointer
 */
void append(FILE *source, FILE *dest) {
    size_t bytes;
    static char temp[BUFSIZE];

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0) {
        fwrite(temp, sizeof(char), bytes, dest);
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
