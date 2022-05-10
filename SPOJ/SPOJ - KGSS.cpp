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


vector<int>arr;

struct node{

    vector<int>carry;

    void add(int val){

        carry.push_back(val);
        sort(carry.rbegin(),carry.rend());
        if(carry.size()>2)
        carry.pop_back();
    }
    int Max(){

        if(carry.size()==2)
        return carry[0]+carry[1];
        else if(carry.size()==1)
            return carry[0];
        else
            return 0;
    }

}Tree[4*(1<<17)];


node merge(node a,node b){

    node now;

    for(int i=0;i<a.carry.size();i++)
        now.add(a.carry[i]);

    for(int i=0;i<b.carry.size();i++)
        now.add(b.carry[i]);

    return now;
}

void bulid(int idx,int s,int e)
{

    if(s==e)
    {

    Tree[idx].add(arr[s]);
        return;
    }

    int mid=(s+e)>>1;

    bulid(2*idx+1,s,mid);
    bulid(2*idx+2,mid+1,e);

    Tree[idx]=merge(Tree[2*idx+1],Tree[2*idx+2]);

}

node query(int idx,int s,int e,int l,int r)
{

    if(l>e || s>r)
    {
        return {};
    }
    if(s>=l && e<=r)
    {

    return Tree[idx];

    }
    int mid=(s+e)>>1;


    return merge(query(2*idx+1,s,mid,l,r),query(2*idx+2,mid+1,e,l,r));

}

void update(int idx,int s,int e,int p,int val)
{

    if(p>e || s>p)
        return ;

    if(s==e && s==p)
    {
        Tree[idx].carry.clear();
        Tree[idx].add(val);

        return ;
    }

    int mid=(s+e)>>1;

    update(2*idx+1,s,mid,p,val);
    update(2*idx+2,mid+1,e,p,val);

    Tree[idx]=merge(Tree[2*idx+1],Tree[2*idx+2]);

}




/***********Stop When You Reach The Concept of Don't Stop******************/


int main()
{

    fast();

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    bulid(0,0,arr.size()-1);

    int q;
    cin>>q;
    while(q--){
        char c;
        int l,r;
        cin>>c>>l>>r;
        if(c=='Q'){
            cout<<query(0,0,arr.size()-1,l-1,r-1).Max()<<'\n';
        }
        else{

            update(0,0,arr.size()-1,l-1,r);

        }

    }



    return 0;
}