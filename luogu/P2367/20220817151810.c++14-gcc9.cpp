#include<stdio.h>
int dataList[5000007],lastTempInput;
int lowbit(int i){return i&(-i);}
int getPrefixSum(int index){
    int returnAns=0;
    while(index>0){
        returnAns+=dataList[index];
        index-=lowbit(index);
    }
    return returnAns;
}
int tempVar,maxNum,maxCount,tempInput,tempType,tempValue1,tempValue2,tempValue3;
unsigned int minn=-1;
void updatePrefix(int index,int val){
    while(index<=maxNum){
        dataList[index]+=val;
        index+=lowbit(index);
    }
}
void updatePrefixs(int index,int indexTo,int val){
    updatePrefix(index,val);
    updatePrefix(indexTo+1,-val);
}
void init(){
    for(int index=1;index<=maxNum;index++){
    	scanf("%d",&tempInput);
        dataList[index]+=tempInput-lastTempInput;
        lastTempInput=tempInput;
        tempVar=index+lowbit(index);
        if(tempVar<=maxNum)dataList[tempVar]+=dataList[index];
    }
}
int main(){
	scanf("%d%d",&maxNum,&maxCount);
	init();
	for(int i=1;i<=maxCount;i++){
//		scanf("%d",&tempType);
//		if(tempType==1){
		scanf("%d%d%d",&tempValue1,&tempValue2,&tempValue3);
		updatePrefixs(tempValue1,tempValue2,tempValue3);
//		}
//		else{
//			scanf("%d",&tempValue1);
//			printf("%d\n",getPrefixSum(tempValue1));
//		}
	}
	for(int i=1;i<=maxNum;i++)
		tempValue1=getPrefixSum(i),
		minn=minn<tempValue1?minn:tempValue1;
	printf("%d",minn);
	return 0;
}