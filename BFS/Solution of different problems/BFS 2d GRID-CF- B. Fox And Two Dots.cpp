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
#define   si             set<int>
#define   ll             long long
#define   sf(a)          scanf("%d",&a)
#define   sff(a,b)       scanf("%d %d",&a,&b)
#define   MOD            1000000007
#define   SIZE           10000+10
using namespace std;

vector<int>edges[SIZE];

int main()
{

  int n,m;

  sff(n,m);

  if(n>=m) cout<<n-m<<endl;
  else{
     queue<int>q;

     while(1){
        int a=q.front();
        q.pop();
        int x=a*2;
        int y=a-1;

        edges[a].pb(x);
        edges[a].pb(y);
        edges[x].pb(a);
        edges[y].pb(a);

       if(x==m or y==m) break;
       q.push(x);
       q.push(y);

       cout<<a<<" "<<x<<endl;
       cout<<a<<" "<<y<<endl;
     }
  }

}
