#include<bits/stdc++.h>
using namespace std;
bool visited[50005];
int edges[50002];
int save[60000];


int DFS(int s){

   int x=0;
   if(visited[s]==1) return 0;
   visited[s]=1;

   x=1+DFS(edges[s]);
   visited[s]=0;

   return save[s]=x;
}


int main()
{

    int n,e,v,u,start,t;


    cin>>t;
    for(int p=1; p<=t; p++){
    cin>>e;
   int ans=0;

   for(int q=0; q<=e; q++) {visited[q]=0; save[q]=-1; }

    for(int i=1; i<=e; i++)
    {
        cin>>u>>v;
        edges[u]=v;
    }
    int node;
    for(int j=1; j<=e; j++){
     if(save[j]==-1){
        DFS(j);
        visited[j]=0;
        if(save[j]>ans){
        ans=save[j];
        node=j;
       }
    }
    }
    printf("Case %d: ",p);
    cout<<node<<endl;

    }
}
