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

int arr[10000000+5];
bool vis[10000000+5];
int last_prim;
void set_prim(){

for(ll i=2;i<=10000000;i++){

    if(!vis[i]){
        arr[i]=i;
        last_prim=arr[i];
            arr[i]=i;
        for(ll j=2*i;j<=10000000;j+=i){


            vis[j]=1;


        }


    }
else
    arr[i]=last_prim;


}



}




/**************************Bisho_O*****************************************/
int main() {

fast();

set_prim();




int n;

while(cin>>n)
{

if(n<=7){cout<<"Impossible."; goto nex;}
for(int i=3;i>=0;i--){

    cout<<arr[n-2*i];
    n-=arr[n-2*i];
    if(i>0){cout<<' ';}

}
nex:
cout<<'\n';

}

/*
cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
*/
return 0;
}
