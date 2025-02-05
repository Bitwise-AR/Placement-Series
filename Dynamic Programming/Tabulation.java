public class Tabulation {
    public int rob(int[] nums) {
        int p1 = 0, p2 = 0;

        for (int num : nums) {
            int current = Math.max(p1, p2 + num);
            p2 = p1;
            p1 = current;
        }
        
        return p1;
    }
}
