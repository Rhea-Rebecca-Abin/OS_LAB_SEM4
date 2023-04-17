//Longest job first algorithm
#include<stdio.h>
#include<stdlib.h>
typedef struct {
 int pid;
int btime;
int wtime;
int ttime;
}sp;
int main(){
  int i,j,n,totwtime=0,totttime=0; 
  sp *p,t;
  printf("\nLJF Scheduling\n");
  printf("\nEnter the number of processes\n");
  scanf("%d",&n);
  p=(sp*) malloc(n*sizeof(sp));
  printf("\nEnter the burst time:\n");
  for (i=0;i<n;i++){
   printf("Process %d:",i+1);
   scanf("%d",&p[i].btime);
   p[i].pid=i+1;
   p[i].wtime=0;
   }
   
   for (i=0;i<n;i++){
       for (j=0;j<n-i-1;j++){
           if(p[j].btime<p[j+1].btime){
                     t=p[j];
                     p[j]=p[j+1];
                     p[j+1]=t;
                    }}}
    
    p[0].wtime=0;
   p[0].ttime=p[0].btime;
   totttime+=p[0].ttime;
     

   for (i=1;i<n;i++){
          p[i].wtime=p[i-1].wtime+p[i-1].btime;
          p[i].ttime=p[i].wtime+p[i].btime;
          totttime+=p[i].ttime;
          totwtime+=p[i].wtime;
     }


    printf("\nProcess Scheduling:\n");
    printf("\nProcess\tBurst time\tWaiting time\tTurnaround time");
    for (i=0;i<n;i++){
            
          printf("\n%d\t\t%d\t\t%d\t\t%d",p[i].pid,p[i].btime,p[i].wtime,p[i].ttime);}
    
    printf("\nTotal waiting time :%d",totwtime);
printf("\nAverage waiting time:%f",(float)totwtime/n);

printf("\nTotal turnaround time :%d",totttime);
printf("\nAVerage turnaround time:%f",(float)totttime/n);
free(p);

return 0;
}











              





