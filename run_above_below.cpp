#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,R,range,mean_ran, run_above=0,run_below=0,no_of_run=0;
    cout<<"N: ";
    cin>>N;

    cout<<"Range: ";
    cin>>range;

    mean_ran = (range-1)/2;




    time_t t;
    srand((unsigned)time(&t));

    fstream file1 ("run_1.txt" , ios :: in | ios :: out | ios :: trunc);
    fstream file2 ("run_2.txt" , ios :: in | ios :: out | ios :: trunc);

    if(!file1.is_open())
    {
        cout<<"File can not be Opened"<<endl;
    }
    else
    {
        cout<<"Random Sequence: ";
        for(int i=0; i<N; i++)
        {
            R = rand() % range;
           // cin>>R;
            file1<<R<<" ";
        }
        file1.seekg(0);  //******

        int num;

        file1>>num;

        while(!file1.eof())
        {
            if(num > mean_ran)
            {
                file2<<"+"<<" ";
            }
            else if(num <= mean_ran)
            {
                file2<<"-"<<" ";
            }
            file1>>num;  //**** incrementing file pointer

        }
        file2.seekg(0);  //*****

        char sign;

        file2>>sign;
        while(!file2.eof())
        {
            if(sign =='+')
            {
                run_above++;
                file2>>sign;
                while(sign =='+'&& !file2.eof())
                {
                    file2>>sign;
                }
            }
            else if(sign =='-')
            {
                run_below++;
                file2>>sign;
                while(sign =='-'&& !file2.eof())
                {
                    file2>>sign;
                }
            }
             //**** Need not to increment the file pointer

        }
        file1.close();
        file2.close();
    }
    no_of_run = run_above + run_below;
    cout<<"No of Above Runs: "<<run_above<<endl;
    cout<<"No of Below Runs: "<<run_below<<endl;
    cout<<"No of Runs: "<<no_of_run<<endl;
    double mean = (double)(2*run_above*run_below)/10 + 0.5;
    double variance = (double) (2*run_above*run_below*(2*run_above*run_below-N)) /((N*N)*(N-1))  ;
    double z0 = (no_of_run - mean)/sqrt(variance);

    cout<<"Mean of the Random Sequence    : "<<mean<<endl;
    cout<<"Variance of the Random Sequence: "<<variance<<endl;
    cout<<"Z0 of the Random Sequence      : "<<z0<<endl;

    cout<<"Value of Alpha is              : "<<0.05<<endl;

    if(-1.96<= z0 && z0<= 1.96)
    {
        cout<<"\n!!!Accepted!!!\nThe Independence of the Numbers can not be Rejected"<<endl;
    }
    else
    {
         cout<<"\n!!!Rejected!!!\nThe Independence of the Numbers can be Rejected"<<endl;
    }

    return 0;
}

