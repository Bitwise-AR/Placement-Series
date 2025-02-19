class recursive {

    private int helper(int n, int capacity, int val[], int wt[], int i) {
        if (i >= n) return 0;
        if (capacity <= 0) return 0;

        int take = 0;
        int notTake = helper(n, capacity, val, wt, i + 1);

        if (capacity - wt[i] >= 0) {
            take = val[i] + helper(n, capacity - wt[i], val, wt, i);
        }

        return Math.max(take, notTake);
    }

    public int knapSack(int val[], int wt[], int capacity) {
        int n = val.length;
        return helper(n, capacity, val, wt, 0);
    }

}
