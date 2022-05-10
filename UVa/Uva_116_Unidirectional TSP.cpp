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

int n,m;
int arr[100][100];
int dp[100][100];
string ans;
bool valid(int i,int j)
{

    return i>=0 && i<n && j>=0 && j<m;
}

int solve(int i,int j){

    if(j==(m-1))
        return dp[i][j]=arr[i][j];

    int &ret=dp[i][j];

    if(ret!=-1)
        return ret;

    int ch1,ch2,ch3,ch4;
    ch4=ch1=ch2=ch3=1e9;


    if(j==0 && (i+1)<n)
    ch1=solve(i+1,j);


     ch2=arr[i][j]+solve(i,(j+1)%m);

     ch3=arr[i][j]+solve((i+1)%n,(j+1)%m);

     ch4=arr[i][j]+solve((i-1+n)%n,(j+1)%m);


    return ret=min(min(ch1,ch4),min(ch2,ch3));

}

void print_path(string now,int i, int j){

        if(j==(m-1)){

            if(ans.size()>=1){

                if(ans>now)
                    ans=now;

            }
            else
                ans=now;

            return ;
        }

    int ch1=1e9;

    if(j==0 && (i+1)<n)
    ch1=solve(i+1,j);

    int ch2=arr[i][j]+solve(i,(j+1)%m);

    int ch3=arr[i][j]+solve((i+1)%n,(j+1)%m);

    int ch4=arr[i][j]+solve((i-1+n)%n,(j+1)%m);
    vector<pair<int,pair<int,int> > >so;
    //sort with priority to avoid equal weight
    //worth case
    so.push_back({ch1,{i+2,5}});
    so.push_back({ch2,{i+1,2}});
    so.push_back({ch3,{(i+1)%n+1,3}});
    so.push_back({ch4,{(i-1+n)%n+1,4}});

    sort(all(so));


    int go=so[0].second.second;

    if(go==5){

        print_path("",i+1,j);

    }

   else  if(go==2){

        string next=" ";

        if(j==0)
            next=to_string(i+1),next+=' ';

        next+=to_string(i+1);
        print_path(now+next,i,(j+1)%m);


    }


     else if(go==3){
        string next=" ";

        if(j==0)
            next=to_string(i+1),next+=' ';

        next+=to_string(((i+1)%n+1));

        print_path(now+next,(i+1)%n,(j+1)%m);


    }


     else if(go==4){

         string next=" ";

        if(j==0)
            next=to_string(i+1),next+=' ';

        next+=to_string((i-1+n)%n+1);

        print_path(now+next,(i-1+n)%n,(j+1)%m);


    }

}


/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/

int main()
{

    fast();

    while(cin>>n>>m && n && m){
    clr(dp,-1);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];

    int ret=solve(0,0);
    print_path("",0,0);
    cout<<(ans.size()==0?"1":ans)<<'\n';
    cout<<ret<<'\n';
    ans="";

    }
    return 0;

}

