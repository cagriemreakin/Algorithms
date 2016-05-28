#include <iostream>

using namespace std;
void selection(int [],int);
int main()
{
	int i,j;
	
	int a[6]={2,7,4,1,5,3};
	selection (a,6);
	system("pause");
	return 0;
}

void selection (int array[],int size)
{
	int i,j,index,temp;
	for ( i = 0 ; i < ( size - 1 ) ; i++ )
   {
      index = i;
      
      for ( j = i + 1 ; j < size ; j++ )
      {
         if (  array[j] < array[index] )
            index = j;
      }
     swap(array[index],array[i]);
         
         
         
     cout<<" i= "<<i<<endl;
     for(int k=0;k<size;k++)
        cout<<array[k]<<" ";
     cout<<endl<<endl;
   }

}
