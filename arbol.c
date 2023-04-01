#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
/*
	Conteo de repeticiones de palabras.
	Usando estructura de datos de tipo "arbol".
*/
struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *custom_strdup(char *);

void main(){
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if(isalpha(word[0]))
				root = addtree(root, word);
	treeprint(root);
	return;
}

/* agrega palabra (nodo) al arbol. */
struct tnode *addtree(struct tnode *p, char *w){
	int cond;
	if(p == NULL){
		p = talloc();
		p -> word = custom_strdup(w);
		p -> count = 1;
		p -> left = p -> right = NULL;
	} else if ((cond = strcmp(w, p -> word)) == 0)
		p->count++;
	else if (cond < 0)
		p -> left = addtree(p->left, w);
	else
		p -> right = addtree(p -> right, w);
	return p;
}

void treeprint(struct tnode *p){
	if(p != NULL){
		treeprint(p->left);
		printf("%4d %s", p->count, p->word);
		treeprint(p->right);
	}
}

int getword(char *word, int lim){
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if ( c != EOF )
		*w++ = c;
	if ( !isalpha(c)){
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++ )
		if (!isalnum(*w = getch())){
			ungetch(*w);
			break;
		}
}

char *custom_strdup(char *s)
{
	char *p;
	p = (char *) malloc(strlen(s) + 1);
	if(p != NULL)
		strcpy(p, s);
	return p;
}

struct tnode *talloc(void){
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/*
char *strdup(char *s){
	char *p;
	p = (char *) malloc(strlen(s) + 1);
	if(p != NULL)
		strcpy(p, s);
	return p;
}
*/