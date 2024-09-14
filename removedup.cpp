#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

vector<int> removeDup(const vector<int>& arr){
    unordered_set <int> set;
    vector<int> result;
    
    for(int elem : arr){
        if(set.insert(elem).second){
            result.push_back(elem);
        }
    }
    return result;
}

int main(){
    vector<int> arr = {1,1,2,2,4,4,5};

    vector<int> result = removeDup(arr);
    cout<<"The array after removing duplicates is: "<<endl;
    for(int elem : result){
        cout<<elem<<" ";
    } 
    cout<<endl;
    return 0;
}