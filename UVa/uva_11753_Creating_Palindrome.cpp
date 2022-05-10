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

/***********************main_problem****************************/

vector<int>arr;
int k;

int solve(int i,int j,int Move){

    if(i>=j)return 0;
    if(Move>k)return 50;
    if(arr[i]==arr[j])return solve(i+1,j-1,Move);

    else{

        return min(solve(i,j-1,Move+1),solve(i+1,j,Move+1))+1;
    }


}


/**************************Bisho_O*****************************************/
int main()
{

    fast();
    //online_judge();
    int t;
    cin>>t;
    int case_=1;
    while(t--){
    arr.clear();

    int n;
    cin>>n>>k;
    lp(0,n){
    int a;
    cin>>a;
    arr.push_back(a);
    }
    int ans=solve(0,(int)arr.size()-1,0);

    if(ans==0){

        cout<<"Case "<<case_++<<": "<<"Too easy\n";
    }
    else if(ans>k){

    cout<<"Case "<<case_++<<": "<<"Too difficult\n";


    }
    else{

    cout<<"Case "<<case_++<<": "<<ans<<"\n";

    }

    }
    return 0;

}
