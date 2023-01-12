#include "CircularBuffer.h"
#include <exception>

using std::cout;
using std::endl;
using std::vector;
CircularBuffer::CircularBuffer(int capacity) //constructor given a max
{
	if(capacity < 1)
	{
		throw std::invalid_argument("CircularBuffer constructor: capacity must be greater than zero.");
	}else{
	//buffer.reserve(capacity);
	Capacity = capacity;
	Size = 0;
	front = 0;
	//back = 0;
	buffer = std::unique_ptr<int16_t[]>(new int16_t[capacity]);
	}
}

int CircularBuffer::size()//return number of items currently in buffer
{
	return Size;
}
bool CircularBuffer::isEmpty()//does size = 0
{
	if (Size == 0)
	{return true;}
	else{return false;}
}

void CircularBuffer::enqueue(int16_t x)//add item x to the end
{
	if(isFull()){
	throw std::runtime_error("enqueue: cant enqueue to full buffer");
	}
	back = (front + Size) % Capacity;
	buffer[back] = x;

	Size++;
}

int16_t CircularBuffer::dequeue()//delete and return item from the front
{
	if(isEmpty())
	{
	throw std::runtime_error("dequeue: can't dequeue from empty ring");
	}

	int16_t item = buffer[front];
	front = (front + 1) % Capacity;
	Size--;
	int i = 0;
	/*for(vector<int16_t>::iterator it = buffer.begin(); it != buffer.end(); it++, i++)
	{
		buffer[i] = buffer[i+1];
	}
	Size--;*/
	return item;

}
int16_t CircularBuffer::peek()//return (but do not delete) item from the front
{
	if(isEmpty()){
	throw std::runtime_error("peek: can't peek from empty ring");
	}
	int16_t item = buffer[front];
	return item;
	
}

//ostream& operator<<(ostream& out, const CircularBuffer& c){

