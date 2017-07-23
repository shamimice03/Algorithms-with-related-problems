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
#define   SIZE           200
using namespace std;

int n,m;
string s,p;

int main()
{

    int cas=1;
    while(scanf("%d",&n)){


    map<string,int>mm;
    map<int,string>mm2;
    vector<int>result;
    vector<int>edges[SIZE];
    int indegree[SIZE];


    int c=1,t;

    t=n;
    while(t--){
        cin>>s;
        if(mm.find(s)==mm.end()) {
            mm[s]=c;
            mm2[c]=s;
            c++;
        }
    }


    for(int i=0; i<=n; i++){

       indegree[i]=0;

   }

    scanf("%d",&m);
    while(m--){
     cin>>s;
     cin>>p;

     edges[mm[s]].pb(mm[p]);
     indegree[mm[p]]++;

    }

   /////////////////////////////////////////
     priority_queue<int, vector<int>,greater<int> >q;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0) {
                q.push(i);
        }
    }

    while(!q.empty()){

        int u= q.top();
        q.pop();
        result.pb(u);
        for(int i=0; i<edges[u].size(); i++){

            int v=edges[u][i];
            indegree[v]--;
            if(indegree[v]==0) q.push(v);

        }
    }
    //////////////

    printf("Case #%d: Dilbert should drink beverages in this order:",cas++);
    for(int i=0; i<result.size(); i++){
        if(i!=result.size()) printf(" ");
        cout<<mm2[result[i]];
    }
    printf(".\n\n");

   c=0;

}
    return 0;
}
