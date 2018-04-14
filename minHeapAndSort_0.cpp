#include<iostream>
using namespace std;

int minHeapSize = 0;

void minHeapify(int arr[], int arrLength){

    int lastParent = (arrLength-1)/2;
    int lc, rc, sc, temp, p;

    for(int i=lastParent; i>=0; i--){
        p = i;

        while(1){
            lc = 2*p + 1;
            rc = 2*p + 2;

            if(lc > (arrLength - 1))
                break;
            else if((lc <= (arrLength - 1)) && (rc > (arrLength - 1))){
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
    int lastParent = (arrLength-1)/2;
    int lc, rc;

    for(int i=0; i<=lastParent; i++){
        lc = 2*i + 1;
        rc = 2*i + 2;

        if((lc <= (arrLength-1)) && (rc > (arrLength - 1))){
            if(arr[i] > arr[lc]){
                return false;
            }
        }
        else if((lc <= (arrLength-1)) && (rc <= (arrLength - 1))){
            if((arr[i] > arr[lc]) || (arr[i] > arr[rc])){
                return false;
            }
        }
    }

    return true;
}

void deleteFromMinHeap(int arr[], int arrLength){

    int temp;
    temp = arr[0];
    arr[0] = arr[arrLength-1];
    arr[arrLength-1] = temp;

    minHeapSize--;

    minHeapify(arr, minHeapSize);
}

void descendingHeapSort(int arr[]){
    while(minHeapSize>0){
        deleteFromMinHeap(arr, minHeapSize);
    }
}

int main(){

    int arr[10] = {32,45,12,64,23,61,21,34,97,86};

    int arrLength = sizeof(arr)/sizeof(arr[0]);

    minHeapSize = arrLength;

    minHeapify(arr,minHeapSize);

    if(itIsAMinheap(arr,minHeapSize)){
        cout<<"Min Heap created successfully!\n";
    }
    else{
        cout<<"Heap creation failed!\n";
    }

    for(int i=0; i<minHeapSize; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl<<endl;

    descendingHeapSort(arr);
    cout<<"After descending sort...\n";
    for(int i=0; i<arrLength; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    return 0;

}
