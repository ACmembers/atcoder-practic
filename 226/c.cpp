/*
 * @Author: ACmember 2802862239@qq.com
 * @Date: 2025-12-30 14:25:49
 * @LastEditors: ACmember 2802862239@qq.com
 * @LastEditTime: 2025-12-30 14:40:11
 * @FilePath: \算法竞赛\acm\atcoder\abc\226\c.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
const int N=2e5+10;
int T[N],vis[N];
using LL=long long;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    memset(vis,false,sizeof(vis));
    std::cin>>n;
    std::vector<std::vector<int>>vec(n+1);
    for(int i=1;i<=n;i++){
       int l;
       std::cin>>T[i]>>l;
       int x;
       for(int j=1;j<=l;j++){
           std::cin>>x;
           vec[i].push_back(x);
       }
    }
    std::queue<int>q;
    LL ans=0;
    q.push(n);
    vis[n]=true;
    ans+=T[n];
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto x:vec[u]){
            if(vis[x]){
                continue;
            }
            ans+=T[x];
            vis[x]=true;
            q.push(x);
        }
    }
    std::cout<<ans<<'\n';
    return 0;
}