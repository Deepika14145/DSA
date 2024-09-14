#include<iostream>
using namespace std;

int maxarr(int arr[], int n){
    int max = arr[0];
    for(int i= 1; i<n; i++){
        if(arr[i]> max)
        max = arr[i] ;
    }
    return max;
}

int minarr(int arr[], int n){
    int min = arr[0];
    for(int i= 1; i<n; i++){
        if(arr[i]< min)
        min = arr[i] ;
    }
    return min;
}

int main(){
    int arr[] = {22,34,1,3,12};
    int n = 5;
    cout<< "Max is: "<<maxarr(arr, n)<<endl;
    cout<< "Min is : "<<minarr(arr, n)<<endl;
    return 0;
}