    #include<stdio.h>
    #include<pthread.h>

    void *threadfunction(void *ch)
    { int j=10;

      printf("helloworld");

      return NULL;

    }

   int main()
    {

      pthread_t thread_id[10];
      char c='a';

      for(int i=0;i<10;i++)
      {
       char temp=c+1;
       pthread_create(&thread_id[i],NULL,&threadfunction,NULL);

      }
     return 0;
}
