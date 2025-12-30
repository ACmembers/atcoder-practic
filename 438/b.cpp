/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-12-29 13:45:23
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-12-29 13:56:14
 * @FilePath: \算法竞赛\acm\atcoder\abc\438\b.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
const int N=105;
int a[N],b[N];
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n,m;
    std::cin>>n>>m;
    std::string s,t;
    std::cin>>s>>t;
    int ans=0;
    int minn=1e7;
    for(int i=0;i<=n-m;i++){
       int sum=0;
       for(int j=0;j<m;j++){
          int t1=s[i+j]-'0';
          int t2=t[j]-'0';
          if(t1==t2){
             continue;
          }
          if(t1>t2){
            sum+=t1-t2;
          }
          else{
             sum+=10-t2+t1;
          }
       }
       minn=std::min(minn,sum);
    }
    std::cout<<minn<<'\n';
    return 0;
}