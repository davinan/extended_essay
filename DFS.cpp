#include <bits/stdc++.h>
using namespace std;
vector <int> adj_list[912345];
int visited[912345];
int cont =0;
int z;
int flag = 0;
void DFS(int IDX){
	cont++;
	visited[IDX] = 1;
	for (int i =0; i<adj_list[IDX].size();i++){
		if (!visited[adj_list[IDX][i]]){
			return DFS(adj_list[IDX][i]);
		}
	}
}
int main() {
	clock_t t;
	int N;
	cin >> N >> z;
	for (int i = 0; i < N; i++){
		visited[i] = 0;
	}
	for (int i = 0; i < z; i++) {
		int x, y;
		cin >> x >> y;
		adj_list[x].push_back(y);
		adj_list[y].push_back(x);	
	}
	t = clock();
	DFS(1);
	t = clock() - t;
	double time = ((double) t) / CLOCKS_PER_SEC;
	cout << "Elapsed Time: " << time << endl;
	cout << "Number of iterations: " << cont << endl;
	return 0;
}
