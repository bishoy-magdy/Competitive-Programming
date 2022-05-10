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
/// if X=2^x*3^y*5^z .... Nfactor (x+1)*(y+1)*(z+1)
/*

map<ll,int>freq;

void Divisors(ll n){
    freq.clear();

    for (ll i = 2;i*i <= (n); i++)
    {
        while (n % i == 0)
        {
            freq[i]++;
            n = n/i;
        }
    }
    if(n>1)
        freq[n]++;



}
 //for map ans*=(x+1);

*/

vector<ll>A;
set<ll>X;
map<pair<ll,ll>,ll>wh;

void Divisors(ll n){
    //freq.clear();
      A.clear();
      X.clear();
      wh.clear();
    for (ll i = 2;i*i <= (n); i++)
    {
        while (n % i == 0)
        {
            A.push_back(i);
            n = n/i;
        }
    }
    if(n)
        A.push_back(n);



}
/// or pick_or_leave

void solve(ll i,ll a){

    if(i==A.size())
        return  ;

    if(wh[{i,a}])
        return ;
    wh[{i,a}]=1;
    X.insert(a);
    solve(i+1,a);
    X.insert(a*A[i]);
    solve(i+1,a*A[i]);


}


/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/

int main()
{

    fast();
    int t;
    cin>>t;
    while(t--){

    ll star,end_;
    cin>>star>>end_;

    ll ans1,ans2=-1;
    for(ll i=star;i<=end_;i++){

        Divisors(i);
        solve(0,1);
    if(ans2<(int)X.size()){
        ans1=i;
        ans2=X.size();
    }

    }

    cout<<"Between "<<star<<" and "<<end_<<", "<<ans1<<" has a maximum of "<<ans2<<" divisors.\n";
}


    return 0;

}
