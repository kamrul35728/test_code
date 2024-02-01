#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> g[100];
vector<pair<int,int>> t[100];
int vis[100];
bool checkcycle(int src,int par=-1){
     vis[src]=1;
     for(auto child:t[src]){

         if(vis[child.first]&&child.first==par) continue;
         if(vis[child.first]){
            return true;
         }
         checkcycle(child.first,src);
     }
     return false;
} 
void tree(multimap<int,pair<int,int>> &mp,int &src){
      for(auto it=mp.begin();it!=mp.end();it++){
        int w=it->first;
        int u=it->second.first;
        
        int v=it->second.second;
        t[u].push_back({v,w});
        t[v].push_back({u,w});
        bool flag=checkcycle(src);
         if(flag){
            t[u].pop_back();
            t[v].pop_back();
         }
      }
}
int main(){
    int n,e;
    cin>>n>>e;
    multimap<int,pair<int,int>> mp;
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
        mp.insert({w,{x,y}});        
    }
    auto it=mp.begin();
    int u=it->second.first; 
    tree(mp,u);
    return 0;
}