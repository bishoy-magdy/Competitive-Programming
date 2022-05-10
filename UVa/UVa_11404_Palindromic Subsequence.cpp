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
#define ii pair<int,int>
/********************************************************/
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
/***********************function************************/
int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};

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

const ll  MOD=1e14+7;
ll Power(ll n,ll deg)
{
    if(!deg)return 1;
    else  if(deg & 1) return (Power(n,deg-1)*n);
    else
    {
        ll half=Power(n,deg/2);
        return ((half*half));
    }
}





/***********************main_problem***************************************/
string s;
string dp[1000][1000];
string compare(string s1, string s2){


    if(s1.size()>s2.size())return s1;

    else if(s2.size()>s1.size())return s2;

    else
    {
        if(s1<=s2)return s1;
        else
            return s2;
    }


}

string Pick_Leave(int i, int j){

    if(i==j)
    {
        string flag="";
        flag+=s[i];
         return flag;
    }
    if(s[i]==s[j] && (i+1)==j){
        string flag="";
        flag+=s[i];
        flag=s[j]+flag;
        return flag;
    }

    if(dp[i][j].size()!=0)return dp[i][j];
    if(s[i]==s[j])
        return s[i]+Pick_Leave(i+1,j-1)+s[j];

   string s1= Pick_Leave(i+1,j);
   string s2= Pick_Leave(i,j-1);

return dp[i][j]=compare(s1,s2);
}



/*--------------------------- OR-------------------


string compare(string s1, string s2)
{


    if(s1.size()>s2.size())return s1;

    else if(s2.size()>s1.size())return s2;

    else
    {
        if(s1<=s2)return s1;
        else
            return s2;
    }


}
string s;
int dp[1000][1000];
string dp2[1000][1000];
//avoid initialization string array
bool flag[1000][1000];
int solve(int i, int j)
{


    if(i==j)
        return 1;

    if(s[i]==s[j] && (i+1)==j)
        return 2;

    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==s[j])
        return dp[i][j]=2+solve(i+1,j-1);

    int ch1=solve(i+1,j);
    int ch2=solve(i,j-1);

    return dp[i][j]=max(ch1,ch2);
}

string trace(int i,int j)
{


    if(i==j)
    {
        string flag="";
        flag+=s[i];
        return flag;
    }

    if(s[i]==s[j] && (i+1)==j)
    {
        string flag="";
        flag+=s[i];
        flag+=s[i];
        return flag;
    }

    if(s[i]==s[j])
    {
        return s[i]+trace(i+1,j-1)+s[j];

    }
    int ch1=solve(i+1,j);
    int ch2=solve(i,j-1);

    int opt = solve(i,j);
    if(flag[i][j])return dp2[i][j];
    if(ch1==opt && ch2==opt)
    {

        string ch1x= trace(i,j-1);
        string ch2x=trace(i+1,j);
        flag[i][j]=1;
        return dp2[i][j]=compare(ch1x,ch2x);

    }

    if(opt==ch1)
    {
        flag[i][j]=1;
        return dp2[i][j]=trace(i+1,j);

    }
    if(opt==ch2)
    {
        flag[i][j]=1;
        return  dp2[i][j]=trace(i,j-1);
    }

}






*/

/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/

int main()
{

    fast();

    while(cin>>s){


    for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++)
        dp[i][j]="";


    cout<<Pick_Leave(0,s.size()-1)<<'\n';
    }



    return 0;

}
