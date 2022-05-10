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

/********************************************************/
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
/***********************function************************/
int dx[8]= {-1,-1,0,1,1,1,0,-1};
int dy[8]= {0,1,1,1,0,-1,-1,-1};

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
const ll OO=1e15+9 ;
const double EPS = (1e-7);
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

ll Power(ll n,ll deg)
{
    if(!deg)return 1;
    else  if(deg & 1) return Power(n,deg-1)*n;
    else
    {
        ll half=Power(n,deg/2);
        return half*half;
    }
}

/***********************main_problem***************************************/

char arr[1001][1001];
bool vis[1001][1001];
int cost[1001][1001];

int n,m;

bool valid(int x,int y)
{
    return x>=0 && x<n && y>=0 && y<m;
}

void memsetX(){

for(int i=0;i<=1000;i++){

    for(int j=0;j<=1000;j++){

        cost[i][j]=1e9;
    }

}

}

int zero_one_BFS(int x1,int y1,int x2,int y2)
{

    memsetX();
    clr(vis,0);

    deque<pair<int,int> >q;

    q.push_front({x1,y1});

    cost[x1][y1]=0;

    while(!q.empty())
    {

        pair<int,int>current=q.front();
        q.pop_front();
        vis[current.first][current.second]=1;

        if(current.first==x2 && current.second==y2) return cost[current.first][current.second];

        for(int k=0; k<8; k++)
        {

            int new_x=current.first+dx[k],new_y=current.second+dy[k];

            if(valid(new_x,new_y) && !vis[new_x][new_y])
            {
                int current_value=cost[current.first][current.second];

                bool flag=false;
                if(k!=(arr[current.first][current.second]-'0'))current_value++,flag=true;

                if(current_value<cost[new_x][new_y]){

                    cost[new_x][new_y]=current_value;

                    if(flag)
                    q.push_back({new_x,new_y});
                    else
                    q.push_front({new_x,new_y});


                }


            }
        }

    }



}


/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/

int main()
{

    fast();



    cin>>n>>m;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    int t;
    cin>>t;
    while(t--)
    {


        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--,y1--,x2--,y2--;
        cout<<zero_one_BFS(x1,y1,x2,y2)<<'\n';



    }


    return 0;

}
