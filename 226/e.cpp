/*
 * @Author: ACmember 2802862239@qq.com
 * @Date: 2025-12-30 14:41:27
 * @LastEditors: ACmember 2802862239@qq.com
 * @LastEditTime: 2026-01-01 20:02:13
 * @FilePath: \算法竞赛\acm\atcoder\abc\226\e.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using u128 = unsigned __int128;
#define int long long 
i64 qpow(i64 x,i64 p){
    i64 r=1;
    while(p){
        if(p&1){
            r=r*x%998244353;
        }
        x=x*x%998244353;
        p>>=1;
    }
    return r;
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,m;
    std::cin>>n>>m;
    int u,v;
    std::vector<std::vector<int>>adj(n+1);
    std::vector<int>vis(n+1,false);
    std::vector<int>count(n+1);
    std::vector<int>cnt(n+1,0);
    auto dfs=[&](auto &&self,int u,int s)->void{
        vis[u]=true;
        count[s]+=1;
        for(auto v:adj[u]){
            if(!vis[v]){ 
                self(self,v,s);
            }
            cnt[s]+=1;;
        }
    };
    for(int i=1;i<=m;i++){
        std::cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    i64 ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(dfs,i,i);
        if(count[i]!=cnt[i]/2){
            std::cout<<0<<'\n';
            return 0;
        }
        ans++;
      }
    }
    if(ans==0){
        std::cout<<0<<'\n';
        return 0;
     }
    
    std::cout<<qpow(2,ans)<<'\n';
    return 0;
}