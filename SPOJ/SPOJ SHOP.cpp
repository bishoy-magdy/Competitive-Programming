#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<list>
#include <algorithm>
#include<vector>
#include<set>
#include <cctype>
#include <cstring>
#include <cstdio>
#include<queue>
#include<stack>
#include<bitset>
#include<time.h>
#include<fstream>


/******************************************************/

using namespace std;


/********************define***************************/
#define ll 				long long
#define ld				long double
#define all(v)				((v).begin()), ((v).end())
#define for_(vec) 		for(int i=0;i<(int)vec.size();i++)
#define lp(j,n)		for(int i=j;i<(int)(n);i++)
#define rlp(j,n)		for(int i=j;i>=(int)(n);i--)
#define clr(arr,x)  memset(arr,x,sizeof(arr))
#define fillstl(arr,X)    fill(arr.begin(),arr.end(),X)
#define pb         push_back
#define mp	   		make_pair
#define print_vector(X)  for(int i=0;i<X.size();i++)
#define ii pair<int,int>
/********************************************************/
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
/***********************function************************/
int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};

void fast()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
}
void online_judge()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
const int flag_max=0x3f3f3f3f;
const ll OO=2e9+10 ;
const double EPS = (1e-8);
int dcmp(double x, double y)
{
    return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;
}
ll gcd(ll a, ll b)
{
    return !b ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

const ll  MOD=1e14+7;
ll Power(ll n,ll deg)
{
    if(!deg)return 1;
    else  if(deg & 1) return (Power(n,deg-1)*n);
    else
    {
        ll half=Power(n,deg/2);
        return ((half*half));
    }
}

/***********************main_problem***************************************/
int V,m,n;

int Dijkstra(vector<vector<ii> >adj ,int s,int dis_){

    vi dis(V+1,OO);

    dis[s]=0;
    int path=s;
    priority_queue<ii,vector<ii> , greater<ii> >pq;
    pq.push({0,s});

    while(!pq.empty()){

        ii now=pq.top();
        pq.pop();
        int d=now.first,u=now.second;

        if(d>dis[u])continue;

        for(int i=0;i<adj[u].size();i++){

            ii next=adj[u][i];

            if(dis[u] + next.second < dis[next.first]){

                dis[next.first]=dis[u]+next.second;
                pq.push({dis[next.first],next.first});

            }

        }



    }


return dis[dis_];
}


bool valid(int x,int y){

return x>=0 && x<n && y>=0 && y<m;
}

/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/

int main()
{


    fast();

    while(cin>>m>>n && n && m){

    V=m*n;
    vector<vector<ii> >adj;
    adj.resize(n*m+1);
    int S,D;

    char arr[n][m];

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++)
        {

                cin>>arr[i][j];
        }

    }



      for(int i=0;i<n;i++){

        for(int j=0;j<m;j++)
        {
            if(arr[i][j]=='S')S=i*m+j+1;
            if(arr[i][j]=='D')D=i*m+j+1;
            if(arr[i][j]=='X')continue;
            int node1=i*m+j+1;
            for(int k=0;k<4;k++){

                int newX=dx[k]+i,newY=dy[k]+j;

                if(valid(newX,newY)){

                int node2=newX*m+newY+1;
                    int cost;
                    if(arr[i][j]=='S' || arr[i][j]=='D'){
                        cost=0;
                    }
                    else
                        cost=arr[i][j]-'0';

                    adj[node1].push_back({node2,cost});

                }


            }

        }

    }

    cout<<Dijkstra(adj,S,D)<<'\n';
    }
    return 0;

}
