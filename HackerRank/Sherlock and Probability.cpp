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

/********************************************************/
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
/***********************function************************/
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,-1,1,1,-1,1,-1};

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

ll Power(ll n,ll deg)
{
    if(!deg)return 1;
    else  if(deg & 1) return Power(n,deg-1)*n;
    else
    {
        ll half=Power(n,deg/2);
        return half*half;
    }
}

/***********************main_problem****************************/
string s;

int arr[100009];

void prefix_sum(){

    arr[0]=(s[0]=='1');
    lp(1,s.size()){

        arr[i]=(s[i]=='1');

        arr[i]+=arr[i-1];

    }

}

ll range(ll left,ll right){

    if(left<0)left=0;
    if(right>s.size()-1)right=s.size()-1;

    if(left==0)return arr[right];

    return arr[right]-arr[left-1];

}




int main()
{

    int t;
    cin>>t;
    while(t--){

        ll n,k;
        cin>>n>>k;
        cin>>s;

        ll top=0,down=n*n;
        prefix_sum();
        lp(0,s.size()){
        if(s[i]=='1')
        top+=range(i-k,i+k);
        }
        ll gcd_=gcd(top,down);
        cout<<top/gcd_<<'/'<<down/gcd_<<'\n';

    }



return 0;

}
