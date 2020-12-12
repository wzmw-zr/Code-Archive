/*************************************************************************
	> File Name: 5.LeetCode1500.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年12月12日 星期六 18时09分36秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class FileSharing {
public:
    int cnt;
    vector<unordered_set<int>> files;
    unordered_map<int, vector<int>> mp;
    int max_ind;
    priority_queue<int, vector<int>, greater<int>> unused_id;

    FileSharing(int m) {
        cnt = m;
        for (int i = 0; i <= m; i++) files.push_back(unordered_set<int>());
        max_ind = 1;
        unused_id.push(1);
    }

    int join(vector<int> ownedChunks) {
        if (!unused_id.size()) unused_id.push(++max_ind);
        int id = unused_id.top();
        unused_id.pop();
        if (id == max_ind) unused_id.push(++max_ind);
        for (int x : ownedChunks) files[x].insert(id);
        mp[id] = ownedChunks;
        return id;
    }

    void leave(int userID) {
        for (int x : mp[userID]) {
            if (!files[x].count(userID)) continue;
            files[x].erase(files[x].find(userID));
        }
        mp.erase(mp.find(userID));
        unused_id.push(userID);
    }

    vector<int> request(int userID, int chunkID) {
        vector<int> ans;
        for (int x : files[chunkID]) ans.push_back(x);   
        sort(ans.begin(), ans.end());
        if (ans.size()) {
            files[chunkID].insert(userID);   
            mp[userID].push_back(chunkID);
        }
        return ans;
    }
};

int main() {
    return 0;
}
