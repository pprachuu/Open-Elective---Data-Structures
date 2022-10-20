//Name Tarush
//SID 21105112

/*
Ans 1)
An "In-Place" sorting algorithm is algorithm whose space complexity lies between O(1) and O(log n) both included.
We can say an in-place algorithm is an algorithm that does need small extra space and produces an output
in the same memory that contains the data by transforming the input �in-place�.
Where as an "Out-Place" sorting algorithm is algorithm whose space complexity is greater than O(log n).
*/

//Ans 2)

//Insertion Sort Using In-Place Algorithm

#include <iostream>
using namespace std;

//Creating Insertion Sort void function
void insertion_sort_IP(int arr[],int n){

    //Initialising variables i and j
    int i=0,j=i+1;
    while(j<=n-1){
        int temp=arr[j];
        while(i>=0){
            if(arr[i]>temp){
                arr[i+1]=arr[i];
                i--;
            }
            if(i==-1){arr[0]=temp;break;}
            if(arr[i]<=temp){arr[i+1]=temp;break;}
        }
        j++;
        i=j-1;
    }
    return;
}

//Insertion Sort Using Out-Place Algorithm
void insertion_sort_OP(int arr[],int si,int ei){
    //si=starting index
    //ei=ending index
    if(si==ei){return;}
    int j=si+1;
    int temp=arr[j];
    while(si>=0){
        if(arr[si]>temp){
            arr[si+1]=arr[si];
            si--;
        }
        if(si==-1){arr[0]=temp;break;}
        if(arr[si]<=temp){arr[si+1]=temp;break;}
    }
    insertion_sort_OP(arr,si+1,ei);
}
//Function to print array
void pfun(int arr[],int n){
    for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
}
int main(){
    int n;
    //Taking Input array
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n],arr2[n];//Two array with same size and elements
    cout<<"Enter elements of array separated by space: ";
    for(int i=0;i<n;i++){cin>>arr[i];}
    //copying arr to arr2
    for(int i=0;i<n;i++){arr2[i]=arr[i];}
    cout<<endl;
    cout<<"array before sorting: ";pfun(arr,n);
    //Calling insertion sort using in-place algorithm.
    insertion_sort_IP(arr,n);
    cout<<endl;
    cout<<"array after sorting using in-place algorithm : ";
    //printing the array
    pfun(arr,n);
    cout<<endl;
    //calling inserting sort using out-place algorithm.
    insertion_sort_OP(arr2,0,n-1);
    cout<<"array after sorting using out-place algorithm: ";
    //printing the array
    pfun(arr,n);
    cout<<endl;

}

/*
Ans 3)
In-place techniques have lesser space complexity but are difficult to apply in algorithm whereas out-place techniques are easy to apply but
increases the space complexity of algorithm.

For example if we want to reverse an array then its in-place algorithm
will be swapping the first and last element of array until we reach the
middle of array,If we want to solve the same problem using out-place
algorithm we have to create one extra array of same size and copy
elements of original array from back to the front of new array,this
algorithm increases the space complexity to O(n) as we have created an
extra array.

In-place algorithm are used in Bubble sort, Selection Sort, Insertion Sort, Heap-sort.
Not In-place algorithm is used in Merge Sort, Because merge sort requires O(n) extra space.
*/
