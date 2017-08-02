#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

//global variable count recursion depth
int recursion = 0;
int num_files=0;



void read_dir_count_lines(char * dir_path){
  recursion=recursion+1;

  printf("recursion : %d\n",recursion );

    DIR *directory = opendir(dir_path);

    if (directory==NULL)
         return;

    struct dirent *dir_file;

        while ( (dir_file=readdir(directory)) != NULL ) {



              if ( dir_file->d_type != DT_DIR && strcmp(dir_file->d_name,".")!=0 && strcmp(dir_file->d_name,"..")!=0 ) {

//&& strcmp(dir_file->d_name,".")!=0 && strcmp(dir_file->d_name,"..")!=0

                  //  printf("%s\n",dir_file->d_name);
                    char abs_file_path[1024];
                    strcpy(abs_file_path,dir_path);
                    strcat(abs_file_path,"/");
                    strcat(abs_file_path,dir_file->d_name);

   //                  printf("abs file path %s\n",abs_file_path);


                    FILE *fp=fopen(abs_file_path,"r");

                   //buffer to hold data read from file
                  //  char buff[10];

                   //set number of lines in a file, to Zero.
                   //int num_lines=0;
                   //printf("%d\n", num_lines);
    //               printf("path in thread %s\n",abs_file_path);

                   int num_lines=0;
                   char ch;
                   if(fp == NULL)
                   {
                      printf("file doesn't exist! NULL file pointer.  \n");
                       return;
                   }
                   else
                    {  while((ch=fgetc(fp) )!= EOF )
                        {
                            if (ch=='\n')
                               num_lines++;
                              /* code */


                             //printf("content: %c  %d \n",ch,num_lines )
                        }
                    }
                    num_files++;
                   printf("file: %s   lines: %d \n",abs_file_path, num_lines);

                   //close the file
                   fclose(fp);


                }
                 else if( dir_file->d_type == DT_DIR  && strcmp(dir_file->d_name,".")!=0 && strcmp(dir_file->d_name,"..")!=0) { //&& strcmp(dir_file->d_name,".")!=0 && strcmp(dir_file->d_name,"..")!=0
                    char dir_name[1024];
                    sprintf(dir_name, "%s/%s",dir_path, dir_file->d_name);

                    read_dir_count_lines(dir_name);
                }
        }

   closedir(directory);
}

int main(int argc, char const *argv[]) {
//  printf("enter path with /\n");
  //char current_path[256];

//  fgets(current_path,sizeof(current_path),stdin);

  //printf("enterred path %s\n",current_path );

  read_dir_count_lines("/home/kamal/program/programs/textfiles/test");
  printf("total files %d\n",num_files );


  return 0;
}
