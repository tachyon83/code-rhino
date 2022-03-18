class Solution {

    List<List<Integer>> arr;
    List<Integer> per1;
    boolean[] visited;
    public List<List<Integer>> permute(int[] nums) {

        arr = new ArrayList<>();
        per1 = new ArrayList<>();

        permutations(nums,per1);

        return arr;

    }
    public void permutations(int[] nums, List<Integer> per){
        if(per.size() == nums.length){
            arr.add(new ArrayList<>(per));
        }
        for(int i : nums){
            if(!per.contains(i)) {
                per.add(i);
                permutations(nums,per);
                per.remove(per.size()-1);
            }
        }
    }
}