#include<iostream>
#include<set>
#include<vector>


int main(){
    std::vector<int> arr = {1, 3, 5, 6, 3, 2, 2, 7};
    std::set <int> orignalunique_set; //set
    std::vector<int> result;

//.end is point ing that no element found throught array after iteration
//  means the element is not present in the set.
    for(int num : arr){

        if(orignalunique_set.find(num) == orignalunique_set.end()){
            orignalunique_set.insert(num);
            result.push_back(num);
        }
    }
    for(int num : result){
        std::cout<<num<<" ";
    }
    return 0;
    
}

