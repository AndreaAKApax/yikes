#include <stdio.h>
#include <stdlib.h>
#include <collectc/hashtable.h>
#include <sys/stat.h>



int main()
{
    HashTable *table;
    enum cc_stat status = hashtable_new(&table);
    if (status == CC_OK)
        printf("table creation ok\n");

    struct stat array[3];
    int i;
    for(i = 0; i<3; i++){
        array[i] = struct stat filestat;
        }




void addToHT (char *pathname){
    static int index = 0;

    int statStatus;
    if((statStatus = stat(pathname, &array[index])) != 0){
        fprintf(stderr, "errore con il metodo stat");
        exit(1);
        }

    printf("file serial number = %ld", array[index].st_ino);

    if((hashtable_add(table, pathname, array[index])) != CC_OK){
        fprintf(stderr, "errore nell'inserire la coppia in tabella");
        exit(1);
        }

    void *value;
    if((hashtable_get(table, pathname, &value) != CC_OK)){
        fprintf(stderr, "errore con il metodo get");
        exit(1);
        }

    printf("file serial number = %d", value.st_ino);

    index++;
}

    addToHT("/home/andrea/Scrivania/file2");
    addToHT("/home/andrea/Scrivania/super");
    addToHT("/home/andrea/Scrivania/file1");

    return 0;
}
