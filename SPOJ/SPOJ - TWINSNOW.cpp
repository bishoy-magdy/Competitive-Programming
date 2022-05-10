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
const ll  MOD=1e6+3;

ll Power(ll n,ll deg)
{
    if(!deg)return 1;
    else  if(deg & 1) return (Power(n,deg-1)*n)%MOD;
    else
    {
        ll half=Power(n,deg/2)%MOD;
        return ((half*half)%MOD);
    }
}

/***********************main_problem***************************************/
int snows[100007][6],Start[1000007],Next[1000007];
bool isEqual(int a[],int b[]){

    vector<string>circles;
    string target="";
 for(int i=0;i<6;i++){

            target+=to_string(b[i]);
           string now="",rnow="";

           int c=0;
            int j=i,jj=j;
           while(c<6){

            int idx=(j+6)%6;
            int idx2=(jj+6)%6;

            now+=to_string(a[idx]);
            rnow+=to_string(a[idx2]);
            j++,c++,jj--;

           }
           circles.push_back(now);
           circles.push_back(rnow);

        }

    for(int i=0;i<circles.size();i++){
        if(circles[i]==target)
            return true;

    }

    return false;
}


int unique_Array(int a[]){


    ll sum=0,mul=1;

    for(int i=0;i<6;i++){

        sum=(sum+(ll)a[i])%MOD;
        mul=(mul*(ll)a[i])%MOD;

    }
    return (sum+mul)%MOD;
}

bool add(int a[]){

    static int sz=0;

    int val=unique_Array(a);

    for(int i=Start[val];i;i=Next[i])
        if(isEqual(snows[i],a))
            return true;
    sz++;

    for(int i=0;i<6;i++)
        snows[sz][i]=a[i];

    Next[sz]=Start[val],Start[val]=sz;

    return false;
}


/*************************************************************************/
int main()
{

    fast();

    int n;
    cin>>n;
    while(n--){

        int a[6];
        for(int i=0;i<6;cin>>a[i++]);

        if(add(a)){
            cout<<"Twin snowflakes found.";
        return 0;
        }


    }
    cout<<"No two snowflakes are alike.";

   return 0;

}
