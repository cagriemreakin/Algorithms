/*C.Emre AKIN 1862457 */
#include<iostream>
#define MAX 1000000
#define MIN -1000000

using namespace std;

int** initializeGraph(int,int);
int **fillGraph(int **,int,int);
void printMatrix(int **,int);
int findMinVal(int,int,bool []);
int calculatePath(int *,int **);
int *findRoot(int**,int*,int * ,int*,int,int);
void prim(int**,int);
void calculatePath(int [], int, int**);

int main()
{
	
	int node,edge,** arr;
	
	try{
		cout<<"Please enter the values"<<endl;
		cin>>node>>edge;  
		arr = initializeGraph(node,edge);
		fillGraph(arr,edge,node);
	printMatrix(arr,node);
	prim(arr,node);	
	}
	catch (const char* msg) {			//throws exception if   n>100 && egde>10000
		cerr << msg << endl;
	}

	
	system("pause");
	return 0;
}

int** initializeGraph(int node,int edge){
	if (node >100 || node <2 || edge>10000 || edge <1)
	{

	 throw "Please check the values again! node<= 100 ,edge< 10000";
	}
	int ** arr = new int *[node];	
	for(int i = 0; i < node; ++i)
    		arr[i] = new int[node];
	
	for(int i = 0; i < node; ++i)
		for (int j=0; j < node; j++)
    	{
   			if(i==j)
			   arr[i][j] = 0; // returns same vertex
		    else 
		       arr[i][j] = MAX;  //cannot reach the vertex,if it has no connection directly
 
    	}
  
	return arr;		
}


int **fillGraph(int **arr,int edge,int node){
	int  source,toNode,distance;

	for(int i = 0; i < edge; i++)
	{
		  cin>>source>>toNode>>distance;
          arr[source-1][toNode-1]=distance; // 1 to 2 = 7 
          arr[toNode-1][source-1]=distance; // 2 to 1 = 7 also

	}
	
	return arr;
}


void printMatrix(int **arr,int node){
	
	for(int i = 0; i < node; i++)
	{
		for (int j=0; j < node; j++)
    	{
    	    cout<< arr[i][j]<<" ";
    	}
     cout<<endl;
	}
}



int findMinVal(int check[],int node,int flag[]){
  int control =MAX,adjacentIndex=-1;
		

	for (int i = 0; i < node; i++)
			if (!flag[i] && check[i] <= control)
			{
				 control= check[i];
				 adjacentIndex = i;
			}
		
	
	
  return adjacentIndex;
}


void prim(int **arr,int node){
	int *check=new int[node],u;
	int *flag=new int[node];
	int *root=new int[node];

	for (int i=0; i<node;) {
		check[i]=MAX; // for all v € V
		flag[i++]=0; // keeps the visited vertexes
	}

	check[0]=0;
	    int k=0;
		while(k<node-1)
		{
			
			u=findMinVal(check,node,flag);  //extract min vertex 
			
	    	flag[u] = 1;  // if vertex visited flag is set to 1;
				
			for (int i = 0;i< node; i++)
				{
					//findRoot(arr,root,flag,check,i,u); //finds the root with respect to flag and check index value
					if(arr && !flag[i]&&check[u]!=MAX)
					if ( arr[u][i]+check[u]<check[i])
						{
							 check[i] = check[u]+arr[u][i];
							
						}
				}
			k++;
		}
	//	calculatePath(root, node, arr);
	 cout<<"Vertex   Distance from Source"<<endl;
	 for (int i = 0; i < node; i++)
      	cout<<i<<"\t\t"<<check[i]<<endl;
}
int *findRoot(int** arr,int *root,int *flag ,int*check,int i,int u){
			
				if(arr && !flag[i]&&check[u]!=MAX)
				if ( arr[u][i]+check[u]<check[i])
					{
						 check[i] = check[u]+arr[u][i];
						
					}
						
	return root;
}
void calculatePath(int root[], int node, int** arr)
{
   int totDistance=0;
   for (int i = 1; i < node; i++)
     totDistance+=arr[i][root[i]];

   cout<<endl<<endl<<totDistance<<endl;
   for (int i = 1; i < node; i++)
	{
	     if(root[i]+1>i+1)
			 cout<<i+1<<" "<<root[i]+1<<" "<<arr[i][root[i]]<<endl;
			  
		 else
			cout<<root[i]+1<<" "<<i+1<<" "<<arr[i][root[i]]<<endl;
	}
}

