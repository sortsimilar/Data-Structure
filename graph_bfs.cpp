#include<iostream>
#include<vector>
using namespace std;


int num_v;
vector<bool> adjacency_matrix;
vector<bool> visited;


bool test_edge(int start, int end)
{
	bool flag = false;

	if(adjacency_matrix[(start-1)*num_v+(end-1)]==true)    flag = true;
	if(adjacency_matrix[(start-1)+(end-1)*num_v]==true)    flag = true;

	return flag;
}


// BFS one range;
void BFS(int i)
{
	visited[i-1] = true;	

	vector<int> q;
	cout<<i<<" ";	
	q.push_back(i);

	while(q.size()!=0)
	{
		int current = q.front();
		q.erase(q.begin());

		for(int j=1;j<=num_v;j++)
		{
			if((test_edge(current, j) == true)&&(visited[j-1]==false))
			{
				visited[j-1] = true;
				cout<<j<<" ";
				q.push_back(j);
			}
		}
	}
}



// BFS all map;
void BFSTraverse()
{
	// initialize visited matrix;
	for(int i=1;i<=num_v;i++)
	{
		visited[i-1] = false;
	}


	for(int i=1;i<=num_v;i++)
	{
		if(visited[i-1]==false)
		{
			BFS(i);
		}
	}
}





int main()
{
	int N; // number of vertices
	cin>>N;	
	num_v = N;
	int M; //  number of edges	
	cin>>M;

	// create adjacency matrix;
	for(int i=0;i<N*N;i++)
	{
		adjacency_matrix.push_back(false);
	}

	// save current amp in adjacency matrix;
	for(int i=0;i<M;i++)
	{
		int start;
		cin>>start;
		int end;
		cin>>end;

		adjacency_matrix[(start-1)*N + (end-1)] = true;
		adjacency_matrix[(start-1) + (end-1)*N] = true;
	}

//	cout<<test_edge(2, 1)<<endl;
//	cout<<test_edge(2, 4)<<endl;

	// generate visited point;
	visited.resize(N);
	for(int i=0;i<N;i++)
	{
		visited[i] = false;
	}



//	BFS(1); // test BFS one range;
	BFSTraverse();



	return 0;
}

/*
5 3
1 2
3 4
2 5
*/
