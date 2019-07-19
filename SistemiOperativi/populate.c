#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <time.h>
#include "populate.h"
#include "PrintErrors.h"

int countFiles(char* inputFileName){
    static int contatore = 0;

    FILE *inputFile;
    if ((inputFile = fopen(inputFileName, "r")) == NULL){
        print_error_fopen(stderr, inputFileName, 1);
    }

    while (!feof(inputFile)){
        /* carico una riga nel buffer */
        if(fgets(riga,100,inputFile) != NULL){
            /* se ho il parametro r allora continuo la conta cercando nella cartella */
            if (strstr(riga, "[r]") != NULL){
                const char s[] = " ";
                char *pathname = strtok(riga, s);
                contatore += countRecursively(pathname);
            } else {
                contatore += 1;
                }
            }
    }

    fclose(inputFile);
    numberOfFiles = contatore;
    return contatore;
}

int countRecursively(char *pathname){
    static int contatore = 0;
    contatore += 1;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (pathname)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            // Salta un ciclo se il nome è . o ..
            if (strcmp(".",ent->d_name) == 0 || strcmp("..",ent->d_name) == 0) {
            continue;
            }
            // Aggiornamento del pathname
            char *buffer = malloc(strlen(pathname)+strlen(ent->d_name)+1+sizeof("/"));
            strcpy(buffer,pathname);
            strcat(buffer, "/");
            strcat(buffer,ent->d_name);

            if (ent->d_type == 4) {
                countRecursively(buffer);
            } else {
                contatore += 1;
            }

            free(buffer);
        }
    }
    return contatore;
}

void computeReport(clock_t start, clock_t end){
    report(numberOfFiles, start, end);
}


//metodo da passare a luca
/*
void report( int numberOfFiles, clock_t start, clock_t end){
    // calcolo il tempo di elaborazione
    double totalTime = ((double)(end-start))/CLOCKS_PER_SEC;;
    // calcolo la dimensione massima
    HashTableIter hti;
    hashtable_iter_init(&hti, table);
    TableEntry *entry;
    long maxLength = 0;
    if((((struct stat*) entry -> value )-> st_size) >= maxLength) {
        maxLength = (((struct stat*) entry -> value )-> st_size);
        }
    // stampo i dati raccolti
    printf("Report\n")
    printf("1) numero di file elaborati: %d\n",numberOfFiles);
    printf("2) tempo di elaborazione: %fms\n",totalTime);
    printf("3) dimensione massima del file: %ld\n",maxLength);
    }
*/
