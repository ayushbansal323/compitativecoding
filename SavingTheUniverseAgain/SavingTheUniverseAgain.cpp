#include<iostream>
#include<string.h>
#include <bits/stdc++.h> 
using namespace std;

int findmyd(int scount,int ccount,int *c,int *cf)
{
    int myd=scount;
    long int p2=1;
    for(int i = 1;i<=ccount;i++)
    {
        myd=myd+(c[i]*p2);
        p2=p2*2;
    }
    return myd;
}

int main()
{
    int t=0;
    cin>>t;

    for(size_t z = 0; z < t; z++)
    {
        int ans=0;
        int d=0;
        cin>>d;
        string p;
        cin>>p;
        //cout<<p<<endl;
        int slength = p.length();
        char parr[slength+1];
        strcpy(parr, p.c_str());
        int ccount = count( p.begin(), p.end(), 'C') ;
        int scount = count( p.begin(), p.end(), 'S') ;
        //cout<<ccount<<endl;
        if(ccount == 0)
        {
            int scount = count( p.begin(), p.end(), 'S');
            if(scount<=d)
            {
                ans=0;
            }
            else
            {
                ans=-1;
            }
            
        }
        else if(ccount == 1 )
        {
            size_t found = p.find('C');

            //cout<<"C found at "<<found<<endl;

            int c1 = count( p.begin()+found, p.end(), 'S') ;
            int dmy = scount +c1;
            //cout<<dmy<<'\t'<<d<<endl;
            int fcs=0;
            if(found < slength && p[found]=='C' && p[found+1] == 'S')
            {
                fcs=1;
                found++;
            }
            while ( (fcs != 0) && d<dmy)
            {
                p[found-1]='S';
                p[found]='C';
                c1--;
                dmy = scount +c1;
                ans++;
                //cout<<"changed p at "<<fcs<<"  "<<p<<endl;
                if(found < slength && p[found]=='C' && p[found+1] == 'S')
                {
                    fcs=1;
                    found++;
                }
                else
                {
                    fcs=0;
                }
                
            }
            if(d<dmy)
            {
                ans=-1;
            }

        }
        else
        {
            int c[ccount+1]={0};
            int cf[ccount+1]={0};
            cf[1]= p.find('C',0);
            c[1] = count( p.begin()+cf[1], p.end(), 'S') ;
            //cout<<"cf[1] == "<<cf[1]<<"  "<<c[1]<<endl;
            for(int i=2 ; i<=ccount ; i++ )
            {
                cf[i] = p.find('C',cf[i-1]+1);
                c[i] = count( p.begin()+cf[i], p.end(), 'S') ;

                //cout<<"cf[1] == "<<cf[i]<<"  "<<c[i]<<endl;
            }

            int dmy = findmyd(scount,ccount,c,cf);
            //cout<<dmy<<endl;
            int fcs=0;
            int j=0;
            for(j=ccount;j>0;j--)
            {
                if(cf[j] < slength && p[cf[j]]=='C' && p[cf[j]+1] == 'S')
                {
                    fcs=1;
                    cf[j]++; 
                    break;
                }
            }
            while ( (fcs != 0) && d<dmy)
            {
                p[cf[j]-1]='S';
                p[cf[j]]='C';
                c[j]--;
                dmy = findmyd(scount,ccount,c,cf);
                ans++;
                //cout<<"changed p at "<<cf[j]<<"  "<<p<<endl;
                fcs=0;
                j=0;
                for(j=ccount;j>0;j--)
                {
                    if(cf[j] < slength && p[cf[j]]=='C' && p[cf[j]+1] == 'S')
                    {
                        fcs=1;
                        cf[j]++; 
                        break;
                    }
                }
               
                
            }
            if(d<dmy)
            {
                ans=-1;
            }
        }
        

        if(ans<0)
        {
            cout<<"Case #"<<z+1<<": "<<"IMPOSSIBLE"<<endl;
        }
        else
        {
            cout<<"Case #"<<z+1<<": "<<ans<<endl;
        }
        
    }
        return 0;
}
