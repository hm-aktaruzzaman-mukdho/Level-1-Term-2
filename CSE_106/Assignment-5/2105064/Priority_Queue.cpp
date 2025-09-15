#include <iostream>
#include <cstdlib>
#include <cmath>

//This file was created by student 2105064
template <typename type>
class Priority_Queue
{
private:
    type *Queue;
    int Queuelength;
    int Arraysize;

    // Helper functions
    int Left(int i) // Returns the index of the left child
    {
        return 2 * i;
    }
    int Right(int i) // Returns the index of the right child
    {
        return 2 * i + 1;
    }
    int Parent(int i) // Returns the index of the parent
    {
        return i / 2;
    }

    void swap(type &x, type &y)
    {
        type temp = x;
        x = y;
        y = temp;
    }

    void MaxHeapify(type *array, int i, int arraylength)
    {
        int l = Left(i);
        int r = Right(i);
        int large = i;

        // check if left child index is not bigger than Queuelength and the key is bigger than parent key
        if (l <= arraylength && array[large] < array[l])
            large = l;

        // check if right child index is not bigger than Queuelength and the key is bigger than parent key
        if (r <= arraylength && array[large] < array[r])
            large = r;

        // Proceeds to swap if either the left or right child has biggger key than the parents.
        // Otheriwse it is the ending of the recursion.
        if (large != i)
        {
            swap(array[i], array[large]);
            MaxHeapify(array, large, arraylength);
        }
    }

    // void SortQueue(type *array, int arraylength)
    // {
    //     if (arraylength < 2)
    //         return;
    //     swap(array[1], array[arraylength]);
    //     arraylength--;
    //     MaxHeapify(array, 1, arraylength);
    //     SortQueue(array, arraylength);
    // }

    // void SortQueue(int arraylength)
    // {
    //     if (arraylength < 2)
    //         return;
    //     swap(Queue[1], Queue[arraylength]);
    //     arraylength--;
    //     MaxHeapify(Queue, 1, arraylength);
    //     SortQueue(arraylength);
    // }

public:
    // Priority_Queue(int Queue_size)
    // {
    //     this->Arraysize=Arraysize;
    //     this->root=1;
    //     this->Queuelength=0;
    //     Queue=(type*)malloc(sizeof(type)*Arraysize+1);
    // }

    Priority_Queue()
    {
        this->Arraysize = 10;
        this->Queuelength = 0;
        Queue = (type *)malloc(sizeof(type) * Arraysize);
    }

    void Insert(type data)
    {

        /*Since the 0th index is always unused so we can keep n-1 data in the array if array size in n.
        So if Queuelength is Arraysize-1 it implies that the array is full and since insert is called
        more memeory is need for the key storing.When allocating more memory the array size is always doubled.*/
        if (Queuelength == Arraysize - 1)
        {
            Arraysize *= 2;
            Queue = (type *)realloc(Queue, sizeof(type) * Arraysize);
        }

        // The first element of the queue is stored in the index 1.so the index 0 is never used.
        Queuelength++;
        Queue[Queuelength] = data;
        int i = Queuelength;
        /*Inserted the new key  and checked with parents and swapped untill the parent is larger than the their child.
        can not use heapify here because this loop checks upward in the heap.*/
        while (i > 1)
        {
            if (Queue[i] > Queue[Parent(i)])
            {
                swap(Queue[i], Queue[Parent(i)]);
                i = Parent(i);
            }
            else
            {
                break;
            }
        }
    }

    type ExtractMax()
    {
        if (Queuelength > 0)
        {
            type maxvalue = Queue[1];

            Queue[1] = Queue[Queuelength];
            Queuelength--;
            MaxHeapify(Queue, 1, Queuelength);
            std::cout << "Max: " << maxvalue << " has been extracted.\n";
            return maxvalue;
        }
        else
        {
            std::cout<<"Priority queue is empty!\n";
            return (type)NULL;
        }
    }
    type FindMax()
    {
        if (Queuelength > 0)
        {
            std::cout << "Max: " << Queue[1] << std::endl;
            return Queue[1];
        }
        else
        {
            std::cout << "Priority Queue is empty" << std::endl;
            return (type)NULL;
        }
    }

    void IncreaseKey(int i, type newKey)
    {
        if(Queuelength<1)
        {
            std::cout<<"Priority Queue is empty!\n";
            return;
        }
        if(i>Queuelength)
        {
            std::cout<<"There is no value in current index.\n";
            return;
        }
        if (Queue[i] > newKey)
        {
            std::cout << "New key is not larger than the previous key\n";
        }
        else
        {
            std::cout << "Key increased!\n";
            Queue[i] = newKey;
            /*This loop checks upward till the root node and swaps keys to maintain heap property.
            If the parent have key value less than the child then their value is swaped to maintain
            max priority queue and parent becomes the new child and the checking and swapping is performed
            the root.If parent is not smaller the loop then breaks*/
            while (i > 1)
            {
                if (Queue[i] > Queue[Parent(i)])
                {
                    swap(Queue[i], Queue[Parent(i)]);
                    i = Parent(i);
                }
                else
                {
                    break;
                }
            }
        }
    }

    void DecreaseKey(int i, type newKey)
    {
        if(Queuelength<1)
        {
            std::cout<<"Priority Queue is empty!\n";
            return;
        }
        if(i>Queuelength)
        {
            std::cout<<"There is no value in current index.\n";
            return;
        }
        if (Queue[i] < newKey) // Checks if the key is small
        {
            std::cout << "New key is not smaller than the previous key\n";
        }
        else
        {
            std::cout << "Key decreased!\n";
            Queue[i] = newKey;
            MaxHeapify(Queue, i, Queuelength); // MaxHeapify is called to maintain the max priority queue after the key change.
        }
    }

    void Print()
    {
        // std::cout << std::endl;
        std::cout << "No of elements: " << Queuelength << std::endl;

        int count1 = 1, count2 = 0, height = ceil(log2(Queuelength + 1));
        // count1 -> maximum number of elements can be present on the current level.
        // count2 -> number of elements printed on current level.
        // height -> height of the current level.
        // All of them ar initialized for root node key.

        for (int i = 1; i <= Queuelength; i++)
        {
            //Code for printing maxheight for pyramid shape.
            // for (int j = 1; j <= (pow(2, height)-1); j++) // Space before every element
            // {
            //     std::cout << " ";
            // }

            // printf("%2d", Queue[i]); // Printing the key

            // for (int j = 1; j <= (pow(2, height) - 1); j++) // Space after every element
            // {
            //     std::cout << " ";
            // }

            
            std::cout << Queue[i] << "\t";
            count2++; // Keeps the number of elements printed in the current level.

            if (count2 % count1 == 0) // This condition is only true when we have printed the maximum number ofelements in a level.
            {
                std::cout << "\n";   // Line break after every level.
                count1 = count1 * 2; // When going to the next level this is doubled
                count2 = 0;          // Initialized the number of elements printed on current level to 0.
                height--;
            }
        }

        std::cout << std::endl;
    }

    void SortQueue()
    {
        int temp = Queuelength;
        // SortQueue(temp);
        while (temp > 1)
        {
            swap(Queue[1], Queue[temp]);
            temp--;
            MaxHeapify(Queue, 1, temp);
        }
    }

    // void printarray()
    // {
    //     std::cout << std::endl;
    //     for (int i = 1; i <= Queuelength; i++)
    //     {
    //         std::cout << Queue[i] << ",";
    //     }
    // }
};