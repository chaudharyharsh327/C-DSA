// adjacency list meaning print neighbour of a node in same  graph
// bfs is queue based dfs is recursion based

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
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

    bool checkCyclicUsingBfs(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1; // default parent -1

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto nbr : adj[frontNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                // agr node visited hai aur neighbour parent nhi hai jo curretn node h uske
                if (visited[nbr] && nbr != parent[frontNode])
                {
                    // cycle present
                    return true;
                }
            }
        }
        return false;
    }

    bool checkCyclicUsingDfs(int src, unordered_map<int, bool> &visited, int parent)
    {
        visited[src] = true;

        for (auto nbr : adj[src])
        {
            if (!visited[nbr])
            {
                bool checkAageKaAns = checkCyclicUsingDfs(nbr, visited, src);
                if (checkAageKaAns == true)
                    return true;
            }
            if (visited[nbr] && nbr != parent)
            {
                // cycle present
                return true;
            }
        }
        return false;
    }

    bool checkCyclicDirectedGraphUsingDfs(int src,  
        unordered_map<int, bool>& visited,  
        unordered_map<int, bool>& dfsVisited)  
    {  
        // 2 data structure for visited and dfs visited  
        visited[src] = true;  
        dfsVisited[src] = true;  

        for(auto nbr: adj[src]){
            if(!visited[nbr]){
                bool aageKaAnswer = checkCyclicDirectedGraphUsingDfs(nbr, visited,dfsVisited);
                if(aageKaAnswer == true)
                return true;
            }
            if(visited[nbr] == true && dfsVisited[nbr] == true){
                return true;
            }
        }
        //jab call aayi tab true jab call gyi tab false
        dfsVisited[src] = false;
        return false;
    }

};  

int main()
{
    graph g;
    // n-> number of nodes
    int n = 5;
    // last 0 is representing undirectional graph
    // last 1 is representing directional graph
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    // g.addEdge(4,0,1);

    g.printAdjList();

    // for a disconected graph
    // it is graph in which two different graphs are one but they are no conneceted
    // har node ko source maanke call maro taki disconnecte graph pe bhi call mar ske

    // run a loop for all nodes
    cout << "Printing BFS Traversal: " << endl;
     unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.bfs(i, visited);
        }
    }

    cout << endl
         << "Printing DFS Traversal: " << endl;
    unordered_map<int, bool> visited2;
    for (int i = 0; i < n; i++)
    {
        if (!visited2[i])
        {
            g.dfs(i, visited2);
        }
    }

    // CYCLIC GRAPH USING BFS

    bool ans = false;
    unordered_map<int, bool> visited3;
    for (int i = 0; i < n; i++)
    {
        if (!visited3[i])
        {
            ans = g.checkCyclicUsingBfs(i, visited3);
            if (ans == true)
                break;
        }
    }
    cout << endl;
    if (ans == true)
        cout << "Cycle is Present" << endl;
    else
        cout << "Cycle Absent" << endl;

    // CYCLIC GRAPH USING DFS

    bool ansDfs = false;
    unordered_map<int, bool> visitedDfs;
    for (int i = 0; i < n; i++)
    {
        if (!visitedDfs[i])
        {
            ansDfs = g.checkCyclicUsingDfs(i, visitedDfs, -1);
            if (ansDfs == true)
                break;
        }
    }
    cout << endl;
    if (ansDfs == true)
        cout << "Cycle is Present" << endl;
    else
        cout << "Cycle Absent" << endl;

    // DFS USING CYCLIC DIRECTED GRAPH
    cout << endl;

     ans = false;
   
    unordered_map<int, bool> dfsVisited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = g.checkCyclicDirectedGraphUsingDfs(i, visited, dfsVisited);
            if (ans == true)
                break;
        }
    }

      if (ansDfs == true)
        cout << "Cycle is Present" << endl;
    else
        cout << "Cycle Absent" << endl;

    // int n;
    // cout << "Enter the number of nodes: ";
    // cin >> n;

    // int m;
    // cout << "Enter the number of edges: ";
    // cin >> m;

    // for (int i = 0; i < m; i++) {
    //     int u, v;
    //     cout << "Enter the edge (u v): ";
    //     cin >> u >> v;
    //     // creating an undirected graph
    //     g.addEdge(u, v, 0);
    // }

    // // printing graph
    // g.printAdjList();

    return 0;
}