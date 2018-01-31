#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,R,no_of_run=1;
    int num = 220,rem,maxx = 0,cnt1=0,cnt2=0,cnt3=0; //*****
    cout<<"N: ";
    cin>>N;

    time_t t;
    srand((unsigned)time(&t));

    fstream file1 ("run_1.txt" , ios :: in | ios :: out | ios :: trunc);

    if(!file1.is_open())
    {
        cout<<"File can not be Opened"<<endl;
    }
    else
    {
        //cout<<"Random Sequence: ";
        for(int i=0; i<N; i++)
        {
            R = rand() % 1000;
           // cin>>R;
            file1<<R<<" ";
        }
        file1.seekg(0);  //******

        int num;

        file1>>num;

        while(!file1.eof())
        {
            int digit[10] = {0}; //**********
            while(num>0)
            {
                rem = num%10;
                digit[rem] ++;
                num = num/10;
            }

            maxx = digit[0];
            for(int i=1; i<=9; i++)
            {
                if(digit[i] > maxx)
                {
                    maxx = digit[i];
                }
            }
            if(maxx == 1 || maxx == 0) //***********
            {
                //cout<<"Different"<<endl;
                cnt1++;
            }
            else if(maxx == 2)
            {
                //cout<<"2 Digits Same"<<endl;
                cnt2++;
            }
            else if(maxx == 3)
            {
                //cout<<"3 Digits Same"<<endl;
                cnt3++;
            }

            file1>>num;;  //**** incrementing file pointer

        }
        file1.seekg(0);  //*****
        file1.close();
    }

    cout<<"All Digits are Different     : "<<cnt1<<endl;
    cout<<"One Pair of Digits are Same  : "<<cnt2<<endl;
    cout<<"All Digits are Same          : "<<cnt3<<endl;
    cout<<endl;
    double E[3],O[3],chy;
    O[0] = cnt1;
    O[1] = cnt2;
    O[2] = cnt3;

    E[0] = 0.72 * N;  // All Digits are Different
    E[1] = 0.27 * N;  // One Pair of Digits are Same
    E[2] = 0.01 * N;  // All Digits are Same


    for(int j=0; j<3; j++)
        {
            chy = chy + (pow((O[j]-E[j]),2)/E[j]);
        }
    cout<<endl;
    cout<<"Poker Test Critical Value (Z0): "<<chy<<endl;

    return 0;
}

