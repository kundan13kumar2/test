#include<stdio.h>
#define MAX 10
int adj[MAX][MAX];
int n;
int main()
{
	int max_edge,start,end,i,j,type;
	printf("\nEnter the number of the vertices:-");
	scanf("%d",&n);
	printf("\nEnter the type of the graph(1 for directed and 2 for undirected):-");
	scanf("%d",&type);
	if(type==2)
		max_edge=n*(n-1)/2;
	else
		max_edge=n*(n-1);
	for(i=1;i<=max_edge;i++)
	{
		printf("\nEnter the edge(-1 -1 for quit):-");
		scanf("%d %d",&start,&end);
		if(start==-1 && end==-1)
			break;
		if(start>=n || start<0 ||end>=n||end<0)
		{
			printf("\nInvalid edge....");
			i--;
		}
		else
		{
			adj[start][end]=1;
			if(type==2)
				adj[end][start]=1;
		}
	}
	printf("\nThe required Adjacency atrix:-\n");
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
			printf("%5d",adj[i][j]);
		printf("\n");
	}
return 0;	
}

