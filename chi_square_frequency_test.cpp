/*
2
4
1000
10
5000

2
4
1000
10
500
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,c,m,x0,n,temp;
    double rand_number,x,O[100] = {0};
    double r,chy = 0;

    cout<<"----- x1 = ((a*x0)+c) mod m ------"<<endl;
    cout<<"a : ";
    cin>>a;
    cout<<"c : ";
    cin>>c;
    cout<<"m : ";
    cin>>m;
    cout<<"x0: ";
    cin>>x0;
    cout<<"n : ";
    cin>>n;

    fstream file1 ("random.txt", ios::in | ios::out | ios::trunc);

    if(!file1.is_open())    // File does not exit or can not be opened
    {
        cout<<"ERROR....File Can't be Opened"<<endl;
        return 0;
    }
    else
    {


        for(int i=1; i<=n; i++)
        {

            temp = ((a*x0)+c);
            x = temp%(m+i);

            x0 = x;
            rand_number = (int)((x/(m+i))*1000);
            x= rand_number;

            file1<<rand_number<<" ";
            cout<<rand_number<<" ";

            if(x>=0 && x<=99)
            {
                O[0]++;
            }
            else if(x>=100 && x<=199)
            {
                O[1]++;
            }
            else if(x>=200 && x<=299)
            {
                O[2]++;
            }
            else if(x>=300 && x<=399)
            {
                O[3]++;
            }
            else if(x>=400 && x<=499)
            {
                O[4]++;
            }
            else if(x>=500 && x<=599)
            {
                O[5]++;
            }
            else if(x>=600 && x<=699)
            {
                O[6]++;
            }
            else if(x>=700 && x<=799)
            {
                O[7]++;
            }
            else if(x>=800 && x<=899)
            {
                O[8]++;
            }
            else if(x>=900 && x<=999)
            {
                O[9]++;
            }
        }
    }
    cout<<endl;
    double k=10, E= n/k;
    for(int j=0; j<k; j++)
        {
            cout<<"O"<<j<<": "<<O[j]<<endl;
            chy = chy + (pow((O[j]-E),2)/E);
        }

        cout<<chy<<endl;


    return 0;
}
