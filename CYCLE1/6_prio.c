#include<stdio.h>
struct process
{
    int WT,AT,BT,TAT,PT;
};

struct process a[10];

int main()
{
    int n,temp[10],t,count=0,short_p;
    float total_WT=0,total_TAT=0,Avg_WT,Avg_TAT;
    printf("Enter the number of the process\n");
    scanf("%d",&n);
    printf("Enter the arrival time , burst time and priority of the process\n");
    printf("AT BT PT\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].AT,&a[i].BT,&a[i].PT);
        
        temp[i]=a[i].BT;
    }
    
   
    a[9].PT=10000;
    
    for(t=0;count!=n;t++)
    {
        short_p=9;
        for(int i=0;i<n;i++)
        {
            if(a[short_p].PT>a[i].PT && a[i].AT<=t && a[i].BT>0)
            {
                short_p=i;
            }
        }
        
        a[short_p].BT=a[short_p].BT-1;
        
       
        if(a[short_p].BT==0)
        {
            count++;
            a[short_p].WT=t+1-a[short_p].AT-temp[short_p];
            a[short_p].TAT=t+1-a[short_p].AT;
            
      
            total_WT=total_WT+a[short_p].WT;
            total_TAT=total_TAT+a[short_p].TAT;
            
        }
    }
    
    Avg_WT=total_WT/n;
    Avg_TAT=total_TAT/n;
    
   
    printf("PROCESS_ID\tArrival time\tPriority\tBurst time\tTurnaround time\tWaiting time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,a[i].AT,a[i].PT,temp[i],a[i].TAT,a[i].WT);
    }
    
    printf("Avg waiting time of the process  is %f\n",Avg_WT);
    printf("Avg turn around time of the process is %f\n",Avg_TAT);
    
    return 0;
}
/* OUTPUT
Enter the number of the process
5
Enter the arrival time , burst time and priority of the process
AT BT PT
0 3 3
1 4 2
2 6 4
3 4 6
5 2 10
PROCESS_ID	Arrival time	Priority	Burst time	Turnaround time	Waiting time
1		0		3		3		7		4
2		1		2		4		4		0
3		2		4		6		11		5
4		3		6		4		14		10
5		5		10		2		14		12
Avg waiting time of the process  is 6.200000
Avg turn around time of the process is 10.000000
*/
