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
int arr[5];
int is23=0;
bool visited[5]={0};
void solve(int len,int value)
{
    if(is23){  return ;}

    if(len==5){

        is23 |=value==23;
        return ;
    }


    for(int j=0;j<5;j++){

        if(visited[j])continue;

    visited[j]=1;

    if(len!=0){
        solve(len+1,value+arr[j]);
        solve(len+1,value*arr[j]);
        solve(len+1,value-arr[j]);
    }
    else{
        //first case 

        solve(len+1,arr[j]);

    }
        visited[j]=0;

    }


}

/**************************Bisho_O*****************************************/
int main()
{

    fast();

    while(cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4] && arr[0]!=0)
    {   clr(visited,0);
        is23=0;
        solve(0,0);
        cout<<(is23?"Possible\n":"Impossible\n");

    }


    return 0;
}

