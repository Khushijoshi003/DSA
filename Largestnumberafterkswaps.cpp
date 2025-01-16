#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void func(int ind,string &s,string &res,int k){
        if(k==0 || ind==s.size()-1){
            return;
        }
        char maxi=*max_element(s.begin()+ind+1,s.end());
        for(int i=ind+1;i<s.size();i++){
            if(s[i]>s[ind] && s[i]==maxi){
                swap(s[ind],s[i]);
                if(s.compare(res)>0) res=s;
                func(ind+1,s,res,k-1);
                swap(s[ind],s[i]);
            }
        }
        func(ind+1,s,res,k);
    }
    string findMaximumNum(string& s, int k) {
        string res=s;
        func(0,s,res,k);
        return res;
    }
};

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
