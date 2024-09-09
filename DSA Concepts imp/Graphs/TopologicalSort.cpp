// adjacency list meaning print neighbour of a node in same  graph
// bfs is queue based dfs is recursion based

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj; // Corrected spelling to unordered_map

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected
        // direction = 1 -> directed graph

        // create an edge from u to v
        adj[u].push_back(v);
        if (direction == 0)
        {
            // undirected graph, so add edge from v to u as well
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    // BFS krna hai
    ////har node ka neighbour add kran hai queue mein
    // ek data structre maintain krna hai taaki repeate na ho elements
    void bfs(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;

        // src yaani pehla node its visited so mark true
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            // front node ko daalke pop krke print krdo
            int frontNode = q.front();
            q.pop();
            cout << frontNode << " , ";

            // insert neighbour
            // neighbour insert krna se pehle check krlo
            // ki vo visited na ho
            for (auto neighbour : adj[frontNode])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void dfs(int src, unordered_map<int, bool> &visited)
    {
        cout << src << ", ";
        visited[src] = true;
        // jo bhi adjcancy list ke neighbour hai
        for (auto neighbour : adj[src])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
        }
    }


    void topoSortDfs(int src, unordered_map<int, bool> &visited, stack<int>&ans)
    {
    
        visited[src] = true;
        // jo bhi adjcancy list ke neighbour hai
        for (auto neighbour : adj[src])
        {
            if (!visited[neighbour])
            {
                topoSortDfs(neighbour, visited, ans);
            }
        }

        //while returning, store the node in stack
        ans.push(src);
    }

};  

int main()
{
    graph g;
    // n-> number of nodes
    int n = 8;
    // last 0 is representing undirectional graph
    // last 1 is representing directional graph
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 4, 1);
    g.addEdge(6, 7, 1);
    // g.addEdge(4,0,1);

    g.printAdjList();
    cout<<endl;

    unordered_map<int,bool> visited;
    stack<int> ans;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.topoSortDfs(i,visited,ans);
        }
    }

    cout<<"Topo Sort: "<<endl;
    while(!ans.empty()){
        cout<<ans.top();
        ans.pop();
    }


    return 0;
}