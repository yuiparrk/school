#include <iostream>

int main()
{
    int array[5] = {5, 3, 4, 1, 2};
    int length = 5;

    for (int i = 0; i < length - 1; ++i) //마지막 숫자 정리 피료 없음
    {
        int lowest = i;
        for (int j = i + 1; j < length; ++j) //j = 색인 1
        {
            if (array[j] < array[lowest]) //j가 i 보다 더 낮으면 : 
            {
                lowest = j; //제일 낮은 숫자가 j의 색인
            }
        }
        if (lowest != i) //제일 낮은 숫자 (j)가 i 보다 다르면 :
        {
            int temp = array[i]; //바꾸기
            array[i] = array[lowest];
            array[lowest] = temp;
        }
    }

  for (int i = 0; i < length; i++) //인쇄
  {
    std::cout << "[" << array[i] << "] ";
  }
}

// 5 4 3 1 2
// 1 4 3 5 2 
// 1 2 3 5 4
// 1 2 3 4 5 