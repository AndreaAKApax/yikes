#include <stdio.h>
#include <stdlib.h>
#include <collectc/hashtable.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <errno.h>

int main(){
/* creo la tabella */
HashTable *table;
enum cc_stat hsh = hashtable_new(&table);
/* check per vedere se è stata creata*/
if (hsh == CC_OK)
    printf("hashtable creata\n");
/* alloco spazio per una struct stat*/
struct stat *buf = malloc(sizeof(struct stat));
int result;
/* metodo per aggiungere una nuova entry nella tabella*/
void addhash (const char *pathname, struct stat *fs, HashTable *ht) {
 /* controllo se stat() è andata a buon fine o se c'è stato un problema*/
 if((result = stat(pathname, fs)) == -1)
    {
        fprintf(stderr, "stat() ha ritornato -1 \n");
        perror("l'errore è");
        exit(1);
    };
 /* aggiungo la entry nella hashtable */
 enum cc_stat ulamog = hashtable_add(ht, pathname, fs);
 /* controllo se l'operazione è andata a buon fine */
 if (ulamog == CC_OK)
    printf("ha funzionato!\n");
}

addhash("/home/andrea/Documenti/ProblemiConHashtable/ciao", buf, table);

/* TEST */
HashTableIter hti;
hashtable_iter_init(&hti, table);
TableEntry *entry;
while (hashtable_iter_next(&hti, &entry) != CC_ITER_END){
	printf("%s\n", (char*)(entry->key));
}

if (hashtable_contains_key(table,"/home/andrea/Documenti/ProblemiConHashtable/ciao"))
    {
    printf("c'è\n");
    }
    else
    {
    printf("non c'è\n");
    };

free(buf);
return 0;
}
