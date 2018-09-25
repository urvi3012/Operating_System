#include<iostream>
using namespace std;
int main()
{	cout<<"\t Round Robin \t";
	int n,tq=0;
	cout<<"\nEnter the number of processes : ";
	cin>>n;
	
	cout<<"\nEnter the time quantum : ";
	cin>>tq;
	
	int bt[n],rbt[n],wt[n],tat[n],t=0;
	cout<<"\nEnter the burst time of Process : ";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<i+1<<" ";
		cin>>bt[i];
		rbt[i]=bt[i];
	}
	int i=0;
	while(1)
	{
		int flg=1;
		
		for(int i=0;i<n;i++)
		{

		if(rbt[i]>0){
		
		flg=0;
		if(rbt[i]>tq)
			{
				t=t+tq;
				rbt[i]=rbt[i]-tq;
			}
		else
			{
				t=t+rbt[i];
				rbt[i]=0;
				wt[i]=t-bt[i];
				tat[i]=wt[i]+bt[i];
			}
		}
		
		}
		if(flg==1)
		break;
		
	}
	
	cout<<endl<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"  "<<bt[i]<<"  "<<wt[i]<<"  "<<tat[i]<<endl;
	}
	return 0;
}
