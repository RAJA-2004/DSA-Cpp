#include <bits/stdc++.h>
using namespace std;

// ! insertion time : O(logn)
// ! deletion time  : O(logn)
// ! find max or min element in array : O(n)

#define endl '\n'

class Heap{
    public:
        int *arr;
        int size;
        int capacity;
        Heap(int capacity){
            this->arr = new int[capacity];
            this->capacity = capacity;
            this->size = 0;
        }
        void insert(int val){
            if(size == capacity){
                cout << "Heap overflow";
            }
            size++;

            int index = size;
            arr[index] = val;
            while(index > 1){
                if(arr[index/2]<arr[index]){
                    swap(arr[index/2],arr[index]);
                    index /=2;
                }else{
                    break;
                }
            }
        }
        int deletion(){
            int answer = arr[1];
            arr[1] = arr[size];
            size--;
            int index = 1;
            while(index < size){
                int leftIndex = 2*index;
                int rightIndex = (2*index) + 1;

                int largestIndex = index;
                if(leftIndex <= size && arr[largestIndex] < arr[leftIndex]){
                    largestIndex = leftIndex;
                }
                if(rightIndex <= size && arr[largestIndex] < arr[rightIndex]){
                    largestIndex = rightIndex;
                }
                if(index == largestIndex){
                    break;
                }else{
                    swap(arr[index],arr[largestIndex]);
                    index = largestIndex;
                }
            }
            return answer;
        }
        void print(){
            for(int i=1;i<=size;i++){
                cout << arr[i] << " ";
            }
        }
};

void heapify(int arr[],int size,int index){
    int leftIndex = 2*index;
    int rightIndex = 2*index+1;
    int largestIndex = index;

    if(largestIndex <= size && arr[largestIndex] < arr[leftIndex]){
        largestIndex = leftIndex;
    }
    if(largestIndex <= size && arr[largestIndex] < arr[rightIndex]){
        largestIndex = rightIndex;
    }

    if(largestIndex != index){
        swap(arr[largestIndex],arr[index]);
        index = largestIndex;
        heapify(arr,size,index);
    }
}

void buildheap(int arr[],int n){
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}

int main(){
    Heap h(20);
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);
    h.print();
    cout << endl << h.deletion() << endl;
    h.print();
    cout << endl;
    int arr[10];
    for(int i=0;i<10;i++){
        arr[i]=i;
    }
    buildheap(arr,10);
    for(int i=1;i<=10;i++){
        cout << arr[i] << endl;
    }
    return 0;
}