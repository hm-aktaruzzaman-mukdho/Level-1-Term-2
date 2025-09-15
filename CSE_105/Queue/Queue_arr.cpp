template <typename type>
class Queue
{
protected:
    int size, head, tail;
    type *headpointer;

public:
    Queue()
    {
        size = 10;
        headnointer = new type[size];
        head = -1;
        tail = -1;
    }

    Queue(int size)
    {
        this->size = size;
        headnointer = new type[this->size];
        head = -1;
        tail = -1;
    }

    void enque(type data)
    {
        if (head == -1)
            head = 0;
        if (!isFull())
        {
            tail++;
            headpointer[tail] = data;
        }
    }

    type deque()
    {
        if (!isEmpty())
        {
            type temp = headpointer[head];
            head++;
            if (head > tail)
            {
                head = tail = -1;
            }
            return temp;
        }
    }

    bool isFull()
    {
        if (tail == size - 1)
            return true;
        else
            return false;
    }

    bool isEmpty()
    {
        if (head == -1)
            return true;
        else
            return false;
    }

    type curVal()
    {
        if (!isEmpty())
            return headpointer[head];
    }

    void printqueue()
    {
        std::cout << "<";
        for (int i = front; i <= top; i++)
        {
            std::cout << headpointer[i] << " ";
        }
        std::cout << ">" << std::endl;
    }
};