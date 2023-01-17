#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

  /**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val)
{
  if (empty())
  {
    Item* newItem = new Item();
    newItem ->val[0] = val;
    newItem ->last++;

    head_ = newItem;
    tail_= newItem;
  }
  else
  {
    if (tail_->last >= ARRSIZE )
    {
      // if array capacity of last Item has been reached
      Item* addedItem = new Item();
      addedItem->val[0] = val;
      addedItem->last++;
      addedItem -> prev = tail_;
      tail_ -> next = addedItem;
      tail_ = addedItem;

    }
    else
    {
      // add to end of array on last Item
      tail_->val[tail_->last] = val;
      tail_->last++;
    }
  }
  size_++;
}
  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back()
  {
    if (empty())
    {
      size_ = 0;
      return;
    }
    else if (size_ <= 1)
    { 
      clear();
      return;
    }
    else
    {
      if (tail_ -> last - tail_ -> first <= 1 ) // if back item will be empty
      {
        Item* temp = tail_;
        tail_ = tail_ -> prev;
        delete temp;
        tail_ ->next = NULL;
      }
      else
      {
        tail_ -> last --;
      }
    }
    size_--;
    
  }

  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_front(const std::string& val)
  {
    if (empty())
    {
      Item* newItem = new Item();
      newItem -> val[ARRSIZE-1] = val;
      newItem -> last = ARRSIZE;
      newItem ->first = ARRSIZE-1;
      head_ = newItem;
      tail_ = newItem;

    }
    else
    {
      if (head_ -> last - head_ -> first >= ARRSIZE || head_ -> first <= 0) // front array already be full
      {
        Item* newHead = new Item();
        newHead -> val[ARRSIZE-1] = val;
        newHead -> last = ARRSIZE;
        newHead ->first = ARRSIZE-1;
        newHead -> next = head_;
        head_ -> prev = newHead;
        head_= newHead; 
      }
      else
      {
        head_->first--;
        head_->val[head_->first] = val;

      }
    }
    size_++;
  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front()
  {
    if (empty())
    {
      size_ = 0;
      return;
    }
    else if (size_ <= 1)
    {
      clear();
      return;
    }
    else
    {
      if (head_ -> last - head_-> first <= 1) // front Item is going to be / is empty
      {
        Item* temp = head_;
        head_ = head_-> next;
        
        delete temp;
        head_ ->prev = NULL;
      }
      else
      {
        head_ -> first++;
      }
    }
    size_--;
  }

/**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const
  {
    return head_ -> val[head_ -> first];
  }

  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const
  {
    return tail_ -> val[tail_->last - 1];
  }


/** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  std::string* ULListStr::getValAtLoc(size_t loc) const
  {
    if (loc >= size() || loc < 0)
      return NULL;
    Item* temp = head_;
    size_t index = 0;
    size_t tempindex = temp ->first; // per val array in each Item

    while (index < loc)
    {
      if (tempindex >= temp -> last)
      {
        temp = temp -> next;
        tempindex = temp -> first;
      }
      tempindex++;
      index++;
    }
    if (tempindex >= temp -> last)
      {
        temp = temp ->next;
        tempindex = temp -> first;
      }

    return &(temp->val[tempindex]);
  }


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

