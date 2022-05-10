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

const ll  MOD=1e9+7;
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


vector<vector<string> >state;

/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/

int main()
{


    fast();
    while(1)
    {

        vector<string>S;
        state.clear();

        for(int i=0; i<52; i++)
        {
            vector<string>F;
            string s;
            cin>>s;

            if(s[0]=='#')return 0;

            S.push_back(s);


            F.push_back(s);

            state.push_back(F);


        }

        for(int i=0; i<state.size(); i++)
        {





            if((i-3)>=0 && state[i].size()>=1 && state[i-3].size()>=1 &&

                    ( state[i][state[i].size()-1][0]==state[i-3][state[i-3].size()-1][0] ||

                      state[i][state[i].size()-1][1]==state[i-3][state[i-3].size()-1][1]

                    ))
            {

                state[i-3].push_back(state[i][state[i].size()-1]);
                state[i].pop_back();

                if(state[i].size()==0)
                {

                    state.erase(state.begin()+i,state.begin()+i+1);

                }


                i-=4;
            }




            else if((i-1)>=0 && state[i].size()>=1 && state[i-1].size()>=1 &&
                    ( state[i][state[i].size()-1][0]==state[i-1][state[i-1].size()-1][0] ||

                      state[i][state[i].size()-1][1]==state[i-1][state[i-1].size()-1][1]

                    ))
            {

                state[i-1].push_back(state[i][state[i].size()-1]);
                state[i].pop_back();

                if(state[i].size()==0)
                {

                    state.erase(state.begin()+i,state.begin()+i+1);

                }


                i-=2;
            }




        }





        cout<<state.size()<<" pile"<<(state.size()>1?"s ":" ")<<"remaining: ";

        string space_="";
        for(int i=0; i<state.size(); i++)
        {

            cout<<space_<<state[i].size();
            space_=" ";
        }
        cout<<'\n';


    }




    return 0;

}



