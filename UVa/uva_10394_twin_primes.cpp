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

void fast(){ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);}
void online_judge(){freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}
const int flag_max=0x3f3f3f3f;
const ll OO=1e19+7;
const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

/***********************main_problem****************************/



int vis[100000000+2];


/**************************Bisho_O*****************************************/
int main() {

fast();


vector<pair<ll,ll> >pa_ir;

ll n=100000000;


for(ll i=2;i*i<=n;i++){

    if(!vis[i]){

        for(ll j=2*i;j<=n;j+=i){vis[j]=1;}



    }


}

for(int i=2;i<=n;i++){

    if(!vis[i] && !vis[i+2]){pa_ir.push_back({i,i+2});}


}
int X;
while(cin>>X){


    cout<<'('<<pa_ir[X-1].first<<','<<' '<<pa_ir[X-1].second<<')'<<'\n';

}


return 0;
}
