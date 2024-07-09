#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int n;
    int g;
    int c = 0;
    srand(time(0)); 
    n = rand() % 100 + 1; 
    cout << "\t\t\tWELCOME TO NUMBER GUESSING GAME\n\n";

    do
    {
        cout << "Enter your guess between 1 and 100: ";
        cin >> g;
        c++;

        if (g > n){
            cout << "Your "<<g<<" guess is  high Please Enter a lower number!\n\n";
        }
        else if (g < n){
            cout << "Your "<<g<<" guess is Too low Please Enter a Higher number!\n\n";
        }
        else{
            cout << "\nWOHOO! You guess the right number "<<g <<" in "<< c << " chance!\n";
        }
    } 
        while (g != n);

	return 0;
}
