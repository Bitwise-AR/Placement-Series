int solve(int i, int j, vector<int> &arr) {
    if(i >= j) return 0;
    int mini = 1e9;
    for(int k=i; k<=j-1; k++){
        int temp = arr[i-1]*arr[k]*arr[j] + solve(i, k, arr) + solve(k+1, j, arr);
        mini = min(mini, temp);
    }
    return mini;
}

int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    return solve(1, n-1, arr, dp);
}