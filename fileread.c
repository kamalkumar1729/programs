#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>
#include<errno.h>

//structure for holding single thread data
typedef struct _thread_data{
  char name[50];
  int linecount;
}thread_data;


//thread function
void * read_and_count(void *file)
{
   thread_data *data_ptr = (thread_data*)file;

   FILE *fp=fopen(data_ptr->name,"r");

  //buffer to hold data read from file
   char buff[50];

  //set number of lines in a file, to Zero.
  data_ptr->linecount=0;
  printf("file path in thread %s\n",data_ptr->name );

  if(fp == NULL)
  {
     printf("file doesn't exist! NULL file pointer.  \n");
     pthread_exit(NULL);
  }
  else
   {
    while(fgets(buff,50,fp) != NULL)
    {
    //  printf("fiel line content %s\n",buff );
     (data_ptr->linecount) ++;
    //printf("linen in iteration %d\n",data_ptr->linecount );
    }
  }
  printf("%s    %d \n",data_ptr->name, data_ptr->linecount );

  //close the file
  fclose(fp);

}


int main()
{
  //thread ids
  pthread_t thread_id[10];

  char current_dir[]="./textfiles/";

  DIR *directory;
  struct dirent *dir;

  directory=opendir(current_dir);

//check if diectory exist
if(directory){

  thread_data *th_ptr[100];
  int iter=0;

  while((dir=readdir(directory)) != NULL){

    th_ptr[iter]= malloc(sizeof(thread_data));
    char full_path[50];

    strcpy(full_path,current_dir);
    strcat(full_path,dir->d_name);
    strcpy(th_ptr[iter]->name,full_path);

    printf("path is %s\n",full_path );

    if((pthread_create(&thread_id[iter],NULL,read_and_count,th_ptr[iter]))!= 0 ){
         printf("Unbale to create thread\n");
         pthread_exit(NULL);
    }

    //printf("thread created with id %d\n",iter);
    iter++;
 }

  //wait for all the threads to finish
 for(int i=0; i<iter; i++)
    pthread_join(thread_id[i],NULL);

  //free the memory
 for(int j=0; j<iter; j++)
    free(th_ptr[j]);


printf("%d error number \n",errno );

}else if(ENOENT == errno){
   printf("Directory doesn't Exist. error no: %s\n",strerror(errno));
   perror("kamal");
}else{
  printf("Can't open directory\n");

}

// errno=0;
// printf("%d error number \n",errno );
// int x=7,y=0;
// int z=x/y;
// printf("%d error number \n",errno );
return 0;
}
