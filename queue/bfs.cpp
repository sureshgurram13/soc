#include <bits/stdc++.h>
using namespace std;

class Graph {
public:

    map<int, vector<int> > adj;
 
    void addEdge(int v, int w);
    void BFS(int v);

};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 
void Graph::BFS(int v)
{   

    map<int, bool> visited;

    queue<int> temp ;
    temp.push(v);

    while(temp.size() != 0){

        int curr = temp.front();
        temp.pop();

        if(!visited[curr]){
            visited[curr] = true;
            cout << curr << " ";            
        }else{continue;}

        for (auto ad : adj[curr]){temp.push(ad);}

    }

}
 

int main()
{

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal"
            " (starting from vertex 2) \n";
 
    g.BFS(2);
 
    return 0;
}