
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
#include <limits>
#define ll long long
#include <queue>
#include <set>






 int main()
{
light();

    int n;
    std::cin>>n;
    //bool indicator=true;  //  in case of adding an element will make then set even then  true means first iterator is the median and false means second iterator is the median
    std::set<int>::iterator t1;
    std::set<int>::iterator t2;
    std::multiset<int> set;

    char c;
    int x;
  for(int i=0;i<n;i++)
  {
      //std::cout<<i+1<<"-->";
      std::cin>>c>>x;
      if(c=='a')
      {
          if(set.size()==0)
          {
              set.insert(x);
              t1=set.begin();
              std::cout<<x<<"\n";
              continue;
          }

          int sz=set.size();
          //std::cout<<sz;
          if((sz%2)!=0)       // case adding the number will make me even
          {
              //std::cout<<set.size();
                set.insert(x);
                  if(x>=*t1)
                  {

                      t2=t1;
                      t2++;
                      std::swap(t1,t2);   // make sure that t1 is always on the right when even
                      //std::cout<<*t1<<"\n"<<*t2<<"\n";
                      double ans=(double)((double)*t1/2+(double)*t2/2);
                      if(ans<0&&ans>-1)
                      {
                        std::cout<<"-0.5\n";
                        continue;
                      }
                      if(ans==std::ceil(ans))
                      {
                        std::cout<<(long long)ans<<"\n";
                      }
                      else
                      {

                        std::cout<<(long long)ans<<".5\n";
                      }
                  }

                  else
                  {
                      t2=t1;
                      t2--;

                       double ans=(double)((double)*t1/2+(double)*t2/2);
                      if(ans<0&&ans>-1)
                      {
                        std::cout<<"-0.5\n";
                        continue;
                      }
                      if(ans==std::ceil(ans))
                      {
                        std::cout<<(long long)ans<<"\n";
                      }
                      else
                      {

                        std::cout<<(long long)ans<<".5\n";
                      }

                  }


              }

          else
          {
            auto loc=set.insert(x);
            if(x<*t1&&x>*t2)
            {
                t1--;
                std::cout<<*t1<<"\n";
            }

            else if(x>=*t1)
            {
                std::cout<<*t1<<"\n";

            }
            else if(x<*t2)
            {

                t1=t2;
                std::cout<<*t1<<"\n";
            }
            else if(x==*t2)
            {
                t1=loc;
                std::cout<<*t1<<"\n";

            }


          }


      }

      else           // when deleting
      {
          if(set.find(x)==set.end() || set.size()==0)
          {
            std::cout<<"Wrong!"<<"\n";
            continue;
          }
           int sz=set.size();
          if(sz%2==0)
          {

              auto tt=set.find(x);

              if(x>*t1||tt==t1)
              {

                  std::swap(t1,t2);
                  set.erase(tt);
                  std::cout<<*t1<<"\n";

              }
              else if(x<=*t2||tt==t2)
              {
                  set.erase(tt);
                  std::cout<<*t1<<"\n";
              }


          }




          else
          {

              if(set.size()==1)
              {
                  set.erase(x);
                  std::cout<<"Wrong!"<<"\n";
                  continue;
              }

              auto tt=set.find(x);
              if(tt==t1)
              {
                  t1++;
                  set.erase(tt);
                  t2=t1;
                  t2--;

                 double ans=(double)((double)*t1/2+(double)*t2/2);
                      if(ans<0&&ans>-1)
                      {
                        std::cout<<"-0.5\n";
                        continue;
                      }
                      if(ans==std::ceil(ans))
                      {
                        std::cout<<(long long)ans<<"\n";
                      }
                      else
                      {

                        std::cout<<(long long)ans<<".5\n";
                      }


              }
              else if(x>*t1)
              {
                  set.erase(tt);
                  t2=t1;
                  t2--;
                    double ans=(double)((double)*t1/2+(double)*t2/2);
                      if(ans<0&&ans>-1)
                      {
                        std::cout<<"-0.5\n";
                        continue;
                      }
                      if(ans==std::ceil(ans))
                      {
                        std::cout<<(long long)ans<<"\n";
                      }
                      else
                      {

                        std::cout<<(long long)ans<<".5\n";
                      }
              }
              else if(x<=*t1)
              {
                  set.erase(tt);
                  t2=t1;
                  t1++;

                  double ans=(double)((double)*t1/2+(double)*t2/2);
                      if(ans<0&&ans>-1)
                      {
                        std::cout<<"-0.5\n";
                        continue;
                      }
                      if(ans==std::ceil(ans))
                      {
                        std::cout<<(long long)ans<<"\n";
                      }
                      else
                      {

                        std::cout<<(long long)ans<<".5\n";
                      }
              }



          }

      }





  }







}
