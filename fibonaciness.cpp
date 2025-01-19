#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int a1, a2, a4, a5;
        cin>> a1 >> a2 >> a4 >> a5;
        
        int maxFiboness = 0;
        
        int a3 = a1 + a2;
        int fiboCount = 0;
        if(a3 == a1 + a2) fiboCount++;
        if(a4 == a2 + a3) fiboCount++;
        if(a5 == a3 + a4) fiboCount++;
        maxFiboness = max(maxFiboness, fiboCount);
        
        a3 = a4 - a2;
        fiboCount = 0;
        if(a3 == a1 + a2) fiboCount++;
        if(a4 == a2 + a3) fiboCount++;
        if(a5 == a3 + a4) fiboCount++;
        maxFiboness = max(maxFiboness, fiboCount);
        
        a3 = a5 - a4;
        fiboCount = 0;
        if(a3 == a1 + a2) fiboCount++;
        if(a4 == a2 + a3) fiboCount++;
        if(a5 == a3 + a4) fiboCount++;
        maxFiboness = max(maxFiboness, fiboCount);
        
        cout<<maxFiboness<<endl;
        
    }
    return 0;
}
