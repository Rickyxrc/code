#include<bits/stdc++.h>
using namespace std;
//template<class T>
//class queu{
//		T qqueu[1001];
//		int  head=0;
//		int  tail=0;
//		int sizee=0;
//	public:
//		void push(const T);
//		void pop();
//		int size(); 
//		T front();
//		T back();
//		T operator[](const int);
//};
//template<class T>
//void queu<T>::push(const T Tp){
//	qqueu[head]=Tp;
//	head++;
//	sizee++;
//	return;
//}
//template<class T>
//void queu<T>::pop(){
//	tail++;
//	sizee--;
//	return;
//}
//template<class T>
//int queu<T>::size(){
////	cout<<"in size("<<endl;
//	return sizee;
//}
//template<class T>
//T queu<T>::front(){
//	return qqueu[head];
//}
//template<class T>
//T queu<T>::back(){
//	return qqueu[tail];
//}
//template<class T>
//T queu<T>::operator[](const int k){
//	return qqueu[head+k];
//}
bool fd[1001];
int main(){
	int m,n,cnt=0,Tp;
	bool f;
	cin>>m>>n;
	queue<int>qu;
	for(int i=1;i<=n;i++){
		scanf("%d",&Tp);
		f=fd[Tp];
		if(!f){
			cnt++;
			qu.push(Tp);
			fd[Tp]=1;
			if(qu.size()>m)
				fd[qu.front()]=0,
				qu.pop();
		}
	}
	cout<<cnt;
}