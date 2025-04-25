// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <limits>


int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_number
  //  variable, and its position in the declaration. It must always be directly before the variable used for input.
  //  You must notify the user if they entered too much data.

  const std::string account_number = "CharlieBrown42";
  char user_input[20];
  std::cout << "Enter a value: ";
 

  std::cin.get(user_input, sizeof(user_input)); // Read up to 19 chars (leaving room for '\0')

  // Check if input exceeded limit
  if (std::cin.peek() != '\n' && std::cin.peek() != -1) {
      std::cout << "Warning: You entered too many characters! Only the first 19 characters were used." << std::endl;
      std::cin.clear(); // Clear error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove excess input
  }


  std::cout << "You entered: " << user_input << std::endl;
  std::cout << "Account Number = " << account_number << std::endl;
}

