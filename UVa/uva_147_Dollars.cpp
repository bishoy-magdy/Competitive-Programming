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
const ll OO=1e9+9 ;
const double EPS = (1e-9);
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
const int Ncoins=11;
int coins[Ncoins]={5,10,20,50,100,200,500,1000,2000,5000,10000};

ll dp[2][30005];


/**************************Bisho_O*****************************************/
int main()
{


    fast();

dp[0][0]=dp[1][0]=1;
int star=1;

for(int i=0;i<11;i++){

    star^=1;
    for(int rem=coins[0];rem<=30000;rem+=5){

        dp[star][rem]=0;
        if(i) dp[star][rem]=dp[1^star][rem];

        if(rem-coins[i]>=0) dp[star][rem]+=dp[star][rem-coins[i]];

    }


}



    //cout<<dp[1][200];


    double n;
    while(cin>>n && n>EPS){
    int print_=n;
      string s=to_string(n);
        int i;
        for(i=0;i<s.size();i++)
            if(s[i]=='.')
                break;

      double N=stod(s.substr(0,i));
     N*=100;
     int Y=0;

     if(s[i+1]-'0' >0){
        Y+=s[i+1]-'0';
     }
     if(s[i+2]-'0'>=0)
        {Y*=10; Y+=s[i+2]-'0'; }
    N+=Y;
    string print=to_string(print_);
    print+='.';
    print+=s[i+1];
    print+=s[i+2];
      cout<<setw(6)<<print<<setw(17)<<dp[0][(int)N]<<'\n';


    }


    return 0;

}

