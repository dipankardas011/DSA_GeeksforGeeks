/*Sparse Search
Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string.

Examples:

Input : arr[] = {"for", "geeks", "", "", "", "", "ide", 
                      "practice", "", "", "", "quiz"}
          x = "geeks"
Output : 1

Input : arr[] = {"for", "geeks", "", "", "", "", "ide", 
                      "practice", "", "", "", "quiz"}, 
          x = "ds"
Output : -1*/
#include <iostream>
#include <string>

int binarySearch(std::string *arr, int low, int high, std::string x)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    /*Modified Part*/
    if (arr[mid] == "")
    {
        int left = mid - 1;
        int right = mid + 1;

        /*Search for both side for a non empty string*/
        while (1)
        {

            /* No non-empty string on both sides */
            if (left < low && right > high)
                return -1;

            if (left >= low && arr[left] != "")
            {
                mid = left;
                break;
            }

            else if (right <= high && arr[right] != "")
            {
                mid = right;
                break;
            }

            left--;
            right++;
        }
    }

    /* Normal Binary Search */
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x)
        return binarySearch(arr, low, mid - 1, x);
    else
        return binarySearch(arr, mid + 1, high, x);
}

int sparseSearch(std::string arr[], std::string x, int n)
{
    return binarySearch(arr, 0, n - 1, x);
}

int main(int argc, char const *argv[])
{
    std::string arr[] = {"for", "geeks", "", "", "", "", "ide", "practice", "", "", "", "quiz"};
    int index;
    std::string x = "geeks";
    std::string x1 = "at";
    int n = sizeof(arr) / sizeof(arr[0]);
    index = sparseSearch(arr, x,n);
    if (index == -1)
        std::cout << "ERROR! not found~~" << std::endl;
    else
        std::cout << "found at  index= " << index << std::endl;

    index = sparseSearch(arr, x1, n);
    if (index == -1)
        std::cout << "ERROR! not found~~" << std::endl;
    else
        std::cout << "found at  index= " << index << std::endl;
    return 0;
}
