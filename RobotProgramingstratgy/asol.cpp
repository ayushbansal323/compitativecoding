#include<iostream>
#include<string>
using namespace std;

struct movess
{
	int r,s,p;

	movess()
	{
		r=s=p=0;
	}
};
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for (int z = 0; z < t; ++z)
	{
		int a;
		cin>>a;
		string sa[a];
		for (int i = 0; i < a; ++i)
		{
			cin>>sa[i];
		}

		movess all[500];
		char ans[501];
		for (int i = 0; i < 501; ++i)
		{
			ans[i]=0;
		}

		for (int i = 0; i < 500; ++i)
		{
			for (int j = 0; j < a; ++j)
			{
				int temp=sa[j].length();
				char check=sa[j][i%temp];
				//cerr<<check;
				if(check=='S')
				{
					all[i].s=1;
				}
				else if(check=='R')
				{
					all[i].r=1;
				}
				else if(check=='P')
				{
					all[i].p=1;
				}
			}
		}
		int flag=0;
		for (int i = 0; i < 500; ++i)
		{

			//cout<<i<<" :"<<all[i].r<<all[i].s<<all[i].p<<endl;
			if((all[i].r==1) && (all[i].s==1) && (all[i].p==1))
			{
				//cerr<<i<<endl;
				flag=1;
				break;
			}
			else if((all[i].r==1) && (all[i].s==1))
			{
				ans[i]='R';
			}
			else if((all[i].r==1) && (all[i].p==1))
			{
				ans[i]='P';
			}
			else if((all[i].p==1) && (all[i].s==1))
			{
				ans[i]='S';
			}
			else if(all[i].r==1)
			{
				ans[i]='P';
				flag=2;
				break;
			}
			else if(all[i].s==1)
			{
				ans[i]='R';
				flag=2;
				break;
			}
			else if(all[i].p==1)
			{
				ans[i]='S';
				flag=2;
				break;
			}
		}
		if(flag<2)
		{
			cout<<"Case #"<<z+1<<": IMPOSSIBLE"<<endl;
		}
		else
		{
			cout<<"Case #"<<z+1<<": "<<ans<<endl;
		}
		//cout<<endl;
	}
	return 0;
}