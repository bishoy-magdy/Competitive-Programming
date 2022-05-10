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

bool custom(string x,string y)
    {


        string case1=x+y;

        string case2=y+x;

        return case1>=case2;

    }

class TheNumbersLord
{

public:




    string create(vector<int>arr,int n )
    {

        vector<string>Arr;

        for(int i=0; i<arr.size(); i++)
        {
            Arr.push_back(to_string(arr[i]));

        }

        sort(all(Arr),custom);

        string ans="",flag="";

        n-=Arr.size();

        for(int i=0;i<Arr.size();i++){

            if(flag.size()<Arr[i].size())
                flag=Arr[i];

            if(flag<Arr[i] && flag.size()==Arr[i].size())
                flag=Arr[i];
        }

        //ans sub (xxxxmax)(n*max)(xxxxxxx)

        for(int i=0; i <Arr.size(); i++)
        {
            ans+=Arr[i];
           if(Arr[i]==flag)
            while(n-- && n>=0)
                ans+=flag;

        }



        return ans;
    }


};
