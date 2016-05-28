#include <iostream>

using namespace std;

void printArray(int A[],int n)
{
	int i;
	for (i=0;i<n;i++)
	{
	cout<<" "<<A[i];
	}
	printf("\n");
}
int partition(int A[], int start, int last)
{
	int x,i,j;

	i = start;
	for (j=start;j<last ;j++)
	{
		if (A[j]<A[last])
		{
			
		swap (A[i],A[j]);
		i++;
	
		for(int x=0;x<=last;x++)
		   cout<<A[x]<<" ";
		cout<<endl;
		}
		
	}
	swap (A[i],A[last]);
    for(int x=0;x<=last;x++)
		   cout<<A[x]<<" ";
	cout<<endl<<endl;
		cout<<"i is "<<i<<endl;
	return i;
}
void quickSort(int A[], int start, int last)
{
	int q;

	if (last>start)
	{
		
		q = partition(A,start,last);
		cout<<"q= "<<q<<endl;
		cout<<"before q-1"<<endl;
		quickSort(A,start,q-1);
			cout<<"before q+1"<<endl;
		quickSort(A,q+1,last);
	}
}



int main()
{
	int n,i,*A;

	cin>>n;

	A = new int[n];

	for (i=0;i<n;i++)
	{
		cin>>A[i];
	}

	printArray(A,n);

	quickSort(A,0,n-1);
	
	printArray(A,n);
}
