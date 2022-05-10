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

struct ans
{
    ll a,b,c;
};

ans solve(ll n)
{


    vector<int>prime;

    ans ans_=*new ans;

    for(int i=2; i*i<=n; i++)
    {


        while(n%i==0)
        {

            prime.push_back(i);
            n/=i;
        }

    }

    if(n>1)prime.push_back(n);

    ll a=1,b,c;

    for(int i=0; i<(int)prime.size()-2; i++)
    {
        a*=prime[i];
    }
    b=prime[prime.size()-2];
    c=prime[prime.size()-1];

    ans_.a=a;
    ans_.b=b;
    ans_.c=c;

    return ans_;
}


/**************************Bisho_O*****************************************/
int main()
{

    fast();


    int t,case_=1;
    cin>>t;
    while(t--)
    {

        ll n;
        cin>>n;
        ans ANS=solve(n);

        cout<<"Case #"<<case_<<": "<<n<<" = "<<ANS.a<<" * "<<ANS.b*ANS.c<<" = "<<ANS.a*ANS.b<<" * "<<ANS.c<<'\n';

        case_++;
    }




    return 0;

}
