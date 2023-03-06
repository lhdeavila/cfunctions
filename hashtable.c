#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Tabla hash.
  marco teorico: [https://es.wikipedia.org/wiki/Tabla_hash]
*/
struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

/*
  Esta solo cumple la funcion de retornar un hash.
  Se selecciono el numero primo 31, no tiene nada de especial.
  "no es mucho, pero es trabajo honesto".
*/

unsigned hash(char *s){
	unsigned hashval;
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* Busca s en hashtab */
struct nlist *lookup(char *s){
	struct nlist *np;
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if ( strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

struct nlist *lookup(char *);

/*
  si no encuentra s en hashtab, lo inserta en la tabla.
*/
struct nlist *install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;
  if((np = lookup(name)) == NULL) {
    np = (struct nlist *) malloc(sizeof(*np));
    if (np == NULL || (np -> name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np -> next = hashtab[hashval];
    hashtab[hashval] = np;
  } else
        free((void *) np -> defn);
  if ((np -> defn = strdup(defn)) == NULL)
      return NULL;
  return np;
};