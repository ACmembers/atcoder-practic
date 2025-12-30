/*
 * @Author: ACmember 2802862239@qq.com
 * @Date: 2025-12-30 18:28:46
 * @LastEditors: ACmember 2802862239@qq.com
 * @LastEditTime: 2025-12-30 18:49:14
 * @FilePath: \算法竞赛\acm\atcoder\abc\438\e1.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
const int N=2e5+10;
using LL=long long ;
int a[N];
LL st[N][35],s[N][35];
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,q;
    std::cin>>n>>q;
    int x;
    for(int i=1;i<=n;i++){
        std::cin>>x;
        st[i][0]=x;
        s[i][0]=i;//水桶水量
    }
    for(int j=1;j<=32;j++){
        for(int i=1;i<=n;i++){
            int mid=st[i][j-1];
            st[i][j]=st[mid][j-1];
            s[i][j]=s[i][j-1]+s[mid][j-1];
        }
    }
    while(q--){
        int t,b;
        std::cin>>t>>b;
        LL sum=0;
        for(int k=0;k<=30;k++){
            if(t>>k&1){
                sum+=s[b][k];
                b=st[b][k];
            }
        }
        std::cout<<sum<<'\n';

    }
    return 0;
}