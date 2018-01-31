#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num = 0,rem,digit[10] = {0},maxx = 0;

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

    if(maxx == 1)
    {
        cout<<"Different"<<endl;
    }
    else if(maxx == 2)
    {
        cout<<"2 Digits Same"<<endl;
    }
    else if(maxx == 3)
    {
        cout<<"3 Digits Same"<<endl;
    }

    cout<<maxx<<endl;
    return 0;
}
