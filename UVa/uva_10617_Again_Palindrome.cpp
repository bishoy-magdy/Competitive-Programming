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
ll solve(){


 string s;
    cin>>s;

    ll dp[61][61];
    clr(dp,0);

    for(int i=0;i<s.size();i++){

        for(int j=0;(i+j)<s.size();j++){

            if(!i)dp[j][j]=1;
            //(Note---->Repeat exist)It is the sum of the probabilities before adding the two new letters and the second iteration when adding them
            else if(s[j]==s[i+j]) dp[j][i+j]= dp[j][i+j-1]+dp[j+1][i+j]+1;

            else
                dp[j][i+j]=dp[j][i+j-1]+dp[j+1][i+j]-dp[j+1][i+j-1];

        }


    }


    return dp[0][s.size()-1];


}



/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/


int main()
{

    fast();
    int t;
    cin>>t;
    while(t--){

        cout<<solve()<<'\n';

    }

    return 0;

}
