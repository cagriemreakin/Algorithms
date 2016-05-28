#include <stdio.h>
#include <stdlib.h>

void printArray(int A[],int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}

void heapify(int* A, int i, int n)
{

	int l,r,smallest;
	int temp;

	l = (i+1)*2-1;
	r = (i+1)*2+1-1;

	if (l<n && A[l]>A[i])
		smallest = l;
	else
		smallest = i;

	if (r<n && A[r]>A[smallest])
		smallest = r;

	if (smallest == i)
	{
		return;
	}

	temp = A[smallest];
	A[smallest] = A[i];
	A[i] = temp;
	
	heapify(A,smallest,n);

}

void buildHeap(int *A, int n)
{
	int i;
	for (i=n/2-1;i>=0;i--)
		heapify(A,i,n);
}

void heapSort(int A[], int n)
{
	int i,j;
	int temp;

	buildHeap(A,n);

	j = n;

	for (i=0;i<j;i++)
	{
		temp = A[n-1];
		A[n-1] = A[0];
		A[0] = temp;
		n = n-1;
		heapify(A,0,n);
	}
}

int main()
{
	int n;
	int i;
	int *A;

	scanf("%d",&n);

	A = (int *)malloc(sizeof(int)*n);

	for (i=0;i<n;i++)
	{
		scanf("%d",&(A[i]));
	}

	printArray(A,n);

	heapSort(A,n);
	
	printArray(A,n);
}
