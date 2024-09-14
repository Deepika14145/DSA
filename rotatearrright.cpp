#include<iostream>
using namespace std;

void rotate_arr(int arr[], int n){
    int temp = arr[n-1];
    for(int i = n-1; i>0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}
int main(){
    int arr[] = {2,4,55,3,6,4};
    int n = 6;
    rotate_arr(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}