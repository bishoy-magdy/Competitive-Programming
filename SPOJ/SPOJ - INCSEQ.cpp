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
#define ll              long long
#define ld              long double
#define all(v)              ((v).begin()), ((v).end())
#define for_(vec)       for(int i=0;i<(int)vec.size();i++)
#define lp(j,n)     for(int i=j;i<(int)(n);i++)
#define rlp(j,n)        for(int i=j;i>=(int)(n);i--)
#define clr(arr,x)  memset(arr,x,sizeof(arr))
#define fillstl(arr,X)    fill(arr.begin(),arr.end(),X)
#define pb         push_back
#define mpp          make_pair
#define print_vector(X)  for(int i=0;i<X.size();i++)
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

/********************************************************/
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef pair<int,int>point;
/***********************function************************/
int dx[8]= {1,1,1,-1,-1,-1,0,0};
int dy[8]= {1,0,-1,1,0,-1,1,-1};
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

const ll  MOD=5000000;
ll Power(ll n,ll deg)
{
    if(!deg)return 1;
    else  if(deg & 1) return (Power(n,deg-1)*n)%MOD;
    else
    {
        ll half=Power(n,deg/2)%MOD;
        return ((half*half)%MOD);
    }
    return 0;
}



/***********************main_problem***************************************/
const int sz=10000;
int arr[sz],Nsub[sz];
struct BIT{
    int sz;
    vector<int>Tree;

    BIT(int sz=100000):sz(sz),Tree(sz+1){

    }

    void update(int idx,int val){

        for(;idx<=sz;idx+=idx&-idx){

            Tree[idx]+=val;
            Tree[idx]%=MOD;
        }

    }

    int get(int idx){

        int sum=0;

        for(int i=idx;i;i-=i&-i){

            sum=(sum+Tree[i])%MOD;

        }

        return sum;
    }

    ~BIT(){
        Tree.clear();
    }
};

/***********Stop When You Reach The Concept of Don't Stop******************/


int main()
{

    fast();

    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        ++arr[i];
        Nsub[i]=1;
    }

    BIT *bit;

    for(int i=1;i<=k;i++){

         free(&bit);
        bit=new BIT();
        for(int j=0;j<n;j++){

            bit->update(arr[j],Nsub[j]);
            Nsub[j]=bit->get(arr[j]-1);

            //cout<<Nsub[j]<<"<<<<\n";
        }

    }

    cout<<bit->get(100000);


    return 0;
}