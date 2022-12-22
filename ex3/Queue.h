#ifndef EX3_Queue_H
#define EX3_Queue_H

#include <cassert>
#include <new>

template <class DataType>
class Queue
{
public:
    
    /*
    * Creator of Queue class.
    *
    * @return
    *      A new instance of Queue.
   */
    Queue();

    /*
    * Destructor of Queue class.
   */
    ~Queue();

    /*
    * Copy constructor of Queue class
    */
    Queue(const Queue &other);

    /*
    * Assingment operator of Queue class
    */
    Queue &operator=(const Queue & other);

    /*
    * Adds the data to the end of the Queue.
    *
    * @param value - The value of the data.
   */
    void pushBack(const DataType& value);

    /*
    * Returns the data first in the Queue.
    * Has a const and non const version.
    * 
    * @return
    *      The DataType that is in the front.
   */
    DataType &front();
    const DataType &front() const;

    /*
    * Removes the first data in the queue
   */
    void popFront();

    /*
    * Returns the size of the Queue.
    *
    * @return
    *      integer representing the size.
   */
    int size() const;

    /*
    * Class for iterating the queue.
   */
    class Iterator;

    /*
    * Class for iterating the queue.
   */
    class ConstIterator;

    /*
    * Returns the beginning of the queue.
    *
    * @return
    *      Iterator obj with the pointer to the beginning of the queue.
   */
    Iterator begin();

    /*
    * Returns the ending of the queue.
    *
    * @return
    *      ConstIterator obj with the pointer to the ending of the queue.
   */
    Iterator end();

    /*
    * Returns the beginning of the queue.
    *
    * @return
    *      ConstIterator obj with the pointer to the beginning of the queue.
   */
    ConstIterator begin() const;

    /*
    * Returns the ending of the queue.
    *
    * @return
    *      ConstIterator obj with the pointer to the ending of the queue.
   */
    ConstIterator end() const;


    /*
     * Exceptions
     */
    class EmptyQueue : public std::exception {};

private:
    DataType** m_data;
    int m_maxSize;
    int m_nextIndex;
    static const int DEFAULT_MAX_SIZE = 10;
    static const int QUEUE_EXPAND_RATE = 2;

    /*
     * Expands the queue to have more room for data.
    */
    void expand();

    /*
     * Contracts the queue to have less room for data.
    */
    void contract();

    /*
     * Frees all pointers in an array of pointers.
     *
     * @param array - array of pointers.
     * @param size - size of the array.
     */
    static void freeQueueMemory(DataType** array, int size);

    /*
     * copying content of array of pointers while handling badAlloc exception.
     *
     * @param dest - the array to copy to.
     * @param source - the array to copy from.
     * @param size - the number of elements needed to be copied.
     */
    static void copyData(DataType** dest, DataType** source, int size);
};

template <class DataType>
class Queue<DataType>::Iterator
{
public:
    /*
     * Operator overloads needed for iterating the queue class objects
    */
    DataType &operator*();
    Iterator &operator++();
    Iterator operator++(int);
    bool operator==(const Iterator &other) const;
    bool operator!=(const Iterator &other) const;

    /*
    * Explicitly telling the compiler to use the default methods
   */
    ~Iterator() = default;
    Iterator(const Iterator &) = default;
    Iterator &operator=(const Iterator &) = default;

    /*
    * Exceptions
    */
    class InvalidOperation : public std::exception {};

private:
    Queue<DataType> *m_queue;
    int m_index;

    /*
    * Creator of Iterator class.
    *
    * @return
    *      A new instance of Iterator.
   */
    Iterator(Queue<DataType> *queue, int index);

    /*
    * Declaring Queue class as a friend class.
   */
    friend class Queue<DataType>;


};


template <class DataType>
class Queue<DataType>::ConstIterator
{
public:
    /*
     * Operator overloads needed for iterating the queue class objects
    */
    const DataType &operator*() const;
    ConstIterator &operator++();
    ConstIterator operator++(int);
    bool operator==(const ConstIterator &other) const;
    bool operator!=(const ConstIterator &other) const;

    /*
    * Explicitly telling the compiler to use the default methods
   */
    ~ConstIterator() = default;
    ConstIterator(const ConstIterator &) = default;
    ConstIterator &operator=(const ConstIterator &) = default;

