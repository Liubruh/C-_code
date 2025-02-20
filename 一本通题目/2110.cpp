/*
    素数环问题：
        1.枚举方案数
        2. 标记-防止重复搜索
        3. 搜索当前层
        4. 进入下一层去搜索下一个方案
        5. 回溯
        6. 终止条件
        7. 重复性剪枝
*/
#include<bits/stdc++.h>
using namespace std;
int n;
bool vis[31];
int ans[31]; // 用来存储每层的数
bool flag; // 用来判断是否是素数

// 判断是否为素数 - 使用优化遍历法 sqrt(n)
bool isPrime(int num){
    if(num<=1) return false;
    int limit = sqrt(num);
    for(int i = 2;i<=limit;i++){
        if(num%i == 0) return false;
    }
    return true;
}

void dfs(int dep){
    
    // 6. 终止条件
    if(dep == n+1){
        if(isPrime(ans[n]+ans[1])){
            for(int i = 1;i<dep;i++){
                printf("%d",ans[i]);
                if(i<n) printf(" ");
            }
            printf("\n");
            exit(0); // 直接强制结束程序
        }
        return ;
    }
    
    // 重复性剪枝
    // 1. 枚举方案数：
    for(int i = 2;i<=n;i++){
        // 2. 标记 - 防止重复搜索
        if(!vis[i]){
            int tmp = ans[dep-1] + i;
            if(isPrime(tmp)){ // 如果是两个数的和为素数时，再下一行
                // 3. 搜索当前层
                vis[i] = 1;
                ans[dep] = i;
                int tmp = ans[dep] + ans[dep-1];
                // 4. 进入下一层搜索下一个方案
                dfs(dep+1);
            }
            // 5. 回溯
            vis[i] = 0;
        }
    }
}

int main(){
    scanf("%d",&n);
     // 剪枝：如果 n 是奇数，不可能构成素数环
     if (n % 2 == 1) {
        return 0;
    }
    ans[1] = 1;
    vis[1] = 1;
    dfs(2);
    // cout<<isPrime(3)<<endl;
    return 0;
}