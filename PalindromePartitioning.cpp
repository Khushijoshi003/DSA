#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  bool isValid(string temp){
      int i=0,j=temp.size()-1;
      while(i<=j){
          if(temp[i]!=temp[j]){
              return false;
          }
          i++,j--;
      }
      return true;
  }
    void func(int ind,string &s,vector<string>&res,vector<vector<string>>&ans){
        if(ind==s.size()){
            ans.push_back(res);
            return;
        }
        string temp="";
        for(int i=ind;i<s.size();i++){
            temp+=s[i];
            if(isValid(temp)){
                res.push_back(temp);
                func(i+1,s,res,ans);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>>ans;
        vector<string>res;
        func(0,S,res,ans);
        return ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    
cout << "~" << "\n";
}
    return 0;
}