#include <iostream>
using namespace std;
#define MAX 290
void Floyd_Warshal(int graph[MAX][MAX], int D[MAX][MAX], int P[MAX][MAX], int numberOfNodes){
 	  for(int i = 0 ; i < numberOfNodes ; i++)
 	    for(int j = 0 ; j < numberOfNodes ; j++){
 	      D[i][j] = graph[i][j];
 	      P[i][j] = -1;
 	    }
 	  for(int k = 0 ; k < numberOfNodes ; k++)
 	    for(int i = 0 ; i < numberOfNodes ; i++)
 	      for(int j = 0 ; j < numberOfNodes ; j++)
 	        if(D[i][j] > D[i][k] + D[k][j]){
 	          D[i][j] = D[i][k] + D[k][j];
 	          P[i][j] = k;
 	        }
 }

int main()
{
	int n,m;
	cin >> n >> m;
	int input[MAX][MAX];
	int dummy_use[MAX][MAX];
	int answer[MAX][MAX];
	int dummy1,dummy2,dummy3;
	for( int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			input[i][j] = 2;
		}
	for(int i = 0; i < m; i++)
	{
		cin >> dummy1 >> dummy2 ;
		input[dummy1-1][dummy2-1] = 1;
		input[dummy2-1][dummy1-1] = 1;
	}
	for(int i = 0; i < n; i++)
		input[i][i] = 0;
	Floyd_Warshal(input,answer,dummy_use,n);
	int min = 0;
	int min_position = -1;
	int complex_of_point[MAX];

	for( int i = 0; i < n; i++)
		complex_of_point[i] = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			complex_of_point[i] += answer[i][j];
	}
	min = complex_of_point[n-1];
	for(int i = n-1; i >= 0; i--)
	{
		if( complex_of_point[i] <= min)
		{
			min = complex_of_point[i];
			min_position = i;
		}
	}
	cout << min_position+1 << endl;
}






