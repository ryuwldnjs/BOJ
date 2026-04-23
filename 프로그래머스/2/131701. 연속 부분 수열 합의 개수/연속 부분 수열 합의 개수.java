import java.util.*;

class Solution {
    public int solution(int[] elements) {
        int answer = 0;
        // return answer;
        int n = elements.length;
        Set<Integer> s = new HashSet<>();
        //시작점
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += elements[j];
                s.add(sum);
            }
            for(int j=0;j<i;j++){
                sum += elements[j];
                s.add(sum);
            }
        }
        answer = s.size();
        return answer;
    }
    
}