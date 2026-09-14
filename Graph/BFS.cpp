// You are using GCC
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void BFS_Queue(int start, vector<vector<int>>&graph, int v){
    
    vector<int>visited(v);
    queue<int>q;
    q.push(start);
    visited[start] = 1;
    
    while(!q.empty()){
        int  node = q.front();
        q.pop();
        
        cout<<node<<" ";
        
        for(int neighbour : graph[node]){
            if(!visited[neighbour]){
                visited[neighbour] = 1;
                q.push(neighbour);
            }
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    
    vector<vector<int>>graph(v);
    
    for(int i = 0; i < e; i ++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    BFS_Queue(0, graph, v);
}

// INPUT :

// 5 4
// 0 1
// 0 2
// 1 3
// 1 4

// OUTPUT :

// 0 1 2 3 4