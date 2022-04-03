#include<bits/stdc++.h>
using namespace std;

    unordered_map<string, bool> mp;
bool solve(string a, string b){
        if(a.compare(b) == 0){
            return true;
        }
        if(a.length() <= 1){
            return false;
        }
        string key = a;
        key.push_back(' ');
        key.append(b);
        
        if(mp.find(key) != mp.end()){
            return mp[key];
        }
        int n = a.length();
        bool flag = false;
        for(int i = 1; i< n; i++){
            bool cond1 = solve(a.substr(0, i), b.substr(n-i, i)) and solve(a.substr(i, n-i), b.substr(0, n-i));
            bool cond2 = solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i));
            if(cond1 or cond2){
                flag = true;
                break;
            }
        }
        return mp[key] = flag;
    }
    bool isScramble(string s1, string s2) {
        
        if(s1.length() != s2.length()){
            return false;
        }
        if(s1.length() == 0 and s2.length() == 0){
            return true;
        }
        mp.clear();
        return solve(s1, s2);
}
int main(){
    string s1, s2;
    cin >> s1 >> s2;

    cout<<isScramble(s1, s2)<<'\n';

}