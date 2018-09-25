#include<iostream>
using namespace std;

int main()
 {
   cout<<"\t Priority Scheduling \t";
   int n;
   cout<<"Enter the number of process : ";
   cin>>n;
   int x,p[n],pp[n],pt[n],w[n],t[n],awt,atat,i;
   cout<<"\n Enter process : time priorities \n";
   for(i=0;i<n;i++)
    {
      cout<<"\nProcess no : "<<i+1;
      cin>>pt[i]>>pp[i];
      p[i]=i+1;
    }
  for(i=0;i<n-1;i++)
   {
     for(int j=i+1;j<n;j++)
     {
       if(pp[i]<pp[j])
       {
         x=pp[i];
         pp[i]=pp[j];
         pp[j]=x;
         x=pt[i];
         pt[i]=pt[j];
         pt[j]=x;
         x=p[i];
         p[i]=p[j];
         p[j]=x;
      }
   }
}
w[0]=0;
awt=0;
t[0]=pt[0];
atat=t[0];
for(i=1;i<n;i++)
 {
   w[i]=t[i-1];
   awt+=w[i];
   t[i]=w[i]+pt[i];
   atat+=t[i];
 }
cout<<"\n\n Job \t Burst Time \t Waiting Time \t Turn Around Time   Priority \n";
for(i=0;i<n;i++)
  cout<<"\n"<<p[i]<<"\t\t"<<pt[i]<<"\t\t"<<w[i]<<"\t\t"<<t[i]<<"\t\t"<<pp[i]<<"\n";
awt/=n;
atat/=n;
cout<<"\n Average Wait Time : "<<awt;
cout<<"\n Average Turn Around Time : "<<atat;
return 0;
}
