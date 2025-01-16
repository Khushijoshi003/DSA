
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void func(int ind,string &s,vector<string>&ans){
        if(ind==s.size()){
            ans.push_back(s);
            return;
        }
        unordered_set<char>mp;
        for(int i=ind;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
            mp.insert(s[i]);
            swap(s[i],s[ind]);
            func(ind+1,s,ans);
            swap(s[i],s[ind]);
            }
        }
    }
    vector<string> findPermutation(string &s) {
        vector<string>ans;
        func(0,s,ans);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
