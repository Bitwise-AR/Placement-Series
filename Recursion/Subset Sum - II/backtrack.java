public class backtrack{
    private void helper(int index, int[] nums, List<Integer> sub, List<List<Integer>> res) {
        res.add(new ArrayList<>(sub));

        for (int i = index; i < nums.length; i++) {
            if (i != index && nums[i] == nums[i - 1]) continue;
            sub.add(nums[i]);
            helper(i + 1, nums, sub, res);
            sub.remove(sub.size() - 1);
        }
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> sub = new ArrayList<>();

        Arrays.sort(nums);
        helper(0, nums, sub, res);
        return res;
    }
}