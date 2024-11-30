#include <stdio.h>      // printf
#include <sys/time.h>   // time
#include <time.h>       // local time
#include <unistd.h>     // usleep
#define RST 	"\033[0m"       
#define RED     "\033[1;31m" 
#define GREEN   "\033[1;32m"
#define CYAN    "\033[1;36m"

// Questo programma misura il tempo di sospensione effettivo rispetto al tempo richiesto usando gettimeofday().
// La funzione usleep() viene usata per "dormire" per un tempo specificato in microsecondi, 
// ma a causa di eventuali latenze del sistema, l'effettivo tempo di sospensione potrebbe essere leggermente diverso.

int main()
{
    struct timeval start_time;          // Struttura per memorizzare il tempo di inizio
    struct timeval end_time;            // Struttura per memorizzare il tempo di fine
    long requested_sleep_time;          // Tempo di sospensione richiesto in microsecondi
    long actual_sleep_time;             // Tempo di sospensione effettivo in microsecondi
    struct timeval tv;
    struct tm *tm_info;
    char buffer[26];

    gettimeofday(&tv, NULL);            // Ottieni il tempo corrente
    tm_info = localtime(&tv.tv_sec);    // Converti i secondi in una struttura tm
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("date:\t\t%s\n", buffer);
    printf("seconds:\t%ld.%ld\n", tv.tv_sec, tv.tv_usec);
    unsigned long msec = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    printf("milliseconds:\t%.6lu\n", msec);
    unsigned long usec = tv.tv_sec * 1000000 + tv.tv_usec;
    printf("microseconds:\t%.6lu\n", usec);

    requested_sleep_time = 200 * 1000;  // Tempo di sospensione richiesto: 200 millisecondi (200000 microsecondi)
    gettimeofday(&start_time, NULL);    // Memorizza il tempo attuale (prima di dormire)
    usleep(requested_sleep_time);       // Sospende l'esecuzione per il tempo richiesto (200000 microsecondi, cioè 200 ms)
    gettimeofday(&end_time, NULL);      // Memorizza il tempo attuale (dopo il risveglio)
    actual_sleep_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);
    printf(CYAN"Requested Sleep Time:\t"RST GREEN"%ld microseconds\n"RST, requested_sleep_time);
    printf(CYAN"Actual Sleep Time:\t"RST RED"%ld microseconds\n"RST, actual_sleep_time);

    return (0);
}

