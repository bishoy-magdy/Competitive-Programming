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
int a,b,t;

int vis[1000][1000];
struct point{

    int a=0,b=0;
    string path="";

};



void bfs(){

    queue<point>q;
    int T=0;

    q.push(*new point);

    while(!q.empty()){


    point nowx=q.front();
    q.pop();

    vis[nowx.a][nowx.b]=1;

    for(int i=0;i<6;i++){

        point now=nowx;


        if(now.a==t || now.b==t){

            for(int idx=0;idx<now.path.size();idx++){

                if(now.path[idx]=='0'){

                    cout<<"fill A\n";

                }
                 if(now.path[idx]=='1'){

                    cout<<"fill B\n";

                }

                 if(now.path[idx]=='2'){

                    cout<<"empty A\n";

                }

                 if(now.path[idx]=='3'){

                    cout<<"empty B\n";

                }

                 if(now.path[idx]=='4'){

                    cout<<"pour A B\n";

                }
                 if(now.path[idx]=='5'){

                    cout<<"pour B A\n";

                }



            }

            cout<<"success\n";
            return ;
        }

        if(i==0 && now.a!=a && !vis[a][now.b])
            now.a=a,now.path+='0',q.push(now),vis[a][now.b]=1;
        else if(i==1 && now.b!=b && !vis[now.a][b])
            now.b=b,now.path+='1',q.push(now),vis[now.a][b]=1;
        else if(i==2 && now.a!=0 && !vis[0][now.b])
            now.a=0,now.path+='2',q.push(now),vis[0][now.b]=1;
        else if(i==3 && now.b!=0 && !vis[now.a][0])
            now.b=0,now.path+='3',q.push(now),vis[now.a][0]=1;
        else if(i==4 && now.b<b && now.a>=1){

            int X=min(b-now.b,now.a);

            if(!vis[now.a-X][now.b+X]){
            now.b+=X;
            now.a-=X;
            now.path+='4';
            q.push(now);
            vis[now.a][now.b]=1;

            }

        }
        else if(i==5 && now.a<a && now.b>=1){
            int X=min(a-now.a,now.b);

            if(!vis[now.a+X][now.b-X]){
            now.a+=X;
            now.b-=X;

            now.path+='5';
            q.push(now);
            vis[now.a][now.b]=1;
        }

        }

    }

    }
}

/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/

int main()
{

    fast();

while(cin>>a>>b>>t)
    clr(vis,0),bfs();



   return 0;

}
