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
    const int PROB_A = 55;
    
    /* initialize random seed: */
    srand (time(NULL));
    
    /* generate number between 1 and 100: */
    num = rand() % 100 + 1;
    cout << num << endl;
    if (num <= PROB_A)
    {
        scoreA++;
    }
    else
    {
        scoreB++;
    }
    cout << "Score: " << scoreA << " - " << scoreB << endl;
    
    return 0;
}