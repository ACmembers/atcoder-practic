/*
 * @Author: ACmember 2802862239@qq.com
 * @Date: 2025-12-30 14:41:13
 * @LastEditors: ACmember 2802862239@qq.com
 * @LastEditTime: 2025-12-30 15:24:04
 * @FilePath: \算法竞赛\acm\atcoder\abc\226\d.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
const int N=505;
int x[N],y[N];
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::set<std::pair<int,int>>q;
    int n;
    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::cin>>x[i]>>y[i];
    }
    for(int i=1;i<=n;i++){
        int dx=x[i],dy=y[i];
        for(int j=i+1;j<=n;j++){
            int px=x[j]-x[i],py=y[j]-y[i];
            int tx=gcd(px,py);
            px/=tx,py/=tx;
            q.insert({px,py});
        }
    }
    std::cout<<q.size()*2<<'\n';
    return 0;
}