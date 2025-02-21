vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
    int maxLIS = 1;
    int lastIndex = 0;
    vector<int> dp(n, 1);
    vector<int> parent(n, -1);
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
                parent[i] = j;
            }
        }
        if(dp[i] > maxLIS){
            maxLIS = dp[i];
            lastIndex = i;
        }
    }
    
    vector<int> lis;
    while(lastIndex != -1){
        lis.push_back(arr[lastIndex]);
        lastIndex = parent[lastIndex];
    }
    reverse(lis.begin(), lis.end());
    return lis;
}