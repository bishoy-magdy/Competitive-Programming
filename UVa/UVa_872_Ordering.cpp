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
    //freopen("input.txt", "r", stdin);
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

const ll  MOD=1e9+7;
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

map<string , int>vis;
vector<string>ans;
vector<char>var;
stringstream ss;

bool visit[22];


void solve(string now){

    if(now.size()==var.size()){

     string space="",Flag="";
       for(int idx=0;idx<now.size();idx++){

        Flag+=space;
        Flag+=now[idx];
        space=" ";

       }
       ans.push_back(Flag);

        return ;
    }

    for(int j=0;j<var.size();j++){

        if(visit[j])
            continue;

        for(int k=0;k<now.size();k++){
            string X="";
            X+=now[k];
            X+='>';
            X+=var[j];
            if(vis[X])
                return ;

        }

        visit[j]=1;
        solve(now+var[j]);
        visit[j]=0;


    }

}


/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/



int main()
{
    //online_judge();
    //fast();
    int t;
     scanf("%d\n\n", &t);

    for(int q = 0;q<t; q++) {

        if(q >0)
            cout<<'\n';

        char a,b,c;
        string line;
        var.clear();
        clr(visit,0);
        vis.clear();
        ans.clear();

        getline(cin, line);
        ss.clear();
        ss.str(line);

        while(ss >> a)
            var.push_back(a);

        sort(all(var));

        getline(cin, line);
        ss.clear();
        ss.str(line);

        while(ss >> a >> b >> c)
        if(b=='>'){
            string now="";
            now+=a;
            now+='>';
            now+=c;
            vis[now]=1;

        }
        else if(b=='<'){
            string now="";
            now+=c;
            now+='>';
            now+=a;
            vis[now]=1;

        }
        solve("");
        if(ans.size()==0)
            cout<<"NO\n";

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<'\n';
       }
        //last space
        getline(cin, line);
    }

   return 0;

}
