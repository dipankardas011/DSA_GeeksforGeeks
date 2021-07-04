#include <iostream>
#include <list>
using namespace std;

void strandSort(list<int>& ip, list<int>& op)
{
    if(ip.empty())
        return ;
    
    list<int> sublist;
    sublist.push_back(ip.front());
    ip.pop_front();

    for(list<int>::iterator it=ip.begin(); it!=ip.end();)
    {
        // if current item of input list is greater then last added item to sublist move curent item to sublist as sorted order is maintaned
        if(*it>sublist.back()){
            sublist.push_back(*it);
            it=ip.erase(it);
        }
        else
            it++;
    }
    op.merge(sublist);

    strandSort(ip,op);
}

int main(int argc, char const *argv[])
{
    list<int>ip{10,5,30,40,2,9};
    list<int> op;
    strandSort(ip,op);
    for(auto x:op)
        cout<<x<<" ";
    cout<<endl;
    remove(argv[0]);
    return 0;
}
