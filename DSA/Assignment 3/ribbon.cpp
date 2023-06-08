#include <iostream>
using namespace std;
void printPieces(int pieces[], int currentPieces[], int currentLength, int target);
int maxPiece(int pieces[], int length, int n);
int main()
{
    int n = 5, pieces[] = {1, 2, 3}, currentPieces[100] = {}; // I have taken 5 as example, you can take any number.
    cout << "The ribbon can be cut into pieces of length: ";
    printPieces(pieces, currentPieces, 0, n);
    cout << endl;
    cout << "The maximum number of pieces is: " << maxPiece(pieces, n, 3) << endl;
}
void printPieces(int pieces[], int currentPieces[], int currentLength, int target)
{
    if (target == 0)
    {
        for (int i = 0; i < currentLength; i++)
        {
            cout << currentPieces[i] << " ";
            if (i != currentLength - 1)
                cout << "+ ";
        }
        cout << " = " << currentLength << endl;
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        if (target >= pieces[i])
        {
            currentPieces[currentLength] = pieces[i];
            printPieces(pieces, currentPieces, currentLength + 1, target - pieces[i]);
            currentPieces[currentLength] = 0;
        }
    }
}
int maxPiece(int pieces[], int length, int n)
{
    if (n == 0)
        return 0;
    int maxCount = -1;
    for (int i = 0; i < length; i++)
    {
        if (n >= pieces[i])
        {
            int count = maxPiece(pieces, length, n - pieces[i]);
            if (count != -1)
                maxCount = max(maxCount, count + 1);
        }
    }
}