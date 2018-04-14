#include<iostream>
using namespace std;

int maxHeapSize = 0;

void maxHeapify(int brr[], int brrLength){

    int lastParent = (brrLength-1)/2;
    int lc, rc, sc, temp, p;

    for(int i=lastParent; i>=0; i--){
        p = i;

        while(1){
            lc = 2*p + 1;
            rc = 2*p + 2;

            if(lc > (brrLength - 1))
                break;
            else if((lc <= (brrLength - 1)) && (rc > (brrLength - 1))){
                sc = lc;
            }
            else{
                sc = brr[lc] >= brr[rc] ? lc : rc;
            }

            if(brr[sc] > brr[p]){
                temp = brr[sc];
                brr[sc] = brr[p];
                brr[p] = temp;

                p = sc;
            }
            else{
                break;
            }
        }
    }
}

bool itIsAMaxheap(int brr[], int brrLength){
    int lastParent = (brrLength-1)/2;
    int lc, rc;

    for(int i=0; i<=lastParent; i++){
        lc = 2*i + 1;
        rc = 2*i + 2;

        if((lc <= (brrLength-1)) && (rc > (brrLength - 1))){
            if(brr[i] < brr[lc]){
                return false;
            }
        }
        else if((lc <= (brrLength-1)) && (rc <= (brrLength - 1))){
            if((brr[i] < brr[lc]) || (brr[i] < brr[rc])){
                return false;
            }
        }
    }

    return true;
}

void deleteFromMaxHeap(int brr[], int brrLength){

    int temp;
    temp = brr[0];
    brr[0] = brr[brrLength-1];
    brr[brrLength-1] = temp;

    maxHeapSize--;

    maxHeapify(brr, maxHeapSize);
}

void ascendingHeapSort(int brr[]){
    while(maxHeapSize>0){
        deleteFromMaxHeap(brr, maxHeapSize);
    }
}

int main(){

    int brr[10] = {32,45,12,64,23,61,21,34,97,86};

    int brrLength = sizeof(brr)/sizeof(brr[0]);

    maxHeapSize = brrLength;

    maxHeapify(brr,maxHeapSize);

    if(itIsAMaxheap(brr,maxHeapSize)){
        cout<<"Max Heap created successfully!\n";
    }
    else{
        cout<<"Heap creation failed!\n";
    }

    for(int i=0; i<maxHeapSize; i++){
        cout<<brr[i]<<" ";
    }

    cout<<endl<<endl;

    ascendingHeapSort(brr);
    cout<<"After ascending sort...\n";
    for(int i=0; i<brrLength; i++){
        cout<<brr[i]<<" ";
    }

    cout<<endl;

    return 0;

}
