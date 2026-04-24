import java.util.*;

class Info{
    int y,x,cost;
    Info(int a, int b, int c){
        y=a;
        x=b;
        cost=c;
    }
};

class Solution {
    int[] dy = {0,0,-1,1};
    int[] dx = {-1,1,0,0};
    int[] dy8 = {-1,-1,-1,0,0,1,1,1};
    int[] dx8 = {-1,0,1,-1,1,-1,0,1};
    
    int[][] board = new int[105][105];
    boolean[][] visited = new boolean[105][105];
    
    boolean pass(int y, int x){
        return 0<=y&&y<105 && 0<=x&&x<105;
    }
    
    void dfs(int y, int x){
        visited[y][x] = true;
        
        for(int i=0;i<8;i++){
            int yy = y + dy8[i];
            int xx = x + dx8[i];
            if(pass(yy,xx) && board[yy][xx] == 1) board[yy][xx] = 2;
        }
        for(int i=0;i<4;i++){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(!pass(yy,xx) || visited[yy][xx]) continue;
            
            if(board[yy][xx] == 0) dfs(yy,xx);
            
        }
    }
    
    
    int bfs(int sy, int sx, int ey, int ex){
        Queue<Info> q = new ArrayDeque<Info>();
        visited = new boolean[105][105];
        q.offer(new Info(sy,sx,0));
        
        while(!q.isEmpty()){
            Info now = q.peek(); q.poll();
            
            if(now.y == ey && now.x == ex) return now.cost;
            
            for(int i=0;i<4;i++){
                int yy = now.y + dy[i];
                int xx = now.x + dx[i];
                if(!pass(yy,xx) || board[yy][xx] != 2) continue;
                if(!visited[yy][xx]){
                    visited[yy][xx] = true;
                    q.offer(new Info(yy,xx,now.cost + 1));
                }
            }
        }
        return -1;
    }
    
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        
        //렉탱글 내부 색칠
        for(int[] r: rectangle){
            int x1 = r[0]*2;
            int y1 = r[1]*2;
            int x2 = r[2]*2;
            int y2 = r[3]*2;
            
            for(int y=y1;y<=y2;y++){
                for(int x=x1;x<=x2;x++){
                    board[y][x] = 1;
                }
            }
        }
        dfs(0,0); //플러드필로 경계 찾기

        
        // for(int i=0;i<55;i++){
        //     for(int j=0;j<55;j++){
        //         System.out.print(board[i][j]);
        //     }
        //     System.out.println();
        // }
        int answer = bfs(characterY*2, characterX*2, itemY*2, itemX*2) / 2;
        return answer;
    }
}