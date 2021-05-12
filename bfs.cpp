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
vector<int> bfs;

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
void bfsOfGraph(int n, vector<int> adj[]){
    vector<int> vis(n,0);
   
    for(int i=0;i<n;i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it:adj[node])
                {
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
    }
}


/*Write all function Definition Here */
void solve() { 
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    bfsOfGraph(n,adj);
    for(auto i:bfs){
        cout<<i+1<<" ";
    }

}