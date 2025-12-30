/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-12-29 14:10:24
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-12-29 14:48:35
 * @FilePath: \算法竞赛\acm\atcoder\abc\438\d.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
const int N=3e5+10;
using namespace std;
using LL=long long;
struct ST{
    const int n,k;
    vector<LL>in1,in2;
    vector<vector<LL>>Max,Min;
    ST(int n):n(n),in1(n+1),in2(n+2),k(log2(n)){
       Max.resize(k+1,vector<LL>(n+1));
       Min.resize(k+1,vector<LL>(n+1));
    }
    void init(){
        for(int i=1;i<=n;i++){
            Max[0][i]=in1[i];//对于本身的一个区间
            Min[0][i]=in2[i];
        }
    //k代表的是倍增区间(可供倍增区间)
    for(int i=0,t=1;i<k;i++,t<<=1){
        const int T=n-(t<<1)+1;//代表的是可用的一个区间
        for(int j=1;j<=T;j++){
            Max[i+1][j]=max(Max[i][j],Max[i][j+t]);
            Min[i+1][j]=min(Min[i][j],Min[i][j+t]);
        }
    }
}
    LL getMax(int l,int r){
        if(l>r){
            swap(l,r);
        }
        int k=log2(r-l+1);//获取目标区间的长度
        return max(Max[k][l],Max[k][r-(1<<k)+1]);
    }
    LL getMin(int l,int r){
        if(l>r){
            swap(l,r);
        }
        int k=log2(r-l+1);
        return min(Min[k][l],Min[k][r-(1<<k)+1]);
    }
};
using LL=long long ;
LL a[N],b[N],c[N];
LL sum[N],num[N],kem[N];
const LL MAXN=1e15;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin>>n;
    sum[0]=0,num[0]=0,kem[0]=0;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        std::cin>>b[i];
        num[i]=num[i-1]+b[i];
    }
    for(int i=1;i<=n;i++){
        std::cin>>c[i];
        kem[i]=kem[i-1]+c[i];
    }
    LL MINX=-MAXN;
    ST d(n);
    for(int i=1;i<=n;i++){
        LL suy=num[i]-kem[i];
        d.in1[i]=suy;
    }
    LL MINS=-MAXN;
    d.init();
    for(int i=1;i<n-1;i++){
          LL ak=d.getMax(i+1,n-1);
          MINS=std::max(MINS,sum[i]-num[i]+ak);
    }
    std::cout<<MINS+kem[n]<<'\n';
    return 0;
}