#include <iostream>
#include <math.h>
using namespace std;
void displayPieces(int pieces[], int currentPieces[], int currentLength, int target, int n);
int maxPieces(int pieces[], int length, int n);
int main()
{
    int n = 5;
    int pieces[] = {1, 2, 3};
    int currentPieces[100] = {0};
    cout << "The ribbon can be cut into pieces of length: ";
    cout << endl;
    displayPieces(pieces, currentPieces, 0, n, n);
    cout << endl;
    cout << "The maximum pieces in which a ribbon can cut into is " << n << " , so the answer is  " << maxPieces(pieces, 3, n) << endl;
}
int maxPieces(int pieces[], int length, int n)
{
    int countMax = -1;
    if (n == 0)
    {
        return 0;
    }
    for (int i = 0; i < length; i++)
    {
        if (n >= pieces[i])
        {
            int count = maxPieces(pieces, length, n - pieces[i]);
            if (count != -1)
            {
                countMax = max(countMax, count + 1);
            }
        }
    }
    int cm = countMax;
    return cm;
}
void displayPieces(int pieces[], int currentPieces[], int currentLength, int t, int n)
{
    if (t == 0)
    {
        for (int i = 0; i < currentLength; i++)
        {
            cout << currentPieces[i] << " ";
            if (i != currentLength - 1)
               {
                 cout << " + ";
            }
        }
        cout << " = " << n << endl;
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        if (t >= pieces[i])
        {
            currentPieces[currentLength] = pieces[i];
            displayPieces(pieces, currentPieces, currentLength + 1, t - pieces[i], n);
            currentPieces[currentLength] = 0;
        }
    }
}
