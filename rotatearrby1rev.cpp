#include<iostream>
using namespace std;

void rotate_arr(int arr[], int n){
    int temp = arr[0];
    for(int i = 0; i< n-1; i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
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