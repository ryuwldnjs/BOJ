import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int m = sc.nextInt();

        if(m-45 < 0) h--;
        if(h < 0) h = 23; //0시보다 일찍 맞출땐 23시로 넘어감

        m = (m-45+60) % 60; // 45분을 빼고 모듈러

        System.out.print(h + " " + m);
    }
}
