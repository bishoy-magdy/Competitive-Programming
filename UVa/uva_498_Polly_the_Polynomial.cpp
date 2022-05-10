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
const ll OO=1e9 ;
const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}


/***********************main_problem****************************/

vector<int>c;
vector<int>x;

vector<int>convert__(string X){

vector<int>ans;

for(int i=0;i<X.size();i++){

    bool neg=0;
    int res=0;
    while((X[i])!=' '){

            if(X[i]=='-'){neg=1;i++; continue;}
            res+=X[i]-'0'; if(X[i+1]!=' '){res*=10;  } i++;

            }
    neg?res*=-1:neg;
    ans.push_back(res);
    res=0;
}


return ans;
}

/**************************Bisho_O*****************************************/
int main() {

fast();

string X,Y;
while(getline(cin,X))
{


getline(cin,Y);
X+=' ';
Y+=' ';
c=convert__(X);
x=convert__(Y);
int n=c.size()-1;

for(int i=0;i<x.size();i++){

    ll res=0;

    for(int j=0;j<c.size();j++){


        res+=c[j]*(ll)pow(x[i],n-j);


    }


    cout<<res<<(i<(x.size()-1)?' ':'\n');
}


}
return 0;
}
