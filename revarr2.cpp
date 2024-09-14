#include<iostream>
#include<algorithm>

using namespace std;
//using st
int main(){
    int arr[] = {22, 31, 1, 54, 65, 0};
    int n = 6;
    reverse(arr, arr + n);
    //reversed array
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" "<<endl;
        }

    return 0;    
}