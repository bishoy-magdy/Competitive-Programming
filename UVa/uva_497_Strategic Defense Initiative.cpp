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

vector<int>arr;

map<pair<int,int> , vector<int> >memo;

vector<int> pick_or_leave(int s,int pre){

    if(memo[{s,pre}].size()>=1){ /*cout<<"hi\n";*/return memo[{s,pre}];}

    if(s==arr.size()){vector<int> w;return w;}

    vector<int>ch1=pick_or_leave(s+1,pre);
    vector<int> ch2;

    if(arr[s]>arr[pre] || arr.size()==pre)
       {
         ch2=pick_or_leave(s+1,s);
         ch2.push_back(arr[s]);

       }

    if(ch1.size()>ch2.size()){return memo[{s,pre}]=ch1;}
    else{
        return memo[{s,pre}]=ch2;
    }

}


void solve(){

    vector<int>ans=pick_or_leave(0,arr.size());
    reverse(all(ans));
    cout<<"Max hits: "<<ans.size()<<'\n';
    for(auto ANS:ans){cout<<ANS<<'\n';}
    memo.clear();
    arr.clear();

}


/**************************Bisho_O*****************************************/
int main()
{
    fast();

    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while ( t-- )
    {

        string s;
        while (getline(cin, s) && s != "")
        {
            stringstream ss(s);
            int Bishoy;

            ss >> Bishoy;
            arr.push_back(Bishoy);
        }
        
            solve();

        if (t)
            cout << '\n';
    }





    return 0;
}
