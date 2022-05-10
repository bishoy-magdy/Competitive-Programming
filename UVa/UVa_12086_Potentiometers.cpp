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

const ll  MOD=1e9+7;
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
int n;
struct BIT
{

    int arr[200005];
    void init(){

        clr(arr,0);
    }
    void set(int pos,int val)
    {
        for(pos;pos<=n;pos+=(pos&-pos))
            arr[pos-1]+=val;


    }

    int get(int pos){
        int ret=0;

        for(pos;pos;pos-=(pos & -pos) )
            ret+=arr[pos-1];

        return ret;

    }



} bit;


/***********Stop When You Reach The Concept of Don`t Stop******************/

int main()
{


    fast();
    int tc=0;
    string nx="";
    while(cin>>n && n){

        bit.init();
        int arr[n];


        for(int i=0;i<n;i++){

            cin>>arr[i];
            bit.set(i+1,arr[i]);

        }
        string state;
        cout<<nx;
        cout<<"Case "<<++tc<<":\n";
        nx='\n';

        while(cin>>state && state[0]!='E'){

        if(state[0]=='S'){

            int a,b;
            cin>>a>>b;
            bit.set(a,b-arr[a-1]);
            arr[a-1]=b;
        }
        else if(state[0]=='M'){

            int a,b;
            cin>>a>>b;
            cout<<bit.get(b)-bit.get(a-1)<<'\n';

        }
        }

    }


    return 0;
}
