#include<bits/stdc++.h>
using namespace std;
#define V 4
#define INF 999999

void floydWarshall(int graph[V][V]){
    int dis[V][V], i, j, k;

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++)
            dis[i][j] = graph[i][j];
    }

    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(dis[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d",dis[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

    floydWarshall(graph);
    return 0;
}
