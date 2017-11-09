/*
#TEST CASE
0 1
0 2
2 0
2 3
3 2
4 2
4 3
5 5

ans : 5;

*/

#include<bits/stdc++.h>
using namespace std;


typedef pair<int,int>pi;
#define Size 200
vector< pi > bpGraph[Size];
int M,N;


bool bpm(int u, bool seen[], int matchR[])
{
	for (int v = 0; v < N; v++)
	{
	    //cout<<u<<" -----> "<<v<<" --> "<<bpGraph[u][v].second<<endl;

		if (bpGraph[u][v].second==1 && !seen[v])
		{
		   // cout<<u<<" --> "<<v<<endl;
			seen[v] = true;

			if (matchR[v] < 0 || bpm(matchR[v], seen, matchR))
			{
				matchR[v] = u;
				return true;
			}
		}
	}
	return false;
}


int maxBPM( )
{

	int matchR[N];
	memset(matchR, -1, sizeof(matchR));
	int result = 0;
	for (int u = 0; u < M; u++)
	{
		bool seen[N];
		memset(seen, 0, sizeof(seen));
		if (bpm(u, seen, matchR))
			result++;
	}
	return result;
}


int main()
{


	int u,v,t;

	cin>>t;

	for(int tt=1; tt<=t; tt++){

    cin>>M;
    vector<int>P,Q;

    for(int i=0; i<M; i++){
        cin>>u;
        P.push_back(u);
    }
    cin>>N;
     for(int i=0; i<N; i++){
        cin>>u;
        Q.push_back(u);
    }

	for(int i=0; i<=Size; i++) bpGraph[i].clear();

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){

        if( P[i]<=Q[j] and (Q[j]%P[i])==0){
            bpGraph[i].push_back(make_pair(j,1));
          //  cout<<i<<" "<<j<<endl;
        }
        else
            bpGraph[i].push_back(make_pair(j,0));
        }
    }


    printf("Case %d: ",tt);
	cout<<maxBPM( )<<endl;;
	}

	return 0;
}



