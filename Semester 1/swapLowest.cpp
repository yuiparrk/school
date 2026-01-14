#include <iostream>
#include <climits>

int main()
{
  int nums[5] = {15, 65, 100, -3, 22};
  int lowest = INT_MAX;
  int lindex;
  int temp;

  for (int i = 0; i < 5; i++)
  {
    if (nums[i] < lowest)
    {
      lowest = nums[i]; //-3
      lindex = i; //index of 3
    }
  }
  temp = nums[0];
  nums[0] = lowest;
  nums[lindex] = temp;

  std::cout << nums[0] << std::endl;
  std::cout << nums[lindex];
}