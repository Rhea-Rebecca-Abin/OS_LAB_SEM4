#include<stdio.h>
#include<stdlib.h>
struct rr {
 int pno;
int btime;
int sbtime;
int wtime;
int lst;
}p[10];

int main(){

  int pp=-1,ts,flag,count,ptm=0,i,n,twt=0,tottime=0;
  printf("\nRound Robin Scheduling...\n");
  printf("Enetr the number of processes:");
 scanf("%d",&n);
 printf("ENter the time slice");
 scanf("%d",&ts);
 printf("ENter the burst time:\n");

  for (i=0;i<n;i++)
  {printf("Process %d:",i+1);
   scanf("%d",&p[i].btime);
  
   p[i].wtime=p[i].lst=0;
   p[i].pno=i+1;
   p[i].sbtime=p[i].btime;
  
  }

  printf("Scheduling...\n");
  do{
     flag=0;
     for(i=0;i<n;i++){
         count=p[i].btime;
         if(count>0){
              flag=-1;
               count=(count>=ts)?ts:count;
               printf("\nProcess %d from %d to %d",p[i].pno,ptm,ptm+count);
               ptm+=count;
               p[i].btime-=count;
                 
               if(pp!=i){
                   pp=i;
                   p[i].wtime+=ptm-p[i].lst;
                   p[i].wtime-=count;
                   p[i].lst=ptm;
                   twt+=p[i].wtime;
         }}}

     }while (flag!=0);


  printf("\nProcess Scheduling:\n");
  printf("\nProcess\tBurst time\tWaiting time\tTurnaround time");
    
   for (i=0;i<n;i++){
            p[i].wtime=p[i].lst=p[i].sbtime;
            
            tottime+=p[i].lst;
            printf("\n%d\t\t%d\t\t%d\t\t%d",p[i].pno,p[i].sbtime,p[i].wtime,p[i].lst);}
            
printf("\nTotal waiting time :%d",twt);
printf("\nAverage waiting time:%f",(float)twt/n);

printf("\nTotal turnaround time :%d",tottime);
printf("\nAVerage turnaround time:%f",(float)tottime/n);
 return 0;
 }       
