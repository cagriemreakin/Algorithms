#include <iostream>

using namespace std;

int bubble_sort(int [],int); 

int main()
{
	int i,j,temp;
	int a[5]={5,4,3,1,2};
	int size=5;
	for(i=1;i < size;i++)
	{
		int flag=0;
		for (j=0 ; j < size-1 ; j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				flag=1;
				cout<<"i= "<<i<<" j= "<<j<<endl;
					for(int k=0;k<size;k++)
	 					std::cout<<a[k]<<" ";
			}
		}
		if (flag==0)
		{
			cout<< "burda"<<endl;
			 break;
			
		}
		 
	}

	//insertion_sort(a, size);

	system("pause");
	return 0;
	
}

