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
    int setA = 0;
    int setB = 0;
    int count = 0;
    int wins = 0;
    char turn = 'A';
    const int PROB_A = 79;
    const int PROB_B = 79;
    const int MAX_SET = 6;
    const int MAX_SET_WIN = 3;
    const int NUM_MATCHES = 10000;
    
    /* initialize random seed: */
    srand (time(NULL));
    
    while (count < NUM_MATCHES)
    {
        setA = 0;
        setB = 0;
        while((setA < MAX_SET_WIN) && (setB < MAX_SET_WIN))
        {
            scoreA = 0;
            scoreB = 0;
            while((scoreA < MAX_SET && scoreB < MAX_SET) || ((scoreA >= MAX_SET || scoreB >= MAX_SET) && (abs(scoreA - scoreB)<2)))
            {
                /* generate number between 1 and 100: */
                num = rand() % 100 + 1;
                //cout << num << endl;
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
                    //cout << "Score: " << scoreA << " - " << scoreB << endl;
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
                    //cout << "Score: " << scoreA << " - " << scoreB << endl;
                }
                
            }
            if (scoreA > scoreB)
            {
                setA++;
            }
            else
            {
                setB++;
            }
            //cout << "Sets: " << setA << " - " << setB << endl;
        }
        count++;
        if (setA > setB)
        {
            wins++;
        }
    }
    cout << "Player A wins " << wins*100/NUM_MATCHES << "% of the time" << endl;
    return 0;
}