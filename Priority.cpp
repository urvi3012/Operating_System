#include<iostream>
using namespace std;

int s=1, f=0, empty=5;

int wait(int s)
{
	return --s;
}
int signal(int s)
{
	return ++s;
}

void producer()
{
	s= wait(s);
	f=signal(f);
	empty=wait(empty);
	cout<<"  producer running"<<endl;
	s=signal(s);
}


void consumer()
{
	s= wait(s);
	empty=signal(empty);
	f=wait(f);
	cout<<"  consumer running"<<endl;
	s=signal(s);
}


int main()
{	cout<<"\t Producer Consumer Problem \t";
    cout<<"\n  max size is 5";
    char choice='Y';
	do
	{   cout<<"\n 1. producer \n 2. consumer \n 3. quit";
	    cout<<"\n enter your choice";
		int ch;
	    cin>>ch;
		
		switch(ch)
		{
			case 1 :    if( s==1 && empty!=0)
						producer();
						else
						cout<<"  producer waiting \n" ;
						break;
			case 2 :    if( s==1 && f!=0)
						consumer();
						else
						cout<<"  consumer waiting \n";
						break;
			case 3   :  exit(1);
			
		}	cout<<"do you want to continue? ";
		cin>>choice;
	}	while(choice=='Y'|| choice=='y');
	return 0;
}


