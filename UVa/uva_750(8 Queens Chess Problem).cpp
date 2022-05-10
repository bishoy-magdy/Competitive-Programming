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
const ll OO=1e9 ;
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

bool visit_colom[8],left_diag[2*8],right_diag[2*8];

vector<vector<int> >all_ans;

void queen(int row ,vector<int>&ans){


        if(row==8){

            all_ans.push_back(ans);
            return;
        }

        for(int c=0;c<8;c++){

            if(!visit_colom[c] && !left_diag[8+c-row] && !right_diag[row+c]){
                ans.push_back(c+1);

                visit_colom[c]=left_diag[8+c-row]=right_diag[row+c]=1;

                queen(row+1,ans);
                ans.pop_back();
                visit_colom[c]=left_diag[8+c-row]=right_diag[row+c]=0;


            }


        }


    }


    void solve(int n,int m){
    vector<vector<int> >ANS;
    for(int i=0;i<all_ans.size();i++){

        if(all_ans[i][m-1]==n){ANS.push_back(all_ans[i]);}

    }

        cout<<"SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";

        for(int i=0;i<ANS.size();i++){

            if((i+1)<10){cout<<' ';}
            cout<<i+1<<"      ";
            for(int j=0;j<ANS[i].size();j++){cout<<ANS[i][j]; cout<<(j<ANS[i].size()-1?" ":""); }

            cout<<'\n';

        }

    }





/**************************Bisho_O*****************************************/
int main()
{

    fast();
    clr(visit_colom,0);
    clr(left_diag,0);
    clr(right_diag,0);
    vector<int>ans;
    queen(0,ans);

    int t;
    cin>>t;
    while(t--){

        int n,m;
        cin>>n>>m;
        solve(n,m);

        if(t>0){
            cout<<'\n';
        }


    }

    return 0;
}

