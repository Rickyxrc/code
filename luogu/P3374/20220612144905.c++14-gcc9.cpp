#include<stdio.h>
int dataList[500007];
int lowbit(int i){return i&(-i);}
int getPrefixSum(int index){
    int returnAns=0;
    while(index>0){
        returnAns+=dataList[index];
        index-=lowbit(index);
    }
    return returnAns;
}
int tempVar,maxNum,maxCount,tempInput,tempType,tempIndex,tempValue;
void updatePrefix(int index,int val){
    while(index<=maxNum){
        dataList[index]+=val;
        index+=lowbit(index);
    }
}
void init(){
    for(int index=1;index<=maxNum;index++){
    	scanf("%d",&tempInput);
        dataList[index]+=tempInput;
        tempVar=index+lowbit(index);
        if(tempVar<=maxNum)dataList[tempVar]+=dataList[index];
    }
}
int main(){
	scanf("%d%d",&maxNum,&maxCount);
	init();
	for(int i=1;i<=maxCount;i++){
		scanf("%d%d%d",&tempType,&tempIndex,&tempValue);
		if(tempType==1){
			updatePrefix(tempIndex,tempValue);
		}
		else{
			printf("%d\n",getPrefixSum(tempValue)-getPrefixSum(tempIndex-1));
		}
	}
	return 0;
}