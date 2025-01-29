public class bruteForce{
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);

        HashSet<List<Integer>> result = new HashSet<>();
        result.add(new ArrayList<>());

        for (int num : nums) {
           HashSet<List<Integer>> newSubsets = new HashSet<>();
            for (List<Integer> sub : result) {
                List<Integer> newSub = new ArrayList<>(sub);
                newSub.add(num);
                newSubsets.add(newSub);
            }
            result.addAll(newSubsets);
        }

        return new ArrayList<>(result);
    }
}