#include <iostream>

using namespace std;

int insertion_sort(int [],int); 

int main()
{
	int i,j,temp;
	int a[6]={7,2,4,1,5,3};
	int size=6;
	for(i=1;i<=size;i++)
	{
		j=i;
		while(j>0 && a[j]<a[j-1]){
		    
		    
		   swap(a[j],a[j-1]);
		   j--;
		   cout<<"If i = "<<i<<endl;
		   	for(int k=0;k<size;k++)
	   		 std::cout<<a[k]<<" ";
	   	
		cout<<endl<<endl;   
	}
}
	//insertion_sort(a, size);

	system("pause");
	return 0;
	
}

