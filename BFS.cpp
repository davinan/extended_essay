#include <bits/stdc++.h>
using namespace std;
vector <int> adj_list[912345];
int visited[912345];
int z;
void BFS (int IDX){
	visited[IDX] =1;
	queue <int> q;
	q.push(IDX);

	while (!q.empty()){
		int actual = q.front();
		q.pop();
		for (int i=0;i<adj_list[actual].size();i++){
			if (!visited[adj_list[actual][i]]){
				visited[adj_list[actual][i]] = 1;
				q.push(adj_list[actual][i]);
			}
		}
	}
}

int main() {
	clock_t t;
	int N;
	cin >> N >> z;
	for (int i =0; i < N; i++) {
		visited[i] = 0;
	}
	for (int i =0;i<z;i++){
		int x, y;
		cin >> x >> y;
		adj_list[x].push_back(y);
		adj_list[y].push_back(x);
	}
	t = clock();
	BFS(1);
	t = clock() -t;
	double time = ((double)t) / CLOCKS_PER_SEC;
	cout << "Elapsed Time: " << time << endl;
	return 0;
}
