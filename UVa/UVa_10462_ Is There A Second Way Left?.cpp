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

class Disjoint_set{

private :
    vector<int>Parent,Rank;

public:
    Disjoint_set(int N){

    Parent.assign(N,0),Rank.assign(N,0);

    for(int i=0;i<N;i++)
        Parent[i]=i;

    }

    int Set_Parent(int x){return Parent[x]==x ? x :Parent[x]=Set_Parent(Parent[x]);}

    bool Same_Parent(int x,int y) { return Set_Parent(x)==Set_Parent(y);  }

    void Link(int x,int y){

            int parent_x=Set_Parent(x),parent_y=Set_Parent(y);

            if(Rank[parent_x] > Rank[parent_y])
                    Parent[parent_y]=parent_x;
            else
                Parent[parent_x]=parent_y,Rank[parent_x]==Rank[parent_y]?Rank[parent_x]++ :1;




    }

};




string solve(){


    int v, q;
    cin>>v>>q;

    Disjoint_set DS(v+1);

    vector<pair<int ,pair<int,int> > >list_;
    while(q--){

        int a,b,c;
        cin>>a>>b>>c;
        list_.push_back({c,{a,b}});

    }
    sort(all(list_));

    int ans=0;

    vector<int>marks;

    for(int i=0;i<list_.size();i++){

        pair<int ,pair<int,int> >now=list_[i];

        if(!DS.Same_Parent(now.second.first,now.second.second)){

            ans+=now.first;
            DS.Link(now.second.first,now.second.second);
            marks.push_back(i);
        }

    }


    vector<int>__2MST;

    if(marks.size()!=(v-1))
        return "No way";
    else
    __2MST.push_back(ans);


    for(int j=0;j<marks.size();j++){

       int E=0,_2MST=0;
       Disjoint_set DS2(v+1);

      for(int i=0;i<list_.size();i++){

        pair<int ,pair<int,int> >now=list_[i];

        if(!DS2.Same_Parent(now.second.first,now.second.second) && marks[j]!=i){

            _2MST+=now.first;
            DS2.Link(now.second.first,now.second.second);
            E++;
        }

    }
    if(E==(v-1))
        __2MST.push_back(_2MST);


    }

    sort(all(__2MST));

    if(__2MST.size()>=2)return to_string(__2MST[1]);
    else
        return "No second way";




}




/***********𝓢𝓣𝓞𝓟 𝓦𝓗𝓔𝓝 𝓨𝓞𝓤 𝓡𝓔𝓐𝓒𝓗 𝓣𝓗𝓔 𝓒𝓞𝓝𝓒𝓔𝓟𝓣 𝓞𝓕 𝓓𝓞𝓝'𝓣 𝓢𝓣𝓞𝓟******************/

int main()
{


    fast();
    int t;
    cin>>t;
    lp(0,t)
      cout<<"Case #"<<i+1<<" : "<<solve()<<'\n';


    return 0;

}
