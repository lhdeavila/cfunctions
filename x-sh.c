#include <stdio.h>
/* ejecuta una shell /bin/sh */
void main() {
        char *name[2];
        name[0] = "/bin/sh";
        name[1] = NULL;
        execve(name[0], name, NULL);
}