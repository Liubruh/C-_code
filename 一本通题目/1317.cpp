#include<bits/stdc++.h>
using namespace std;
/*
    ��������ݣ���ϵ����
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
int n/*���ָ���1-n*/,r/*Ҫȡ�����ݸ���*/;
int ans[22]; // ����
bool vis[22]; // ��ʾ�����Ĳ���ʹ�ù�

// ������
void dfs(int dep){
    // 6. ��ֹ����
    if(dep == r+1){
        for(int i = 1;i<dep;i++){
            printf("%3d",ans[i]);
        } 
        printf("\n");
        return ;
    }

    // 1. ö�ٷ�����
    for(int i = 1;i<=n;i++){
        if(!vis[i]&&ans[dep-1]<i){
            // 2. ��� - ��ֹ�ظ�����
            vis[i] = i;
            // 3. ������ǰ��
            ans[dep] = i;
            // 4. ������һ��
            dfs(dep+1);
            // 5. ����
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