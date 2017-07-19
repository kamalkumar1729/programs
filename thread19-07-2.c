#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


void * threadfunction(void *num){
     int count=5;
    for (size_t i = 0; i < count; i++)
       printf("Hello thread:%d\n",*((int *)num));
  }

int main(int argc, char const *argv[]) {
      int num_threads;
      printf("enter the number of threads(<50):");
      scanf("%d",&num_threads);

      pthread_t threads_id[50];

      int arr_ids[50];

      for(int j=0;j<num_threads;j++)
           arr_ids[j]=j;

      for(int i=0;i<num_threads;i++){
          int jj= pthread_create(&threads_id[i],NULL,threadfunction,&arr_ids[i]);
          printf("thread return value %d\n",jj);
        // if(i%4==0)
          //  sleep(1);
      }
      sleep(3);
  return 0;
}
