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

vector<int>solve(ll n){
    vector<int>prime;
    for(ll i=2;i*i<=n;i++){

        int counter=0;

        while(n%i==0){
            counter++;
            if(counter==1)prime.push_back(i);
            n/=i;

        }

        if(counter>=1)prime.push_back(counter);

    }
if(n>1)prime.push_back(n),prime.push_back(1);

return prime;
}


/**************************Bisho_O*****************************************/
int main()
{

    fast();

        //online_judge();

    string s;
    while(getline(cin,s)){

    if(s[0]-'0'==0)break;

    s=' '+s;
    s+=' ';
    int star_,end_;
    star_=end_=-1;
    vector<int>N;
    for(int i=0;i<s.size();i++){

        if(s[i]==' ' && star_==-1){star_=i;continue;}


        if(star_!=-1 && s[i]==' '){

            int X=stoi(s.substr(star_+1,i-star_-1));

            N.push_back(X);
            star_=i;
        }

    }

    ll ans=1;

    for(int i=0;i<N.size();){

        ans*=pow(N[i],N[i+1]);
        i+=2;

    }
    vector<int>ANS=solve(ans-1);


    string space="";
    reverse(all(ANS));
    for(int i=0;i<ANS.size();i++){

        if(i%2==0)swap(ANS[i],ANS[i+1]);
        cout<<space<<ANS[i];
        space=" ";
    }
    cout<<'\n';

    }




    return 0;

}
