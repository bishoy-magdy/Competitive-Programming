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

string s;
int dp[1000][1000];
int solve(int i, int j)
{

    if(i==j)
        return 0;

    if((i+1)==j)

    {
        if(s[i]!=s[j])
            return 1;
        else
            return 0;

    }
    if(dp[i][j]!=-1)
        return dp[i][j];

    if(s[i]==s[j])
        return dp[i][j]=solve(i+1,j-1);

    int ch1=1+solve(i+1,j);
    int ch2=1+solve(i,j-1);
    return dp[i][j]=min(ch1,ch2);

}

void trace(int i,int j)
{


    if(i==j)
    {
        cout<<s[i];
        return ;
    }
    if((i+1)==j)

    {
        string flag="";
        if(s[i]!=s[j])
        {
            flag+=s[j];
            flag+=s[i];
            flag+=s[j];
            cout<<flag;
        }
        else
        {

            flag+=s[j];
            flag+=s[i];

            cout<<flag;
        }
        return;
    }

    if(s[i]==s[j])
    {

        cout<<s[i];
        trace(i+1,j-1);
        cout<<s[j];

        return ;
    }

    int ch1=1+solve(i+1,j);
    int ch2=1+solve(i,j-1);
    int opt=solve(i,j);

    if(opt==ch1)
    {

        cout<<s[i];
        trace(i+1,j);
        cout<<s[i];

    }
    else
    {
        cout<<s[j];
        trace(i,j-1);
        cout<<s[j];

    }


}


/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/

int main()
{

    fast();
    while(cin>>s)
    {

        clr(dp,-1);


        int ans= solve(0,s.size()-1);
        cout<<ans<<' ';
        trace(0,s.size()-1);
        cout<<'\n';

    }


}
