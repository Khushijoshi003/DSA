
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void func(int n,vector<int>&ans,vector<int>&res){
        if(n==0){
            int sum=0;
            for(int i=0;i<res.size();i++){
                sum=sum*10+res[i];
            }
            ans.push_back(sum);
            return;
        }
        for(int i=1;i<=9;i++){
            if(res.empty() || i>res[res.size()-1]){
                res.push_back(i);
                func(n-1,ans,res);
                res.pop_back();
            }
        }
    }
    vector<int> increasingNumbers(int n) {
        vector<int>ans;
        if(n==1){
            for(int i=0;i<=9;i++){
                ans.push_back(i);
            }
            return ans;
        }
        vector<int>res;
        func(n,ans,res);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
