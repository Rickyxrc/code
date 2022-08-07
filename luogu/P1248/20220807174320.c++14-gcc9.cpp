#include<stdio.h>
#include<algorithm>
#include<vector>
#define maxNum 10007
//#define __DebugFlagByRickyxrcNorepeat
int minValue(int __valueAProps,int __valueBProps){return __valueAProps>__valueBProps?__valueBProps:__valueAProps;}
struct Product{
	int useTimeA;
	int useTimeB;
	int productionIdUnique;
	int getMinValue() const {
		return minValue(useTimeA,useTimeB);
	}
	bool operator <(const Product b) const {
		return getMinValue()<b.getMinValue();
	}
}productionsList[maxNum];
std::vector<Product> makeProductListFromStart,makeProductListFromBack;
std::vector<Product> makeProductList;
int main(){
	int n;
	scanf("%d",&n);
	for(int __iteratorTempWithIteratorId_In_productionsList=0;__iteratorTempWithIteratorId_In_productionsList<n;__iteratorTempWithIteratorId_In_productionsList++)
		scanf("%d",&productionsList[__iteratorTempWithIteratorId_In_productionsList].useTimeA),
		productionsList[__iteratorTempWithIteratorId_In_productionsList].productionIdUnique = __iteratorTempWithIteratorId_In_productionsList+1;
	for(int __iteratorTempWithIteratorId_In_productionsList=0;__iteratorTempWithIteratorId_In_productionsList<n;__iteratorTempWithIteratorId_In_productionsList++)
		scanf("%d",&productionsList[__iteratorTempWithIteratorId_In_productionsList].useTimeB);
	std::sort(productionsList,productionsList+n);
	#ifdef __DebugFlagByRickyxrcNorepeat
	printf("start Debug......\n");
	for(auto __iteratorTempWithValue_In_productionsListk:productionsList){
		if(__iteratorTempWithValue_In_productionsListk.useTimeA == 0)
			break;
		printf("%d %d\n",__iteratorTempWithValue_In_productionsListk.useTimeA,__iteratorTempWithValue_In_productionsListk.useTimeB);
	}
	printf("end Debug......\n");
	#endif
	for(int __iteratorTempWithIteratorId_In_productionsList=0;__iteratorTempWithIteratorId_In_productionsList<n;__iteratorTempWithIteratorId_In_productionsList++)
		if(productionsList[__iteratorTempWithIteratorId_In_productionsList].getMinValue() == productionsList[__iteratorTempWithIteratorId_In_productionsList].useTimeA)
			makeProductListFromStart.push_back(productionsList[__iteratorTempWithIteratorId_In_productionsList]);
		else
			makeProductListFromBack.insert(makeProductListFromBack.begin(),productionsList[__iteratorTempWithIteratorId_In_productionsList]);
	
	for(auto __iteratorTempWithValue_In_makeProductListFromBack:makeProductListFromBack)
		makeProductListFromStart.push_back(__iteratorTempWithValue_In_makeProductListFromBack);

	int needTimeA=0,needTimeB=0;
	for(auto __iteratorTempWithValue_In_makeProductListFromStart:makeProductListFromStart){
		needTimeA+=__iteratorTempWithValue_In_makeProductListFromStart.useTimeA;
		if(needTimeA>needTimeB)
			needTimeB=needTimeA;
		needTimeB+=__iteratorTempWithValue_In_makeProductListFromStart.useTimeB;
	}
	printf("%d\n",needTimeB);
	for(auto __iteratorTempWithValue_In_makeProductListFromStart:makeProductListFromStart)
		printf("%d ",__iteratorTempWithValue_In_makeProductListFromStart.productionIdUnique,__iteratorTempWithValue_In_makeProductListFromStart.useTimeA,__iteratorTempWithValue_In_makeProductListFromStart.useTimeB);
		
	return 0;
}
