// You are using GCC
#include<iostream>
#include<vector>
using namespace std;

void dfs_Recursion(int start, vector<vector<int>>&graph, vector<int>& visited){
    
    visited[start] = 1;
    
    cout<<start<<" ";
    for(int neighbour : graph[start]){
        if(!visited[neighbour]){
            dfs_Recursion(neighbour, graph, visited);
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    
    vector<vector<int>>graph(v);
    vector<int>visited(v,0);
    
    for(int i = 0; i < e; i ++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs_Recursion(0, graph, visited);
}

// INPUT :

// 5 4
// 0 1
// 0 2
// 1 3
// 1 4

// OUTPUT :

// 0 1 3 4 2 