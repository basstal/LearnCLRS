#include <math.h>
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <utility>
#include <functional>
/**
计算算法复杂度随时间增长的处理数量级n变化

*/
using namespace std;

long long nlognbase2(long long l){
    static long long n = 1;
    while(n * log2(n) < l){
        ++n;
        if(n % 100 == 0)
            printf("%lld  ",n);
    }
    if(n * log2(n) == l)
        return n;
    return n - 1;
}

long long npow2(long long l){
    static long long n = 1;
    while(pow(n,2) < l)
        ++n;
    if(pow(n,2) == l)
        return n;
    return n - 1;
}

long long npow3(long long l){
    static long long n = 1;
    while(pow(n,3) < l)
        ++n;
    if(pow(n,3) == l)
        return n;
    return n - 1;
}

long long twopown(long long l){
    static long long n = 1;
    while(pow(2,n) < l)
        ++n;
    if(pow(2,n) == l)
        return n;
    return n - 1;
}

long long nfractorial(long long l){
    static long long sum = 1;
    static long fractorial = 1;
    while(sum < l){
        ++fractorial;
        sum *= fractorial;
    }
    if(sum == l)
        return fractorial;
    return fractorial - 1;
}

int main(){
    long long s = 1000,min = 60000,hour = 3600000,day = 86400000, month =2592000000, year=31104000000,centary = 3110400000000;
    map<string,function<long long(long long)>> cal = {
        {"nlognbase2",nlognbase2},
        // {"npow2",npow2},
        // {"npow3",npow3},
        // {"twopown",twopown},
        // {"nfractorial",nfractorial}
    };

    for(pair<string,function<long long(long long)>> f : cal){
        cout<<f.first<<endl;
        printf("%lld\n",cal[f.first](s));
        printf("%lld\n",cal[f.first](min));
        printf("%lld\n",cal[f.first](hour));
        printf("%lld\n",cal[f.first](day));
        printf("%lld\n",cal[f.first](month));
        printf("%lld\n",cal[f.first](year));
        printf("%lld\n",cal[f.first](centary));
    }
}

