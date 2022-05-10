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
map<ll,int>seq;

void prime_factorization(ll n){


    for(ll i=2;i*i<=n;i++){

        while(n%i==0){
            seq[i]++;
            n/=i;
        }

    }

    if(n>1)seq[n]++;


}


/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/

int main()
{

    fast();

    //using Legendre's formula
    // e.g (42!)=14+4+1=19
    //42!=2^39⋅3^19⋅5^9⋅7^6⋅11^3⋅13^3⋅17^2⋅19^2⋅23⋅29⋅31⋅37⋅41.
    //let p is prime the p^N N is 42/(p^1)+42/(p^2) ... to 42/(p^x)=0 <--stop
    //if prime factorization of m repeat in formula of n then can "divides"
    ll n,m;
    while(cin>>n>>m){

    seq.clear();
    prime_factorization(m);
    for(auto w:seq){

        ll now = w.first;
        int i=1;
        ll sum=0;
        while(1){

            ll now2=n/Power(now,i++);
            if(now2==0)break;
            else{
                sum+=now2;
            }


        }
        if(sum<seq[now]){
            cout<<m<<" does not divide "<<n<<"!\n";
            goto nex;
        }


    }

    cout<<m<<" divides "<<n<<"!\n";

   nex:
        continue;

    }

    return 0;

}
