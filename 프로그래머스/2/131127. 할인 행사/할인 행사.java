import java.util.*;
class Solution {
    Map<String, Integer> m = new HashMap<>();
    
    boolean able(String[] want, int[] number){
        for(int i=0;i<want.length;i++){
            if(m.getOrDefault(want[i], 0) < number[i]) return false;
        }
        return true;
    }
    
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        for(int i=0;i<10;i++){
            m.put(discount[i], m.getOrDefault(discount[i], 0) + 1);
        }
        
        int n = discount.length;
        
        if(able(want, number)) answer++; 
        for(int i=10;i<n;i++){
            m.put(discount[i], m.getOrDefault(discount[i], 0) + 1);
            m.put(discount[i-10], m.getOrDefault(discount[i-10], 0) - 1);
            if(able(want, number)) answer++; 
        }
        return answer;
    }
}