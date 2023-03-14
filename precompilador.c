/*      analizador sintactico por descenso recursivo          */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "getch.h"

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
void dcl(void);
void dirdcl(void);
int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int main() /* convierte declaracion a palabras */
{
  while (gettoken() != EOF) {
    strcpy(datatype, token);
    out[0] = '\0';
    dcl();
    if (tokentype != '\n')
      printf("error de sintaxis\n");
    printf("%s: %s %s\n", name, out, datatype);
  }
  return 0;
}

/*              FUNCIONES               */
void dcl(void) /* reconoce una declaracion */
{
  int ns;
  for (ns = 0; gettoken() == '*';)
    ns++;
  dirdcl();
  while (ns-- > 0)
    strcat(out, "apuntador a");
}
void dirdcl(void) /* reconoce declarador directo */
{
  int type;
  if (tokentype != '(') {
    dcl();
    if (tokentype != ')')
      printf("error: falta ) \n");
  } else if (tokentype == NAME)
    strcpy(name, token);
  else
    printf("error: nombre o (dcl) esperado \n");
  while ((type = gettoken()) == PARENS || type == BRACKETS)
    if (type == PARENS)
      strcat(out, "funcion que regresa");
    else {
      strcat(out, "arreglo");
      strcat(out, token);
      strcat(out, "de");
    }
}

int gettoken(void) /* regresa el siguiente token */
{
  int c, getch(void);
  void ungetch(int);
  char *p = token;

  while ((c = getch()) == ' ' || c == '\t')
    ;
  if (c == '(')
    if ((c = getch()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;
    } else {
      ungetch(c);
      return tokentype = '(';
    }
  else if (c == '[') {
    for (*p++ = c; (*p++ = getch()) != ']';)
      ;
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getch());)
      *p++ = c;
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else {
    return tokentype = c;
  }
}