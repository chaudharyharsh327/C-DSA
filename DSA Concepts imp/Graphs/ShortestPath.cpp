#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;

class graph{
    public:
    //list is adjacancy list where each key represend node pair
    unordered_map<int, list<pair<int,int> > >adjList;

    void addEdge(int u, int v,int wt, bool direction){
        //direction = 1 ->undirected graph
        //direction = 0 ->directed graph

        adjList[u].push_back({v,wt});
        if(direction == 0){
            adjList[v].push_back({u,wt});
        }
    }

    void printAdjList(){
        //i.first is intiial node node like 0 se 1 jaa skte ho 2 jaa skte ho
        //j. first is kaha jaa skte hi jaise 1 se 1 mein j.first = 1 and j.second is constant
        for(auto i: adjList){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<"{" <<j.first<<","<<j.second<<"},";
            }
            cout<<endl;
        }
    }

    void shortestPathBfs(int src, int dest){
        queue<int> q;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;

        //intial steps for src
        q.push(src);
        visited[src] = 1;
        parent[src]=-1;

        while(!q.empty()){
            int fNode = q.front();
            q.pop();

            for(auto nbr: adjList[fNode]){
                if(!visited[nbr.first]){
                    q.push(nbr.first);
                    visited[nbr.first] = 1;
                    parent[nbr.first] = fNode;
                }
            }
        }

        //store path in ans, after traversing in parent array
        vector<int> ans;
        int node = dest;
        while(node != -1){
            ans.push_back(node);
            node = parent[node];
        }
        //to use reverse you have to #include<algorithm>
        reverse(ans.begin(),ans.end());
        cout<<"Printing Ans: "<<endl;
        for(auto i: ans){
            cout<< i <<", ";
        }
        cout<<endl;
    }
};

int main(){
    graph g;

    g.addEdge(0,1,1,1);  
    g.addEdge(1,2,1,1);  
    g.addEdge(2,3,1,1);  

    
    g.addEdge(3,4,1,1);  
    g.addEdge(0,5,1,1);  
    g.addEdge(5,4,1,1); 

    
    g.addEdge(0,6,1,1);  
    g.addEdge(6,7,1,1);  
    g.addEdge(7,8,1,1); 
    g.addEdge(8,4,1,1); 

    g.printAdjList();

    //by above example
    int src = 0;
    int dest = 4;

    g.shortestPathBfs(src,dest);
}