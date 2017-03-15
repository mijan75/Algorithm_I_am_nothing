#define loop(i,n) for(int i=1; i<=n; i++)
#define add(x,y) (x+y)
#define max (x,y) (x>y?x:y)
#define mx 100000


#include<bits/stdc++.h>
using namespace std;

vector<int> graph[mx];
bool visit [mx];

class Node{

public:
    int u, w;
};

int bfs(int source, int destinaiton){
    queue<Node> Queue;
    Node node;
    node.u = source;
    node.w = 0;
    Queue.push(node);
    visit[source] = true;

    while(Queue.size() != 0){
        int u = Queue.front().u;
        ///This line is for traversal;
        cout << u << endl;
        int w = Queue.front().w;
        Queue.pop();

        ///This line is for find the vlaue of cost
        //if(u == destinaiton) return w;
        for(int i=0; i< graph[u].size(); i++){
            int v = graph[u][i];

            if(visit[v] == false){
                visit[v] = true;
                node.u = v;
                node.w = w + 1;
                Queue.push(node);
            }
        }

    }
    return -1;

}

int main(){
    int vertex, edge;
    cout << "Enter number of vertex and edge" << endl;
    cin >> vertex >> edge ;

    int from, where;
    for(int i=0; i<edge; i++){
        cin >> from >> where;

        graph[from].push_back(where);
        
    }

    int source, destination;
    cout << "Enter the source and the destination" << endl;
    cin >> source >> destination;
    int value = bfs(source, destination);
    value==-1?cout << "There is no path between source and destination": cout << value ;
    return 0;
}

    ///(0, 1);
    ///(0, 2);
    ///(1, 2);
    ///(2, 0);
    ///(2, 3);
    ///(3, 3);

