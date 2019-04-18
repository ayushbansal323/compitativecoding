#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;

    for (size_t z = 0; z < t; z++)
    {
        int r, c, h, v;
        cin>>r>>c>>h>>v;
        char waf[r][c];

        for (size_t i = 0; i < r; i++)
        {
            for (size_t j = 0; j < c; j++)
            {
                cin>>waf[i][j];
            }
            
        }
        
        /*for (size_t i = 0; i < r; i++)
        {
            for (size_t j = 0; j < c; j++)
            {
                cout<<waf[i][j]<<"\t";
            }
            cout<<"\n";
        }*/


        int hchipscount[r];
        int cumsumcounth[r];
        for (size_t i = 0; i < r; i++)
        {
            int temp=0;
            for (size_t j = 0; j < c; j++)
            {
                if(waf[i][j] == '@')
                {
                    temp++;
                }
            }
            hchipscount[i]=temp;
            if(i==0)
            {
                cumsumcounth[i]=temp;
            }
            else
            {
                cumsumcounth[i]=cumsumcounth[i-1]+temp;
            }
            //cout<<temp<<endl;
            //cout<<cumsumcounth[i]<<endl;
        }

        int vchipscount[c];
        int cumsumcountv[c];
        for (size_t i = 0; i < c; i++)
        {
            int temp=0;
            for (size_t j = 0; j < r; j++)
            {
                if(waf[j][i] == '@')
                {
                    temp++;
                }
            }
            vchipscount[i]=temp;
            if(i==0)
            {
                cumsumcountv[i]=temp;
            }
            else
            {
                cumsumcountv[i]=cumsumcountv[i-1]+temp;
            }
            //cout<<temp<<endl;
            //cout<<cumsumcountv[i]<<endl;
        }


        int hchips =  cumsumcounth[r-1] / (h + 1);
        int vchips =  cumsumcountv[c-1] / (v + 1);
        if((cumsumcounth[r-1] % (h + 1))!=0 || (cumsumcountv[c-1] % (v + 1))!=0) 
        {
            cout<<"Case #"<<z+1<<": IMPOSSIBLE"<<endl;
            continue;
        }

        int temp=hchips;
        int hparts[h+1];
        int flag=0;
        int count=0;
        for (size_t i = 0; i < r; i++)
        {
            if (temp==cumsumcounth[i])
            {
                temp=temp+hchips;
                hparts[count]=i;
                //cout<<i<<"\t"<<cumsumcounth[i]<<endl;
                count++;
                if(count==h+1)
                {
                    break;
                }

            }
            else if(temp<cumsumcounth[i])
            {
                flag=1;
                break;
            }
            
        }

        if(flag==1)
        {
            cout<<"Case #"<<z+1<<": IMPOSSIBLE"<<endl;
            continue;
        }
        
        //vertical
        temp=vchips;
        int vparts[v+1];
        flag=0;
        count=0;
        for (size_t i = 0; i < c; i++)
        {
            if (temp==cumsumcountv[i])
            {
                temp=temp+vchips;
                vparts[count]=i;
                //cout<<i<<"\t"<<cumsumcountv[i]<<endl;
                count++;
                if(count==v+1)
                {
                    break;
                }

            }
            else if(temp<cumsumcountv[i])
            {
                flag=1;
                break;
            }
            
        }

        if(flag==1)
        {
            cout<<"Case #"<<z+1<<": IMPOSSIBLE"<<endl;
            continue;
        }

        int eachpiece=cumsumcounth[r-1]/ ((h + 1) * (v + 1));
        int hstart=0,hend=0,vstart=0,vend=0;
        count=0;
        flag=0;
        for (size_t i = 0; i < (h + 1)  ; i++)
        {
            vstart=vend=0;
            for (size_t j = 0; j < (v + 1); j++)
            {
                hend=hparts[i]+1;
                vend=vparts[j]+1;
                count=0;
                for (size_t k = hstart; k < hend; k++)
                {
                    for (size_t l = vstart; l < vend; l++)
                    {
                        if(waf[k][l]=='@')
                        {
                            count++;
                        }
                    }
                }
                if(count!=eachpiece)
                {
                    flag=1;
                    break;
                }
                //cout<<"start :"<<hstart<<" "<<vstart<<"\tend :"<<hend<<" "<<vend<<"\tcount :"<<count<<endl;
                
                vstart=vend;
            }
            hstart=hend;
        }

        if(flag==1)
        {
            cout<<"Case #"<<z+1<<": IMPOSSIBLE"<<endl;
            continue;
        }

        cout<<"Case #"<<z+1<<": POSSIBLE"<<endl;
    }
    
    return 0;
}
