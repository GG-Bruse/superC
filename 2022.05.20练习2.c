#include<stdio.h>
int main()
{
    int arr[2][15] = { {1,2,3,4,5,6,6,5,4,3,2,1,6,5,6},{0,1,0,1,0,1,1,0,1,0,1,0,1,0,1} };
    int temp[6] = {0};
    int power_one = temp[0];
    int max1 = 0;
    int power_two = temp[0];
    int max2 = 0;
    for (int i = 0; i < 15; ++i)
    {
        ++temp[arr[0][i] - 1];
    }
    for (int i = 0; i < 6; ++i)
    {
        if (power_one < temp[i])
        {
            power_one = temp[i];
            max1 = i + 1;
        }
    }
    for (int i = 0; i < 6; ++i)
    {
        if (i == max1 - 1)
        {
            continue;
        }
        if (power_two < temp[i])
        {
            power_two = temp[i];
            max2 = i + 1;
        }
    }
    int left = 0;
    int right = 0;
    for (int i = 0; i < 15; ++i)
    {
        if (max1 == arr[0][i])
        {
            if (arr[1][i] == 0)
            {
                left = max1;
            }
            else
            {
                right = max1;
            }
        }
        if (max2 == arr[0][i])
        {
            if (arr[1][i] == 0)
            {
                left = max2;
            }
            else
            {
                right = max2;
            }
        }
    }
    printf("左left = %d", left);
    printf("右right = %d", right);
    return 0;
}
