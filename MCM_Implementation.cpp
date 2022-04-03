#include<bits/stdc++.h>
using namespace std;

int dp[101][101];
    int matrixMultiplication(int arr[], int i, int j){
        int mini = INT_MAX;
        if(i >= j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        for(int k = i; k < j; k++){
            int tempans = matrixMultiplication(arr, i, k) + matrixMultiplication(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
            mini = min(mini, tempans);
        }
        dp[i][j] =  mini;
        return dp[i][j];
    }
int main(){
    memset(dp, -1, sizeof(dp));
    int N;
    cin >> N;

    int arr[N];
    for (int a = 0; a < N; ++a)
    {
        cin >> arr[a];
    }


    
    int i = 1;
    int j = N - 1;
        
    cout<<matrixMultiplication(arr, i, j)<<'\n';

}