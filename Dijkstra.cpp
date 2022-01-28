#include<bits/stdc++.h>
using namespace std;

#define V 6

int selectMinVertex(vector<int>& value,vector<bool>& processed)
{
	int minimum = INT_MAX;
	int vertex;
	for(int i=0;i<V;++i)
	{
		if(processed[i]==false && value[i]<minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}

void dijkstra(int graph[V][V])
{
	int parent[V];		//Stores Shortest Path Structure
	vector<int> value(V,INT_MAX);	//Keeps shortest path values to each vertex from source
	vector<bool> processed(V,false);	//TRUE->Vertex is processed

	//Assuming start point as Node-0
	parent[0] = -1;	//Start node has no parent
	value[0] = 0;	//start node has value=0 to get picked 1st

	for(int i=0;i<V-1;++i)
	{
		int U = selectMinVertex(value,processed);
		processed[U] = true;

		for(int j=0;j<V;++j)
		{
			if(graph[U][j]!=0 && processed[j]==false && value[U]!=INT_MAX && (value[U]+graph[U][j] < value[j]))
			{
				value[j] = value[U]+graph[U][j];
				parent[j] = U;
			}
		}
	}
	for(int i=1;i<V;++i)
		cout<<"U->V: "<< 0 <<"->"<<i<<"  weight = "<<value[i]<<"\n";
}

int main()
{
	int graph[V][V] = { {0, 1, 4, 0, 0, 0},
						{1, 0, 4, 2, 7, 0},
						{4, 4, 0, 3, 5, 0},
						{0, 2, 3, 0, 4, 6},
						{0, 7, 5, 4, 0, 7},
						{0, 0, 0, 6, 7, 0} };

	dijkstra(graph);	
	return 0;
}
