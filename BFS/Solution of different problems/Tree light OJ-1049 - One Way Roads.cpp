#include<bits/stdc++.h>
#define inf 100000000000000000
#define X first
#define Y second
#define B begin()
#define E end()
#define mp make_pair
#define pb push_back
#define loop1(i,n) for(int i=1; i<=(n); i++)
#define loop2(j,n) for(int j=1; j<=(n); j++)
#define loop0(i,n) for(int i=0; i<(n); i++)
#define valid(nx,ny) nx>=1 && nx<=8 && ny>=1 && ny<=8
#define pii pair<int, int>
#define ll long long
#define SIZE 105
using namespace std;

bool Right[SIZE];
bool Left[SIZE];

int cost1,cost2;

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++){


        memset(Right, 0, sizeof Right);
        memset(Left, 0, sizeof Left);

        cost1=cost2=0;

        int n;
        scanf("%d",&n);
        int a,b,c;
        for(int j=0; j<n; j++){

            scanf("%d %d %d",&a,&b,&c);

            if(!Left[a] && !Right[b]){
                Left[a]=Right[b]=true;
                cost1+=c;
            }
            else{
                Left[b]=Right[a]=true;
                cost2+=c;
            }
        }

         printf("Case %d: %d\n",i,min(cost1,cost2));

    }

    return 0;
}


