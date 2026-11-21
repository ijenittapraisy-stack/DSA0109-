#include <iostream>
using namespace std;

int& highest(int marks[], int n)
{
    int max = 0;

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > marks[max])
            max = i;
    }

    return marks[max];
}

int main()
{
    int marks[5] = {70, 85, 90, 75, 80};

    cout << "Highest Mark = " << highest(marks, 5) << endl;

    highest(marks, 5) = highest(marks, 5) + 2;

    cout << "After Moderation = " << highest(marks, 5);

    return 0;
}