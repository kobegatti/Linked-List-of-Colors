// Kobe Gatti
#ifndef COLORLIST_H_
#define COLORLIST_H_
#include <string>

// Array of type colors
static const std::string COLORNAMES[] =  
{
   "none", // 0
   "red",  // 1
   "blue", // 2
   "yellow", // 3
   "PURPLE", // 4
   "GREEN" //5
};

class ColorList 
{
public:
   // Type colors
   enum class Colors 
   {
      none = 0,
      red = 1,
      blue = 2,
      yellow = 3,
      PURPLE = 4,
      GREEN = 5
   };

   // Constructor
   ColorList();

   // Deconstructor
   ~ColorList();

   //////////////////////////////////////////////////////////////////////////////
   // Function Prototypes
   //////////////////////////////////////////////////////////////////////////////
   void AppendNode(Colors);
   int InsertNode(Colors, unsigned int);
   void PrintList() const;
   int DeletNode(unsigned int);
   void ReverseList();
   int SearchList(Colors);

private:
   // Private members
   struct ListNode {
      Colors value;
      ListNode *next;
      ListNode() : value(Colors::none), next(nullptr) {}
      ListNode(Colors input) : value(input), next(nullptr) {}
   };

   ListNode *head;
};
#endif  // COLORLIST_H_
