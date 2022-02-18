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
    const int PROB_A = 75;
    const int PROB_B = 74;
    const int MAX_SET = 6;
    
    /* initialize random seed: */
    srand (time(NULL));
    
    while (scoreA < MAX_SET && scoreB < MAX_SET)
    {
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
            cout << "Score: " << scoreA << " - " << scoreB << endl;
        }
        else
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
            cout << "Score: " << scoreA << " - " << scoreB << endl;
        }
        
    }
    return 0;
}