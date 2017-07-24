#include<stdio.h>
#include<pthread.h>
#include<string.h>


typedef struct _thread_data{
    char name[20];
    int linecount;
}thread_data;




void * read_and_count(void *file)
{
   thread_data *data_ptr= (thread_data*)file;

  FILE *fp=fopen(data_ptr->name,"r");

   char buff[10];

   while(fgets(buff,10,fp) != NULL)
  {
      (data_ptr->linecount)++;
    }
 printf("#lines %d\n",data_ptr->linecount );

}


int main()
{

    pthread_t thread_id[10];

    char current_dir[]="./textfiles/";
    DIR *directory;
    struct dirent *dir;
    d=opendir(current_dir);

    int iter=0;

    thread_data *th_ptr[10]

    while((dir=read(d)) != NULL){

        thread_data *th_ptr[iter]= malloc(sizeof(thread_data));
        char full_path[50];

        strcpy(full_path,current_dir);
        strcat(full_path,dir->d_name);

         printf("path is %s\n",full_path );

        if( ! (create_thread(&thread_id[iter],NULL,read_and_count,th_ptr)) );
            printf("thread creatted with id %d\n",iter);


        iter++;

 }













}
