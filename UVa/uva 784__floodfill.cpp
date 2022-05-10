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
void online_judge(){freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}
const int flag_max=0x3f3f3f3f;
const ll OO=1e9+7;
const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

/***********************main_problem****************************/
char arr[100][100];
bool visited[100][100];

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void dfs(int i,int j){

visited[i][j]=1;
arr[i][j]='#';

    for(int k=0;k<4;k++){

        if(!visited[i+dx[k]][j+dy[k]] && arr[i+dx[k]][j+dy[k]]==' '){ arr[i+dx[k]][j+dy[k]]='#';  dfs(i+dx[k],j+dy[k]);}



    }







}


int con(string N){

    int ans=N[0]-'0';
    for(int i=1;i<N.size();i++){ans*=10; ans+=N[i]-'0'; }

    return ans;

}


/*******************************************************************/
int main() {

    fast();


string N;
getline(cin,N);
int n=con(N);
while(n--){
        string s[1000];
        string line;
        int t=0;

        while(getline(cin,s[t])){

            if(s[t][0]=='_'){line=s[t];break;}
            else
                t++;

        }
        for(int i=0;i<t;i++){

            for(int j=0;j<s[i].size();j++){arr[i][j]=s[i][j];}


        }






        for(int i=0;i<t;i++){

            for(int j=0;j<s[i].size();j++){if(arr[i][j]=='*'){dfs(i,j);};}


        }



        for(int i=0;i<t;i++){

            for(int j=0;j<s[i].size();j++){cout<<arr[i][j];}

            cout<<'\n';

        }
cout<<line;
if(n>=1){cout<<'\n';}
for(int i=0;i<100;i++){for(int j=0;j<100;j++){visited[i][j]=0;}}


}
cout<<'\n';



  return 0;
}


