
 
#include <iostream>
using namespace std;
#define V 500
 int n;

int minKey(int key[], bool mstSet[])
{
   int min = INT_MAX;
	int min_index = 0; 
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 

void printMST(int parent[], int n, int graph[V][V])
{
 
	int ans = 0;
   for (int i = 1; i < n; i++)
	   ans += graph[i][parent[i]];
   cout << ans <<endl;
   for (int i = 1; i < n; i++)
      cout << parent[i]+1 << " " << i+1 << '\n';

}

void primMST(int graph[V][V])
{
     int parent[V];
     int key[V];   
     bool mstSet[V];  
 
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
     key[0] = 0;     
     parent[0] = -1; 
     for (int count = 0; count < V-1; count++)
     {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
     printMST(parent, n, graph);
}
 
 
int main()
{

   int graph[V][V];
  int m;
   cin >> n >> m;
   for( int i = 0; i < V; i++)
   {
	   for( int j = 0; j < V; j++)
		   graph[i][j] = 0;
   }
   int dummy1,dummy2,dummy3;
   for(int i = 0; i < m; i++)
   {
	   cin >> dummy1 >> dummy2 >> dummy3;
	   graph[dummy1-1][dummy2-1] = dummy3;
	   graph[dummy2-1][dummy1-1] = dummy3;
   }

    primMST(graph);
 
    return 0;
}