#include<stdio.h>
#define MAX 50
int adj[MAX][MAX];
int n;
int state[MAX];
int queue[MAX],front=-1,rear=-1;
#define non_Visited 1
#define visited 2
#define processed 3
void create_graph()
{
	int init,dest,max_edge,i,j,type;
	printf("\nEnter the number of vertices:-");
	scanf("%d",&n);
	printf("\nEnter the type of the graph(1 for directed and 2 for indirected):-");
	scanf("%d",&type);
	if(type==1)
		max_edge=n*(n-1);
	else
		max_edge=n*(n-1)/2;
	for(i=1;i<=max_edge;i++)
	{
		printf("\nEnter the edge(-1 -1 for quit)");
		scanf("%d %d",&init,&dest);
		if(init==-1 &&dest==-1)
			break;
		if(init>=n||init<0||dest>=n||dest<0)
		{
			printf("\nInvalid entry");
			break;
		}
		else
		{
			adj[init][dest]=1;
			if(type==2)
				adj[dest][init]=1;
		}
	}
}
void insert(int n)
{
	if(rear==MAX-1)
		printf("Queue overflow..");
	else
	{
		if(front==-1)
			front=0;
		rear=rear+1;
		queue[rear]=n;
	}
}
int isEmpty()
{
	if(front==-1|| front>rear)
		return 1;
	else
		return 0;
		
}
int delete()
{
	int num;
	if(front==-1 ||front>rear)
	{
		printf("Queue underflow");
		exit(1);
	}
	num=queue[front];
	front=front+1;
return num;
}
void BFS(int v)
{
	int i;
	insert(v);
	state[v]=visited;
	while(!isEmpty())
	{
		v=delete();
		printf("%5d",v);
		state[v]=processed;
		for(i=0;i<n;i++)
		{
			if(adj[v][i]==1 && state[i]==non_Visited)
			{
				insert(i);
				state[i]=visited;
			}
		}
	}
	printf("\n");
}
void BF_Search()
{
	int v;
	for(v=0;v<n;v++)
		state[v]=non_Visited;
	printf("\nEnter the source vertices of the graph:-");
	scanf("%d",&v);
	BFS(v);
}
int main()
{
	create_graph();
	BF_Search();
return 0;
}
