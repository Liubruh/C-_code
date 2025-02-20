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
    
    // 6. ��ֹ����
    if(dep == n+1){
        if(isPrime(ans[n]+ans[1])){
            for(int i = 1;i<dep;i++){
                printf("%d",ans[i]);
                if(i<n) printf(" ");
            }
            printf("\n");
            exit(0); // ֱ��ǿ�ƽ�������
        }
        return ;
    }
    
    // �ظ��Լ�֦
    // 1. ö�ٷ�������
    for(int i = 2;i<=n;i++){
        // 2. ��� - ��ֹ�ظ�����
        if(!vis[i]){
            int tmp = ans[dep-1] + i;
            if(isPrime(tmp)){ // ������������ĺ�Ϊ����ʱ������һ��
                // 3. ������ǰ��
                vis[i] = 1;
                ans[dep] = i;
                int tmp = ans[dep] + ans[dep-1];
                // 4. ������һ��������һ������
                dfs(dep+1);
            }
            // 5. ����
            vis[i] = 0;
        }
    }
}

int main(){
    scanf("%d",&n);
     // ��֦����� n �������������ܹ���������
     if (n % 2 == 1) {
        return 0;
    }
    ans[1] = 1;
    vis[1] = 1;
    dfs(2);
    // cout<<isPrime(3)<<endl;
    return 0;
}