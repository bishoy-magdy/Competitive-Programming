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

const ll  MOD=1e9+7;
ll Power(ll n,ll deg)
{
    if(!deg)return 1;
    else  if(deg & 1) return (Power(n,deg-1)*n);
    else
    {
        ll half=Power(n,deg/2);
        return (half*half);
    }
}

/***********************main_problem***************************************/
map<string,vector<string> >Relation;
map<string,bool>visited;

int dfs(string s){


    int ans=0;
    if(!visited[s])ans=1;
    visited[s]=1;
    for(int i=0;i<Relation[s].size();i++){

        string now=Relation[s][i];
        if(!visited[now] ){

            visited[now]=1;

            ans+=1+dfs(now);

        }


    }

return ans;
}

/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/

int main()
{

    fast();

    int n,m;
    while(cin>>n>>m ){

    if(n==0 && m==0)break;

    visited.clear();
    Relation.clear();
    vector<string>sta;

    while(n--){

        string s;
        cin>>s;
        sta.push_back(s);

    }

    while(m--){

        string a,b;
        cin>>a>>b;

        Relation[a].push_back(b);
        Relation[b].push_back(a);
    }
    int ans=0;

    for(auto f:sta){

        if(!visited[f]){

            ans=max(dfs(f),ans);

        }


    }

    cout<<ans<<'\n';
    }





    return 0;

}
