#include <iostream>
#include <queue>

int main (int argc, char* argv[])
{
    int n, k;
    std::cin>>n>>k;
    int t;
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int> > minHeap;
    for (int i=0; i<n; ++i)
    {
        std::cin>>t;
        maxHeap.push(t);
        minHeap.push(t);
    }
    int max=maxHeap.top();
    int maxcost=0;
    maxHeap.pop();
    while (!maxHeap.empty())
    {
        max+=maxHeap.top();
        maxHeap.pop();
        maxcost+=max;
    }
    int min;
    int c;
    int mincost=0;
    //c=(k-n%(k-1))%(k-1);
    c=n%(k-1);
    if (c!=1)
    {    
        while (c--)
        {
            mincost+=minHeap.top();
            minHeap.pop();
        }
        minHeap.push(mincost);
    }
    
    while (!minHeap.empty())
    {
        min=minHeap.top();
        minHeap.pop();
        if (minHeap.empty())
            break;
        c=k-1;
        while (c--)
        {
            min+=minHeap.top();
            minHeap.pop();
        }
        mincost+=min;
        minHeap.push(min);
    }
    std::cout<<maxcost<<" "<<mincost<<std::endl;
    return 0;
} 