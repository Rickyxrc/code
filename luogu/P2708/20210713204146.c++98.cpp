#include<stdio.h>
#include<iostream>
#include<string.h>
int main(){
    std::string s;
    int sum=0;
    std::cin>>s;
    sum=s.length()-1;
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1])sum--;
    }
    if(s[s.length()-1]=='0')sum++;
    printf("%d",sum);
    return 0;
}
/*

01010100001
11010100001


*/