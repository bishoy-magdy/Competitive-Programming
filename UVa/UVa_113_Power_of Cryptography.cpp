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

bool compare(string n1,string n2){

    if(n1.size()>n2.size() || n1==n2)return 1;
    else if(n2.size()>n1.size())return 0;
    for(int i=0;i<min(n1.size(),n2.size());i++){

        int x=n1[i]-'0',y=n2[i]-'0';

        if(x>y)return 1;
        else if (x<y)return 0;

    }

}



string multiply(string num1, string num2)
{

    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";
    int I,J;
    I=J=0;
    vector<int> result(len1 + len2, 0);

    for(int i=len1-1;i>=0;i--){

        int n1=num1[i]-'0';
        int carry=0;
        J=0;
        for(int j=len2-1;j>=0;j--){

            int n2=num2[j]-'0';
            int sum=n1*n2+result[I+J]+carry;

            carry=sum/10;

            result[I+J]=sum%10;
            J++;
        }
        if(carry)
            result[I+J]+=carry;
        I++;
    }
    reverse(all(result));

    string ans="";
    bool flag=0;
    for(auto X:result){
        if(flag)
            {ans+=X+'0';
            continue;
            }

        if(X!=0)flag=1,ans+=X+'0';


    }
return ans;

}

int binaryX(string target,int n){

int star=1,end_=1e9;

    while(star<=end_){

        int mid=(star+end_)>>1;

        string First=to_string(mid);

        string ans="1";
        int t=n;
        while(t--)
        ans=multiply(ans,First);

        if(ans==target)return mid;

        if(compare(ans,target)){
            end_=mid-1;

        }
        else
            star=mid+1;



    }

return 0;
}



/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/

int main()
{


    fast();



    string s;
    int a;
    while(cin>>a>>s){
    cout<<binaryX(s,a)<<'\n';

    }

    

/*
    or using long double
    double n, p;

	while (cin>>n>>p) {
		printf("%.0lf\n", pow(p, 1 / n));
	}
*/

    return 0;

}
