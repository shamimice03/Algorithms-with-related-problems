#include<bits/stdc++.h>
#define   inf            100000000000000000
#define   X              first
#define   Y              second
#define   B              begin()
#define   E              end()
#define   mp             make_pair
#define   pb             push_back
#define   loop1(i,n)     for(int i=1; i<=(n); i++)
#define   loop2(j,n)     for(int j=1; j<=(n); j++)
#define   loop0(i,n)     for(int i=0; i<(n); i++)
#define   valid(nx,ny)   nx>=1 && nx<=8 && ny>=1 && ny<=8
#define   pii            pair<int, int>
#define   ll             long long
#define   MOD            1000000007
#define   SIZE           10000+10
using namespace std;

int main()
{
    int test,m;
    vector<int>edges[SIZE];
    int indegree[SIZE];
    string s,p;
    cin>>test;

    for(int j=1; j<=test; j++){

       map<string,int>mm;

    memset(indegree, 0,sizeof(indegree));
       int c=1,t;

       cin>>m;
       t=m;
       while(t--){
        cin>>s>>p;

        if(mm.find(s)==mm.end()){
           mm[s]=c;
           c++;
        }
        if(mm.find(p)==mm.end()){
           mm[p]=c;
           c++;
        }

        edges[mm[s]].pb(mm[p]);
        indegree[mm[p]]++;

       }

       int k=0;

       priority_queue<int, vector<int>, greater<int> >q;

      for(int i=1; i<c; i++){
        if(indegree[i]==0) q.push(i);
       }

       while(!q.empty()){
          int u=q.top();
          q.pop();
          k++;

          for(int i=0; i<edges[u].size(); i++){
               int v=edges[u][i];
               indegree[v]--;
               if(indegree[v]==0) q.push(v);
          }
       }

       c--;
       if(k==c) printf("Case %d: Yes\n",j);
       else  printf("Case %d: No\n",j);

       for(int i=0; i<=c; i++){
        edges[i].clear();
       }

    }

    return 0;
}
