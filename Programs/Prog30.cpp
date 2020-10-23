//Program that prints a teamwise list of cricket players
//Rudraksh Kapil - 951775 - M - 12/4/2018

#include <iostream>
#include <cstring>
using namespace std;

//structure definition
struct cricket{
    char player_name[40];
    char team_name[40];
    double average;
    bool flag;
    
    //member functions
    void getDetails() {
        cout << "Enter Player Name:\n";
        cin >> player_name;
        cout << "Enter Team Name:\n";
        cin >> team_name;
        cout << "Enter the player's batting average:\n";
        cin >> average;
    }
    
    void printDetails() {
        cout << team_name << "\t\t\t" << player_name << "\t\t\t" << average;
    }
};

//array declaration
struct cricket player[50];

//[MAIN]
int main()
{
    cout << "\n[This is a program that prints a teamwise list of cricket players]\n\n";
    
    int n;
    cout << "How many teams are there: ";
    cin >> n;
    
    cout << "Enter the data of the 50 players:\n\n";
    for (int i = 0; i < 50; i++) {
        player[i].getDetails();		//call to structure function
        player[i].flag == false;
    }
    
    for (int i = 0; i < n; i++)
        if (player[i].flag == false) {
            cout << "\nTEAM NAME\t\tPLAYER NAME\t\tBATTING AVERAGE\n";
            player[i].printDetails();
            cout << endl;
            
            for (int j = i+1; j < 50; j++)
                if ((strcmp(player[i].team_name, player[j].team_name) == 0) && player[j].flag == false) {
                    player[j].printDetails();
                    cout << endl;
                    player[j].flag == true;
                }
            
            player[i].flag == true;
        }
    
    return 0;
}
