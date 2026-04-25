class Solution {
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }
    
    int lcm(int a, int b){
        return a*b / gcd(a,b);
    }
    
    public int solution(int[] arr) {
        int answer = 1;
        for(int a: arr){
            System.out.println("" + answer + a + gcd(answer,a));
            answer = lcm(answer,a);
        }
        return answer;
    }
}