//Name Tarush
//SID 21105112

/*

Ans 1) We can search an element in an array whose size is unknown in O(logn) time complexity provided that the array is in sorted order (here i am taking case of ascending order).
We can do this by making some modification in binary search technique.
The concept behind this approach is:
*Take inital value of i as 0 and j as 1.
*Now increase j to j*2 until arr[j] exceed the key to be searched.
*Now search the key using binary search between i and j.

*/

#include <iostream>
using namespace std;


//simple binary search function
int binary_search(int arr[],int i,int j,int key){
    int m=(i+j)/2; //m=middle element
    while(i<=j){   //i=starting index j=ending index
    if(arr[m]==key){return m;}  // if key to be searched is present we will return index of the key
    else{
        if(arr[m]<key){i=m+1;}
        else{j=m-1;}
    }
    m=(i+j)/2;
    }
    return -1;  // when element is not present we will return -1
}
//enhanced binary search function or binary search for array with unknown length
int binary_search_unknown(int arr[],int key){
    //initializing i as 0 and j as 1.
    int i=0,j=1;
    //increase j until arr[j] exceeds key to be searched.
    while(arr[j]<key){
        i=j;
        j=2*j;
    }
    //simple binary search on range i to j.
    return binary_search(arr,i,j,key);
}
