#include <iostream>
#include <math.h>
using namespace std;

bool compare(int first,int second)
{
    if(first > second)
        return true;
    return false;
}
bool compare(string first,string second)
{
    if(first[0] > second[0])
        return true;
    else if(first[0] == second[0] && first[1] > second[1] )
        return true;
    return false;
}
template <typename T>
int partation(T *arr,int low,int high)
{
    int pi  = high;
    int low_index = low - 1;
    for(int i= low; i < high; i++)
    {
        if(compare(arr[pi],arr[i]))
        {
            low_index++;
            swap(arr[i],arr[low_index]);
        }
    }
    low_index++;
    swap(arr[pi],arr[low_index]);
    return low_index;
}
template <typename T>
void _quick_sort(T *arr,int low,int high)
{
    if(low < high)
    {
        int pi = partation(arr,low,high);
        _quick_sort(arr,pi +1,high);
        _quick_sort(arr,low,pi - 1);
    }
}

int main()
{
    int arr[] = {70,10,80,30,90,40,50};
    string arr2[] = {"fhmed","ahmed","ezat","badr","crag","gmal","aodo"};
    // _recprint(10);
    int low = 0;
    int high = 6;
    _quick_sort(arr2,low,high);
    for(int i = 0;i <= high;i++)
    {
        cout<<arr2[i]<<endl;
    }
    // print(10);
    return 0;
}