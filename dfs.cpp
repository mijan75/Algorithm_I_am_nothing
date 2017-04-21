#include<bits/stdc++.h>
using namespace std;
int graph[10][10],visited[10];
stack<int> s;

int main(){
   int vertex, edge;
   cin >> vertex >> edge;

    int from, where;
    for(int i=0; i<edge; i++){
        cin >> from >> where;
        graph[from][where] = 1;
    }

    int source;
    cin >> source;
    cout << source << " ";
    visited[source] = 1;

    int k=1;
    while(k < vertex){
        for(int j = vertex; j>=1; j--)
            if(graph[source][j] != 0 && visited[j] != 1)
                s.push(j);
        source = s.top();
        s.pop();
        cout << source << " ";
        visited[source] = 1;
        k++;
    }
   return 0;
}

