#include<bits/stdc++.h>
using namespace std;

int dp[2001][2001];
    bool isPalindrome(string &str, int i, int j)
    {
        
        while (j > i)
        {
            if (str[i++] != str[j--])
            {
                return false;
            }
        }
        return true;
        
    }
    
    int solve(string &s, int i, int j){
        
        if((i >= j) or (isPalindrome(s, i, j))){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int k = i; k < j; k++){
            if(isPalindrome(s, i, k)){
                int tempans = 1 + solve(s, k+1, j);
                mini = min(mini, tempans);
            }
        }
        return dp[i][j] =  mini;
    }
    int PalindromePartitioning(string s) {
        int i = 0;
        int j = s.length()-1;
        
        
        
        return solve(s, i, j);
    }
int main(){
    memset(dp, -1, sizeof(dp));
    string s;
    cin >> s;

    cout<<PalindromePartitioning(s)<<'\n';

}