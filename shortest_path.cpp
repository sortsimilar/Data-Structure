#include<iostream>  
#include<climits>
#include<vector>
using namespace std;


int num_v; // Number of vertices in the graph
vector<int> dist;     // The output array.  dist[i] will hold the shortest distance from src to i
vector<bool> sptSet; // sptSet[i] will true if vertex i is included in shortest path tree or shortest distance from src to i is finalized
vector<int> previous;
vector<int> adjacency_matrix;

int get_weight(int start, int end)
{
	return adjacency_matrix[start*num_v + end];
}


int get_MinIndex()
{
	// Initialize min value
	int min_distance = INT_MAX;
	int min_index;
  
	for (int v=0;v<num_v;v++)
	{
		if (sptSet[v]==false && dist[v]<=min_distance)
		{
			min_distance = dist[v];
			min_index = v;
		}
	}

	return min_index;
}



void dijkstra(int src)
{            
	for (int i=0;i<num_v;i++)
	{
        dist[i] = INT_MAX;
		sptSet[i] = false;
		previous[i] = -1;
	}
  

	dist[src] = 0;
  
	for (int i=0;i<num_v;i++)
	{
		int u = get_MinIndex();
		sptSet[u] = true;


		for (int v=0;v<num_v;v++)
		{
			if (!sptSet[v] && get_weight(u, v) && dist[u]!=INT_MAX && dist[u]+get_weight(u, v) < dist[v])
			{
				dist[v] = dist[u] + get_weight(u, v);
				previous[v] = u;
			}
		}
	}

}
  

// A utility function to print the constructed distance array
int printSolution(int src)
{
	for (int i=0;i<num_v;i++)
	{
		cout<<src<<" distance to ";
		cout<<i<<" is "<<dist[i]<<"; path is ";

		int current = i;
		while(current != -1)
		{
			cout<<current<<" ";
			current = previous[current];
		}
		cout<<endl;
	}
}



int main()
{
	num_v = 9;

	dist.resize(num_v);
	sptSet.resize(num_v);
	previous.resize(num_v);


	adjacency_matrix.resize(num_v*num_v);
	for(int i=0;i<num_v*num_v;i++)
	{
		adjacency_matrix[i] = 0;
	}

	// save current amp in adjacency matrix;
	int num_e = 14;
	for(int i=0;i<num_e;i++)
	{
		int start;
		cin>>start;
		int end;
		cin>>end;
		int weight;
		cin>>weight;

		adjacency_matrix[start*num_v + end] = weight;
		adjacency_matrix[start + end*num_v] = weight;
	}
  
    dijkstra(1);
  
	// print the constructed distance array
	printSolution(1);

    return 0;
}

/*
0 1 4
1 2 8
2 3 7
3 4 9
4 5 10
5 6 2
6 7 1
7 0 8
1 7 11
3 5 14
2 8 2
8 6 6
7 8 7
2 5 4
*/
