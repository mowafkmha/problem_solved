#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#define  forn(n) for(int i=0;i<n;i++)
#include <numeric>
#define  light()  std::ios_base::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
#include <bitset>
#include <math.h>
#pragma GCC target("popcnt")
#include <cstring>
#include <list>
#include <iterator>
#include<map>






int main()
{
    light();
    int t,n;
    std::cin>>t;
    while(t--)
    {
        std::cin>>n;
        int b_size=(n-1)*n/2;
        std::map<int,int,std::greater<int>> freq;
        for(int i=0;i<b_size;i++)
        {
            int number;
            std::cin>>number;
            freq[number]++;

        }

        std::vector<int> was;
        for(auto [i,j]:freq)
            {
                if((was.size()) >=j)
                {
                  was.push_back(i);
                  std::cout<<i;
                }

                else
                {

                double a=1;
                double b=-0.5;
                double c=(-1.0*(double)j);    //multiplay the equation with 2 to get rid of float numbers
                c*=2;
                b=(b+(was.size()))*2;        // was.size is added to the x term , because  (x(x-1)/2) will count the number of pair compare that will happen between only the added number but there is also x*(size) pair compare will happen because each added number will be compared with all the number in the was arry which are before him so

                double x=((-1*b)+std::sqrt((b*b)-(4*a*c))  )/2*a;  // x is how many time we need to place the number and its always an int number because the statement says that there is always a solution
                double x0=((-1*b)-std::sqrt((b*b)-(4*a*c))  )/2*a;
                x=std::max(x,x0);  // take the positive number  not sure yet but i think that sometimes 4ac might be bigger than the b^2  so the (-) will give the positive answer


                for(int ii=0;ii<x;ii++)
                {
                    was.push_back(i);
                    std::cout<<i<<" ";

                }

                }

            }


            std::cout<<"\n";

    }




}





