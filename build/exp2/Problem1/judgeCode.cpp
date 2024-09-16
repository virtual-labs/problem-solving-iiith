
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<cmath>
#include<set>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<cassert>
#include<climits>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<int,int> ii;
typedef pair<int,ii> pii;
typedef long long LL;
#define sz(c) (int)c.size()
#define pb push_back
#define all(v) v.begin(),v.end()
#define inc(i,n) for(int i=0;i<n;i++)
#define dec(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define INF 100000000
#define F first
#define S second
int main(){
	string s;
	getline(cin,s);
	bool flag=1;
	for(int i=0,j=sz(s)-1;i<j;i++){
		if(!((s[i]>='a' && s[i]<='z') ||( s[i]>='A' && s[i]<='Z')))
			continue;
		
		while(j>i && !((s[j]>='a' && s[j]<='z') ||( s[j]>='A' && s[j]<='Z')))j--;

		if(!((s[j]==s[i]) or abs(s[j]-s[i])==32)){
			flag=0;
			break;
		}

		j--;
	}
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}

