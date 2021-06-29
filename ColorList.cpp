// Kobe Gatti
#include "ColorList.h"
#include <iostream>
#include <string>
using namespace std;

////////////////////////////////////////
// Constructor
////////////////////////////////////////
ColorList::ColorList() : head(nullptr) {} // List is empty

////////////////////////////////////////
// Destructor
////////////////////////////////////////
ColorList::~ColorList() 
{
   ListNode *current = head; // Current pointing where head points
   while (current != nullptr) // List is not empty
   {
      ListNode *next = current->next; // Looking at next node
      delete current; // Delete previous node
      current = next; // Current catches up to next
   }
   head = 0; // Head points to nullpointer
}

////////////////////////////////////////
// Append function
////////////////////////////////////////
void ColorList::AppendNode(Colors input) 
{
   if (input == Colors::none) return; // None is invalid

   ListNode* newNode = new ListNode(input); // Initialize 

   if (!head) // List is empty
   {
      head = newNode; // Move newNode where head is
   } 
   else 
   {
      ListNode* nodePtr{head}; // Initialize

      while (nodePtr->next) 
      {
         nodePtr = nodePtr->next; // Traverse the list
      }
      nodePtr->next = newNode; // Insert newNode at end
   }
}

////////////////////////////////////////
// Insert function
////////////////////////////////////////
int ColorList::InsertNode(Colors input, unsigned int pos) 
{
   if (input == Colors::none) return -1; // None is invalid

   ListNode* prev{}; // Initialize pointers
   ListNode* current{ head };
   unsigned int count = 0; // Counter

   if (pos == 0) // Special case push
   {
      ListNode* newNode = new ListNode(input);
      newNode->next = head; // newNode pointing to same node as head
      head = newNode; // Head points to newNode
      return 0;
   }
   for (count = 0; count < pos; count++) 
   {
      if (current == nullptr) // Empty list case
         break;
      prev = current; // Traverse list
      current = current->next;
   }
   if (count == pos) // When position is reached
   {
      ListNode* newNode = new ListNode(input); // Initialize
      prev->next = newNode; // Node before position points to newNode
      newNode->next = current; // newNode points to position after
      return 0;
   }
   else // Error
   {
      return -1;
   }
}


////////////////////////////////////////
// Delete function
////////////////////////////////////////
int ColorList::DeletNode(unsigned int pos)
{
   if (head == nullptr) // Invalid empty list
      return -1;

   if (pos == 0) // Special case pop
   {
      ListNode* temp{ head }; // Initialize temp pointer 
      head = head->next; // Move head to next node
      delete temp; // Delete temp pointer
      return 0;
   }

   ListNode* prev{}; // Initialize pointers
   ListNode* current{ head };
   unsigned int count = 0; // Counter

   for (count = 0; count < pos; count++)
   {
      if (current == nullptr) // List is not empty
         break;
      prev = current; // Traverse list
      current = current->next;
   }
   if (current == nullptr) // Error
      return -1;
   if (count == pos) // Once position is reached
   {
      prev->next = current->next; // Have previous pointer hop over position
      delete current; // Delete node in position
      return 0;
   }
   else // Error 
   {
      return -1;
   }
}

////////////////////////////////////////
// Print function
////////////////////////////////////////
void ColorList::PrintList() const 
{
   ListNode *nodePtr; // Initialize pointers
   nodePtr = head;

   while (nodePtr != nullptr) // List is not empty
   {
      cout << COLORNAMES[static_cast<int>(nodePtr->value)] << " "; // Print colors
      nodePtr = nodePtr->next; // Traverse list
   }
}


////////////////////////////////////////
// Reverse function
////////////////////////////////////////
void ColorList::ReverseList()
{
   ListNode* prev = nullptr; // Initialize pointers
   ListNode* next = nullptr;
   ListNode* current = head;

   while (current != nullptr) // List is not empty
   {
      next = current->next; // Next points to next node
      current->next = prev; // First node turns around to null
      prev = current; // Prev jumps to next node
      current = next; // Current jumps to next node
   }
   head = prev; // Move head to end.
}

////////////////////////////////////////
// Search function
////////////////////////////////////////
int ColorList::SearchList(Colors input)
{
   if (head == nullptr) return -1; // List is not empty

   ListNode* current{ head }; // Initialize pointers
   unsigned int count = 0; // Counters

   while (current != nullptr && current->value != input) // List is not empty and data is not found
   {
      current = current->next; // Traverse list
      count++; // Counter increases
   }
   
   if (current) // Once value is found
   {
      return count; // Position 
   }
   else // Error
   {
      return -1;
   }
}
