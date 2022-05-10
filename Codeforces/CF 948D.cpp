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

int binary_decimal(string s)
{



    int ans=0;

    for(int i=0; i<s.size(); i++)
    {
        ans+=(1<<i)*(s[i]-'0');


    }
    return ans;

}


struct trie
{


    trie *arr[2];

    bool isleaf;

    int cnt=0;
    trie()
    {
        isleaf=false;
        clr(arr,0);
        cnt=0;
    }

    void add(int a,int index=30)
    {

        bitset<31>bit=a;

        if(index==-1)
            isleaf=true;
        else
        {
            if(arr[bit[index]]==0)
                arr[bit[index]]=new trie();
            arr[bit[index]]->add(a,index-1);
            arr[bit[index]]->cnt++;
        }

    }


    string match_x(int a,int index=30)
    {


        bitset<31>bit=a;
        if(index==-1)
        {
            return "";
        }

        else
        {


            if(bit[index]==0){

               if(arr[0]!=0){

                if(arr[0]->cnt){
                arr[0]->cnt--;
                return arr[0]->match_x(a,index-1)+'0';
                }
                else{
                arr[1]->cnt--;
                return arr[1]->match_x(a,index-1)+'1';
                }


               }
               else{

               arr[1]->cnt--;
                return arr[1]->match_x(a,index-1)+'1';

               }

            }

            else if(bit[index]==1){

                if(arr[1]!=0){

                if(arr[1]->cnt){
                arr[1]->cnt--;
                return arr[1]->match_x(a,index-1)+'1';
                }
                else{
                arr[0]->cnt--;
                return arr[0]->match_x(a,index-1)+'0';
                }

               }
               else {
                arr[0]->cnt--;
                return  arr[0]->match_x(a,index-1)+'0';

               }

            }


        }
    }
};


/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/

int main()
{

    fast();

    trie t;

    int n;
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;scanf("%d",arr+i++));

    for(int i=0;i<n;i++){

        int a;
        scanf("%d",&a);
        t.add(a);
    }
    for(int i=0;i<n;i++){

        string bits=t.match_x(arr[i]);
        printf("%d ",binary_decimal(bits)^arr[i])<<' ';

    }


    return 0;

}
