// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
#include<iostream>  
#include<climits>
#include<vector>
using namespace std;
// Number of vertices in the graph
#define num_v 9
  

struct Edge
{
	int start;
	int end;
	int weight;
};

vector<Edge> store_edge;

vector<int> dist;     // The output array.  dist[i] will hold the shortest
                      // distance from src to i

vector<bool> sptSet; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized

vector<bool> adjacency_matrix;

int graph[num_v][num_v]= {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance()
{
	// Initialize min value
	int min = INT_MAX;
	int min_index;
  
	for (int v = 0; v < num_v; v++)
	{
		if (sptSet[v] == false && dist[v] <= min)
		{
			min = dist[v];
			min_index = v;
		}
	}  

	return min_index;
}
  
// A utility function to print the constructed distance array
int printSolution()
{
	cout<<"Vertex   Distance from Source"<<endl;
	for (int i = 0; i < num_v; i++)
	{
		cout<<i<<" tt "<<dist[i]<<endl;
	}
}
  
// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int src)
{          
  
	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < num_v; i++)
	{
        dist[i] = INT_MAX;
		sptSet[i] = false;
	}
  
	// Distance of source vertex from itself is always 0
	dist[src] = 0;
  
	// Find shortest path for all vertices
	for (int count = 0; count < num_v-1; count++)
	{
	   // Pick the minimum distance vertex from the set of vertices not
	   // yet processed. u is always equal to src in the first iteration.
	   int u = minDistance();

	   // Mark the picked vertex as processed
	   sptSet[u] = true;

	   // Update dist value of the adjacent vertices of the picked vertex.
	   for (int v = 0; v < num_v; v++)

		 // Update dist[v] only if is not in sptSet, there is an edge from 
		 // u to v, and total weight of path from src to  v through u is 
		 // smaller than current value of dist[v]
		 if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
		                               && dist[u]+graph[u][v] < dist[v])
		    dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution();
}
  
// driver program to test above function
int main()
{
	dist.resize(num_v);
	sptSet.resize(num_v);

	// create adjacency matrix;
	adjacency_matrix.resize(num_v*num_v);
	for(int i=0;i<num_v*num_v;i++)
	{
		adjacency_matrix[i] = 0;
	}

	int num_e = 14;
	store_edge.resize(num_e);
	for(int i=0;i<num_e;i++)
	{
		cin>>store_edge[i].start;
		cin>>store_edge[i].end;
		cin>>store_edge[i].weight;
	}

  
    dijkstra(0);
  
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
