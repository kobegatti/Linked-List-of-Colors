// Kobe Gatti
#include <iostream>
#include "ColorList.h"
#include <sstream>
using namespace std;

////////////////////////////////////////
// Global Constants
///////////////////////////////////////
const string MAIN_MENU = "1. Append\n2. Insert\n3. Delete\n4. Print\n5. Reverse\n6. Search\n7. Exit";
const string MENU_PROMPT = "Please choose a menu option: ";
const string APPEND_PROMPT = "What value do you wish to append? ";
const string INSERT_PROMPT_VAL = "What value do you wish to insert? ";
const string INSERT_PROMPT_POS = "What position do you wish to insert? ";
const string DELETE_PROMPT = "What position do you wish to delete? ";
const string SEARCH_PROMPT = "What value do you want to find? ";
const string LIST = "List: ";
const string THANK_YOU = "Thank you and goodbye.";
const string VALID_CHOICE = "Please enter a valid choice.";

////////////////////////////////////////
// String to number function
///////////////////////////////////////
int GetNumber_From_String(string str)
{
   if (str.empty()) // Enter nothing error
      return -1;

   if (str.size() == 1 && str.at(0) =='0') // Special case for zero
   {
      return 0;
   }

   stringstream ss(str); 
   int num{};

   ss >> num; // Convert string to int

   if (num == 0) // Error for single char input
   {
      return -1;
   }

   return num;
}

////////////////////////////////////////
// String to color function
///////////////////////////////////////
ColorList::Colors GetColor_From_String(const string& str)
{
   int array_size = sizeof(COLORNAMES) / sizeof(COLORNAMES[0]);

   for (int i = 0; i < array_size; i++) // Traverse array
   {
      if (str == COLORNAMES[i]) // Once array reached
      {
         return static_cast<ColorList::Colors>(i); // Print color
      }
   }
   return ColorList::Colors::none; // Else no color
}

////////////////////////////////////////
// Append function
///////////////////////////////////////
void ProcessAppend(ColorList& list)
{
   cout << APPEND_PROMPT << endl; 
   string str;
   getline(cin, str);
   ColorList::Colors color; // Initialize 
   color = GetColor_From_String(str); // Function call

   if (color == ColorList::Colors::none) // Error for invalid color
   {
      cout << str << " is not a valid color." << endl;
      return;
   }
   else
   {
      list.AppendNode(color); // Call mutator function
   }
   cout << endl;
}

////////////////////////////////////////
// Insert function
///////////////////////////////////////
void ProcessInsert(ColorList& list)
{
   cout << INSERT_PROMPT_VAL << endl;
   string color_str;
   getline(cin, color_str);
   ColorList::Colors color;
   color = GetColor_From_String(color_str); // Function call

   if (color == ColorList::Colors::none) // Error for invalid color
   {
      cout << color_str << " is not a valid color." << endl;
      return;
   }

   cout << INSERT_PROMPT_POS << endl;
   string pos_str;
   getline(cin, pos_str);
   int num = GetNumber_From_String(pos_str); // Function call

   if (num < 0) // Error for negative position
   {
      cout << pos_str << " is not a valid position." << endl;
      return;
   }

   int result = list.InsertNode(color, num); // Call mutator function

   if (result < 0) // Error for negative result
   {
      cout << "Unable to insert " << color_str << " at position " << pos_str << endl;
   }
   cout << endl;
}

////////////////////////////////////////
// Delete function
///////////////////////////////////////
void ProcessDelet(ColorList& list)
{
   cout << DELETE_PROMPT << endl;
   string pos_str;
   getline(cin, pos_str);
   unsigned int  num = GetNumber_From_String(pos_str); // Function call

   if (num < 0) // Error for negative position
   {
      return;
   }
   else // Call mutator function
   {
      list.DeletNode(num);
   }
   cout << endl;
}

////////////////////////////////////////
// Print function
///////////////////////////////////////
void ProcessPrint(ColorList& list)
{
   cout << LIST << endl;
   list.PrintList();
   cout << endl;
}

////////////////////////////////////////
// Reverse function
///////////////////////////////////////
void ProcessReverse(ColorList& list)
{
   list.ReverseList();
   cout << endl;
}

////////////////////////////////////////
// Search function
///////////////////////////////////////
void ProcessSearch(ColorList& list)
{
   cout << SEARCH_PROMPT << endl;

   string str;
   getline(cin, str);
   ColorList::Colors color;
   color = GetColor_From_String(str); // Function call

   if (color == ColorList::Colors::none) // Error for invalid color
   {
      cout << str << " is not a valid color." << endl;
      return;
   }
   int result = list.SearchList(color); // Call mutator function

   if (result >= 0) // Positive case
   {
      cout << "Color " << str << " found at position " << result << endl;
   }
   else // Invalid color
   {
      cout << "Color " << str << " not found. " << endl;
   }
   cout << endl;
}

////////////////////////////////////////
// Driver function
///////////////////////////////////////
int main() 
{
   string choice_str;
   
   ColorList list{};
   int choice = 0;
   do
   {
      cout << MAIN_MENU << endl;
      cout << MENU_PROMPT << endl;

      getline(cin, choice_str);
      choice = GetNumber_From_String(choice_str); // Function call

      if (choice == 7) // Exit status
      {
         cout << THANK_YOU << endl;
         break;
      }

      switch (choice) // Menu options
      {
      case 1: ProcessAppend(list);
         break;
      case 2: ProcessInsert(list);
         break;
      case 3: ProcessDelet(list);
         break;
      case 4: ProcessPrint(list);
         break;
      case 5: ProcessReverse(list);
         break;
      case 6: ProcessSearch(list);
         break;
      default: cout << VALID_CHOICE << endl << endl;
         break;
      }
   } while (true);
   
   return EXIT_SUCCESS;
}
