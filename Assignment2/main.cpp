//Assignment by Shivani Mangal

#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


/***** Complete this program. *****/

using namespace std;
typedef int Door;

const int SIMULATION_COUNT = 100;

void simulate( int simulate_count, int& win_one, int& win_two);
Door hideCar();
Door openDoor( int car_Door, int chosen_Door );
Door makeFirstChoice();
Door makeSecondChoice( int open_Door,int initial_choice);
int WinFirst(int car,int first);
int WinSwitch(int car,int second);

int main()
{
    int win1 = 0, win2 = 0;

    cout<<"#   "<<"Car  "<<"First  "<<"Opened "<<"Second "<<"Win   "<<"Win "<<endl;
    cout<<"   Here Choice Door   Choice first second";
    cout<<endl;
    // Run the simulations.
    srand(time(0));

    for (int i = 1; i <= SIMULATION_COUNT; i++) simulate(i, win1, win2);
    cout<<win1<<" wins if stay with the first choice"<<endl;
    cout<<win2<<" wins if stay with the second choice"<<endl;
    cout<<"Win ratio of switch over stay: "<<static_cast<float>(win2)/win1<<endl;
}



void simulate(int simulate_count, int& win_stay, int& win_switch)
{
    cout<<simulate_count<<"   ";


    int car_here= hideCar();
    int first_choice= makeFirstChoice();
    int openedDoor = openDoor(car_here,first_choice);
    int second_choice = makeSecondChoice(openedDoor,first_choice);
    win_stay+=WinFirst(car_here,first_choice);

    win_switch+=WinSwitch(car_here,second_choice);

}
/*
 * Selects a random number from 1 to 3 to set the car
 * No parameters
 * Returns door value
 */

Door hideCar()
{
    int random = rand()%3 + 1;
    cout<<random<<"    ";
    return random;
}
/*
 * Randomly selects a door as the first choice of door that will be opened and returns that door
 * No parameters passed
 */

Door makeFirstChoice()
{
    int random = rand()%3 + 1;
    cout<<random<<"      ";
    return random;
}

/*
 * The door to be opened by monty is decided and returned
 * Parameters : Door number where car is hidded and door of number of of chosen door
 */

Door openDoor(int carDoor,int choiceDoor)
{
    int openDoor;

    if(carDoor==choiceDoor)
    {
        do{
            openDoor = rand()%3 + 1;
        }while(openDoor==carDoor);
    }

    else
    {
        do{
            openDoor = rand()%3 + 1;
        }while(openDoor==choiceDoor||openDoor==carDoor);

    }
    cout<<openDoor<<"      ";
    return openDoor;
}
/*
 * The third door is selected and returned
 * The two doors which have been opened are passed
 */

Door makeSecondChoice(int openDoor,int onechoice)
{
   int second_choice;
    /*do{
        second_choice = rand()%3 + 1;
    }while(second_choice==openDoor||second_choice==onechoice);*/

    if(1 != openDoor && 1!= onechoice) second_choice=1;
    if(2 != openDoor && 2!= onechoice) second_choice=2;
    if(3 != openDoor && 3!= onechoice) second_choice=3;

    cout<<second_choice<<"      ";

    return second_choice;
}
/*
 * Check if first choice wins
 * Returns 1 if first choice wins and false otherwise
 * Parameters: Door number behind which car is hidden and door number of first choice
 */

int WinFirst(int car, int choice_first)
{
    int x =1;
    if(car==choice_first)
    {
        cout<<"Yes   ";
        return x;
    }
    else
    {
        cout<<"      ";
        return 0;
    }

}
/*
 * Check if second choice wins
 * Returns 1 if second choice wins and false otherwise
 * Parameters: Door number behind which car is hidden and door number of second choice
 */

int WinSwitch(int car, int choice_two)
{
    int x =1;
    if(car==choice_two)
    {
        cout<<"Yes   "<<endl;
        return x;
    }
    else
    {
        cout<<"    "<<endl;
        return 0;
    }

}