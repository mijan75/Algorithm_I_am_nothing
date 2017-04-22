#include<bits/stdc++.h>
using namespace std;
#define mx 1000
#define INF 1000000

int graph[mx][mx];

void floydWarshal(int vertex){
    for(int k=0; k<vertex; k++)
        for(int j=0; j<vertex; j++)
            for(int i=0; i<vertex; i++)
                if(graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];

    /// This portion is fron print all the path from each vertex
    /*
    for(int i=0; i<vertex; i++){

        for(int j=0; j<vertex; j++){
            if(graph[i][j] == 1000000)
                cout << "There is no path between " << i << " and " << j << endl;
            else
                cout << "The shortest path between " << i << " and " << j << " is: " << graph[i][j] << endl;
        }
        cout << endl;
    }
    */
    int source, destinaiton;
    cin >> source >> destinaiton;
    cout << "The shortest path between " << source << " and " << destinaiton << " is: " << graph[source][destinaiton] << endl;
}

int main(){
    int vertex;
    cout << "Enter the nubmer of vertex: " << endl;
    cin >> vertex;

    int cost;
    for(int i=0; i<vertex; i++){
        for(int j=0; j<vertex; j++){
            cin >> cost;
            graph[i][j] = cost;
        }
    }

    floydWarshal(vertex);

    return 0;
}

