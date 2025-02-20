#include<bits/stdc++.h>
using namespace std;
/*
    搜索与回溯：组合的输出
    input:
    5 3
    output:
    1  2  3
    1  2  4
    1  2  5
    1  3  4
    1  3  5
    1  4  5
    2  3  4
    2  3  5
    2  4  5
    3  4  5
*/
int n/*数字个数1-n*/,r/*要取的数据个数*/;
int ans[22]; // 数组
bool vis[22]; // 表示数组哪部分使用过

// 深搜树
void dfs(int dep){
    // 6. 终止条件
    if(dep == r+1){
        for(int i = 1;i<dep;i++){
            printf("%3d",ans[i]);
        } 
        printf("\n");
        return ;
    }

    // 1. 枚举方案数
    for(int i = 1;i<=n;i++){
        if(!vis[i]&&ans[dep-1]<i){
            // 2. 标记 - 防止重复搜索
            vis[i] = i;
            // 3. 搜索当前层
            ans[dep] = i;
            // 4. 搜索下一层
            dfs(dep+1);
            // 5. 回溯
            vis[i] = 0;
        }
    }

}

int main(){
    scanf("%d %d",&n,&r);
    // ans[1] = 1;
    // vis[1] = 1;
    dfs(1);
    return 0;
}