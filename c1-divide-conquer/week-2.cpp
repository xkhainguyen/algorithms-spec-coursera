#include <bits/stdc++.h>
using namespace std;

class CountInv
{
    /* Counting Inversions: Use Merge Sort */
    public:

   long long int sort_and_count(int arr[], int array_size)
    {
        return _sort_and_count(arr, 0, array_size - 1);
    }

    long long int merge_and_countSplitInv(int *arr, int left, int mid, int right)
    {
        int i, j, k;
        long long int inv_count = 0;
        int temp[right+1];
    
        i = left;   // i is index for left subarray
        j = mid + 1;    // j is index for right subarray
        k = left;   // k is index for merged array
        while ((i <= mid) && (j <= right)) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];

                inv_count += (mid - i + 1);
            }
        }
    
        /* Copy the remaining elements of left subarray (if there are any) to 
        temp*/
        while (i <= mid)
            temp[k++] = arr[i++];
    
        /* Copy the remaining elements of right subarray (if there are any) to 
        temp*/
        while (j <= right)
            temp[k++] = arr[j++];
    
        /*Copy back the merged elements to original array*/
        for (i = left; i <= right; i++)
            arr[i] = temp[i];
    
        return inv_count;        
    }

    long long int _sort_and_count(int arr[], int left, int right)
    {
        int mid;
        long long int inv_count = 0;

        if (right > left) {
            mid = (right + left) / 2;
    
            inv_count += _sort_and_count(arr, left, mid);
            inv_count += _sort_and_count(arr, mid + 1, right);
    
            /*Merge the two parts*/
            inv_count += merge_and_countSplitInv(arr, left, mid, right);
        }
        return inv_count;
    }
  
};

int main()
{
    int arr[100000];
    int n = 0;
    int temp;

    ifstream inFile;
    inFile.open("file-test.txt");
    if (inFile.is_open())
        while (inFile >> temp)
        arr[n++] = temp;
    else
        cout << "Cannot open the file!";
    // for (int i = 0; i < n; i++) cout << arr[i] << endl;

    inFile.close(); // CLose input file

    CountInv alg;

    long long int ans = alg.sort_and_count(arr, n);
    cout << "Number of inversions are " << ans;
    return 0;
} 