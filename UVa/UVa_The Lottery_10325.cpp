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

/***********************function************************/

void fast(){ios_base::sync_with_stdio(NULL);cin.tie(0); cout.tie(0);}
void online_judge(){freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}
const int flag_max=0x3f3f3f3f;
const ll OO=1e9 ;
const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}


/***********************main_problem****************************/

ll lcm(ll a,ll b){


return __int128(a*b)/__gcd(a,b);

}

/**************************Bisho_O*****************************************/
int main() {


fast();

ll n,m;
while(cin>>n>>m)
{


int arr[m];
for(int i=0;i<m;cin>>arr[i++]);

int ans=0;

for(int i=1;i<=(1<<m)-1;i++){

bitset<20>X=i;
ll flag=1;
int count_=0;
for(int j=0;j<X.size();j++)
{

    if(X[j]==1){flag=lcm(flag,arr[j]); }

}

if(X.count() &1 ){ ans+=n/flag; }
else{

ans-=n/flag;
}

}

cout<<n-ans<<'\n';
}
return 0;
}
