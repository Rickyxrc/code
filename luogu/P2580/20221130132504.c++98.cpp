#include<stdio.h>
#include<string.h> 

#define num_id 27
int mapping(char n){return n-'a';}

struct Node{
	Node* sons[num_id];
	int value;
	Node(){
		for(int i=0;i<num_id;i++)
			sons[i] = NULL;
	}
};

int cnt;

Node* trie = new Node;

void insert(Node* root,char* str){
	Node* index = root;
	for(int i=0;i<strlen(str);i++){
		if(index->sons[mapping(str[i])] == NULL){
			index->sons[mapping(str[i])] = new Node;
		}
		index = index->sons[mapping(str[i])];
	}
	index->value = ++cnt;
	return;
}

int query(Node* root,char* str){
	Node* index = root;
	for(int i=0;i<strlen(str);i++){
		if(index->sons[mapping(str[i])] == NULL)
			return 0;
		index = index->sons[mapping(str[i])];
	}
	return index->value;
}

int n,m,tmp;
char s[55];
int mark[10007];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){	
		scanf("%s",s);
		insert(trie,s);
	}
	
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",s);
		tmp = query(trie,s);
		if(tmp)
			if(mark[tmp] == 0){
				mark[tmp] = 1;
				puts("OK");
			}
			else
				puts("REPEAT");
		else
			puts("WRONG");
			
	}
	
	return 0;
}