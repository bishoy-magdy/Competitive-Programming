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

/*
    another solution using merge sort (count swap 1..N)

ll mergeX(int l,int r){

    if(l>=r)
        return 0;

    int mid=(l+r)/2;


    ll from_left=mergeX(l,mid);
    ll from_right=mergeX(mid+1,r);

    ll rem=0,star1=0,star2=0,idx=l;

    vector<int>L,R;

    for(int i=l;i<=mid;i++)
        L.push_back(arr[i]);

    for(int j=mid+1;j<=r;j++)
        R.push_back(arr[j]);

    while(star1<L.size() && star2<R.size()){

        if(L[star1]>R[star2]){

            rem+=(mid-l+1)-star1;

            arr[idx++]=R[star2++];
        }
        else{

            arr[idx++]=L[star1++];

        }

    }



    while(star1<L.size())
        arr[idx++]=L[star1++];



    while(star2<R.size())
        arr[idx++]=R[star2++];


    return from_left+from_right+rem;
}



*/
const int N=30005;

struct BIT{
    int Tree[N];

    void init(){

        clr(Tree,0);
    }

    void set(int idx){

        for(;idx<N;idx+=idx&-idx)
            Tree[idx]+=1;
    }
    int get(int idx){

        int ret=0;

        for(;idx;idx-=idx&-idx)
            ret+=Tree[idx];

        return ret;
    }


};




/***********Stop When You Reach The Concept of Don't Stop******************/


int main()
{

    fast();
    int t;
    cin>>t;
    BIT bit;
    while(t--){
    int n;
    cin>>n;

    bit.init();

    unordered_map<string,int>idx;

    for(int i=1;i<=n;i++){

        string s;
        cin>>s;
        idx[s]=i;
    }

    int ans=0;

    for(int i=0;i<n;i++){

        string s;
        cin>>s;

        ans+=i-bit.get(idx[s]-1);
        bit.set(idx[s]);

    }

    cout<<ans<<'\n';
    }
    return 0;
}