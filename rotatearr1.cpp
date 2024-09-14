#include<iostream>
#include<vector>
using namespace std;

void rotatearr(vector<int>&num, int n){
    int first = num[0];
    for(int i = 0; i < n; i++){
        num[i] = num[i+1];
    }
    //place first element to the last
    num[n-1] = first;
}

int main(){
    vector<int>num = {1,2,3,4,5};
    int n = 5;
    rotatearr(num, n);
    cout<<"After rotating:";
    for(int nums : num){
        cout << nums++ << " ";
    }
    cout<<endl;
    return 0;
}