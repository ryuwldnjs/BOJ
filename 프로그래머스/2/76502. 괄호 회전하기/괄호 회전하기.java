import java.util.*;
class Solution {
    Map<Character, Character> match = Map.of(
        ')', '(',
        '}', '{',
        ']', '['
    );
    
    int solve(String s){
        Deque<Character> st = new ArrayDeque<>();
        
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == '[' || s.charAt(i) == '{' || s.charAt(i) == '('){
                st.push(s.charAt(i));
                continue;
            }
            //닫는괄호
            if(!st.isEmpty() && match.get(s.charAt(i)).equals(st.peek())) st.pop();
            else return 0;
        }
        
        return st.isEmpty()? 1 : 0;
    }
    
    public int solution(String s) {
        int answer = 0;
        
        for(int i=0;i<s.length();i++){
            String str = s.substring(i) + s.substring(0, i);
            answer += solve(str);
        }
        return answer;
    }
}