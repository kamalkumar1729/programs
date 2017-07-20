#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int shared_var;
pthread_mutex_t mut;

void * thread_func(void *add)
{
  pthread_mutex_lock(&mut);

  shared_var++;
  printf("shared_var value: %d \n",shared_var);
  pthread_mutex_unlock(&mut);


}
int main(void) {
  int THREADS=50;
  pthread_t threads_id[THREADS];

  shared_var=0;
  pthread_mutex_init(&mut,NULL);

  for(int i=0; i<THREADS;i++){
    printf("thread created with id: %d \n",i);
    pthread_create(&threads_id[i],NULL,thread_func,NULL);
  }

  //wating for all the threads to sync with main threads
  for(int j=0; j<THREADS; j++){
    pthread_join(threads_id[j],NULL);
  }

  // your code goes here
  return 0;
}
