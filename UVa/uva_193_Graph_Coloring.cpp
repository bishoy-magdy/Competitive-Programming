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
int n,m;
vector<vector<int> >adj;
vector<bool>visited;
vector<int>ans;
vector<int>black;



bool canblack(int node){


    for(int i=0;i<adj[node].size();i++){
        //check not visited and no cycle
        if(visited[adj[node][i]]==1 || node==adj[node][i]){return 0;}
    }

    return 1;
}

void backtrack(int node){
    //update size
    if(black.size()>ans.size()){ans=black; }

    if(node==n+1){ return ;}


   int max_possible=n-node+1;
    //max possible can reach less than I have
   if((max_possible+black.size())<=ans.size()){return;}

    for(int i=node;i<=n;i++){

        if(canblack(i)){
            //do
            visited[i]=1;
            black.push_back(i);
            //rec
            backtrack(i+1);
            //undo
            visited[i]=0;
            black.pop_back();


        }

    }


}



void solve(){

    cin>>n>>m;
    //initialization
    adj.clear();
    adj.resize(n+1);
    visited.clear();
    visited=vector<bool>(n+1,false);
    ans.clear();
    black.clear();

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    backtrack(1);

    cout<<ans.size()<<'\n';
        string space="";
		for(int i=0;i<ans.size();i++){
			cout<<space<<ans[i],space=" ";

		}
    cout<<'\n';

}




/**************************Bisho_O*****************************************/
int main()
{

    fast();

    int t;
    cin>>t;
    while(t--){
    solve();

    }

    return 0;
}

