#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* PrintHello(void* data)
{   //sleep(1);

    int my_data = *((int *)data);

    printf("%d\n",pthread_self());

    pthread_detach(pthread_self());

    printf("new thread sleeping !!Hello from new thread - got %d\n", my_data);
  //  pthread_exit(&my_data);
}

int main(int argc, char* argv[])
{
    int rc;
    pthread_t  thread_id;
    int t=11;

    void **recv_data;


    rc = pthread_create(&thread_id, NULL, PrintHello,&t);
    if(rc)
    {
        printf("\n ERROR: return code from pthread_create is %d \n", rc);
        exit(1);
    }

    sleep(1);
    printf("\n Created new thread %i ... \n", thread_id);
    printf("%d\n",pthread_self());


    //pthread_join(thread_id,&recv_data);

    // int *mydatapointer;
    // mydatapointer= (int *)recv_data;
    // printf("recoved value from thread %d\n",*mydatapointer );




  //  pthread_exit(NULL);		/* terminate the thread */
}
