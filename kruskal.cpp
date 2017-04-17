#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int u, v, w;
};

vector<Node> graph;
int parent[1000];

int findParent(int x){
    if(parent[x] = x) return x;
    else return parent[x] = findParent(parent[x]);
}

bool Compare(Node a, Node b){
    return a.w < b.w;
}

int kruskal(int vertex){
    for(int i=1; i<=vertex; i++)
        parent[i] = i;

    sort(graph.begin(), graph.end(), Compare);
    int answer = 0, howmanyEdges = 0;
    for(int i=0; i<graph.size(); i++){
        Node node = graph[i];
        int x = findParent(node.u);
        int y = findParent(node.v);

        if(x != y){
            parent[x] = y;
            howmanyEdges++;
            answer = answer + node.w;
        }
        if(howmanyEdges == vertex-1) break;
    }
    if(howmanyEdges != vertex-1) return -1;
    return answer;
}

int main(){
    int vertex, edge;
    cout << "Enter the number of vertex and edge" << endl;
    cin >> vertex >> edge;

    int from, where, cost;
    while(edge--){
        cin >> from >> where >> cost;
        Node node;
        node.u = from;
        node.v = where;
        node.w = cost;
        graph.push_back(node);
    }
    cout << "The cost is: " << kruskal(vertex);
    return 0;
}
