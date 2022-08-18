#include<stdio.h>
#define maxn 500007
int queuee[maxn],sums[maxn],n,m,left,right,ans;
inline int max(int i,int j){return i>j?i:j;}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",sums+i),
        sums[i]+=sums[i-1];
    left=right=1;
    queuee[1]=0;
    for(int i=1;i<=n;i++){
        while (left<=right&&queuee[left]<i-m)left++;
        ans=max(ans,sums[i]-sums[queuee[left]]);
        while (left<=right&&sums[i]<=sums[queuee[right]])right--;
        queuee[++right]=i;
    }
    printf("%d",ans);
    return 0;
}