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
const ll OO=1e15+9 ;
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

//the seq : 2,3,5,7,13,17,19 is the Mersenne prime and can detect it with -----> primes p such that 2^p - 1 is prime <----".


bool is_prime(ll n){
    vector<ll>ans;
  for(ll i=2;i*i<=n;i++){

            if(n%i==0)return 0;

    }


    return 1;
}


/**************************Bisho_O*****************************************/
int main()
{

    fast();


    ll n;

    while(cin>>n && n!=0){

        if(is_prime(n) && is_prime((1<<n)-1)){
            ll ans=(ll)(1<<(n-1))*((1<<n)-1);
            cout<<"Perfect: "<<ans<<"!\n";

        }
        else if(is_prime(n)){

            cout<<"Given number is prime. But, NO perfect number is available.\n";
        }
        else{

            cout<<"Given number is NOT prime! NO perfect number is available.\n";
        }


    }


    return 0;

}
