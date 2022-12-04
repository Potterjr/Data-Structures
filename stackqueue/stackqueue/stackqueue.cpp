#include <iostream>
using namespace std;
template <class Object>
class Queue
{
public:
    explicit Queue(int capacity = 10);

    bool isEmpty() const;
    bool isFull() const;
    const Object& getFront() const;
    void makeEmpty();
    Object dequeue();
    void enqueue(const Object& x);

private:
    vector<Object> theArray;
    int currentSize;
    int front;
    int back;

    void increment(int& x);

};
 

template <class Object>
Queue<Object>::Queue(int capacity) :theArray(capacity)
{
    makeEmpty();
}


template <class Object>
void Queue<Object>::makeEmpty()
{
    currentSize = 0;
    front = 0;
    back = -1;
}


template <class Object>
void Queue<Object>::enqueue(const Object& x) {
    if (isFull())
        throw Overflow();
    increment(back);
    theArray[back] = x;
    currentSize++;
}


template <class Object>
void Queue<Object>::increment(int& x) {
    if (++x == theArray.size())
        x = 0;

}

template <class Object>
Object Queue<Object>::dequeue()
{
    if (isEmpty())
        throw Underflow();

    currentSize--;
    Object frontItem = theArray[front];
    increment(front);
    return frontItem;
}
//-------------------------------------------------------------------------------
template <class Object>
class Stack {
public:
    explicit Stack(int capacity = 10);

    bool isEmpty() const;
    bool isFull() const;
    const Object& top() const;
    void makeEmpty();
    void pop();
    void push(const Object& x);
    Object topAndPop();

private:
    vector<Object> theArray;
    int topOfStack;
};



template <class Object>
Stack<Object>::Stack( int capacity ) : theArray( capacity ) {

topOfStack = -1; }


template <class Object>
bool Stack<Object>::isEmpty( ) const {

return topOfStack == -1; }


template <class Object>
bool Stack<Object>::isFull( ) const {
return topOfStack == theArray.size( ) - 1; }


template <class Object>
void Stack<Object>::makeEmpty( ) {
topOfStack = -1; }




template <class Object>
void Stack<Object>::push( const Object & x ) {
if( isFull( ) ) throw Overflow( );
theArray[ ++topOfStack ] = x;
}


template <class Object>
const Object & Stack<Object>::top( ) const {
if( isEmpty( ) ) throw Underflow( );
return theArray[ topOfStack ];
}


template <class Object>
void Stack<Object>::pop( ) {
if( isEmpty( ) ) throw Underflow( );
topOfStack--;
}


template <class Object>
Object Stack<Object>::topAndPop( ) {
if( isEmpty( ) )
throw Underflow( );
return theArray[ topOfStack-- ];
}

int main()
{
    int x;
    Queue<int>b(5);
    Stack<int>a(5);
    b.enqueue(20);
    a.push(b.dequeue());
    b.makeEmpty();
   x= b.getFront();
   x = b.isEmpty();
   x = b.isFull();
     cout << x;
     cout << "Hello World!\n";
}


