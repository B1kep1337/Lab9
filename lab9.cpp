// lab9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "string.h"
#include <cmath>
#include <queue>
using namespace std;


int vis [5] = {0};
int dist [5] = {-1}; 
std::queue <int> q;

int **createG(int size){
	int **G;
	G = (int**)malloc(size * sizeof(int*));
	for(int i=0; i < size; i++){
		G[i] = ((int*)malloc(size * sizeof(int)));
	}

	for (int i=0; i < size; i++){
		for(int j = i; j<size; j++){
			G[i][j] = rand()%2;
			if (i == j) G[i][j] = 0;
			G[j][i] = G[i][j];
		}
	}
	return G;
}

void **printG(int **G, int size){
	for (int i=0; i < size; i++){
		for(int j = 0; j<size; j++){
			printf("%d ",G[i][j]);
		}
		printf("\n");
	}
	return 0;
}
//int **G=NULL, size = 5, vis[5] = {0};
void BFS_dist (int **G, int size, int *dist, int s){
    queue <int> q;
    q.push (s);
    dist[s]=0;
	//vis[s] = 1;
	while (!q.empty()){
	    s = q.front();
	    //printf("%d ", s);
	    q.pop();
	    for(int i=0; i<size; i++){
            if(G[s][i] == 1&&dist[i]==-1){
                q.push (i);
                dist[i]= dist[s] + 1;
            }
	    }
	}
}

void BFS (int **G, int size, int *vis, int s){
    queue <int> q;
    q.push (s);
	vis[s] = 1;
	while (!q.empty()){
	    s = q.front();
	    printf("%d ", s);
	    q.pop();
	    for(int i=0; i<size; i++){
            if(G[s][i] == 1&&vis[i]==0){
                q.push (i);
                vis[i]=1;
            }
	    }
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int **G=NULL;
	int *vis = NULL;
	int *dist = NULL;
	int size = 5;
	printf("Введите количество вершин:\n");
	scanf("%d",&size);
	G = createG(size);
	printG(G, size);
	printf("\nВведите начальную вершину:\n");

	vis = (int*)malloc(size*sizeof(int));
	for (int i=0; i<size; i++) vis[i]=0;
	
	dist = (int*)malloc(size*sizeof(int));
	for (int i=0; i<size; i++) dist[i]=-1;

	int s = 1;
	scanf("%d",&s);
	printf("\nОбход графа:\n");
	BFS(G, size, vis, s);
	
	printf("\nПоиск расстояния:\n");
	for (int i=0; i<size; i++){
	    	dist[i] = -1;
	}
	BFS_dist (G, size, dist, 0);
	
	for(int i=0; i<size; i++){
	    printf("\nРасстояние до %d вершины = %d\n", i, dist[i]);
	}
	
	
	

getchar();
getchar();
return 0;

}

