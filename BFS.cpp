#include<bits/stdc++.h>
#include <iostream>
using namespace std;

 
#define all(v)              ((v).begin()), ((v).end())
#define sz(v)               ((int)((v).size()))
#define clr(v, d)           memset(v, d, sizeof(v))
#define rep(i, v)       for(int i=0;i<sz(v);++i)
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)    for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)    for(int i=(j);i>=(int)(n);--i)
 
typedef long long         ll;
const int OO = (int)1e6;
const double EPS = (1e-7);
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }
 
#define pb                  push_back
#define MP                  make_pair
#define P(x)                cout<<#x<<" = { "<<x<<" }\n"
typedef long double       ld;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
typedef vector< vd >      vvd;
typedef vector<string>    vs;

vector<int> BFS(int start, vector<vector<int>>& adj)
{
	vector<int>len(sz(adj),OO);
	//this queue for nodes in current depth
	queue<int>curDepth; 
	curDepth.push(start) ,len[start]=0;
	int depth=0,current=start,queueSize=1;
	
	for(;!curDepth.empty();++depth,queueSize=curDepth.size())
	{
		while(queueSize--)
		{
			current=curDepth.front(),curDepth.pop();
			for(int i=0;i<adj[current].size();++i)
			{
				if(len[adj[current][i]]==OO)
				{
					curDepth.push(adj[current][i]);
					len[adj[current][i]]=depth+1;
				}
			}
			
		}
	}
	
	return len;
}
int main() {
    int n, e;
    cin>>n>>e;
 
    vector<vector<int> > adj(n);
 
    lp(i, e) {
        int from, to;
        cin>>from>>to;
        adj[from-1].push_back(to-1);
    }
    
    vector<int>pp=BFS(0,adj);
    rep(i,pp)
    cout<<pp[i]<<" ";
	return 0;
}
