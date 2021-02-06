#include<stdio.h>
#include<iostream>
#include<vector>
#include<time.h>
#include<windows.h>
#include<algorithm>


using namespace std;

void printNums(vector<int>nums)
{
    for(auto num : nums)
    {
        cout << num  << " ";
    }
    cout << endl;
}

void intersectionSort(vector<int>nums)
{
    clock_t start, end;
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);

    // start = clock();
    int pos = 0;
    while(pos < nums.size())
    {
        int min_val = nums[pos];
        int i = pos;
        while(i > 0 and nums[i-1] > min_val)
        {
            nums[i] = nums[i-1];
            i--;
        }
        nums[i] = min_val;
        pos++;
    }

    // end = clock();
    QueryPerformanceCounter(&t2);
    double time = (double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart;
    cout << "IntersectionSort time used : " << time << "s\n";
    printNums(nums);
    return ;
}

void bubbleSort(vector<int>nums)
{

    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    clock_t start, end;
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = 1; j < nums.size()-i; j++)
        {
            if(nums[j] < nums[j-1])
                swap(nums[j], nums[j-1]);
        }
    }

    QueryPerformanceCounter(&t2);
    double time = (double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart;
    cout << "BubbleSort time used : " << time << "s\n";
    printNums(nums);
    return ;
}

void shellSort(vector<int>nums)
{
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    clock_t start, end;

    for(int increment = nums.size()/2; increment > 0; increment /=2)
    {
        for(int i =  increment; i < nums.size(); i++)
        {
            int tmp = nums[i];
            int j ;
            for(j = i; j >= increment; j -= increment)
            {
                if(tmp < nums[j-increment])
                    nums[j] = nums[j-increment];
                else
                {
                    break;
                }
                
            }
            nums[j] = tmp;
        }
    }

    QueryPerformanceCounter(&t2);
    double time = (double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart;
    cout << "ShellSort time used : " << time << "s\n";
    printNums(nums);
    return ;
}

void adjustHeap(vector<int>&nums, int start, int end)
{
    int temp = nums[start];
    int i = 2*start+1;
    while(i <= end)
    {
        if(i+1 <= end and nums[i+1] > nums[i])
            i++;
        if(nums[i] <= temp)
            break;
        nums[start] = nums[i];
        start = i;
        i = 2*start+1;
    }
    nums[start] = temp;
    return ;
}
void heapSort(vector<int>nums)
{
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    clock_t start, end;

    int i;
    for(int i = nums.size()/2-1; i >= 0; i--)
    {
        adjustHeap(nums, i, nums.size()-1);
    }
    for(i = nums.size()-1; i > 0; i--)
    {
        swap(nums[i], nums[0]);
        adjustHeap(nums, 0, i-1);
    }

    QueryPerformanceCounter(&t2);
    double time = (double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart;
    cout << "HeapSort time used : " << time << "s\n";
    printNums(nums);
    return ;
}

void Merge(vector<int>&nums, int start, int mid, int end)
{
    int i = start, j = mid+1;
    vector<int>cmp;
    cmp.clear();
    while(i <= mid and j <= end)
    {
        if(nums[i] <= nums[j])
            cmp.push_back(nums[i++]);
        else
            cmp.push_back(nums[j++]);
    }
    while(i <= mid)
    {
        cmp.push_back(nums[i++]);
    }
    while(j <= end)
    {
        cmp.push_back(nums[j++]);
    }
    for(i = 0; i < cmp.size(); i++)
    {
        nums[i+start] = cmp[i];
    }
}

void MSort(vector<int>&nums, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end)/2;
        MSort(nums, start, mid);
        MSort(nums, mid+1, end);
        Merge(nums, start, mid, end);
    }
}
void mergeSort(vector<int>nums)
{
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    clock_t start, end;

    vector<int>tmp = nums;
    MSort(tmp, 0, tmp.size()-1);

    QueryPerformanceCounter(&t2);
    double time = (double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart;
    cout << "MergeSort time used : " << time << "s\n";
    printNums(tmp);
    return ;

}

void QSort(vector<int>&nums, int start, int end)
{
    if(start < end)
    {
        int left = start, right = end;
        int val = nums[start];
        while(left < right)
        {
            while(left < right and nums[right] > val)
                right--;
            if(left < right)
                nums[left] = nums[right];
            while(left < right and nums[left] < val)
                left++;
            if(left < right)
                nums[right--] = nums[left];
        }
        nums[left] = val;
        QSort(nums, start, left-1);
        QSort(nums, left+1, end);
    }
}

void quickSort(vector<int>nums)
{
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    clock_t start, end;

    QSort(nums, 0, nums.size()-1);

    QueryPerformanceCounter(&t2);
    double time = (double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart;
    cout << "QuickSort time used : " << time << "s\n";
    printNums(nums);
    return ;

}
void insert(vector<int>&arr, int val)
{
    auto iter = arr.begin();
    while(iter != arr.end() and val >= *iter)
        ++iter;
    arr.insert(iter, val);
}

void bucketSort(vector<int>nums)
{
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);
    clock_t start, end;

    int min_val = nums[0], max_val = min_val;
    for(auto num : nums)
    {
        if(num > max_val)
            max_val = num;
        else if(num < min_val)
            min_val = num;
    }
    int k = 10;

    int bucketNum = (max_val - min_val)/k+1;

    vector<vector<int>>buckets(bucketNum);
    for(auto num: nums)
    {
        insert(buckets[(num-min_val)/k], num);
    }
    int index = 0;
    for(auto bucket:buckets)
    {
        if(!bucket.empty())
        {
            for(auto num : bucket)
                nums[index++] = num;
        }
    }

    QueryPerformanceCounter(&t2);
    double time = (double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart;
    cout << "BucketSort time used : " << time << "s\n";
    printNums(nums);
    return ;

}
void bitSort(vector<int>nums)
{
    
}
int main()
{
    vector<int>nums = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    intersectionSort(nums);
    bubbleSort(nums);
    shellSort(nums);
    heapSort(nums);
    mergeSort(nums);
    quickSort(nums);
    bucketSort(nums);
    bitSort(nums);
    return 0;
}