// You are using GCC
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void dfs_Stack(int start, vector<vector<int>>&graph, int v){
    
    vector<int>visited(v,0);
    stack<int>st;
    st.push(start);
    visited[start] = 1;
    
    while(!st.empty()){
        int node = st.top();
        st.pop();
        
        cout<<node<<" ";
        for(int neighbour : graph[node]){
            if(!visited[neighbour]){
                visited[node] = 1;
                st.push(neighbour);
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
    
    dfs_Stack(0, graph, v);
}

// for(int i = graph[node].size() - 1; i >= 0; i--) {

//     int neighbour = graph[node][i];

//     if(!visited[neighbour]) {
//         visited[neighbour] = 1;
//         st.push(neighbour);
//     }
// }

// Use this if we want the order like DFS_1

// INPUT :

// 5 4
// 0 1
// 0 2
// 1 3
// 1 4

// OUTPUT :

// 0 2 1 4 3 