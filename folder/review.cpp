#include <iostream>
#include <algorithm> // std::copy를 위해

using namespace std;

class MinHeap {
private:
  int* heap;
  int capacity;
  int size;

  int parent(int i) { return (i - 1) / 2; }


  int leftChild(int i) { return 2 * i + 1; }


  int rightChild(int i) { return 2 * i + 2; }

  void heapifyUp(int i) {
    while (i > 0 && heap[parent(i)] > heap[i]) {
      swap(heap[parent(i)], heap[i]);
      i = parent(i);
    }
  }

  void heapifyDown(int i) {
    int left = leftChild(i);
    int right = rightChild(i);
    int smallest = i;

    if (left < size && heap[left] < heap[smallest]) {
      smallest = left;
    }

    if (right < size && heap[right] < heap[smallest]) {
      smallest = right;
    }

    if (smallest != i) {
      swap(heap[i], heap[smallest]);
      heapifyDown(smallest);
    }
  }

  void resize(int newCapacity) {
    int* newHeap = new int[newCapacity];
    copy(heap, heap + size, newHeap); // 기존 데이터 복사
    delete[] heap; // 기존 메모리 해제
    heap = newHeap;
    capacity = newCapacity;
  }

public:
  // 생성자
  MinHeap(int initialCapacity = 10) : capacity(initialCapacity), size(0) {
    heap = new int[capacity];
  }

  // 소멸자
  ~MinHeap() {
    delete[] heap;
  }

  // meta func
  bool empty() { return size == 0; }

  int size() { return size; }


  void push(int value) {
    if (size == capacity) {
      resize(capacity * 2); 
    }
    heap[size] = value;
    size++;
    heapifyUp(size - 1);
  }

  int top() { 
    if (empty()) {
      throw out_of_range("Heap is empty"); 
    }
    return heap[0]; 
  }

  void pop() {
    if (empty()) {
      throw out_of_range("Heap is empty"); 
    }
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
  }
};

int main() {
  MinHeap minHeap;

  minHeap.push(10);
  minHeap.push(30);
  minHeap.push(20);
  minHeap.push(5);
  minHeap.push(40);
  minHeap.push(15);

  cout << "힙의 내용: ";
  while (!minHeap.empty()) {
    cout << minHeap.top() << " ";
    minHeap.pop();
  }
  cout << endl; 

  return 0;
}
