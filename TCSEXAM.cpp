#include<iostream>
#include<vector>
using namespace std;

void detRank(const vector<int> &dragon, const vector<int>& sloth){
    int sumD = dragon[0] + dragon[1] + dragon[2];
    int sumS = sloth[0] + sloth[1] + sloth[2];
    
    if(sumD != sumS){
        cout<<(sumD > sumS ? "Dragon" : "Sloth") <<endl;
        return;
    }
    if(dragon[0] != sloth[0]){
        cout<<(dragon[0] > sloth[0] ? "Dragon" : "Sloth") <<endl;
        return;
    }
    if(dragon[1] != sloth[1]){
        cout<<(dragon[1] > sloth[1] ? "Dragon" : "Sloth") <<endl;
        return;
    }
    cout<<"Tie"<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        vector<int> dragon(3), sloth(3);
        for(int& score : dragon) cin>> score;
        for(int& score : sloth) cin >> score;
        detRank(dragon, sloth);
    }
    return 0;
}
