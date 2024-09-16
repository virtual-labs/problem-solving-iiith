	
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
#include<fstream>
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
int main(int argc,char **argv){

	fstream inp;
	inp.open(argv[1],ios::in);
	inp.seekg(-2,ios::end);
	char ch;string s;int n_lines=20;
	while(inp){
		inp.get(ch);
		inp.seekg(-2,ios::cur);
		if(ch=='\n')
			n_lines--;
		if(!n_lines)
			break;
		s.pb(ch);
	}
	reverse(all(s));
	cout<<s<<endl;
	inp.close();

return EXIT_SUCCESS;
}




























