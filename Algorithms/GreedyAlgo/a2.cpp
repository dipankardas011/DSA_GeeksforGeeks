#include <iostream>
#include <cstring>
#include <algorithm>

struct Job{
    char id;
    int deadline;
    int profit;
};

bool comparison(Job a, Job b){return (a.profit > b.profit);}

void printJobScheduling(Job arr[], int n)
{
    std::sort(arr, arr+n, comparison);

    int res[n];
    bool slot[n];
    memset(slot, 0, sizeof(slot));

    for(int i=0;i<n;i++){
        for(int j=std::min(n, arr[i].deadline)-1 ; j>=0 ; j--)
        {
            if(!slot[j]){
                res[j]=i;
                slot[j]=true;
                break;
            }
        }
    }

    for(int i=0;i<n;i++)
        if(slot[i])
            std::cout<<arr[res[i]].id<<" ";

    std::cout<<std::endl;
}

int main(int argc, char const *argv[])
{
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout << "Following is maximum profit sequence of jobs \n";
   
    // Function call
    printJobScheduling(arr, n);
    remove(argv[0]);
    return 0;
}
