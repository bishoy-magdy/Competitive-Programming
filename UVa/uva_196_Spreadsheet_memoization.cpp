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
typedef vector<pair<int, int>> vii;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
/***********************function************************/

void fast(){ios_base::sync_with_stdio(NULL);cin.tie(0); cout.tie(0);}
void online_judge(){freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}
const int flag_max=0x3f3f3f3f;
const ll OO=1e9 ;
const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

 ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
 ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b;}

/***********************main_problem****************************/
int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,-1,1,1,-1,1,-1};

string grid[1000][18278];

int dp[1000][10000];

int go(int x,int y)
{
    if(dp[x][y]!=OO)
        return dp[x][y];
    if(grid[x][y][0]!='=')
        return dp[x][y]=stoi(grid[x][y]);

    int r=0,c=0,res=0;
    for(int i=1;i<=grid[x][y].size();i++)
    {
        if(isdigit(grid[x][y][i]))
           r=r*10+grid[x][y][i]-'0';
        else
        {
            if(isalpha(grid[x][y][i]))
                c=c*26+grid[x][y][i]-'A'+1;
            else
            {
                res+=go(r-1,c-1);
                r=c=0;
            }

        }
    }
    return dp[x][y]=res;
}



/**************************Bisho_O*****************************************/
int main() {

fast();


int t;
cin>>t;

while(t--){

    int n,m;
    cin>>m>>n;
    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            cin>>grid[i][j];
            dp[i][j]=OO;





        }

    }



    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){


        cout<<go(i,j);


        if(j!=m-1){cout<<' ';}
        }

        {cout<<'\n';}

    }


}





return 0;
}
