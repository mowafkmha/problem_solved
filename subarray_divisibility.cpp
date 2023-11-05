#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <stack>





int main() {


std::cin.tie(0);
std::cout.tie(0);
std::ios_base::sync_with_stdio(0);


long long n;
std::cin>>n;

std::vector<long long> vec(n+1);
for(int i=1;i<=n;i++)
    std::cin>>vec[i];


std::vector<long long> pref(n+1);


for(int i=1;i<=n;i++)
    pref[i]=(pref[i-1]+vec[i])%n;             // count the prefix and mod it every time to avoid over flow


    std::vector<std::vector<long long>> mod(n,std::vector<long long>());

    for(int i=1;i<=n;i++)
    {
        if(pref[i]<0)
            pref[i]+=n;    // add n in case of negative mod results so it become positive
        mod[pref[i]].push_back(i);        // if there exist 2 prefix sums (or maybe more) that are both congruence to (mod n), which means they both fall in the same vector then subtracting these 2 will make a number that is product of n

    }


    long long counter=0;
    long long sz;
    counter+=mod[0].size(); // each prefix in the 0th vector is a subarray divisible by n
    for(int i=0;i<n;i++)
    {
        sz=mod[i].size();
        if(sz>1)
        {
            sz--;
            counter+=(sz*(sz+1))/2;           // if there is 2 prefix sums then there is one sub array and if there is n then there is summation from 1 to (n-1)

        }

    }

    std::cout<<counter;









    return 0;
}
