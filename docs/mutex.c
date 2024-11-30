#include <pthread.h>
#include <sched.h>
#include <time.h>
#include <stdio.h>
# define C "\033[1;36m"
# define RST "\033[0m"

int count = 0;
pthread_mutex_t lock;

void *routine() {
  int i = -1;
  while (++i < 1000000) {
    pthread_mutex_lock(&lock);
    count++;
    pthread_mutex_unlock(&lock);
  }
  return (NULL);
}

int main() {
  pthread_t tid1, tid2;

  pthread_mutex_init(&lock, NULL);
  pthread_create(&tid1, NULL, &routine, NULL);
  pthread_create(&tid2, NULL, &routine, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_mutex_destroy(&lock);
  printf(C "count: %d\n" RST, count);
}


/*Si evitano le race condition si usano i mutex che agiscono come "lucchetti".
Se un mutex è bloccato, un thread deve attendere finché non viene sbloccato. 
Così, possiamo evitare la race condition nel precedente esempio, 
aggiungendo un lock attorno all'incremento.*/