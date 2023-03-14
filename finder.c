#include <stdio.h>
#include <string.h>

#include "getline.h"

#define MAXLINE 1000

main(int argc, char *argv[]){
  char line[MAXLINE];
  long lineno = 0;
  int c, except = 0, number = 0, found = 0;
  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0])
      switch(c){
      case 'x':
        except = 1;
        break;
      case 'n':
        number = 1;
        break;
      default:
        printf("find: opcion ilegal %c\n", c);
        argc = 0;
        found = -1;
        break;
      }
    if (argc != 1)
      printf("Uso: find -x -n patron\n");
    else
      while (custom_getline(line, MAXLINE) > 0){
        lineno++;
        if ((strstr(line, *argv) != NULL) != except){
          if(number)
            printf("%ld:", lineno);
          printf("%s", line);
          found++;
        }
      }
    return found;

}
