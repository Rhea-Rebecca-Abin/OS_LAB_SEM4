// Shortest remaining time
#include<stdio.h>
#define MAX 100
int main(){

int a[MAX],b[MAX],x[MAX],i,j,smallest,count=0,time,n;
double avg=0,tt=0,end;

printf("\nEnetr the no of processes\n:");
scanf("%d",&n);
printf("ENter arrival time and burst time\n");
for (i=0;i<n;i++){
    scanf("%d%d",&a[i],&b[i]);
    x[i]=b[i];}
b[MAX-1]=9999;
for (time=0;count!=n;time++){
     smallest=MAX-1;
     for (i=0;i<n;i++){
      if(a[i]<=time & b[i]<b[smallest] && b[i]>0)
            smallest=i;
                      }
     b[smallest]--;
     if(b[smallest]==0){
          count++;
          end=time+1;
          avg=avg+end-a[smallest]-x[smallest];
          tt=tt+end-a[smallest];
          }}
printf("\nAverage waiting time %lf\n",avg/n);
printf("\nAverage turnaround time %lf\n",tt/n);
}
