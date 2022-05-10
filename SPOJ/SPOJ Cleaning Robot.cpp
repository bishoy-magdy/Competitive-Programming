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
int n,m,len,limit_mask;

///the distance for every (tile/house/indx) point to other point
int distace[25][25][11];
///stored for every (tile/house/indx) and mask
int dp[11][1<<11];

vector<pair<int,int> >number_of_tiles;
char grid[25][25];

bool valid(int i,int j){ return i>=0 && i<=n-1 && j>=0 && j<=m-1 && grid[i][j]!='x';}

void BFS_for_every_i(int indx){

    queue<pair<int,int> >q;

    bool vis[n][m];
    int X=number_of_tiles[indx].first,Y=number_of_tiles[indx].second;
    q.push({X,Y});
    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){
            vis[i][j]=0;
            distace[i][j][indx]=OO;

        }

    }

        vis[X][Y]=1;
        distace[X][Y][indx]=0;

while(!q.empty()){

    pair<int,int>Q=q.front();
    q.pop();
    int X=Q.first,Y=Q.second;
    for(int k=0;k<4;k++){

        if(valid(X+dx[k],Y+dy[k]) && !vis[X+dx[k]][Y+dy[k]]){

            vis[X+dx[k]][Y+dy[k]]=1;
            distace[X+dx[k]][Y+dy[k]][indx]=distace[X][Y][indx]+1;
            q.push({X+dx[k],Y+dy[k]});

        }

    }


    }


}

int solve(int indx,int mask){

///the last (tile/house/indx) by using mask ---> last repeation
if(mask==limit_mask){ return 0;}

///is stored before-->>visited used "memoization"
if(dp[indx][mask]!=-1){  return dp[indx][mask];}

int ans=OO;
for(int i=0;i<len;i++){

    if((mask & 1<<i)==0){
    int new_mask=mask|1<<i;
    ///to get the minum distace from i to all permution && ( if the distace are not visited from the posion i to indx==OO)?
    ans=min(ans,solve(i,new_mask)+distace[number_of_tiles[i].first][number_of_tiles[i].second][indx]);

    }


}
///make memoization in the grid dp[][]
return dp[indx][mask]=ans;
}



/**************************Bisho_O*****************************************/
int main() {

fast();


while(cin>>m>>n && m!=0 && n!=0){
clr(dp,-1);
number_of_tiles.clear();
for(int i=0;i<n;i++){

    for(int j=0;j<m;j++){

        cin>>grid[i][j];
        if(grid[i][j]=='*'){number_of_tiles.pb({i,j});}
        if(grid[i][j]=='o'){number_of_tiles.insert(number_of_tiles.begin(),{i,j});}


    }


}
///number of tiles         last number mask permution 1111111....
len=number_of_tiles.size(),limit_mask=(1<<len)-1;

for(int i=0;i<number_of_tiles.size();i++){

    BFS_for_every_i(i);

}
int ANS=solve(0,1);
///if greater than or equal OO that means the one of the tiles||house not reach from indx X;
cout<<(ANS>=OO?-1:ANS)<<'\n';

}


return 0;
}
