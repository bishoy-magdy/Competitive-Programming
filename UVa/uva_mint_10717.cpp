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

void fast(){ios_base::sync_with_stdio(NULL);cin.tie(0); cout.tie(0);}
void online_judge(){freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}
const int flag_max=0x3f3f3f3f;
const ll OO=1000000007 ;
const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}


/***********************main_problem****************************/
ll lcm(ll a,ll b){
return (a*b)/__gcd(a,b);
}
/**************************Bisho_O*****************************************/
int main() {


fast();

int n,m;

while(cin>>n>>m && n!=0){
    if(n==0){return 0;;}

   int coin[n],desin[m];
map<int,pair<ll,ll> >ans;
for(int i=0;i<m;i++){ans[i].first=OO; ans[i].second=-OO; }
   for(int i=0;i<n;cin>>coin[i++]);
   for(int i=0;i<m;cin>>desin[i++]);

    for(int i1=0;i1<n;i1++){


        for(int i2=i1+1;i2<n;i2++){


                for(int i3=i2+1;i3<n;i3++){

                        for(int i4=i3+1;i4<n;i4++){


                                ll x=lcm(coin[i1],lcm(coin[i2],lcm(coin[i3],coin[i4])));

                                ll Min=0,Max=0;
                                for(int i=0;i<m;i++){


                                     Min=desin[i]/x *x;
                                     Max=desin[i]/x *x;

                                    if(desin[i]%x!=0){Min=(desin[i]/x)*x;Max=((desin[i]/x+1)*(x));}

                                    if(Min<=desin[i] &&(ans[i].first<=Min ||ans[i].first==OO)){ans[i].first=Min;}
                                    if(Max>=desin[i] &&(ans[i].second>=Max ||ans[i].second==-OO)){ans[i].second=Max;}



                                }



                            }
    }
    }
    }


    for(int i=0;i<m;i++){

        cout<<ans[i].first<<' '<<ans[i].second<<'\n';

    }

}



return 0;
}
