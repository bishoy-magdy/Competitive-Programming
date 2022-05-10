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


class UnsealTheSafe
{

public:

    vector<vector<int> >N;
    map<vector<int>,int >memo;
    ll dp[35][11];
    ll solve(int n,vector<int> number)
    {

        if(n==0)return 1;

        ll &ret=dp[n][memo[number]];
        ll ans=0;

        if(ret!=-1)return ret;

        for(int i=0; i<number.size(); i++)
        {

            ans+=solve(n-1,N[number[i]]);

        }


        return ret=ans;
    }


    void INIT()
    {

        N.resize(11);
        N[10]= {0,1,2,3,4,5,6,7,8,9};
        N[1]= {2,4};
        N[2]= {1,3,5};
        N[3]= {2,6};
        N[4]= {1,5,7};
        N[5]= {2,4,6,8};
        N[6]= {3,5,9};
        N[7]= {4,8,0};
        N[8]= {5,7,9};
        N[9]= {6,8};
        N[0]= {7};

        for(int i=0; i<=10; i++)
            memo[N[i]]=i;

        clr(dp,-1);

    }

    ll countPasswords(int n)
    {

        INIT();

        return solve(n,N[10]);
    }


};
