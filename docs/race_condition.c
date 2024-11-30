/*Una Race condition è quando due o più thread accedono contemporaneamente 
a una stessa variabile, provocando errori. Consideriamo l'esempio di 
un programma che vuole contare fino a 2.000.000, utilizzando due thread 
che incrementano una variabile cont fino a 1.000.000 ciascuno.*/

#include <pthread.h>
#include <stdio.h>
# define R "\033[1;31m"
# define RST "\033[0m"

int count = 0;

void *routine() {
  int i = -1;
  while (++i < 1000000)
      count++;
  return (NULL);
}

int main() {
  pthread_t tid1, tid2;

  pthread_create(&tid1, NULL, &routine, NULL);
  pthread_create(&tid2, NULL, &routine, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  printf(R "count: %d\n" RST, count);
}

/*Eseguendo il codice, non otterremo mai 2.000.000 esatti per via di una 
race condition. Il problema risiede nel fatto che l'incremento cont++ esegue
tre operazioni in assembly: lettura, incremento e scrittura, che possono 
essere interrotte da un altro thread, portando a un valore errato.*/
