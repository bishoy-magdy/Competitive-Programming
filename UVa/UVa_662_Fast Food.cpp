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

vector<int>arr;
int memo[200][30];

int R(int s,int e){

 int mid=(s+e)/2 + (s+e)%2;

 int ans=0;
 int now=arr[mid];

 for(int j=s;j<=e;j++){
    ans+=abs(arr[j]-arr[mid]);
 }

return ans;
}


int solve(int i , int k,int last){


    if(i==arr.size())
        return 0;

    if(k==0){

        int F=0;

        for(int x=i;x<arr.size();x++)
            F+=abs(arr[x]-last);
        return F;
    }


    int &ret=memo[i][k];

    if(ret!=-1)
        return ret;

    ret=1e8;

   for(int j=i;j<arr.size();j++){

    int mid=(i+j)/2 +(i+j)%2;

    ret=min(ret,solve(j+1,k-1,arr[mid])+R(i,j));

   }


return ret;
}



void track(int i ,int k ,int last,int testcase){

    if(i==arr.size())
        return ;

    if(k==1){

        int mid=((i+1)+arr.size())/2;
        if((i+1)==arr.size())
        cout<<"Depot "<<testcase<<" at restaurant "<<i+1<<" serves restaurant "<<i+1<<'\n';

        else
        cout<<"Depot "<<testcase<<" at restaurant "<<mid<<" serves restaurants "<<i+1<<" to "<<arr.size()<<'\n';

        return ;
    }

    int ret=1e7, I,K,LAST;
    int S,E;
    for(int j=i;j<arr.size();j++){
       int mid=(i+j)/2 +(i+j)%2;

        int now=solve(j+1,k-1,arr[mid])+R(i,j);

        if(now<ret){
            ret=now;
            S=i+1,E=j+1;
            I=j+1,K=k-1,LAST=mid+1;
        }

    }

    int mid=((S+E)/2);


    if(S==E)
        cout<<"Depot "<<testcase<<" at restaurant "<<mid<<" serves restaurant "<<S<<'\n';

    else
    cout<<"Depot "<<testcase<<" at restaurant "<<mid<<" serves restaurants "<<S<<" to "<<E<<'\n';

    track(I,K,LAST,testcase+1);

}

/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/

int main()
{

    fast();

    int n,k,t=1;
    while(cin>>n>>k && n && k)
    {

    cout<<"Chain "<<t++<<'\n';
    clr(memo,-1);
   arr.clear();
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int total=solve(0,k,0);
    track(0,k,0,1);
    cout<<"Total distance sum = "<<total<<"\n\n";

    }
    return 0;
}
