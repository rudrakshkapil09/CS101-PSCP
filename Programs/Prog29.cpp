//Program that simulates a card game where the user guesses the next card in a randomly shuffled deck
//Rudraksh Kapil - 951775 - M - 12/8/14

#include <iostream>
#include <cstdlib>
using namespace std;

//structure definition
struct card{
    int suit; 	//1-4
    int rank; 	//1-13
};

//function & array declarations
card deck[52];
void doInit(struct card l[]);
void doSwap(struct card l[], int n);
void doScis(struct card l[], int n);

//[MAIN]
int main()
{
    cout << "\n[This is a program that simulates a card game where the user guesses the next card in a randomly shuffled deck]\n\n";
    
    int score = 0, rank_val, suit_val;
    srand(static_cast<unsigned>(time(NULL)));		//seeding random generator to be used in swapping function
    
    //function calls
    doInit(deck);
    doSwap(deck, 52);
    doScis(deck, 52);
    
    for (int i = 0; i < 52; i++) {
        cout << "Enter next card suit and rank: ";
        cin >> suit_val >> rank_val;
        
        if (suit_val == deck[i].suit && rank_val == deck[i].rank) {
            cout << "CORRECT!\n";
            score++;
        }
        else
            cout << "Try again. Correct answer was: " << deck[i].suit << " " << deck[i].rank << endl;
    }
    
    //result
    cout << "\nFinal Scores:\nUser => " << score << "\nCPU => " << 52 - score << endl;
    return 0;
}

//Function definitions
//1. initilaise the deck
void doInit(struct card l[])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++) {
            l[i*13+j].suit = i+1;
            l[i*13+j].rank = j+1;
        }
}

//2. swap 20 times randomly
void doSwap(struct card l[], int n)
{
    int i, j, k;
    struct card c;
    
    for(k = 0; k < 20; k++){
        i = rand() % 52;
        j = rand() % 52;
        
        c = l[i];
        l[i] = l[j];
        l[j] = c;
    }
}

//3.more shuffling by scissoring
void doScis(struct card l[], int n)
{
    int i;
    struct card *t;
    
    t = (struct card *)malloc(sizeof(struct card)*52);
    
    //error message
    if (t == NULL) {
        cout << "Memory Allocation Failure.";
        exit(0);
    }
    
    //shuffle
    for (int i = 0; i < n/2; i++) {
        t[2*i] = l[n/2+i];
        t[2*i-1] = l[i];
    }
    
    //copy back
    for (int i = 0; i < n; i++)
        l[i] = t[i];
    
    free(t);
}
