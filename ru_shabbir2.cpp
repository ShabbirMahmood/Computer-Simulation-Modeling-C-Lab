#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,R,no_of_run=1;
    cout<<"N: ";
    cin>>N;

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
            //R = rand() % 100;
            cin>>R;
            file1<<R<<" ";
        }
        file1.seekg(0);  //******

        int num_a,num_b;
        char sign;

        file1>>num_a;
        file1>>num_b;

        while(!file1.eof())
        {
            if(num_b>num_a)
            {
                sign = '+';
            }
            else if(num_b<=num_a)
            {
                sign = '-';
            }
            num_a = num_b;  //**** incrementing file pointer
            file1>>num_b;

            sign = sign_b;  //**** incrementing file pointer

        }
        file2.seekg(0);  //*****

        char sign_a, sign_b;
        file2>>sign_a;
        file2>>sign_b;
        while(!file2.eof())
        {
            if(sign_b == sign_a)
            {
                //continue;
            }
            else if(sign_b != sign_a)
            {
                no_of_run++;
            }
            sign_a = sign_b;  //**** incrementing file pointer
            file2>>sign_b;
        }
        file1.close();
        file2.close();
    }
    cout<<"No of Runs: "<<no_of_run<<endl;
    double mean = (double)(2*N-1)/3;
    double variance = (double)(16*N-29)/90;
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

