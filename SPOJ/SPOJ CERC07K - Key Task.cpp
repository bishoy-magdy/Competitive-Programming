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

/***********************main_problem****************************/
int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,-1,1};

char arr[100][100];
int visited[100][100][17];
int dis[100][100][17];
int n,m;
bool valid(int x,int  y)
{
    return x>=0 && x<n && y>=0 && y<m;
}

bool can(int x,int y,int mask)
{
    // "&" compair bits 01
    return ( (arr[x][y]=='R' && mask & 1) || (arr[x][y]=='G' && mask & 2 ) || (arr[x][y]=='B' &&  mask & 4)
             || (arr[x][y]=='Y' && mask & 8) || arr[x][y]=='*' || arr[x][y]=='X' || arr[x][y]=='.' || arr[x][y]=='r'
             || arr[x][y]=='g' || arr[x][y]=='y' || arr[x][y]=='b'

             );
}

string BFS(int i,int j)
{

    queue<pair<pair<int,int>,int> >q;
    int mask=0,ans=-1;

    q.push({{i,j},mask});
    visited[i][j][mask]=1;
    while(!q.empty())
    {

        pair<pair<int,int>,int> now=q.front();
        q.pop();
        mask=now.second;
        int x=now.first.first,y=now.first.second;

        if(arr[x][y]=='X')
        {
            ans=dis[x][y][mask];
            break;
        }
        else if(arr[x][y]=='r')
            mask|=1;
        else if ( arr[x][y] == 'g')
            mask|=2;
        else if (arr[x][y]=='b')
            mask|=4;
        else if (arr[x][y]=='y')
            mask|=8;

           for(int k=0; k<4; k++)
        {
            int new_x=x+dx[k],new_y=y+dy[k];
            if(!visited[new_x][new_y][mask] && valid(new_x,new_y) && can(new_x,new_y,mask) )
            {
                //"now.second" old mask mark it
                visited[new_x][new_y][now.second]=1;
                dis[new_x][new_y][mask]=dis[x][y][now.second]+1;
                q.push({{new_x,new_y},mask});

            }

        }




    }

    return ans==-1 ?"The poor student is trapped!":"Escape possible in "+to_string(ans)+" steps.";

}




/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/


int main()
{

    fast();

   while( cin>>n>>m  && n && m)
  {

    int x_star,y_star;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='*')x_star=i,y_star=j;
        }

    }

    clr(visited,0);
    clr(dis,0);
    cout<<BFS(x_star,y_star)<<'\n';

  }
    return 0;

}
