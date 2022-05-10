#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<list>
#include<bits/stdc++.h>
#include <algorithm>
#define ll  long long
#include <algorithm>
#include<vector>
#include<set>
#define ln '\n';
#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>
#define pr pair<int,int>
using namespace std;


void BISHOY(){ios_base::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);}

/*string  */
int main(){

/******online judge****/
/*
freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
*/
/*************************/

BISHOY();
int n;
cin>>n;
while(n--){
string s1,s2;
cin>>s1>>s2;
if(s1.size()<=s2.size()){swap(s1,s2);};
reverse(s1.begin(),s1.end());

int arr1[s1.size()+1],arr2[s1.size()+1];

memset(arr1,0,sizeof arr1);
memset(arr2,0,sizeof arr2);


int R=0;
for(int i=1;i<=s1.size();i++)
{
    arr1[i]=s1[R]-'0';
    R++;

}


for(int i=0;i<s2.size();i++)
{

    arr2[s1.size()-i]=s2[i]-'0';
}

/**************************************/

for(int i=s1.size();i>0;i--)
{

int T=arr1[i]+arr2[i];

if(T>9){arr1[i]=T%10; i--; arr1[i]++; i++; }

if(T<=9){arr1[i]=T;}

}


reverse(arr1,arr1+s1.size()+1);


int i=0;

while(arr1[i]==0)
{
    i++;
}
int E_ND=s1.size();

while(arr1[E_ND]==0)
{
    E_ND--;
}
for(i;i<=E_ND;i++)
{

    cout<<arr1[i];

}

cout<<endl;


}
return 0;
}
