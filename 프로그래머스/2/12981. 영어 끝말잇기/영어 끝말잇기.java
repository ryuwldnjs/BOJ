import java.util.*;

class Solution {
    Set<String> s = new HashSet<>();
    char last;
    
    public int[] solution(int n, String[] words) {
        int[] answer = {0,0};
        last = words[0].charAt(0);
        
        for(int i=0;i<words.length;i++){
            String word = words[i];
            if(word.charAt(0) != last || s.contains(word)){
                answer = new int[]{i%n + 1, i/n + 1};
                break;
            }
            s.add(word);
            last = word.charAt(word.length() - 1);
        }
        return answer;
    }
}