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




/**************************Bisho_O*****************************************/
int main() {

fast();

/*
n=(a+dx)^3

n=(a+dx)^2*(a+dx)

n=(a^2+2*a*dx+dx^2)*(a+dx)

n=(a^3+2*a^2*dx+a*dx^2 +a^2*dx and so one......  )

n=a^3+3*a^2*dx+3*a*dx^2+dx^3 and the dx the ranke greater or eqal 2 =0 -->>> we can ignore this small 
dx=(n-a^3)/3a^2
*/

double n;

while(cin>>n && n!=0.00){

int ans=cbrt(n);


double  dx = ( n - ( ans * ans * ans ) ) / ( 3.00 * ans * ans );


printf("%.4f\n",ans+dx);




}


return 0;
}
