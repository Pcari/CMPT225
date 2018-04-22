/* File: char_stack.h       

  Header file for a very basic array-based implementation of a stack.

*/
class char_stack
{
  public:
    char_stack();
    void push( char item );
    char pop(); 
    char top();
    bool empty();
    int size();

  private:
    static const int CAPACITY = 100;
    int top_index;
    char A[CAPACITY];
    int currentSize;
};