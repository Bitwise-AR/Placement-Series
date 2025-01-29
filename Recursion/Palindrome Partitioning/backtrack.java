public class backtrack{
    class Solution {
        public List<List<String>> partition(String s) {
            List<List<String>> res = new ArrayList<>();
            List<String> part = new ArrayList<>();
            helper(0, s, part, res);
            return res;
        }
    
        public void helper(int idx, String s, List<String> part, List<List<String>> res){
            if(idx == s.length()){
                res.add(new ArrayList<>(part));
                return;
            }
    
            for(int i = idx; i < s.length(); i++){
                if(isPalindrome(s, idx, i)){ 
                    part.add(s.substring(idx, i + 1)); 
                    helper(i + 1, s, part, res); 
                    part.removeLast(); 
                }
            }
        }
        
        public boolean isPalindrome(String s, int l, int r){
            while(l <= r){
                if(s.charAt(l++) != s.charAt(r--)) return false;
            }
            return true;
        }
    }
}