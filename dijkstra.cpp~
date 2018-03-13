#include<bits/stdc++.h>
using namespace std;
#define mx 1000

vector<int> graph[mx];
vector<int> cost[mx];
bool visit[mx];

class Node{
public:
    int u, w;

};

class Compare{
public:
    bool operator() (Node &a, Node&b){
        if(a.w > b.w) return true;
        else return false;
    }
};

int dijkstra(int source, int destination){
    priority_queue<Node, vector<Node>, Compare>Pq;
    Node node;
    node.u = source;
    node.w = 0;
    visit[source] = true;
    Pq.push(node);

    while(Pq.size() != 0){
        node = Pq.top();
        Pq.pop();
        int u = node.u;
        int w = node.w;

        if(u == destination) return w;

        for(int i=0; i<graph[u].size(); i++){
            int v = graph[u][i];

            if(visit[v] == false){
                node.u = v;
                node.w = w + cost[u][i];
                visit[v] = true;
                Pq.push(node);
            }
        }
    }
    return -1;
}

int main(){
    int vertex, edge;
    cout << "Eneter number of vertex and edges" << endl;
    cin >> vertex >> edge;
    int from , where, weight;
    cout << "Enter the value of from to and cost" << endl;
    while(edge--){
        cin >> from >> where >> weight;
        graph[from].push_back(where);
        cost[from].push_back(weight);
    }
    int source, destination;
    cout << "Enter the source and the destination" << endl;
    cin >> source >> destination;
    int value = dijkstra(source, destination);

    if(value == -1) cout << "There is no shortest path between " << source << " and " << destination << endl;
    else
        cout << "The sortest path between " << source << " to " << destination << " is: " << value;
    return 0;
}
