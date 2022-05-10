/*************************include******************/
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
/******************************************************/


using namespace std;
/*BISHOY__MAGDY*/
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

void fast(){ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);}
void online_judge(){/*freopen("input.txt", "r", stdin);*/freopen("output.txt","w",stdout);}
const int flag_max=0x3f3f3f3f;
const ll OO=1e9+7;
const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

/***********************main_problem****************************/


class  Disjion_set{

private:
    vector<int>rank,parent;

public:
    Disjion_set(int n){

        rank.assign(n,1);
        parent.assign(n,0);
        for (int i = 0; i <n ; ++i) {
            parent[i]=i;
        }

    }
    int set_parent(int x){ return  parent[x]==x?x:parent[x]=set_parent(parent[x]);}

    bool check_parent(int x,int y){ return  set_parent(x)==set_parent(y);}

    int  linked(int x,int y){
        if(check_parent(x,y)){ return rank[set_parent(x)];}


        if(!check_parent(x,y))
        {
            int X=set_parent(x);
            int Y=set_parent(y);
            if(rank[X]>=rank[Y]){
                parent[Y]=X;
                rank[X]+=rank[Y];

            }
            if(rank[Y]>rank[X]){

                parent[X]=Y;
                rank[Y]+=rank[X];
            }
            return  max(rank[Y],rank[X]);
        }
    }






};



int n,t;
map<string,int>Q;
vector<pair<int ,int> >pa_ir;


/*********************Bishoy__Magdy*****************************/
int main() {

    fast();
/*
online_judge();
 */

cin>>t;
while (t--) {
    cin >> n;
    Q.clear();
    pa_ir.clear();
    int poss = 1;

    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        if (Q[a] == 0) {
            Q[a] = poss;
            poss++;
        }
        if (Q[b] == 0) {
            Q[b] = poss;
            poss++;
        }
        pa_ir.push_back({Q[a], Q[b]});
    }

    Disjion_set UF(poss+5);

    for (int j = 0; j < n; ++j) {

        cout << UF.linked(pa_ir[j].first, pa_ir[j].second) << '\n';
    }


}
   return 0;



}
