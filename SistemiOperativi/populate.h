#ifndef POPULATE_H
#define POPULATE_H
/* modulo contenente le funzioni necessare per popolare la struttura dati con
    coppie di percorsi a file e relative statistiche */

/* variabile di controllo per il parametro l */
bool elle;
/* buffer in cui vado a salvare il file path che dovrò esaminare */
char *pathname;
/* buffer in cui vado ad inserire una riga del file di input */
char riga[100];
/* buffer in cui vado a salvare i parametri r e l se presenti nella riga copiata nel buffer riga */
char *c;
/* numero di file da esaminare */
int numberOfFiles;
/* funzione che conta il numero di file che dovrò andare ad analizzare */
int countFiles(char*);
/* funzione che conta il numero di file all'interno di una cartella */
int countRecursively(char*);
/* funzione che rihiede di effettuare l'opzione di report */
void computeReport(clock_t, clock_t);

#endif // POPULATE_H
