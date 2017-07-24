#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include <sys/types.h>
#include <dirent.h>

typedef struct _thread_data{
    char name[20];
    int linecount;
}thread_data;




void * read_and_count(void *file)
{

 //  printf("kamal\n");
   thread_data *data_ptr = (thread_data*)file;

  //printf("path in thread %s\n",data_ptr->name);

   FILE *fp=fopen(data_ptr->name,"r");
  // printf("after fp\n");

   char buff[100];
   //set number of lines in a file, to Zero.
   data_ptr->linecount=0;

if(fp != NULL)
{
   while(fgets(buff,100,fp) != NULL)
   {
    //  printf("fiel line content %s\n",buff );
      (data_ptr->linecount) ++;
      //printf("linen in iteration %d\n",data_ptr->linecount );
    }

}else
  printf("file doesn't exist! NULL file pointer.  \n");


  printf("lines in %s file are %d\n",data_ptr->name, data_ptr->linecount );

}


int main()
{

    pthread_t thread_id[10];

    char current_dir[]="./textfiles/";

    DIR *directory;
    struct dirent *dir;
    directory=opendir(current_dir);

    int iter=0;

    thread_data *th_ptr[10];

    while((dir=readdir(directory)) != NULL){

        thread_data *th_ptr= malloc(sizeof(thread_data));
        char full_path[50];

        strcpy(full_path,current_dir);
        strcat(full_path,dir->d_name);
        strcpy(th_ptr->name,full_path);

        // printf("path is %s\n",full_path );

        if( ! (pthread_create(&thread_id[iter],NULL,read_and_count,th_ptr)) );
            //printf("thread creatted with id %d\n",iter);


        iter++;

 }

printf("%d\n",iter );



  //wait for all the threads to finish
  for(int i=0; i<iter; i++)
        pthread_join(thread_id[i],NULL);



 //sleep(2);

}
