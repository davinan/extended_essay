#include <bits/stdc++.h>
#include <fstream>
#define N 10000
     
using namespace std;
int NUMedges;
struct graph {
	int x;
	int y;
};
int nEdges (int nNodes){
	/*if (nNodes == 2)
		return 1;
	else 
		return (nEdges(nNodes - 1) + (nNodes - 1));*/ 
	int v = 0; 
	for (int i = 1; i < nNodes; i++)
	{	
		v += i-1;
	}
	return v;
} 
int main() {
	NUMedges = 704882705;//704882705 for 100000
	graph gr[NUMedges];
	int x[N+2];
	for (int i = 0; i < N; i++) {
		x[i] = 0;
	}
	for (int i = 0; i < NUMedges; i++) {
		int v1 = rand()%(N+1);
		int v2 = rand()%(N+1);
		while (v1 == v2){
			v2 = rand()%(N+1);
		}
		//cout << i << endl;
		x[v1]++;
		x[v2]++; 
		gr[i].x = v1;
		gr[i].y = v2;
		if (i == N) {
			for (int y = 0; y < N; y++) {
				if (!x[y]) {
					v1 = y;
					v2 = rand()%(N+1);
					while (v1 == v2 || x[v2]==4) {
						v2 = rand() % (N+1);
					}
					x[y] = 1;
					gr[i+1].x = v1;
					gr[i+1].y = v2;
					i++;
				}
			}
		}
	}
	ofstream myfile;
	myfile.open ("in4.txt");
	myfile << NUMedges << " " << (N-1) << endl;
	for (int i =0; i < NUMedges; i++) {
		myfile << gr[i].x << " " << gr[i].y << endl;
	}
	myfile.close();
	return 0;

}
