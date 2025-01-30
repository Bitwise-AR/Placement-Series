class Solution {
    public ArrayList<String> findPath(ArrayList<ArrayList<Integer>> mat) {
        
        ArrayList<String> res = new ArrayList<>();
        // boolean [][] visited = new boolean [mat.size()][mat.size()];
        helper(0, 0, mat, res, "");
        return res;
        
    }
    
    private void helper(int row, int col, ArrayList<ArrayList<Integer>> mat, ArrayList<String> res, String path){
        
        if(row < 0 || row == mat.size() || col < 0 || col == mat.size() || mat.get(row).get(col) != 1 ){
            return;
        }
        
        if(row == mat.size() - 1 && col == mat.size() - 1){
            res.add(path);
        }
        
        mat.get(row).set(col, 0);;
        
        //DLRU
        
        //Down
        helper(row+1, col, mat, res, path+"D");
        //left
        helper(row, col-1, mat, res, path+"L");
        //Right
        helper(row, col+1, mat, res, path+"R");
        //Up
        helper(row-1, col, mat, res, path+"U");
        

        
        mat.get(row).set(col, 1);;
        
    }
}