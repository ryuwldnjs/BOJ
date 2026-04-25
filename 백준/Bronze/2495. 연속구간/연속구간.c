#include <stdio.h>
#include <string.h>
typedef struct stats{
    int left;
    int right;
    int max;
}stats;

int lsc(char *A, int p, int r);
stats lsc_solve(char *A, int p, int r);
int main(){
	char argv[10];
	int i;
	for(i=0;i<3;i++){
	scanf("%s", argv);
    int l = strlen(argv);
    
    printf("%d\n", lsc(argv, 0, l-1));
}
    return 0;
}
int lsc(char *A, int p, int r){

    stats answer = lsc_solve(A, p, r);

    return answer.max;

}

stats lsc_solve(char *A, int p, int r){
    stats tmp;
    if(r-p==0){ //한개짜리
        tmp.left = 1;
        tmp.right = 1;
        tmp.max = 1;
        return tmp;
    }
    int mid = (p+r)/2;
    stats n1 = lsc_solve(A, p, mid);
    stats n2 = lsc_solve(A, mid+1, r);

    if(A[mid]==A[mid+1]){ //갱신 가능성있을때
        int center = n1.right + n2.left;//중간에서 연속된  글자수
        if(n1.left==mid-p+1){//n1이 전부 같은 글자 일때
            n1.left = center;
        }
        if(n2.right==r-mid){ //n22가 전부 같은 글자 일때
            n2.right = center;
        }



        if(n1.max>n2.max){ //n1,center,n2 중 가장 긴 길이 찾기
            if(n1.max>center) tmp.max = n1.max;
            else tmp.max = center;
        }
        else{
            if(n2.max>center) tmp.max = n2.max;
            else tmp.max = center;
        }

    tmp.left = n1.left;
    tmp.right = n2.right;
    }
    else{ //갱신 가능성이 없을때
        tmp.left = n1.left;
        tmp.right = n2.right;
        tmp.max = n1.max>n2.max ? n1.max : n2.max;
    }

    return tmp;
}
        