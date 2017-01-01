#include<bits/stdc++.h>
using namespace std;
#define v 9

int minIndex(int key[], bool mstSet[]){
    int min = INT_MAX;
    int value;

    for(int i=0; i<v; i++){
        if(mstSet[i] == false && key[i] < min){
            min = key[i];
            value = i;
        }
    }
    return value;
}

void primMST(int parent[], int graph[v][v]){
    cout << "Edges\t\tWeight" << endl;
    for(int i=1; i<v; i++){
        cout << parent[i] << " - " << i << "\t\t" << graph[i][parent[i]] << endl;
    }
}

void primMST(int graph[v][v]){
    int parent[v];
    int key[v];
    bool mstSet[v];

    for(int i=0; i<v; i++){
        mstSet[i] = false;
        key[i] = INT_MAX;
    }

    key[0] = 0;

    for(int i=0; i<v-1; i++){
        int u = minIndex(key, mstSet);
        mstSet[u] = true;

        for(int k=0; k<v; k++){
            if(graph[u][k] && mstSet[k] == false && key[k] > graph[u][k]){
                parent[k] = u;
                key[k] = graph[u][k];
            }
        }
    }
    primMST(parent, graph);
}

int main()
{
   /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
    int graph [v][v] = {    {0,4,0,0,0,0,0,8,0},
                            {4,0,8,0,0,0,0,11,0},
                            {0,8,0,7,0,4,0,0,2},
                            {0,0,7,0,9,14,0,0,0},
                            {0,0,0,9,0,10,0,0,0},
                            {0,0,4,14,10,0,2,0,0},
                            {0,0,0,0,0,2,0,1,6},
                            {8,11,0,0,0,0,1,0,7},
                            {0,0,2,0,0,0,6,7,0},
                        };
    primMST(graph);
    return 0;
}
