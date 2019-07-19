#ifndef PRINT_ERRORS_H
#define PRINT_ERRORS_H

/* stampa messaggio d'errore quando inserisco input non validi */
void print_usage(FILE*, int);
/* stampa messaggio d'errore quando fallisce l'operazione di apertura di un file */
void print_error_fopen (FILE*, char*, int);
/* stampa messaggio d'errore quando fallisce l'inserimento di una coppia nella struttura dati */
void print_error_alloc_entry(FILE*, char*, int);
/* stampa messaggio d'errore quando fallisce la creazione della struttura dati */
void print_error_alloc_table(FILE*, int);

#endif //PRINT_ERRORS_H
