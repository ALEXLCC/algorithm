#include<stdio.h>
#define N 1000
int dp[N][N];
max(a,b){
    return a<b?b:a;
}
solve(char* str1,int len1,char* str2,int len2){
    int i=0;
    int j=0;
    for(i=0;i<len1;++i){
        for(j=0;j<len2;++j){
            if(str1[i]==str2[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }else{
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    return dp[len1][len2];
}
main(){
    char str1[N],str2[N];
    gets(str1);
    gets(str2);
    printf("%d\n",solve(str1,strlen(str1),str2,strlen(str2)));
    getchar();
}
