#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define DEBUG

int main(int argc, char **argv)
{
#ifdef DEBUG
    printf("argc:%d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]:%s\n", i, argv[i]);
    }
#endif

    char *opt_string = "ab:cde:";
    int opt;

    while ((opt = getopt(argc, argv, opt_string)) != -1) {
        printf("this optind: %d\n", optind);
        switch (opt) {
        case 'a':
            printf("-a\n");
            break;
        case 'b':
            printf("-b %s\n", optarg);
            break;
        case 'c':
            printf("-c\n");
            break;
        case 'd':
            printf("-d\n");
            break;
        case 'e':
            printf("-e %s\n", optarg);
            break;
        default:
            printf("Unknow opt:%c\n", opt);
            printf("Usage:%s\n", opt_string);
            exit(EXIT_FAILURE);
        }
    }

#ifdef DEBUG
    printf("scan option done, now optind:%d\n", optind);
    printf("argc:%d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]:%s\n", i, argv[i]);
    }
#endif


    return 0;
}


