#include<iostream>
using namespace std;

int minHeapSize = 0;

void minHeapify(int arr[], int arrLength){

    int lastParent = arrLength/2;
    int lc, rc, sc, temp, p;

    for(int i=lastParent; i>=1; i--){
        p = i;

        while(1){
            lc = 2*p;
            rc = 2*p + 1;

            if(lc > arrLength)
                break;
            else if((lc <= arrLength) && (rc > arrLength)){
                sc = lc;
            }
            else{
                sc = arr[lc] <= arr[rc] ? lc : rc;
            }

            if(arr[sc] < arr[p]){
                temp = arr[sc];
                arr[sc] = arr[p];
                arr[p] = temp;

                p = sc;
            }
            else{
                break;
            }
        }
    }
}

bool itIsAMinheap(int arr[], int arrLength){
    int lastParent = arrLength/2;
    int lc, rc;

    for(int i=1; i<=lastParent; i++){
        lc = 2*i;
        rc = 2*i + 1;

        if((lc <= arrLength) && (rc > arrLength)){
            if(arr[i] > arr[lc]){
                return false;
            }
        }
        else if((lc <= arrLength) && (rc <= arrLength)){
            if((arr[i] > arr[lc]) || (arr[i] > arr[rc])){
                return false;
            }
        }
    }

    return true;
}

void deleteFromMinHeap(int arr[], int arrLength){

    int temp;
    temp = arr[1];
    arr[1] = arr[arrLength];
    arr[arrLength] = temp;

    minHeapSize--;

    minHeapify(arr, minHeapSize);
}

void descendingHeapSort(int arr[]){
    while(minHeapSize>0){
        deleteFromMinHeap(arr, minHeapSize);
    }
}

int main(){

    int arr[11] = {-9999,32,45,12,64,23,61,21,34,97,86};

    int arrLength = (sizeof(arr)/sizeof(arr[0])) - 1;

    minHeapSize = arrLength;

    minHeapify(arr,minHeapSize);

    if(itIsAMinheap(arr,minHeapSize)){
        cout<<"Min Heap created successfully!\n";
    }
    else{
        cout<<"Heap creation failed!\n";
    }

    for(int i=1; i<=minHeapSize; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl<<endl;

    descendingHeapSort(arr);
    cout<<"After descending sort...\n";
    for(int i=1; i<=arrLength; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    return 0;

}
