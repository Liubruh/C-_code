/*
    ���������⣺
        1.ö�ٷ�����
        2. ���-��ֹ�ظ�����
        3. ������ǰ��
        4. ������һ��ȥ������һ������
        5. ����
        6. ��ֹ����
        7. �ظ��Լ�֦
*/
#include<bits/stdc++.h>
using namespace std;
int n;
bool vis[31];
int ans[31]; // �����洢ÿ�����
bool flag; // �����ж��Ƿ�������

// �ж��Ƿ�Ϊ���� - ʹ���Ż������� sqrt(n)
bool isPrime(int num){
    if(num<=1) return false;
    int limit = sqrt(num);
    for(int i = 2;i<=limit;i++){
        if(num%i == 0) return false;
    }
    return true;
}

void dfs(int dep){
    ans[0] = 0;
    // 6. ��ֹ����
    if(dep == n+1){
        for(int i = 1;i<=dep;i++){
            printf("%d ",ans[i]);
        }
        return ;
    }
    
    // 1. ö�ٷ�������
    for(int i = 1;i<=n;i++){
        // 2. ��� - ��ֹ�ظ�����
        if(!vis[i]){
            vis[i] = 1;
            // 3. ������ǰ��
            ans[dep] = i;
            int tmp = ans[dep] + ans[dep-1];
            if(isPrime(tmp)){ // ������������ĺ�Ϊ����ʱ������һ��
                // 4. ������һ��������һ������
                dfs(dep+1);
            }
            // 5. ����
            vis[i] = 0;
        }
    }
}

int main(){
    cin>>n;
    dfs(1);
    return 0;
}