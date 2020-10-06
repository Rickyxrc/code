#include<bits/stdc++.h>
using namespace std;
struct sco{
	int chinese;
	int math;
	int english;
	int max;
};
struct student{
	string name;
	sco score;
};
int main()
{
	student stu[1005];
	int n;
	cin>>n;
	int max=0;
	for(int i=1;i<=n;i++)
	{
		cin>>stu[i].name;
		cin>>stu[i].score.chinese;
		cin>>stu[i].score.math;
		cin>>stu[i].score.english;
		stu[i].score.max=stu[i].score.chinese+stu[i].score.math+stu[i].score.english;
	}
	int j;
	for(int i=1;i<=n;i++)
	{
		if(stu[i].score.max>max)
		{
			j=i;
			max=stu[i].score.max;
		}
	}
	cout<<stu[j].name<<" "<<stu[j].score.chinese<<" "<<stu[j].score.math<<" "<<stu[j].score.english;    
	return 0;
}
