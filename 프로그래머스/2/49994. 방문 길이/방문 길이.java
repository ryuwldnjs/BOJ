import java.util.*;
class Solution {
    final int BIAS = 5;
    final int n = 10; //[0~10] 닫
    Map<Character, Integer> match = Map.of('U',0,'R',1,'D',2,'L',3);  
    int[] dy = {-1,0,1,0};
    int[] dx = {0,1,0,-1};
    int y=5;
    int x=5;
    
    boolean[][][] visited = new boolean[15][15][4];
    int answer = 0;
    
    boolean pass(int y, int x){
        return 0<=y&&y<=10 && 0<=x&&x<=10;
    }
    
    void move(char dir){
        int i = match.get(dir);
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(!pass(yy,xx)) return;
        
        if(!visited[y][x][i]){
            answer++;
            visited[y][x][i] = visited[yy][xx][(i+2)%4] = true;
        }
        y = yy;
        x = xx;
    }
    
    public int solution(String dirs) {
        
        for(int i=0;i<dirs.length();i++){
            char dir = dirs.charAt(i);
            move(dir);
        }
        return answer;
    }
}