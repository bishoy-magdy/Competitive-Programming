#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<list>
#include<bits/stdc++.h>
#include <algorithm>
#include <algorithm>
#include<vector>
#include<set>
#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>
#include<queue>
#define pr pair<int,int>
#define OO (int)1e6
#define ll  long long
#define ln  cout<<'\n';

using namespace std;
void BISHOY(){ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);}


int X[8]={2,2,-1,1,-2,-2,-1,1};
int Y[8]={-1,1,2,2,1,-1,-2,-2};
int BFS(int xx,int xy,int yx,int  yy)
{
int distance[8][8];
memset(distance,-1,sizeof distance);
queue<int>q;
q.push(xx);
q.push(xy);
distance[xx][xy]=0;
int cx,cy;


while(!q.empty())
{

    cx=q.front(),q.pop();
    cy=q.front(),q.pop();

    if(cx==yx && cy==yy){return distance[yx][yy];}

    for(int i=0;i<8;i++)
    {
        int nx=X[i]+cx,ny=Y[i]+cy;

        if(nx>=0 && ny>=0 && nx<=7 && ny<=7 && distance[nx][ny]==-1){ distance[nx][ny]=distance[cx][cy]+1;q.push(nx);q.push(ny); }


    }


}


}


int main(){

/******online judge****/
/*
freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
*/
/*************************/

BISHOY();
char a,b;
int A,B;
string S1,S2;
while(cin>>S1>>S2 && S1.size()==2&& S2.size()==2)
{
a=S1[0];
A=S1[1]-'0';
b=S2[0];
B=S2[1]-'0';


		printf("To get from %s to %s takes %i knight moves.\n", S1.c_str(), S2.c_str(), BFS(a-'a',A-1,b-'a',B-1));

}


return 0;
}

