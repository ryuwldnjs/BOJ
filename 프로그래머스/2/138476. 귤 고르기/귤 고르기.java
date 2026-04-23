import java.util.*;

class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        Integer[] cnt = new Integer[10000000+5];
        Arrays.fill(cnt, 0);
        
        for(int size : tangerine){
            cnt[size]++;
        }
        
        Arrays.sort(cnt, Collections.reverseOrder());
        
        int now = 0;
        for(int i=0; i<cnt.length;i++){
            now += cnt[i];
            if(now >= k) return i + 1;
        }
        return answer;
    }
}