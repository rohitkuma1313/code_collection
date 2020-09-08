#include <iostream>
#include <vector>
using namespace std;
long long int getperiod(long long int n,long int m){
    vector<long int> storemod;
    storemod.push_back(0);
    storemod.push_back(1);
    for(long long int i=2;i<=n;i++){
        storemod.push_back((storemod[i-1]+storemod[i-2])%m);
        if(storemod[i]==1 && storemod[i-1]==0){
            return i-1;
        }
    }
}
long long int fib1(long long int n,long long int m) {
    if (n <= 1)
        return n;

    long long int previous = 0;
    long long int current  = 1;

    for (long long int i = 0; i < n - 1; ++i) {
        long long int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
    }

    return current ;
}

int main(){
    long long int n,m;
    cin>>n>>m;
    long long int period1= getperiod(n,m);
    long long int reduced_n= (long long)n%period1;
    cout<<fib1(reduced_n,m);
    return 0;
}
