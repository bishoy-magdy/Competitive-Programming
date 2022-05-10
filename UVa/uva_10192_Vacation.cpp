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

string s1,s2;
int ans=0;
int memo[105][105];
int pick_or_leave(int index1,int index2){


    if(index1==s1.size() || index2==s2.size()){ return 0;}

    if(memo[index1][index2]!=-1){return memo[index1][index2];}

    if(s1[index1]==s2[index2]){

        return memo[index1][index2]&=1+pick_or_leave(index1+1,index2+1);

    }

    int ch1=pick_or_leave(index1+1,index2);
    int ch2=pick_or_leave(index1,index2+1);



    return memo[index1][index2]&=max(ch1,ch2);
}

void solve(int t){


    clr(memo,-1);

    s1,s2;

    getline(cin,s1);

    if(s1[0]=='#'){return ;}
    getline(cin,s2);

    cout<<"Case #"<<t<<": you can visit at most "<<pick_or_leave(0,0)<<" cities.\n";

    solve(t+1);
}



/**************************Bisho_O*****************************************/
int main()
{

    fast();


    solve(1);


    return 0;
}
