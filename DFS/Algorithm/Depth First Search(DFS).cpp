#include <bits/stdc++.h>
using namespace std;
bool visited[100];
vector<int>edges[100001];
int start;
int dfs(int node)
{
    if(visited[node]==1) return 1;
    else{
        visited[node]=1;
    }
    for(int i=0;i<edges[node].size();i++){
        dfs(edges[node][i]);
    }

}
int main()
{
    int n,e,u,v;
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cin>>start;
    dfs(start);
    return 0;
}
