/* Merge sort*/


#include <iostream>
void Merge (int *,int *,int,int* ,int);
void Mergesort(int *, int);
using namespace std;

int main()
{
	int size=5;
    int a[size]={88,11,99,125,12};
    
 
	  Mergesort(a,size);
 	
       
    	for(int i=0; i<size; i++)
           cout<<a[i]<<" ";
         cout<<endl;
   
    system("pause");
    return 0;
    
}
void Merge (int *A,int *L,int leftCount,int* R,int rightCount){
	int i,j,k;
	i=j=k=0;
	

	cout<<"leftCount = mid "<<leftCount<<" rightCount =size-mid "<< rightCount<<endl;
		while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
	
	for(int i=0; i<leftCount+rightCount; i++)
           cout<<A[i]<<" ";
         cout<<endl;
	
}

void Mergesort(int *a, int size){
	
	int *l,*r,mid;
	if (size<2) return;
	
	mid=size/2;
	
	l=new int[mid];
	r=new int[size-mid];

	for (int i=0;i<mid;i++)
	     l[i]=a[i];

	for (int i=mid;i<size;i++)
	     r[i-mid]=a[i];
	
cout<<"burda leftten ONCE"<<endl;
	for(int i=0; i<size; i++)
           cout<<a[i]<<" ";
         cout<<endl;
	Mergesort(l,mid);
	
	cout<<"burda leftten sonra"<<endl;
	for(int i=0; i<size; i++)
           cout<<a[i]<<" ";
         cout<<endl;
	Mergesort(r,size-mid);
		cout<<"burda righttan sonra"<<endl;
	Merge(a,l,mid,r,size-mid);
		cout<<"burda mergetensonra"<<endl;
}
