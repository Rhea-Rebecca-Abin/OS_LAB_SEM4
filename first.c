// C implementation of First - Fit algorithm
#include<stdio.h>

// Function to allocate memory to
// blocks as per First fit algorithm
void firstFit(int blockSize[], int m, int processSize[], int n)
{
	int i, j;
	// Stores block id of the
	// block allocated to a process
	int allocation[n];

	// Initially no block is assigned to any process
	for(i = 0; i < n; i++)
	{
		allocation[i] = -1;
	}

	// pick each process and find suitable blocks
	// according to its size ad assign to it
	for (i = 0; i < n; i++)	 //here, n -> number of processes
	{
		for (j = 0; j < m; j++)	 //here, m -> number of blocks
		{
			if (blockSize[j] >= processSize[i])
			{
				// allocating block j to the ith process
				allocation[i] = j;

				// Reduce available memory in this block.
				blockSize[j] -= processSize[i];

				break; //go to the next process in the queue
			}
		}
	}

	printf("\nProcess No.\tProcess Size\tBlock no.\n");
	for (int i = 0; i < n; i++)
	{
		printf(" %i\t\t\t", i+1);
		printf("%i\t\t\t\t", processSize[i]);
		if (allocation[i] != -1)
			printf("%i", allocation[i] + 1);
		else
			printf("Not Allocated");
		printf("\n");
	}
}

// Driver code
int main()
{       
 int i;
	int m; //number of blocks in the memory
	int n; //number of processes in the input queue
	int blockSize[10];
	int processSize[10];
        printf("Enter no. of blocks: ");
	scanf("%d", &m);
	printf("\nEnter size of each block: ");
	for(i = 0; i < m; i++)
		scanf("%d", &blockSize[i]);
	printf("\nEnter no. of processes: ");
	scanf("%d", &n);
	printf("\nEnter size of each process: ");
	for(i = 0; i < n; i++)
		scanf("%d", &processSize[i]);
	

	firstFit(blockSize, m, processSize, n);

	return 0 ;
}

