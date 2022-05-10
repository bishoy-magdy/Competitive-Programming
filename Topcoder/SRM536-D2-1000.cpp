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

class MergersDivTwo
{

public:
    vector<int>arr;
    int k;
    int n;

    int sum[51];
    double dp[51];

    double solve()
    {


        sum[0]=0;

        for(int i=1; i<=n; i++)
        {

            sum[i]=sum[i-1]+arr[i-1];
            dp[i]=(double)sum[i]/(double)i;

        }



        for(int i=k; i<=n; i++)
        {

            int counter_=k;
            for(int j=i+k-1; j<=n; j++)
            {

                dp[j]=max(dp[j],(double)(dp[i]+sum[j]-sum[i])/(double)counter_);

                counter_++;
            }

        }

        return dp[this->n];
    }

    double findMaximum(vector<int>arr, int k)
    {

        this->arr=arr;
        this->k=k;
        this->n=arr.size();
        sort(this->arr.begin(),this->arr.end());
        return solve();
    }
};

/**************************Bisho_O*****************************************/