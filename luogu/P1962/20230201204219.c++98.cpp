#include<stdio.h>
#include<memory.h>

#define int long long

const int mod = 1e9 + 7;

int n,m,k;

#define maxn 107
struct matrix{
	int data[maxn][maxn];
	int width,height;
	matrix(){
		width=0;
		height=0;
		memset(data,0,sizeof(data));
	}
	int* operator[] (int i){
		return data[i];
	}
	void input(int n,int m){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%lld",&data[i][j]),
				data[i][j] %= mod;
		width=n;
		height=m;
	}
	void output(){
		for(int i=1;i<=width;i++){
			for(int j=1;j<=height;j++)
				printf("%lld ",data[i][j]%mod);
			putchar('\n');
		}
	}
};

matrix basematrix(int n){
	matrix res;
	res.width=n;
	res.height=n;
	for(int i=1;i<=n;i++)
		res[i][i] = 1;
	return res;
}

matrix operator*(matrix a,matrix b){
	matrix res;
	for(int k=1;k<=a.height;k++)
		for(int i=1;i<=a.width;i++)
			for(int j=1;j<=b.height;j++)
				res[i][j] = (res[i][j] + a[i][k]%mod * b[k][j]%mod)%mod;
	res.height = b.height;
	res.width = a.width;
	return res;
}

inline matrix fastpow(matrix num,int p){
	matrix res = basematrix(num.width);
	while(p){
		if(p&1)
			res = res*num;
		num = num*num;
		p>>=1;
	}
	return res;
}
 
matrix S;
signed main(){
	scanf("%lld",&k);
	
	S[1][1]=0;
	S[1][2]=1;
	S[2][1]=1;
	S[2][2]=1;
	S.width=2;
	S.height=2;

	printf("%lld",fastpow(S,k)[1][2]);
	return 0;
}