import java.util.*;

class Solution {
    public int[] solution(int n, long left, long right) {
        int[] answer = {};
        List<Integer> a = new ArrayList<>();
        
        for(long i=left;i<=right;i++){
            long y = i / n + 1;
            long x = i % n + 1;
            a.add((int)Math.max(y,x));
        }
        
        return a.stream().mapToInt(i->i).toArray();
    }
}