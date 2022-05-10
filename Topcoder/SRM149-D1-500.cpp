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

class MessageMess{

public:

vector<string>arr;
string s;
string ans_="";
ll memo[55][55];
ll solve(int i,int ret,string S)
{
    if(i==s.size())
    {
        if(ret==s.size()){
                ans_=S;
                return 1;}
        return 0;
    }

    ll & ret_=memo[i][ret];
    if(ret_!=-1) return ret_;

    string ans="";
    ll solv=0;
    for(int j=i; j<s.size(); j++)
    {
        ans+=s[j];
        if(binary_search(all(arr),ans))
        {
          solv+=solve(j+1,ret+ans.size(),S+ans+" ");
        }
        else
        {
            solv+=solve(j+1,ret,S);
        }
    }
  return ret_=solv;
}

string restore(vector<string>arr,string target){

    this->arr=arr;
    this->s=target;
    sort(all(this->arr));
    clr(memo,-1);
    ll ans=solve(0,0,"");
    if(ans==1){
    ans_.pop_back();
    return ans_;
    }
    else if(ans>1){
        return "AMBIGUOUS!";
    }
    else
        return "IMPOSSIBLE!";

}

};
