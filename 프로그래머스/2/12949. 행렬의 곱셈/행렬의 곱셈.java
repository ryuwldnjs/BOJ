class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        int[][] answer = {};
        int a = arr1.length;
        int b = arr2.length;
        int c = arr2[0].length;
        answer = new int[a][c];
        for(int i=0;i<a;i++){
            for(int j=0;j<c;j++){
                for(int k=0;k<b;k++){
                    answer[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        return answer;
    }
}