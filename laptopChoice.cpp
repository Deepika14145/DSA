#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    
    while(T--){
        int N;
        cin>>N;
        
        int freq[11] = {0};

        for(int i = 0; i <N; i++){
            int laptop;
            cin>>laptop;
            freq[laptop]++;
        }
        int maxFreq = *max_element(freq + 1, freq + 11);
        
        int count = 0;
        int result = -1;
        for(int i=1; i<= 10; i++){
            if(freq[i] == maxFreq){
                count++;
                result = i;
            }
        }
        if(count == 1){
            cout<<result <<endl;
        }else{
            cout<<"CONFUSED"<<endl;
        }
        
    }
    return 0;
    
}
