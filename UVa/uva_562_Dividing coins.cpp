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
const ll OO=1e9 ;
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

/***********************main_problem****************************/

    int memo[105][50005],arr[105],n;
    int total=0;
    int pick_or_leave(int index,int diffrent){

    if(index==n){  return abs(diffrent-(total-diffrent));}

    if(memo[index][diffrent]!=-1){cout<<index<<' '<<diffrent<<'\n';return memo[index][diffrent];}

    return memo[index][diffrent]&=min(pick_or_leave(index+1,diffrent),pick_or_leave(index+1,diffrent+arr[index]));

    }


    void solve(){


        cin>>n;
        total=0;
        clr(memo,-1);
        for(int i=0;i<n;cin>>arr[i++],total+=arr[i-1]);

        cout<<pick_or_leave(0,0)<<'\n';


    }

/**************************Bisho_O*****************************************/
int main()
{

    fast();

    int t;
    cin>>t;
    while(t--){

    solve();


    }


    return 0;
}
