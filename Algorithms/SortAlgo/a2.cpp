#include <iostream>
#include <algorithm>
/*We can also write our own comparator function and pass it as a third parameter. This “comparator” function returns a value; convertible to bool, which basically tells us whether the passed “first” argument should be placed before the passed “second” argument or not. */

struct Interval{
    int start, end;
};
bool compareInterval(Interval i, Interval j){
    return (i.start < j.start);
}
int main(int argc, char const *argv[])
{
    int ar[]={11,34,67,2464,769};
    int n=sizeof ar /sizeof ar[0];
    std::sort(ar,ar+n,std::greater<int>());
    for(auto i:ar)
        std::cout<<i<<" ";
    std::cout<<std::endl;

    Interval arr[]
        = { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
    n = sizeof(arr) / sizeof(arr[0]);
  
    // sort the intervals in increasing order of
    // start time
    std::sort(arr, arr + n, compareInterval);
  
    std::cout << "Intervals sorted by start time : \n";
    for (int i = 0; i < n; i++)
        std::cout << "[" << arr[i].start << "," << arr[i].end << "] ";
    std::cout<<std::endl;
    remove(argv[0]);
    return 0;
}
