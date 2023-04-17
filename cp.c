//cp 
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
   FILE *source_fp,*dest_fp;
   char buffer[4096];
size_t bytes_read,bytes_written;
   if(argc!=3){
       printf("Usage :%s<source_file><dest_file>\n",argv[0]);
exit(1);
}

source_fp=fopen(argv[1],"rb");
if(source_fp==NULL){
  printf("Error opening source file:%s\n",argv[1]);
  exit(1);}
 dest_fp=fopen(argv[2],"wb");
 if(dest_fp==NULL){
       printf("Error opening dest file:%s\n",argv[2]);
fclose(source_fp);
exit(1);
}

while((bytes_read=fread(buffer,1,sizeof(buffer),source_fp))>0){
       bytes_written=fwrite(buffer,1,bytes_read,dest_fp);
   

if(bytes_written!=bytes_read){
    printf("Error writing to destination file:%s\n",argv[2]);
     fclose(source_fp);
     fclose(dest_fp);
exit(1);
}}

 fclose(source_fp);
     fclose(dest_fp);
return 0;}




