#include<iostream>
#include <iomanip>
#include <bits/stdc++.h> 
#include<cmath>
using namespace std;
//https://www.diffchecker.com/diff#right-4
struct activity
{
	int shift,start,stop;
};

int compare_function(const void *a,const void *b) {
activity *x = (activity *) a;
activity *y = (activity *) b;
return x->start - y->start;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for (int z = 0; z < t; ++z)
	{
		int activityC,activityJ;
		cin>>activityC>>activityJ;
		//cout<<"\n\n"<<activityC<<"\t"<<activityJ<<"\n\n";
		activity act[activityC+activityJ];
		long long timeC=720,timeJ=720;
		int minShift=0;
		for (int i = 0; i < activityC; ++i)
		{
			act[i].shift=0;
			cin>>act[i].start>>act[i].stop;
			timeC=timeC-(act[i].stop-act[i].start);
		}

		for (int i = activityC; i < activityC+activityJ; ++i)
		{
			act[i].shift=1;
			cin>>act[i].start>>act[i].stop;
			timeJ=timeJ-(act[i].stop-act[i].start);
		}




		

		qsort (act, sizeof(act)/sizeof(*act), sizeof(*act), compare_function);

		for (int j = 0; j < activityJ+activityC; ++j)
		{
			int min=999999;
			int mini=-1;
			int mintemp=0;
			for (int i = 0; i < activityJ+activityC-1; ++i)
			{
				int temp=(i+1)%(activityJ+activityC);
				if(act[i].shift<0)
				{
					continue;
				}
				while(act[temp].shift<0)
				{
					temp=(temp+1)%(activityJ+activityC);
				}
				if(i==temp)
				{
					continue;
				}
				if(act[i].shift==act[temp].shift)
				{
				int ctime=(act[temp].start-act[i].stop);
				if(ctime<0)
				{
					ctime=1440+ctime;
				}

				if(ctime<min)
				{
					min=ctime;
					mini=i;
					mintemp=temp;
				}
				}
			}
			if(min<0)
			{
				continue;
			}

			if(act[mini].shift<0)
			{
				continue;
			}
			//cout<<"min :"<<(act[mintemp].start-act[mini].stop)<<"  "<<min<<"\t"<<mintemp<<" "<<mini<<endl;
			
			if(act[mini].shift==1)
			{
				if(min<=timeJ)
				{
					timeJ=timeJ-min;
					act[mini].stop=act[mintemp].stop;
					act[mintemp].shift=-1;
					//act[mintemp].stop=min;
					act[mintemp].start=0;
				}
			}
			else 
			{
				if(min<=timeC)
				{
					timeC=timeC-min;
					act[mini].stop=act[mintemp].stop;
					act[mintemp].shift=-1;
					//act[mintemp].stop=min;
					act[mintemp].start=0;
				}
			}
		}




		qsort (act, sizeof(act)/sizeof(*act), sizeof(*act), compare_function);



		for (int i = 0; i < activityJ+activityC; ++i)
		{
			//cout<<act[i].start<<"\t"<<act[i].stop<<"\t"<<act[i].shift<<endl;
			int temp=(i+1)%(activityJ+activityC);

			if(act[i].shift<0)
			{
					continue;
			}
			while(act[temp].shift<0)
				{
					temp=(temp+1)%(activityJ+activityC);
				}
			if(act[i].shift!=act[temp].shift)
			{
				minShift++;
			}
			else if(act[i].shift == 0)
			{
				int ctime=(act[temp].start-act[i].stop);

				if(ctime<0)
				{
					ctime=1440+ctime;
				}
				//cout<<"ctime :"<<ctime<<"\ttime :"<<timeC<<endl;
				if(ctime<=timeC)
				{
					timeC=timeC-ctime;
				}
				else
				{
					minShift=minShift+2;
				}
			}
			else if(act[i].shift == 1)
			{
				int ctime=(act[temp].start-act[i].stop);
				
				if(ctime<0)
				{
					ctime=1440+ctime;
				}
				//cout<<"ctime :"<<ctime<<"\ttimej :"<<timeJ<<endl;
				if(ctime<=timeJ)
				{
					timeJ=timeJ-ctime;
				}
				else
				{
					minShift=minShift+2;
				}
			}
			//cout<<"mainshift: "<<minShift<<endl;
		}


		cout<<"Case #"<<z+1<<": "<<minShift<<endl;
	}
	return 0;
}