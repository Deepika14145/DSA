// // class Solution {
// // public:
// //     vector<int> arrayRankTransform(vector<int>& arr) {
// //         vector<int> temp = arr;
// //         sort(temp.begin(), temp.end());

// //         unordered_map<int, int> mp;
// //         int rank = 1;

// //         for(int x : temp){
// //             if(mp.find(x) == mp.end())
// //                 mp[x] = rank++;
// //         }

// //         for(int &x : arr)
// //             x = mp[x];

// //         return arr;
// //     }
// // };

// class Solution {
// public:
//     vector<int> arrayRankTransform(vector<int>& arr) {
//         vector<int> temp = arr;
//         sort(temp.begin(), temp.end());

//         unordered_map<int, int> mp;
//         int rank = 1;

//         for (int x : temp) {
//             if (!mp.count(x))
//                 mp[x] = INT_MAX;

//             mp[x] = min(mp[x], rank);

//             if (mp[x] == rank)
//                 rank++;
//         }

//         for (int &x : arr)
//             x = mp[x];

//         return arr;
//     }
// };

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;

        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        unordered_map<int, int> mp;
        for (int i = 0; i < temp.size(); i++)
            mp[temp[i]] = i + 1;

        for (int &x : arr)
            x = mp[x];

        return arr;
    }
};