    /*
    * Exceptions
    */
    class InvalidOperation : public std::exception {};

private:
    const Queue<DataType> *m_queue;
    int m_index;

    /*
    * Creator of ConstIterator class.
    *
    * @return
    *      A new instance of ConstIterator.
   */
    ConstIterator(const Queue<DataType> *queue, int index);

    /*
    * Declaring Queue class as a friend class.
   */
    friend class Queue<DataType>;


};


/*
* ----------------------------------= Queue Class Definitions =------------------------------------
*/

template <class DataType>
Queue<DataType>::Queue() :
    m_data(new DataType*[DEFAULT_MAX_SIZE]),
    m_maxSize(DEFAULT_MAX_SIZE),
    m_nextIndex(0)
{}


template <class DataType>
Queue<DataType>::~Queue()
{
    freeQueueMemory(m_data, m_nextIndex);
    delete[] m_data;
}


template <class DataType>
Queue<DataType>::Queue(const Queue<DataType> &other) :
    m_data(new DataType*[other.m_maxSize]),
    m_maxSize(other.m_maxSize),
    m_nextIndex(other.m_nextIndex)
{
    copyData(m_data, other.m_data, other.m_nextIndex);
}


template <class DataType>
Queue<DataType> &Queue<DataType>::operator=(const Queue<DataType> & other)
{
    if (this == &other)
    {
        return *this;
    }
    DataType** newData = new DataType*[other.m_maxSize];
    copyData(newData, other.m_data, other.m_nextIndex);
    freeQueueMemory(m_data, m_nextIndex);
    delete[] m_data;
    m_data = newData;
    m_maxSize = other.m_maxSize;
    m_nextIndex = other.m_nextIndex;
    return *this;
}


template <class DataType>
void Queue<DataType>::pushBack(const DataType& value) {
    if (m_nextIndex >= m_maxSize) {
        this->expand();
    }
    m_data[m_nextIndex++] = new DataType(value);
}

template <class DataType>
DataType& Queue<DataType>::front()
{
    if (m_nextIndex == 0)
    {
        throw EmptyQueue();
    }
    return *(m_data[0]);
}

template <class DataType>
const DataType &Queue<DataType>::front() const
{
    if (m_nextIndex == 0)
    {
        throw EmptyQueue();
    }
    return *(m_data[0]);
}

template <class DataType>
void Queue<DataType>::popFront()
{
    if (m_nextIndex == 0)
    {
        throw EmptyQueue();
    }
    delete m_data[0];
    m_nextIndex--;
    for (int i = 0; i < m_nextIndex; ++i)
    {
        m_data[i] = m_data[i + 1];
    }
    if (m_nextIndex < m_maxSize / (QUEUE_EXPAND_RATE + QUEUE_EXPAND_RATE))
    {
        this->contract();
    }
}

template <class DataType>
int Queue<DataType>::size() const
{
    return m_nextIndex;
}

template <class DataType>
typename Queue<DataType>::Iterator Queue<DataType>::begin()
{
    return Iterator(this, 0);
}

template <class DataType>
typename Queue<DataType>::Iterator Queue<DataType>::end()
{
    return Iterator(this, this->size());
}

template <class DataType>
typename Queue<DataType>::ConstIterator Queue<DataType>::begin() const
{
    return ConstIterator(this, 0);
}

template <class DataType>
typename Queue<DataType>::ConstIterator Queue<DataType>::end() const
{
    return ConstIterator(this, this->size());
}


template <class DataType>
void Queue<DataType>::expand()
{
    m_maxSize *= QUEUE_EXPAND_RATE;
    DataType **newData = new DataType*[m_maxSize];
    copyData(newData, m_data, m_nextIndex);
    freeQueueMemory(m_data, m_nextIndex);
    delete[] m_data;
    m_data = newData;
}


template <class DataType>
void Queue<DataType>::contract()
{
    if (m_maxSize == DEFAULT_MAX_SIZE)
    {
        return;
    }

    m_maxSize /= QUEUE_EXPAND_RATE;
    if (m_maxSize < DEFAULT_MAX_SIZE)
    {
        m_maxSize = DEFAULT_MAX_SIZE;
    }

    DataType **newData = new DataType*[m_maxSize];
    copyData(newData, m_data, m_nextIndex);
    freeQueueMemory(m_data, m_nextIndex);
    delete[] m_data;
    m_data = newData;
}


