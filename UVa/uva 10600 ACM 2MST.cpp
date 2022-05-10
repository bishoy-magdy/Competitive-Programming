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
void online_judge(){freopen("input.txt", "r", stdin);freopen("output.txt","w",stdout);}
const int flag_max=0x3f3f3f3f;
const ll OO=1e9+7;
const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

/***********************main_problem****************************/




class  Disjoint_set{

private:
    vector<int>pairent ,rank;

public:
    Disjoint_set(int N){
        pairent.assign(N,0);
        rank.assign(N,0);
        for (int i = 0; i <N ; ++i) {
            pairent[i]=i;
        }

    }

 int set_pairent(int x){ return  pairent[x]==x? x:pairent[x]=set_pairent(pairent[x]);   }

 bool  check_pairent(int x,int y){ return set_pairent(x)==set_pairent(y);  }

 void linked(int x,int y){

        if(!check_pairent(x,y)){

            int X=set_pairent(x),Y=set_pairent(y);

            if(rank[X]<rank[Y]){
                pairent[X]=Y;
            } else{

                pairent[X]=Y;
                if(rank[X]==rank[Y]){rank[Y]++; }
            }

        }


    }




};






/*********************Bishoy__Magdy*****************************/
    int main() {

        fast();
/*
online_judge();
 */
int t;
cin>>t;
while (t--) {


    int n, m;
    cin >> n >> m;
    Disjoint_set UF(n + 1);

    vector<pair<int, pair<int, int>>> edglist;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edglist.push_back({c, {a, b}});

    }

    sort(edglist.begin(), edglist.end());
    int mst_cost = 0;

    bool arr[100000] = {0};

    int sz = 0;
    for (int j = 0; j < edglist.size(); ++j) {
        pair<int, pair<int, int> > element = edglist[j];
        if (!UF.check_pairent(element.second.first, element.second.second)) {

            mst_cost += element.first;
            UF.linked(element.second.first, element.second.second);
            arr[j] = 1;


        }

    }
    vector<int> ans;


    for (int k = 0; k < edglist.size(); ++k) {

        int second_mst = 0;
        int sec_arr[100000] = {0};
        Disjoint_set check(n + 1);
        int EE = 0;
        if (arr[k]) {
            sec_arr[k] = 1;
            for (int j = 0; j < edglist.size(); ++j) {

                if (!sec_arr[j]) {
                    pair<int, pair<int, int> > element = edglist[j];
                    if (!check.check_pairent(element.second.first, element.second.second)) {
                        EE++;
                        second_mst += element.first;
                        check.linked(element.second.first, element.second.second);


                    }


                }
            }
            sec_arr[k] = 0;
            if (EE == n - 1)
                ans.push_back(second_mst);


        }
    }
    sort(all(ans));
    cout << mst_cost << ' ' << ans[0] << '\n';
    ans.clear();
}

    return 0;



    }
