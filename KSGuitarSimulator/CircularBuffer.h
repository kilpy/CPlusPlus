#include <stdint.h>
#include <iostream>
#include <vector>
#include <memory>

using std::vector;
//class CirclularBuffer

class CircularBuffer{
public:
CircularBuffer(int capacity); //constructor given a max

int size();		//return number of items currently in buffer
bool isEmpty();		//does size = 0
bool isFull(){return Size == Capacity;}	//does size=capacity
void enqueue(int16_t x);//add item x to the end
int16_t dequeue();	//delete and return item from the front
int16_t peek();		//return (but do not delete) item from the front

//friend ostream& operator<<(ostream& out, const CircularBuffer& item);
//private:
int Capacity;
int Size;
//vector<int16_t> buffer;
std::unique_ptr<int16_t[]>buffer;
int front;
int back;
};
