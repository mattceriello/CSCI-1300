#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

int main()
{
    int scoreA = 0;
    int scoreB = 0;
    int num;
    char turn = 'A';
    const int PROB_A = 55;
    const int PROB_B = 50;
    
    /* initialize random seed: */
    srand (time(NULL));
    
    /* generate number between 1 and 100: */
    num = rand() % 100 + 1;
    cout << num << endl;
    if (turn == 'A')
    {
        if (num <= PROB_A)
        {
            scoreA++;
        }
        else
        {
            scoreB++;
        }
        turn = 'B';
    }
    cout << "Score: " << scoreA << " - " << scoreB << endl;
    num = rand() % 100 + 1;
    cout << num << endl;
    if (turn == 'B')
    {
        if (num <= PROB_B)
        {
            scoreB++;
        }
        else
        {
            scoreA++;
        }
        turn = 'A';
    }
    cout << "Score: " << scoreA << " - " << scoreB << endl;
    
    return 0;
}