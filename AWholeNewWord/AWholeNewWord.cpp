#include<iostream>
#include<cstring>
using namespace std;
int checkmyletter(char *test,char **arr,int n,int l)
{
    int check=0;
    for (size_t i = 0; i < n; i++)
    {   
        
        if(strcmp(arr[i],test)==0)
        {
            //cout<<"\tvxvzvvz"<<i<<"\t";
            check=1;
            break;
        }
       
    }
    if(check==0)
    {
            return 1;
    }
    return 0;
}
void searcharr(char **arr,int l,int n,int z)
{
    int count=0;
        for (size_t k = 0; k < l; k++)
        {
            for (size_t i = 0; i < n; i++)
            {
            char test[l+1];
            test[l]='\0';
            for (size_t c = 0; c < n; c++)
            {   //cout<<count<<'\t';
                for (size_t j = 0; j < l; j++)
                {
                    if(j==k)
                    {
                        test[j]=arr[(i+c)%n][j];
                        //cout<<test[j];
                        continue;
                    }

                    test[j]=arr[i][j];
                    //cout<<test[j];
                }
                int ret=0;
                if((ret=checkmyletter(test,arr,n,l))==1)
                {
                        cout<<"Case #"<<z+1<<": "<<test<<"\n";
                        return ;
                }
                else
                {
                        //cout<<"Case #"<<z+1<<": -"<<"\n";
                }
                
                //cout<<endl;
                count++;
            }
            }
        }
    cout<<"Case #"<<z+1<<": -"<<"\n";
}
int main()
{
    int t=0;
    cin>>t;
    for (size_t z = 0; z < t; z++)
    {
        int n , l;
        cin>>n>>l;
        char **arr;
        arr = new char*[n];
        for (int i=0; i<n; i++)
        {
            arr[i] = new char[l+1];
        }
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < l; j++)
            {
                cin>>arr[i][j];
            }
            arr[i][l]='\0';
        }
        

        // for (size_t i = 0; i < n; i++)
        // {
        //     for (size_t j = 0; j < l; j++)
        //     {
        //         cout<<arr[i][j]<<"\t";
        //     }
        //     cout<<endl;
        // }
        searcharr(arr,l,n,z);
        
    }
    
    return 0;
}