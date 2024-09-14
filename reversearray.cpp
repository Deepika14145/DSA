#include<iostream>
using namespace std;
//using loop
void reverseArray(int arr[], int n){
    for(int i=0; i< n/2; i++){
        swap(arr[i], arr[n-1]);
        // int temp = arr[i];
        // int arr[i] = arr[n-1];
        // arr[n-1] = temp;
    }
}
int main(){
    int arr[] = {22, 31, 1, 54, 65, 0};
    int n = 6;
    reverseArray(arr, n);
    //reversed array
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" "<<endl;
        }

    return 0;    
}