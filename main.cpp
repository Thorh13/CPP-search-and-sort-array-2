#include <iostream>
using namespace std;

// Function prototypes
int linear_search(const int[], int, int);
int binary_search(const int[], int, int);

// Constant for the array size
const int SIZE = 10;

// Array of lotto numbers
int lotto[SIZE] = 
  { 13579, 26791, 26792, 33445, 55555,
    62483, 77777, 79422, 85647, 93121 };

int main() 
{
  // Display the array of the player's lottery numbers
  cout << "Your numbers are:" << endl;
  for (const int &n : lotto) 
    cout << n << " | ";
  cout << endl;

  // Get the winning lotto from the user.
  int lotto_number;   // To hold winning lotto number
  cout << "\nPlease enter this week's 5-digit winning lottery numbers: ";
  cin >> lotto_number;

  // Search the array for the winning number using linear_search
  // and indicate wether it is a winner or not.
  int linear_results;    //hold results of linear_search
  cout << "Using the linear search....." << endl;
  linear_results = linear_search(lotto, SIZE, lotto_number);
  if (linear_results == -1)    // If flagg was not triggered
    cout << "You did not win this week.\n" << endl;
  else                  // If flag was triggered
    cout << "You have a winning ticket.\n" << endl;
  
  // Search the array for the winning number using binary_search
  // and indicate wether it is a winner or not.
  int binary_results;    //hold results of binary_search
  cout << "Using the binary search....." << endl;
  binary_results = binary_search(lotto, SIZE, lotto_number);
  if (binary_results == -1)    // If flagg was not triggered
    cout << "You did not win this week.\n" << endl;
  else                  // If flag was triggered
    cout << "You have a winning ticket.\n" << endl;

	return 0;
}

//*********************
// The linear search  *
//*********************

int linear_search(const int arr[], int size, int value)
{
  int index = 0;      // Used as a subscript to search array
  int position = -1;  // To record position of record value
  bool found = false; // Flag to indicate if the value is found

  while (index < size && !found)
  {
    if (arr[index] == value)    // If value is found
    {
      found = true;             // Set the flag
      position = index;         // Record the values subscript
    }
    index++;
  }
  return position;              // Return the position, or -1
}

//*********************
// The binary search  *
//*********************
int binary_search(const int array[], int size, int value)
{
  int first = 0,          // First array element
      last = size - 1,    // Last array element
      middle,             // Midpoint of search
      position = -1;      // Position of search value
  bool found = false;     // Flag

  while (!found && first <= last)
  {
    middle = (first + last) / 2;    // calculate midpioint
    if (array[middle] == value)     // If value is found at middle
    {
      found = true;
      position = middle;
    }
    else if (array[middle] > value) // If value is in lower half
      last = middle - 1;
    else                            // If value is in upper half
      first = middle + 1;
  }    
  return position;
}