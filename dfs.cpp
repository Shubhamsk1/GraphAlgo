/* Code by shubhamsk1 */
/* Shubham S Kudekar */
#include<bits/stdc++.h>
#define int long long
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define endl "\n"
#define N 10000007
using namespace std;
int fme(int a,int b){
int res=1;
while(b>0){
if(b&1){
res=(res*a)%N;
}
a=(a*a)%N;
b=b>>1;
}
return res;
}
/*Declare function prototypes here*/
void solve();



/*Declare Global variables here*/



/* Main function starts from here */
int32_t main() { 
/*Fast IO*/ 
ios_base::sync_with_stdio(false);cin.tie(NULL);

/*Input-output file creation*/
#ifndef ONLINE_JUDGE 
freopen("input.txt", "r", stdin); 
freopen("error.txt", "w", stderr); 
freopen("output.txt", "w", stdout);
#endif

int t=1; 

/*is Single Test case?*/cin>>t;
while(t--)
{ 
solve(); 
cout<<"\n";
}
cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;

return 0;
} 
/*Main function Ends */
bool allvisted(vector<int> visited){
    for(auto i:visited)
        if(i==0) return false;
    return true;
}
void dfsOfGraph(int node,vector<int> adj[],vector<int>&dfs,vector<int>&vis){
    dfs.push_back(node+1);
    vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]){
            dfsOfGraph(i,adj,dfs,vis);
        }
    }
}


/*Write all function Definition Here */
void solve() { 
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for0(i,m){
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    vector<int> dfs;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i])
            dfsOfGraph(i,adj,dfs,vis);
    }
    for(auto i:dfs)
        cout<<i<<" ";

}