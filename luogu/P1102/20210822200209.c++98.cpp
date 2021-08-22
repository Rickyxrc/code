#include <stdio.h>
#define MAXLENGTH 400007

struct hashh{
	int cnt;
	int data;
};

hashh pHashTableData[MAXLENGTH];
long long abs(int a){
	return a<0 ? -a : a;
}
int pHashFunction(int hashNum) { return abs((hashNum ^ 0x71e2a ) % 0x61a80); }


int find(int fnd){
	int index;
	index = pHashFunction(fnd);
    while (pHashTableData[index].data && pHashTableData[index].data!=fnd)
		index = pHashFunction(index+1);
	return index;
}


long long rec[MAXLENGTH];
int n,c,index;
long long solut;
int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++){
		scanf("%d",&rec[i]);
		index=find(rec[i]);
		pHashTableData[index].cnt++;
		pHashTableData[index].data=rec[i];
	}
		
		
	for(int i=1;i<=n;i++){
		solut+=pHashTableData[find(rec[i]-c)].cnt;
	}
	
	printf("%lld",solut);
	
	return 0;
}