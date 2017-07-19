#include<stdio.h>
#include<pthread.h>

void *threadfunction(void *ch){
   printf("%c",*(char *)ch);
   return NULL;
 }

int main(){
   pthread_t thread_id[10];
   char c='a';

   for(int i=0;i<10;i++)  {
       char temp=c+i;
       pthread_create(&thread_id[i],NULL,&threadfunction,&temp);
     }
  return 0;
}

pt
