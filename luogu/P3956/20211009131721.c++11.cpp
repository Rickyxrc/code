#include<stdio.h>
#include<queue>
#include<string.h>
#include<stdlib.h>
#define maxm 101
int map[maxm][maxm],mins[maxm][maxm],n,m,Tp1,Tp2,Tpc;
struct node{
	int x,y,cnt;
	bool in(){return (x<=m && x>=1 && y<=m && y>=1);}
	bool end(){return (x==m&&y==m);}
	node up(){return node({x,y+1,cnt});}
	node dn(){return node({x,y-1,cnt});}
	node lf(){return node({x-1,y,cnt});}
	node rt(){return node({x+1,y,cnt});}
	node a1(){return node({x,y,cnt+1});}
	node a2(){return node({x,y,cnt+2});}
	node a3(){return node({x,y,cnt+3});}
	int col(){return map[x][y];} 
	bool operator<(const node& o)const{
		return cnt > o.cnt;
	}
}Tp,top;
std::queue<node> q;
void pushin(const node& x){/*printf("push in (%d,%d)-%d \n",x.x,x.y,x.cnt);*/q.push(x);}
void log(){system("cls");
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)
			printf("%10d ",mins[i][j]);
		putchar('\n');
	}
	putchar('\n');
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)
			printf("%10d ",map[i][j]);
		putchar('\n');
	}
	system("pause");
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&Tp1,&Tp2,&Tpc);
		map[Tp1][Tp2]=Tpc+1;
	}
	for(int i=1;i<=m;i++)
		memset(mins[i],0x3f,sizeof(mins[i]));

	node Tp={1,1,0};
	pushin(Tp);
	while(!q.empty()){
		top = q.front(); 
		
		//记忆化优化 
		if(top.cnt >= mins[top.x][top.y]){ //记忆化 
			q.pop();
			continue;
		}
		else
			mins[top.x][top.y]=top.cnt; //更新 
			
//		log(); //debug		
		
		//特例 : 要施展魔法到达终点
		if(top.rt().end()) //右侧是终点 
			pushin(top.rt().a2());
		if(top.dn().end()) //下侧是终点
			pushin(top.dn().a2());
		if(top.lf().end()) //左侧是终点
			pushin(top.lf().a2());
		if(top.up().end()) //上侧是终点
			pushin(top.up().a2());
		q.pop();
		
		//不用魔法
		if(top.up().in() && top.up().col()) //在上方 并且有颜色 
			if(top.up().col() == top.col()) //并且同色
				pushin(top.up());
			else //不同色
				pushin(top.up().a1());
		if(top.dn().in() && top.dn().col()) //在下方 并且有颜色 
			if(top.dn().col() == top.col()) //并且同色
				pushin(top.dn());
			else //不同色
				pushin(top.dn().a1());
		if(top.lf().in() && top.lf().col())//在左方 并且有颜色 
			if(top.lf().col() == top.col()) //并且同色
				pushin(top.lf());	
			else //不同色
				pushin(top.lf().a1());
		if(top.rt().in() && top.rt().col())//在右方 并且有颜色 
			if(top.rt().col() == top.col()) //并且同色
				pushin(top.rt());
			else //不同色
				pushin(top.rt().a1());
		
		// 用 魔 法  
		// 以下 “不为空” 均指颜色 
		
		if(top.up().in() && !(top.up().col())){//上边是空的 
			if(top.up().up().col()) //上-上不为空 
					if(top.up().up().col() == top.col()) // 颜色一致
						pushin(top.up().up().a2());
					else // 颜色不一致
						pushin(top.up().up().a3());
			if(top.up().lf().col()) //上-左不为空 
				if(top.up().lf().col() == top.col()) // 颜色一致
					pushin(top.up().lf().a2());
				else // 颜色不一致
					pushin(top.up().lf().a3());
			if(top.up().rt().col()) //上-右不为空 
				if(top.up().rt().col() == top.col()) // 颜色一致
					pushin(top.up().rt().a2());
				else // 颜色不一致
					pushin(top.up().rt().a3());
		}	
					
		if(top.dn().in() && !(top.dn().col())){//下边是空的 
			if(top.dn().dn().col()) //下-下不为空 
					if(top.dn().dn().col() == top.col()) // 颜色一致
						pushin(top.dn().dn().a2());
					else // 颜色不一致
						pushin(top.dn().dn().a3());
			if(top.dn().lf().col()) //下-左不为空 
				if(top.dn().lf().col() == top.col()) // 颜色一致
					pushin(top.dn().lf().a2());
				else // 颜色不一致
					pushin(top.dn().lf().a3());
			 if(top.dn().rt().col()) //下-右不为空 
				if(top.dn().rt().col() == top.col()) // 颜色一致
					pushin(top.dn().rt().a2());
				else // 颜色不一致
					pushin(top.dn().rt().a3());
		}
					
		if(top.lf().in() && !(top.lf().col())){//左边是空的 
			if(top.lf().lf().col()) //左-左不为空 
					if(top.lf().lf().col() == top.col()) // 颜色一致
						pushin(top.lf().lf().a2());
					else // 颜色不一致
						pushin(top.lf().lf().a3());
			if(top.lf().up().col()) //左-上不为空 
				if(top.lf().up().col() == top.col()) // 颜色一致
					pushin(top.lf().up().a2());
				else // 颜色不一致
					pushin(top.lf().up().a3());
			 if(top.lf().dn().col()) //左-下不为空 
				if(top.lf().dn().col() == top.col()) // 颜色一致
					pushin(top.lf().dn().a2());
				else // 颜色不一致
					pushin(top.lf().dn().a3());
		}
					
		if(top.rt().in() && !(top.rt().col())){//右边是空的 
			if(top.rt().rt().col()) //右-右不为空 
					if(top.rt().rt().col() == top.col()) // 颜色一致
						pushin(top.rt().rt().a2());
					else // 颜色不一致
						pushin(top.rt().rt().a3());
			if(top.rt().up().col()) //右-上不为空 
				if(top.rt().up().col() == top.col()) // 颜色一致
					pushin(top.rt().up().a2());
				else // 颜色不一致
					pushin(top.rt().up().a3());
			 if(top.rt().dn().col()) //右-下不为空 
				if(top.rt().dn().col() == top.col()) // 颜色一致
					pushin(top.rt().dn().a2());
				else // 颜色不一致
					pushin(top.rt().dn().a3());
		}
		
		
	}
	if(mins[m][m] > 21474836)
		printf("%d",-1);
	else
		printf("%d",mins[m][m]);
	return 0;
}
/*
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0

ans=8

2 3
1 1 0
1 2 0
2 1 1

ans=2

5 8
1 1 0
1 2 1
2 2 0
3 3 1
4 2 1
5 1 0
5 3 1
5 4 0

ans = 10
*/