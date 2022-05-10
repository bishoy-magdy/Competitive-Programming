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
#define ll              long long
#define ld              long double
#define all(v)              ((v).begin()), ((v).end())
#define for_(vec)       for(int i=0;i<(int)vec.size();i++)
#define lp(j,n)     for(int i=j;i<(int)(n);i++)
#define rlp(j,n)        for(int i=j;i>=(int)(n);i--)
#define clr(arr,x)  memset(arr,x,sizeof(arr))
#define fillstl(arr,X)    fill(arr.begin(),arr.end(),X)
#define pb         push_back
#define mp          make_pair
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
    //freopen("output.txt", "w", stdout);
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

int idx=0,deg[150],w;

string str[1000];
vector<string>ans;

struct Edge{

int to,nxt;


} edges[1000+5];

int Head[1000+5];

void addEdge(int u,int v){

    edges[idx].to=v;
    edges[idx].nxt=Head[u];
    Head[u]=idx++;


}

void init(){

    clr(Head,-1);
    idx=0;
    fill(deg+'a',deg+'z'+1,0);
    ans.clear();

}
void Euler(int star){

    for(int &e=Head[star];~e;){

        int x=e,xx=edges[e].to;

        e=edges[x].nxt;

        Euler(xx);
        ans.push_back(str[w-x-1]);

    }


}

/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/

int main()
{

   fast();

   int t;
   cin>>t;
   while(t--){

    init();

    cin>>w;

    for(int i=0;i<w;i++){

        cin>>str[i];
    }
    sort(str,str+w);

    int starpoint='z';
    for(int i=w-1;i>=0;i--){

        int last=str[i].size()-1;
        addEdge(str[i][0],str[i][last]);
        deg[str[i][0]]++;
        deg[str[i][last]]--;
        starpoint=min({starpoint,(int)str[i][0],(int)str[i][last]});


    }

    bool valid=1;
    int cnt1=0;

    for(int i='a';i<='z';i++){

        if(deg[i]==1)
            if(cnt1){
                valid=0;
            }
            else
                starpoint=i,cnt1++;

        else if(deg[i]>1)
            valid=0;

    }

    Euler(starpoint);
    if(valid &&ans.size()==w){

        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<".\n"[i==0?1:0];

        }

    }
    else{

        cout<<"***\n";
    }

   }
/*
1
6
ab
ba
bc
ca
ad
da


0
4
1
2
5
3

*/

   return 0;

}
