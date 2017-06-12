#include <bits/stdc++.h>
using namespace std;
void dfs(int source);

int graph[100][100];
int visit[100];
stack<int> s;

int main(){
    int vertex, edge;
    cin >> vertex >> edge;
    int from, where;
    while(edge--){
        cin >> from >> where;
        graph[from][where] = 1;
    }
    int source;
    cin >> source;
    dfs(source);
}

void dfs(int source){
    s.push(source);
    cout << source << " ";
    visit[source] = 1;
    bool check = false;

    while(s.size() != 0){
        int f = s.top();
        check = false;
        for(int i=0; i<100; i++){
            if(graph[f][i] == 1 && visit[i] == 0){
                visit[i] = 1;
                cout << i << " ";
                s.push(i);
                check = true;
                break;
            }
        }
        if(check == false)
            s.pop();
    }
}

