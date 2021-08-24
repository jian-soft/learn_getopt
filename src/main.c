#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>  //to use getopt_long

//#define GETOPT  //uncomment this to test getopt, or test getopt_long

int test_getopt(int argc, char **argv)
{
    char *opt_string = "ab:cde:";
    int opt;

    while ((opt = getopt(argc, argv, opt_string)) != -1) {
        printf("This optind: %d\n", optind);
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

    printf("Scan option done, now optind:%d\n", optind);
    return 0;
}


const struct option opts[] = {
	{"add",         no_argument,        NULL, 'a'},
	{"begin",       required_argument,  NULL, 'b'},
	{"config",      no_argument,        NULL, 'c'},
	{"debug",       no_argument,        NULL, 'd'},
	{"exit",        required_argument,  NULL, 'e'},
    {NULL,          0,                  NULL, '\0'}
};

int test_getopt_long(int argc, char **argv)
{
    char *opt_string = "ab:cde:";
    int opt;
    int lidx;
    //while ((opt = getopt_long(argc, argv, opt_string, opts, &lidx)) != -1) {
    while ((opt = getopt_long(argc, argv, "", opts, &lidx)) != -1) {
        printf("This optind: %d\n", optind);
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

    return 0;
}

int main(int argc, char **argv)
{
    printf("argc:%d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]:%s\n", i, argv[i]);
    }

#ifdef GETOPT
    test_getopt(argc, argv);
#else
    test_getopt_long(argc, argv);
#endif

    printf("argc:%d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]:%s\n", i, argv[i]);
    }

    return 0;
}


