#include<iostream>
using namespace std;

void rotate_arr(int arr[], int n){
    int temp1 = arr[n-3];
    int temp2 = arr[n-2];
    int temp3 = arr[n-1];

    for(int i = n-1; i >= 3; i--){
        arr[i] = arr[i-2];
    }
    arr[0] = temp1;
    arr[1] = temp2;
    arr[2] = temp3;
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