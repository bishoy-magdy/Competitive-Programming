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

void fast(){ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);}
void online_judge(){/*freopen("input.txt", "r", stdin);*/freopen("output.txt", "w", stdout);}
const int flag_max=0x3f3f3f3f;
const ll OO=1e9+7;
const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

/***********************main_problem****************************/

class Uninfind{

private:
    vector<int> p,Rank;
public:

    Uninfind(int n){p.assign(n+1,0); Rank.assign(n+1,0);for(int i=0;i<=n;i++){p[i]=i;} }

    int findset(int i){ return p[i]==i?i:p[i]=findset(p[i]); }

    bool issameset(int i,int j){ return findset(i)==findset(j); }

    void unionset(int i,int j){


    if(!issameset(i,j)){

        int X=findset(i),Y=findset(j);
        if(Rank[X]>Rank[Y]){p[Y]=X;}
        else{

            p[X]=Y;
            if(Rank[X]==Rank[Y]){++Rank[Y];}

        }


    }


    }




};



/*******************************************************************/
int main() {

    fast();
/*
online_judge();
*/
    int t;
    cin>>t;
    while(t--){


        int n;
        cin>>n;
        Uninfind unf(n+5);

        int e;
        cin>>e;
        vector<pair<int,pair<int,int> > >edge;
        int nex=1;
        map<string,int>fla;
        for(int i=0;i<e;i++){
            string a,b;
            int w;
            cin>>a>>b>>w;
            int X,Y;

            if(fla[a]==0){fla[a]+=nex; nex++;}

            if(fla[b]==0){fla[b]+=nex; nex++;}

            edge.pb({w,{fla[a],fla[b]}});



        }



        sort(all(edge));


        int mst=0;
        for(int i=0;i<e;i++){

            pair<int,pair<int,int> >E;
            E=edge[i];
            if(!unf.issameset(E.second.first,E.second.second)){mst+=E.first; unf.unionset(E.second.first,E.second.second); }


        }


     cout<<mst;

     if(t>=1){cout<<"\n\n";}


    }
cout<<'\n';




  return 0;
}


