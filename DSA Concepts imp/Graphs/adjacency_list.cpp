//adjacency list meaning print neighbour of a node in same  graph 
//bfs is queue based dfs is recursion based

#include<iostream>  
#include<unordered_map>  
#include<list>  
#include<queue>
using namespace std;  

class graph {  
public:  
    unordered_map<int, list<int>> adj; 

    void addEdge(int u, int v, bool direction) {  
        // direction = 0 -> undirected  
        // direction = 1 -> directed graph  

        // create an edge from u to v  
        adj[u].push_back(v);  
        if (direction == 0) {  
            // undirected graph, so add edge from v to u as well  
            adj[v].push_back(u);  
        }  
    }  

    void printAdjList() {  
        for (auto i : adj) {  
            cout << i.first << " -> ";  
            for (auto j : i.second) {  
                cout << j << ", ";  
            }  
            cout << endl;  
        }  
    }  

        //BFS krna hai 
        ////har node ka neighbour add kran hai queue mein
        //ek data structre maintain krna hai taaki repeate na ho elements
    void bfs(int src, unordered_map<int,bool>& visited){
        queue<int> q;
        
        //src yaani pehla node its visited so mark true
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            //front node ko daalke pop krke print krdo
            int frontNode = q.front();
            q.pop();
            cout<<frontNode<<" , ";

            //insert neighbour
            //neighbour insert krna se pehle check krlo
            //ki vo visited na ho
            for(auto neighbour: adj[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]= true;
                }
            }
        }

    }

    void dfs(int src, unordered_map<int ,bool>& visited){
        cout<<src<<", ";
        visited[src] = true;
        //jo bhi adjcancy list ke neighbour hai 
        for(auto neighbour: adj[src]){
                if(!visited[neighbour]){
                    dfs(neighbour, visited);
                }
            }
    }
};  

int main() {  
    graph g;  
    //n-> number of nodes
    int n = 5;
    //last 0 is representing undirectional graph
    g.addEdge(0,1,0);
    g.addEdge(1,3,0);
    g.addEdge(0,2,0);
    g.addEdge(2,4,0);

    g.printAdjList();  

    cout<<endl;

    //for a disconected graph
    //it is graph in which two different graphs are one but they are no conneceted
    //har node ko source maanke call maro taki disconnecte graph pe bhi call mar ske
    unordered_map<int,bool> visited;

    //run a loop for all nodes
    cout<<"Printing BFS Traversal: "<<endl;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.bfs(i, visited);
        }
    }



    cout<<endl<<"Printing DFS Traversal: "<<endl;
    unordered_map<int,bool> visited2;
    for(int i=0;i<n;i++){
        if(!visited2[i]){
            g.dfs(i, visited2);
        }
    } 
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