#include<stdio.h>
#include<stdlib.h>
class block{
	private:
		int bk[11][11];
	public:
		int n;
		block(int m){
			n=m;
		}
		void init(){
			char ch;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					scanf("%c",&ch);
					if(ch=='\r'||ch==' '||ch=='\n'){
						j--;
						continue;
					}
//					printf("[%c]",ch);
					bk[i][j]=(ch=='@')?1:0;
				}
			return;
		}
		bool operator==(const block& bbk){
			if(n!=bbk.n)
				return false;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(bk[i][j]!=bbk.bk[i][j])
						return 0;
			return 1;
		}
		block turn(void){
			block rt=block(this->n);
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					rt.bk[j][n-i+1]=bk[i][j];
			return rt;
		}
		block reverse(void){
			block rt=block(this->n);
			for(int i=n;i>0;i--)
				for(int j=1;j<=n;j++)
					 rt.bk[i][j]=bk[i][n-j+1];
			return rt;
		} 
		//just for debug!
//		void print(){
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=n;j++){
//					printf("%d ",bk[i][j]);
//				}
//				putchar('\n');
//			}
//		}
};
int k;
void log(int n){
	printf("%d",n);
	exit(0);
}
int main(){
	scanf("%d",&k);
	block b(k),tar(k),r90(k),r180(k),r270(k),jx(k);
	b.init();
	tar.init();
	r90=b.turn();
	
	
	
	if(r90==tar){log(1);}
	r180=r90.turn();
	if(r180==tar){log(2);}
	r270=r180.turn();
	if(r270==tar){log(3);}
	jx=b.reverse();
	if(jx==tar){log(4);}
	
	if(r90.reverse()==tar || r180.reverse()==tar || r270.reverse()==tar){log(5);}

	if(b==tar){log(6);}
    
	log(7);
	
	
	return 0;
}