template <class DataType>
void Queue<DataType>::freeQueueMemory(DataType** array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        delete array[i];
    }
}


template <class DataType>
void Queue<DataType>::copyData(DataType** dest, DataType** source, int size)
{
    for (int i = 0; i < size; ++i)
    {
        try
        {
            dest[i] = new DataType( *(source[i]) );
        }
        catch (std::bad_alloc &e)
        {
            freeQueueMemory(dest, i);
            delete[] dest;
            throw;
        }
    }
}


/*
* --------------------------------= Iterator Class Definitions =-----------------------------------
*/

template <class DataType>
Queue<DataType>::Iterator::Iterator(Queue<DataType> *queue, int index) :
    m_queue(queue),
    m_index(index)
{}

template <class DataType>
DataType &Queue<DataType>::Iterator::operator*()
{
    if (*this == this->m_queue->end())
    {
        throw InvalidOperation();
    }
    assert(m_index >= 0 && m_index < m_queue->size());
    return *(m_queue->m_data[m_index]);
}

template <class DataType>
typename Queue<DataType>::Iterator &Queue<DataType>::Iterator::operator++()
{
    if (*this == this->m_queue->end())
    {
        throw InvalidOperation();
    }
    ++m_index;
    return *this;
}

template <class DataType>
typename Queue<DataType>::Iterator Queue<DataType>::Iterator::operator++(int)
{
    if (*this == this->m_queue->end())
    {
        throw InvalidOperation();
    }
    Iterator result = *this;
    ++(*this);
    return result;
}

template <class DataType>
bool Queue<DataType>::Iterator::operator==(const Iterator &other) const
{
    assert(m_queue == other.m_queue);
    return (m_index == other.m_index);
}

template <class DataType>
bool Queue<DataType>::Iterator::operator!=(const Iterator &other) const
{
    return !(*this == other);
}


/*
* --------------------------------= ConstIterator Class Definitions =-----------------------------------
*/

template <class DataType>
Queue<DataType>::ConstIterator::ConstIterator(const Queue<DataType> *queue, int index) :
        m_queue(queue),
        m_index(index)
{}

template <class DataType>
const DataType &Queue<DataType>::ConstIterator::operator*() const
{
    if (*this == this->m_queue->end())
    {
        throw InvalidOperation();
    }
    assert(m_index >= 0 && m_index < m_queue->size());
    return *(m_queue->m_data[m_index]);
}

template <class DataType>
typename Queue<DataType>::ConstIterator &Queue<DataType>::ConstIterator::operator++()
{
    if (*this == this->m_queue->end())
    {
        throw InvalidOperation();
    }
    ++m_index;
    return *this;
}

template <class DataType>
typename Queue<DataType>::ConstIterator Queue<DataType>::ConstIterator::operator++(int)
{
    if (*this == this->m_queue->end())
    {
        throw InvalidOperation();
    }
    ConstIterator result = *this;
    ++(*this);
    return result;
}

template <class DataType>
bool Queue<DataType>::ConstIterator::operator==(const ConstIterator &other) const
{
    assert(m_queue == other.m_queue);
    return (m_index == other.m_index);
}


template <class DataType>
bool Queue<DataType>::ConstIterator::operator!=(const ConstIterator &other) const
{
    return !(*this == other);
}

/*
* -----------------------------------= Independent functions =--------------------------------------
*/


/*
 * makes a new queue with all the elements in an origin queue that pass a curtain filter condition.
 *
 * @param queue - the origin queue the elements are taken from.
 *        filterFunction - the filter condition.
 *
 * @return
 *      a filtered queue (different from origin)
*/
template <class DataType, class Condition>
Queue<DataType> filter(const Queue<DataType> &queue, const Condition &filterFunction)
{
    Queue<DataType> result;
    for (const DataType &element : queue )
    {
        if (filterFunction(element))
        {
                result.pushBack(element);
        }
    }
    return result;
}


/*
 * changes every element in a queue according to a curtain rule.
 *
 * @param queue - the origin queue to be changed.
 *        filterFunction - the transformation rule.
 *
*/
template <class DataType, class Condition>
void transform(Queue<DataType> &queue, const Condition& transformFunction)
{
    for (DataType &element : queue)
    {
        transformFunction(element);
    }
}


#endif //EX3_Queue_H