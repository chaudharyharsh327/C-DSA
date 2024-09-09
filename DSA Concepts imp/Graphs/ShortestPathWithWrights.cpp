#include <iostream>  
#include <unordered_map>  
#include <list>  
#include <queue>  
#include <stack>  
#include <algorithm>  
#include <climits>  
using namespace std;  

class graph {  
public:  
    unordered_map<int, list<pair<int, int>>> adjList;  

    void addEdge(int u, int v, int wt, bool direction) {  
        //directed edge = 1;
        //undirected edge = 0;
        //add edge from u to v with weight
        //FOR DIRECTED
        adjList[u].push_back({v, wt});  
        //if graph is undierected or direction = 1 it also adds edge from u to v
        //FOR UNDIRECTED
        if (direction == 1) {  
            adjList[v].push_back({u, wt});  
        }  
    }  

    void printAdjList() {  
        for (auto i : adjList) {  
            cout << i.first << "->";  
            for (auto j : i.second) {  
                cout << "{" << j.first << "," << j.second << "},";  
            }  
            cout << endl;  
        }  
    }  

    void topoSortDfs(int src, unordered_map<int, bool> &visited, stack<int> &ans) {  
        visited[src] = true;  
        for (auto neighbour : adjList[src]) {  
            //jo neighbour visited nhi hai uspe toposort call krdo
            if (!visited[neighbour.first]) {  
                topoSortDfs(neighbour.first, visited, ans);  
            }  
        }  
        //Pushes the current node onto the stack after all its neighbors have been processed.
        ans.push(src);  
    }  

    void shortestPathDfs(int src, int n) {  
        //Initializes a stack to store the nodes in topological order and a map to keep track of which nodes have been visited.
        stack<int> topoOrder;  
        unordered_map<int, bool> visited;  

        // Perform topological sort  
        for (int i = 0; i < n; i++) {  
            if (!visited[i]) {  
                topoSortDfs(i, visited, topoOrder);  
            }  
        }  
        //intially all distance are infinite thats why INT_MAX
        vector<int> dist(n, INT_MAX);  
        dist[src] = 0; 


        //jab tak stack empty nhi ho jata
        while (!topoOrder.empty()) {  
            int topElement = topoOrder.top();  
            topoOrder.pop();  

            // If topElement has been reached  
            if (dist[topElement] != INT_MAX) {  
                for (auto nbr : adjList[topElement]) {  
                    // Relaxation step mean agr shorter distance hai toh update krdo
                    if (dist[topElement] + nbr.second < dist[nbr.first]) {  
                        dist[nbr.first] = dist[topElement] + nbr.second;  
                    }  
                }  
            }  
        }  

        cout << "Printing Array Distances from Node " << src << ":\n";  
        for (int i = 0; i < n; i++) {  
            cout << i << "->" << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;  
        }  
    }  
};  

int main() {  
    graph g;  

    g.addEdge(0, 1, 5, 0);  
    g.addEdge(0, 2, 3, 0);  
    g.addEdge(2, 1, 2, 0);  
    g.addEdge(1, 3, 3, 0);  
    g.addEdge(2, 3, 5, 0);  
    g.addEdge(2, 4, 6, 0);  
    g.addEdge(4, 3, 1, 0);  

    g.printAdjList();  

    int n = 5; // Total number of nodes  
    g.shortestPathDfs(0, n); // Find shortest path from node 0  

    return 0;  
}