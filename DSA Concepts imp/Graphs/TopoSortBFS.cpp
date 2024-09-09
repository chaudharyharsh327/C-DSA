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




    void topoSortBfs(int n, vector<int>& ans){
        queue<int> q;
        unordered_map<int, int> indegree;

        //indegree calculate kro
        //jo bhi neighbour hai uski indegreee +1 krdo 
        for(auto i: adj ){
            int src = i.first;
            for(auto nbr:i.second){
                indegree[nbr]++;
            }
        }

        //indegree calculate krli jiski indegree 0 hai use queue mein insert krdo
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        //bfs logic
        while(!q.empty()){
            int fNode = q.front();
            q.pop();

            ans.push_back(fNode);

            for(auto nbr: adj[fNode]){
                indegree[nbr]--; //queue mein daalne ke baad jab node ko hatoge toh saari degree -1 ho jaegi
                if(indegree[nbr] == 0){ //- krne ke baad koi indegree zero hoti hai toh use push krdo
                    q.push(nbr);
                }
            }

        }


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


    vector<int> ans;
    g.topoSortBfs(n,ans);

    if(ans.size() == n){
        cout<<"It is a valid topo sort"<<endl;
    }
    else{
        cout<<"Cycle present or invalid topo sort"<<endl;
    }
    
    cout<<"Printing Topological Sort using BFS: "<<endl;

    for(auto i:ans){
        cout<<i<<", ";
    }cout<<endl;
    return 0;
}








