#include<bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define inf 10000000
#define mp make_pair
#define pb push_back
#define loop1(i,n) for(int i=1; i<=(n); i++)
#define loop2(j,n) for(int j=1; j<=(n); j++)
#define loop0(i,n) for(int i=0; i<(n); i++)
#define valid(nx,ny) nx>=1 && nx<=8 && ny>=1 && ny<=8
using namespace std;
map<pii, pii>parent;
map<pii,string>Move;
vector<string> ans;
int dis[50][50];
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};

int BFS(int sx, int sy, int dx, int dy){

    loop1(i,8) loop2(j,8){dis[i][j]=inf;}

    dis[sx][sy]=0;

    queue<pii>q;
    q.push(mp(sx,sy));

    while(!q.empty()){

        pii top=q.front();
        q.pop();

        pii v=mp(top.X,top.Y);

        loop0(i,8){
          int nx=fx[i]+top.X;
          int ny=fy[i]+top.Y;

         pii z=mp(nx,ny);

          if(valid(nx,ny) && dis[nx][ny]==inf){
            dis[nx][ny]=dis[top.X][top.Y]+1;
            parent[z]=v;
            q.push(mp(nx,ny));

 if(fx[i]==0 && fy[i]==-1) Move[z]="D";
 if(fx[i]==0 && fy[i]==1) Move[z]="U";
 if(fx[i]==1 && fy[i]==0) Move[z]="R";
 if(fx[i]==-1 && fy[i]==0) Move[z]="L";
 if(fx[i]==1 && fy[i]==-1) Move[z]="RD";
 if(fx[i]==1 && fy[i]==1 ) Move[z]="RU";
 if(fx[i]==-1 && fy[i]==1 )Move[z]="LU";
 if(fx[i]==-1 && fy[i]==-1) Move[z]="LD";

        }
    }
    }

    pii k=mp(dx,dy);
    pii s=mp(sx,sy);

    ans.pb(Move[k]);

    while(s!=k){
        k=parent[k];
        ans.pb(Move[k]);
    }

    reverse(ans.begin(),ans.end());
      cout<<ans.size()-1<<endl;
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<endl;

}


int main()
{
    string ss,dd;

    while(cin>>ss>>dd){

     int sx=ss[0]-96;
     int sy=ss[1]-48;

     int dx=dd[0]-96;
     int dy=dd[1]-48;

    BFS(sx,sy,dx,dy);

}

}


