// Shabbir Mahmood ID:14015439 Simulation Lab-02 Date:23-07-2017

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,rand_number,no_of_run=0;
    double mean=0, variance=0, z0=0;
    cout<<"Enter the Length of Random Sequence(N): ";
    cin>>N;




    time_t t ;



    srand(((unsigned)time(&t)));   // Random Number Generating Function //Initial Seed in Unix time(second) from system

    fstream file ("input_run.txt", ios::in | ios::out | ios::trunc);  // File stream for file read,write and truncation

    if(!file.is_open())    // File does not exit or can not be opened
    {
        cout<<"ERROR....File Can't be Opened"<<endl;
        return 0;
    }
    else
    {
        for(int i=0; i<N; i++)
        {
            //cin>>rand_number;           // Enter the Random Numbers
            rand_number = rand()%1000;     // *** Generates Random Numbers within 100
            file<<rand_number<<" ";       // *** Writes the random numbers in file with a succeeding space

        }
        file.seekg(0);                    // Returns and sets the File Pointer to initial 0 position
        int num_a, num_b;

        file>>num_a;      // Reading the first number from file
        file>>num_b;      // Reading the second number from file

        while(!file.eof()) // Until the end of the file
        {
            if(num_a > num_b)  //**** Down Run
            {
                no_of_run++;
                num_a = num_b;
                file>>num_b;   // Increasing File Pointer
                while(num_a>num_b && !file.eof())
                {
                    num_a = num_b;
                    file>>num_b;
                }
                num_a = num_b;
                file>>num_b;
            }
            else if( num_a <= num_b) //**** Up Run
            {
                no_of_run++;
                num_a = num_b;
                file>>num_b;
                while(num_a<=num_b && !file.eof())
                {
                    num_a = num_b;
                    file>>num_b;
                }
                num_a = num_b;
                file>>num_b;
            }

        }
        file.close();
    }
    cout<<"No. of Runs                    : "<<no_of_run<<endl; // **** See the Random Numbers in input.txt file

    mean = (double)(2*N-1)/3;
    variance = (double)(16*N-29)/90;
    z0 = (no_of_run - mean)/sqrt(variance);

    cout<<"Mean of the Random Sequence    : "<<mean<<endl;
    cout<<"Variance of the Random Sequence: "<<variance<<endl;
    cout<<"Z0 of the Random Sequence      : "<<z0<<endl;

    cout<<"Value of Alpha is              : "<<0.05<<endl;

    if(-1.96<= z0 && z0<= 1.96)
    {
        cout<<"The Independence of the Numbers can not be Rejected"<<endl;
    }
    else
    {
         cout<<"The Independence of the Numbers can be Rejected"<<endl;
    }




    return 0;
}
