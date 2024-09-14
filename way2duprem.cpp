#include<iostream>
#include<vector>
using namespace std;

bool contains(const vector<int>& arr, int value){
    for(int num : arr){
        if(num == value){
            return true;
        }
    }
    return false;
}

vector<int>removeDup(vector<int>&arr){
    vector<int> unique_ele;

    for(int num : arr){
        if(!contains(unique_ele, num)){
            unique_ele.push_back(num);
        }
        }
        return unique_ele;
    }


int main(){
    vector<int> arr = {1,3,4,5,5,3,7,7,7};
    vector<int> result = removeDup(arr);
    cout<<"The array after removing duplicates: "<<endl;
    for(int num : result){
        cout<<num<<" ";
    }
    cout << endl;
    return 0;
    
}