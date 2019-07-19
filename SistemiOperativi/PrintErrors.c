#include <stdio.h>
#include <stdlib.h> //per exit
#include <errno.h>
#include "PrintErrors.h"

void print_usage(FILE* stream, int exitCode)
{
    fprintf(stream,
            "La sinossi del programma è: \n"
                " filestat: [options] [input] [output]\n"
            "Le possibili opzioni sono:\n"
                " --verbose|-v \n"
                " --stat|-s \n"
                " --report|-r \n"
                " --history|-h <filepah> \n"
                " --user|-u <userId> \n"
                " --group|-g <groupId> \n"
                " --length|-l <min>:<max> \n"
                " --noscan \n");
    exit(exitCode);
}

void print_error_fopen(FILE* stream, char *filePath, int exitCode)
{
    fprintf(stream, "Errore nell'apertura del file %s\n", filePath);
    exit(exitCode);
}

void print_error_alloc_entry(FILE *stream, char *filePath, int exitCode)
{
    fprintf(stream, "Inserimento della coppia con chiave %s fallito!\n", filePath);
    exit(exitCode);
}

void print_error_alloc_table(FILE *stream, int exitCode)
{
        fprintf(stream, "Fallimento nell'allocare la memoria per l'hashtable!\n");
        exit(exitCode);
}
