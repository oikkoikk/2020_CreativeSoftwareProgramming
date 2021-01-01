#include <string>
#include <functional>

#include "double_linked_node.h"

template <typename T>
class List
{
public:
    List() : count(0)
    {
        head = new Node<T>(0, nullptr, nullptr);
        tail = new Node<T>(0, nullptr, nullptr);

        head->next = tail;
        tail->prev = head;
    }
    ~List()
    {
        // TODO: write your code here
        // release remain nodes before delete head node
        delete head;
        delete tail;
    }

    void push_front(T value)
    {
        Node<T> *newNode = new Node<T>(value, nullptr, nullptr);

        if (head->next == tail)
        {
            newNode->prev = head;
            newNode->next = tail;
            head->next = newNode;
            tail->prev = newNode;
        }
        else
        {
            Node<T> *tempNode = head->next;

            tempNode->prev = newNode;
            newNode->next = tempNode;
            newNode->prev = head;
            head->next = newNode;
        }
        count++;
        // TODO: write your code here
        // create new node with value
        // and add node to front of list
    }
    void push_back(T value)
    {
        Node<T> *newNode = new Node<T>(value, nullptr, nullptr);

        if (head->next == tail)
        {
            newNode->prev = head;
            newNode->next = tail;
            head->next = newNode;
            tail->prev = newNode;
        }
        else
        {
            Node<T> *tempNode = head;
            for (int i = 0; i < count; i++)
            {
                tempNode = tempNode->next;
            }

            tempNode->next = newNode;
            newNode->prev = tempNode;
            newNode->next = tail;
            tail->prev = newNode;
        }
        count++;
        // TODO: write your code here
        // create new node with value
        // and add node to back of list
    }
    T pop_front()
    {
        if (head->next != tail)
        {
            Node<T> *temp = head->next;
            T popped = temp->value;

            head->next = temp->next;
            temp->next->prev = head;

            delete temp;
            count--;
            return popped;
        }
        return 0;
        // TODO: write your code here
        // remove front node(not head)
        // and return its value
        // if try to remove head node return 0
    }
    T pop_back()
    {
        if (head->next != tail)
        {
            Node<T> *temp = head;

            for (int i = 0; i < count - 1; i++)
            {
                temp = temp->next;
            }
            Node<T> *newLastNode = temp;
            temp = temp->next;
            newLastNode->next = tail;
            tail->prev = newLastNode;
            T popped = temp->value;

            delete temp;
            count--;
            return popped;
        }
        return 0;
        // TODO: write your code here
        // remove back node(not head)
        // and return its value
        // if try to remove head node return 0
    }

    size_t size()
    {
        return count;
        // TODO: write your code here
        // return current items in list (except head)
    }

    void traverse(const std::function<void(const Node<T> &)> &f)
    {
        for (Node<T> *node = head->next; node != nullptr; node = node->next)
        {
            f(*node);
        }
    }

    void reverse_traverse(const std::function<void(const Node<T> &)> &f)
    {
        for (Node<T> *node = tail->prev; node != nullptr; node = node->prev)
        {
            f(*node);
        }
    }

private:
    Node<T> *head;
    Node<T> *tail;
    size_t count;

    // OPTIONAL: you can write helper functions
};
