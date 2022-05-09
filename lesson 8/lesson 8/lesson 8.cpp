#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Vint;

// 2 6 7 4
// 2 6     7 4
// 2   6   7   4


Vint MergeSort(Vint Arr)
{
    if (Arr.size() == 1) return Arr;

    Vint LeftArr;
    Vint RigthArr;

    for (int i = 0; i < Arr.size(); i++)
    {
        if (i < Arr.size() / 2)
        {
            LeftArr.push_back(Arr[i]);
        }
        else
        {
            RigthArr.push_back(Arr[i]);
        }
    }

    LeftArr = MergeSort(LeftArr);
    RigthArr = MergeSort(RigthArr);

    int countLeft = 0;
    int countRigth = 0;
    Vint sortedArr;

    while (true)
    {
        if ((countLeft == LeftArr.size()) && (countRigth == RigthArr.size()))
        {
            return sortedArr;
        }

        if (countLeft == LeftArr.size())
        {
            sortedArr.push_back(RigthArr[countRigth]);
            countRigth++;
            continue;
        }

        if (countRigth == RigthArr.size())
        {
            sortedArr.push_back(LeftArr[countLeft]);
            countLeft++;
            continue;
        }

        if (LeftArr[countLeft] > RigthArr[countRigth])
        {
            sortedArr.push_back(RigthArr[countRigth]);
            countRigth++;
        }
        else
        {
            sortedArr.push_back(LeftArr[countLeft]);
            countLeft++;
        }
    }

}

int main()
{
    Vint A;
    A.push_back(2);
    A.push_back(6);
    A.push_back(4);
    A.push_back(7);

    A = MergeSort(A);

    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
