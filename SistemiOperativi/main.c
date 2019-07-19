#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <collectc/hashtable.h>
#include <stdbool.h>
#include "populate.h"
#include "PrintErrors.h"
#include <time.h>

int main(int argc, char* argv[])
{
    clock_t start = clock();
    /* creo un'hashtable con configurazione standard */
    HashTable *table;
    enum cc_stat status = hashtable_new(&table);
    if (status == CC_ERR_ALLOC){
        print_error_alloc_table(stderr, 1);
        }
    /* flag per --noscan */
    int do_noscan;
    /* flag per --verbose*/
    bool do_verbose = false;
    /* flag per --report */
    bool do_report = false;
    /* variabile che mi fa scorrere lungo gli argomenti */
    int next_option;
    /* stringa che contiene le lettere che rappresentano le opzioni valide */
    const char* const short_options = "-:vsrh:u:g:l:";
    /* array che contiene la versione lunga delle opzioni */
    const struct option long_options[] = {
        {"verbose", 0, NULL, 'v'},
        {"stat", 0, NULL, 's'},
        {"report", 0, NULL, 'r'},
        {"history", 1, NULL, 'h'},
        {"user", 1, NULL, 'u'},
        {"group", 1, NULL, 'g'},
        {"lenght", 1, NULL, 'l'},
        {"noscan", 0, &do_noscan, 1},
        {NULL, 0, NULL, 0}
    };

    /* variabile usata per contare quanti argomenti non opzione sono stati dati in input */
    int non_option_occurrences = 0;
    char *inputFileName = "qwerty/filestat.in";
    char *outputFileName = "qwerty/filestat.db";

    /* vengono individuati i file di input e di output se sono stati passati */
    /* viene individuata l'opzione noscan se presente */
    /* viene individuata l'opzione noscan se presente */
// TODO (andrea#1#): da completare!!!!!
    while((next_option = getopt_long(argc, argv, short_options,long_options, NULL)) != -1){
        if(non_option_occurrences >= 2){
            printf("Hai provato ad inserire più di 2 argomenti! \n");
            print_usage(stderr, 1);
            }
// TODO (andrea#1#): da completare!!!!!
        switch(next_option){
            case ('v'):
                do_verbose = true;
                printf("ok\n");
                break;
            case('r'):
                //qualcosa
                do_report = true;
                break;
            case(0):
                /* il flag di noscan viene settato a 1 */
                printf("%d \n", do_noscan);
                break;
            case (1):
                /* routine per creare file di input e di output */
                if ((non_option_occurrences += 1) == 1){
                    inputFileName = optarg;
               } else {
                    outputFileName = optarg;
                    }
                break;
        }
    }
// TODO (andrea#1#): codice che esegue noscan se il suo flag è 1 - IMPORTARE FILESTAT DI NIKO
    if (do_noscan == 1){
        noscan(outputFileName);
        }
//prova conteggio - DA CANCELLARE UNA VOLTA FINITO TUTTO
int c = countFiles(inputFileName);
printf("%d\n",c);

    /* codice per eseguire report se il parametro viene passato */
    if (do_report){
        clock_t end = clock();
        computeReport(start, end);
        }

    /* ho terminato la ricerca dei file di input e di output quindi reimposto optind a 1*/
    optind = 1;

// TODO (andrea#1#): codice ft. metodi di Niko: LEGGE INPUT E SCRIVE OUTPUT
    //tutto(inputFileName, outputFileName, table);

    /*eseguo le opzioni richieste*/
// TODO (andrea#1#): da completare!!!!!
    while((next_option = getopt_long(argc, argv, short_options,long_options, NULL)) != -1){
        switch(next_option){
            case('s'):
                //qualcosa
                printf("s ok \n");
                break;
            case('h'):
                //qualcosa
                printf("h ok \n");
                break;
            case('u'):
                //qualcosa
                printf("u ok \n");
                break;
            case('g'):
                //qualcosa
                printf("g ok \n");
                break;
            case('l'):
                //qualcosa
                printf("l ok \n");
                break;
            case('?'):
                /* L'utente ha specificato un'opzione non valida. Stampo quindi un messaggio d'errore.*/
                fprintf(stderr, "È stata inserita un'opzione non valida.\n");
                print_usage(stderr, 1);
            case(':'):
                /* manca l'argomento */
                fprintf(stderr, "Manca l'argomento per l'opzione -%c \n", optopt);
               print_usage(stderr, 1);
            case(-1):
                break;
            }
    }

    return 0;
}
