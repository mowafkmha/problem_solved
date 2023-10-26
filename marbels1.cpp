#include <iostream>
#include <math.h>




long long co1,co2;

long long gcd(long long x,long long y)
{
    if(y==0)
    {
        co1=1;
        co2=0;

        return x;
    }
    long long res=gcd(y,x%y);
    long long temp=co1;
    co1=co2;
    co2=temp-(x/y)*co2;
    return res;

}




int main() {

long long n,c1,p1,c2,p2;
std::cin>>n;
while(n!=0)
{
    std::cin>>p1>>c1>>p2>>c2;
    long long g=gcd(c1,c2);
    if((n%g)!=0)
    {
        std::cout<<"failed"<<"\n";

    }
    else
    {
        co1*=(n/g);  // this is x1 initial for the n
        co2*=(n/g);  // this is y1 initial for the n
        // but we only need the positive numbers so we have to solve the inquality for n
        //the formula to get the infinity solution for the diophantine equation is x=x0+k*(c2/gcd(a,b))  and y=y0-k*(gcd(c1,c2))   where k is any integer
        // now but a constrain that you want the answer to be greater than or equal to 0
        // x0+k*(c2/gcd(a,b)>=0
        // y0-k*(gcd(c1,c2))>=0
        // solve for n you will get that
        // n>=-x0*g/c2
        // n <=y0*g/c1
        c2/=g;         // reverse it here but will make it correct in the next step
        c1/=g;
        long long lowerbound=std::ceil(-(double)co1/c2);   // divide col over c2 instead of multiplay its the same as -x0*g/c2 just to avoid overflow that can occur with multiplication
        long long upperbound=std::floor((double)co2/c1);

        if(lowerbound<=upperbound)
        {
            long long res1=p1*(co1+c2*lowerbound)+p2*(co2-(c1)*lowerbound);
            long long res2=p1*(co1+c2*upperbound)+p2*(co2-(c1)*upperbound);

            if(res1<res2)
            {
                std::cout<<(co1+(c2)*lowerbound)<<" "<<(co2-(c1)*lowerbound)<<"\n";

            }

            else

            {
                std::cout<<(co1+(c2)*upperbound)<<" "<<(co2-(c1)*upperbound)<<"\n";

            }

        }

        else
        {
            std::cout<<"failed"<<"\n";
        }


    }


    std::cin>>n;


}



    return 0;
}
