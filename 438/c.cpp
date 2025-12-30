#include<bits/stdc++.h>
const int N=2e5+10;
using PII=std::pair<int,int>;
int a[N];
int main(){
    int n;
    std::cin>>n;
    std::stack<PII>d;
    int x;
    for(int i=1;i<=n;i++){
        std::cin>>x;
        if(d.empty()){
            d.push({x,1});
        }
        else{
            if(d.top().first==x){
                d.push({x,d.top().second+1});
            }
            else{
                d.push({x,1});
            }
        }
        if(d.top().second==4){
            int num=0;
            while(num<4){
                d.pop();
                num++;
            }
        }
    }
    std::cout<<d.size();
    return 0;
}