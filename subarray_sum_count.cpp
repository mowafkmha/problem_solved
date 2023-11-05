#include <iostream>
#include <vector>
#include <algorithm>
#include <map>



int main()
{
    long long n,s;
    std::cin>>n>>s;
    std::vector<long long> vec(n+1);
    for(int i=1;i<=n;i++)
        std::cin>>vec[i];

    std::map<long long,long long> map;

       long long sum=0;
       long long cnt=0;
       for(int i=1;i<=n;i++)
       {
           sum+=vec[i];
           if(sum==s)
            cnt++;
           if(map[sum-s]!=0)
            cnt+=map[sum-s];

            map[sum]++;

       }

       std::cout<<cnt;









    return 0;
}




