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
struct state{int l,r,k,real_idx;};

int Tree[1<<15],N=(1<<15)-1,n,ans[200005];

vector<point>arr;
vector<state>query;

struct BIT{

    void set(int pos){

        for(;pos<N;pos+=pos&-pos)
            Tree[pos]++;

    }

    int get(int pos){
        int ret=0;
        for(;pos;pos-=pos&-pos)
            ret+=Tree[pos];
        return ret;
    }

};



/***********Stop When You Reach The Concept of Don't Stop******************/

int main()
{

    fast();
    BIT bit;
    //cin>>n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){

        int x;
        //cin>>x;
        scanf("%d",&x);
        arr.push_back({x,i+1});

    }

    sort(all(arr));

    int q;
    //cin>>q;
    scanf("%d",&q);

    for(int i=0;i<q;i++){

        int l,r,k;
        //cin>>l>>r>>k;
        scanf("%d%d%d",&l,&r,&k);

        query.push_back({l,r,k,i});

    }

    sort(all(query), [&](const state &x,const state &y){
         return x.k>y.k;
         });

    for(int i=0;i<query.size();i++){

        if(arr.size()>=1)
        while(arr[arr.size()-1].first>query[i].k){
            if(arr.size()==0)
                break;
            bit.set(arr[arr.size()-1].second);
            arr.pop_back();
        }

        ans[query[i].real_idx]=bit.get(query[i].r)-bit.get(query[i].l-1);
    }
    for(int i=0;i<q;i++)
        printf("%d\n",ans[i]);//cout<<ans[i]<<'\n';

    return 0;
}