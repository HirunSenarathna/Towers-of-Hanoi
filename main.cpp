#include <iostream> // Include the standard input/output stream library for user input and output.
#include <cstdlib>  // Include the C Standard Library for various utility functions.
#include <ctime>    //Include the C Standard Library for functions related to time.Used to genarate random numbers.
#include<conio.h> // Include a header for console input/output functions.
#include <cmath> //Include the C math library for mathematical functions. 
               
using namespace std; // Use the standard namespace for simplifying code.



// Global variables to store game data.
int size = 3;          // Number of disks (default to 3).
int moves = 0;         // Counter for the number of moves.
int* a = nullptr;      // Pointer to the first tower array.
int* b = nullptr;      // Pointer to the second tower array.
int* c = nullptr;      // Pointer to the third tower array.
int NextIndexA = 3;    // Index to track the next available position in tower A.s
int NextIndexB = 0;    // Index to track the next available position in tower B.
int NextIndexC = 0;    // Index to track the next available position in tower C.
string name;           //Player's name
void ShowMenu ();

// Function to display the current state of the towers.
void Display()
{
    cout << "\n---------------Towers Of Hanoi Game--------------\n"; // Display game header.
    cout << '\n';

    for (int i = size; i >= 0; i--) // Loop through each row (disk).
    {
        cout << "\t\t";
        for (int j = 0; j < 3; j++) // Loop through each tower (A, B, C).
        {
            if (i == size)
            {
                cout << ".\t"; // Display the top row with dots (initial state).
            }
            else
            {
                if (j == 0)//Tower A
                {
                    if (a[i] == 0)
                    {
                        cout << ".\t"; // If the tower has no disk, display a dot.
                    }
                    else
                    {
                        cout << a[i] << '\t'; // Display the disk value.
                    }
                }
                else if (j == 1)//Tower B
                {
                    if (b[i] == 0)
                    {
                        cout << ".\t"; // Similar display for tower B.
                    }
                    else
                    {
                        cout << b[i] << '\t';
                    }
                }
                else if (j == 2)//Tower C
                {
                    if (c[i] == 0)
                    {
                        cout << ".\t"; // Similar display for tower C.
                    }
                    else
                    {
                        cout << c[i] << '\t';
                    }
                }
            }
        }
        cout << '\n'; // Move to the next row.
    }

    cout << "\t      -----   -----   -----";
    cout << "\n\t\tA\tB\tC\n"; // Display tower labels.

    cout << "\n-------------------------------------------------\n";
}

// Function to perform a disk Swap between towers.
int Swap(char source, char dest)
{
    int* s;//s=source
    int* q;//q=destination
    int* sourceIndex;// Pointer to the source tower index.
    int* destIndex;// Pointer to the destination tower index.

    //Depends on the user input. Swap the value and dot(.) according to the source and destination given.
    if (source == 'A')
    {
        sourceIndex = &NextIndexA;
        s = a;
    }
    else if (source == 'B')
    {
        sourceIndex = &NextIndexB;
        s = b;
    }
    else
    {
        sourceIndex = &NextIndexC;
        s = c;
    }

    if (dest == 'A')
    {
        q = a;
        destIndex = &NextIndexA;
    }
    else if (dest == 'B')
    {
        q = b;
        destIndex = &NextIndexB;
    }
    else
    {
        q = c;
        destIndex = &NextIndexC;
    }

    if (*destIndex >= 0 && *destIndex < size && (*sourceIndex - 1) >= 0 && (*sourceIndex - 1) < size)
    //The first condition ensures that the destination tower index is a valid, non-negative value.
    //The second condition ensures that the destination tower index is within the bounds of the tower array.
    //The third condition ensures that there is at least one disk in the source tower (i.e., it's not empty).
    // The last condition ensures that the source tower index minus 1 is within the bounds of the tower array.
    {
        if (*sourceIndex == 0)
        {
            return -1; // Invalid move if source tower is empty.
        }
        else if ((*destIndex - 1 >= 0) && q[*destIndex - 1] <= s[*sourceIndex - 1])
        // First condition checks that there is at least one disk already present in the destination tower.
        //The next condition checks if the disk in the destination tower is smaller than or equal to the disk in the source tower.
        {
            return 0; // Invalid move if placing a larger disk on a smaller one.
        }
        else
        {
            int temp = q[*destIndex];
            q[*destIndex] = s[*sourceIndex - 1]; // Perform the disk Swap.
            s[*sourceIndex - 1] = temp;
            *sourceIndex = *sourceIndex - 1;
            *destIndex = *destIndex + 1;
            return true; // Successful move.
        }
    }
}

// Function to reset the game state.
void ResetGame()
{
    if (a && b && c)
    {
        delete[] a; // Deallocate memory if towers exist.
        delete[] b;
        delete[] c;
        a = nullptr; // Reset tower pointers.
        b = nullptr;
        c = nullptr;
    }

    a = new int[size]; // Create new tower arrays with the specified size.
    b = new int[size];
    c = new int[size];
    NextIndexA = size; // Reset next available positions.
    NextIndexB = 0;
    NextIndexC = 0;

    int count = size;
    for (int i = 0; i < size; i++)
    {
        a[i] = count; // Fill tower A with disks in descending order.
        count = count - 1;
    }

    for (int i = 0; i < size; i++)
    {
        b[i] = 0; // Initialize towers B and C with zeros (no disks).
        c[i] = 0;
    }

    moves = 0; // Reset the move counter.
}

// Function to check if the game is won (all disks are on tower C).
bool IsGameWin()
{
    int* c = ::c; // Access the global tower C array.
    for (int i = 0; i < size; i++)
    {
        if (c[i] == 0)
        {
            return false; // If any element in tower C is zero, the game is not won.
        }
    }
    return true; // All elements in tower C are non-zero, the game is won.
}

// Function to play the Tower of Hanoi game.
void PlayGame()
{
    ResetGame(); // Reset the game state.
    bool flag = false; // Initialize a flag to check if the game is won.
    char source;
    char dest;
    int invalidCheck;

    while (flag == false)
    {
        system("CLS"); // Clear the console screen.
        Display(); // Display the current state of the towers.
        cout << "\nTotal Moves:\t" << moves;
        cout << "\nMinimum number of moves:  " << pow(2, size) - 1;
        cout << "\nSelect the Source tower (A,B,C):\t";
        cin >> source;
        
        while (source != 'A' && source != 'B' && source != 'C')
        {
            cout << "invalid input";
            cout << "\nSelect the Source tower (A,B,C):\t";
            cin >> source; // Get the source tower from the user.
        }

        cout << "Select the Destination tower (A,B,C):\t";
        cin >> dest;

        while (source == dest || (dest != 'A' && dest != 'B' && dest != 'C'))
        {
            cout << "invalid input";
            cout << "\nSelect the Destination tower(A,B,C):\t";
            cin >> dest; // Get the destination tower from the user.
        }

        invalidCheck = Swap(source, dest); // Attempt to perform the disk Swap.

        if (invalidCheck != 1)
        {
            if (invalidCheck == 0)
            {
                cout << "\nWarning!, a bigger number can't be placed above a smaller number\n";
            }
            else
            {
                cout << "\nInvalid Move from " << source << " to " << dest << "\n";
            }
            system("pause"); // Pause the game to allow the player to read the message.
        }
        else
        {
            moves = moves + 1; // Increment the move counter for a successful move.
        }

        flag = IsGameWin(); // Check if the game is won.
    }

    system("CLS");
    Display(); // Display the final state of the towers.
    cout << "Total Moves:\t" << moves;
    cout << "\nCongrats! You Solved The Tower of Hanoi Puzzle in " << moves << " moves\n";
    system("pause"); // Pause the game before exiting.
}

// Function to start a new game.
void NewGame()
{
	cout << "\n\n\t\t\t\t\tEnter your name/nick name: ";
    cin >> name;
	int option;
    do
    {
        system("CLS"); // Clear the console screen.
        cout << "\n";
        cout << "\n";
        cout << "\t\t------------------------------------------------";
        cout << "\n\t\t\tWelcome To Tower Of Hanoi Game\n";
        cout << "\t\t------------------------------------------------";
        cout << "\n";
        cout << "\n";
        cout << "\n\tEnter 1 to Select number of Disks";
        cout << "\n\tEnter 2 to Start Game";
        cout << "\n\tEnter 3 to Play Random number of Disk (3-7)";
        cout << "\n\tEnter 0 to Exit the game";
        cout << "\n";
        cout << "\n\tChoose Option:\t";
        
        cin >> option;

        if (option == 1)
        {
            cout << "Enter number of disks for Tower Of Hanoi Game: ";
            cin >> size;
            
            while (size <= 0)
            {
                cout << "Invalid Input. Size Must Be Greater than Zero\n";
                cout << "Enter number of disks for Tower Of Hanoi Game: ";
                cin >> size;
            }
            ResetGame(); // Reset the game state with the new number of disks.
        }
        else if (option == 2)
        {
            cout << "\nNumber of Disks are:\t" << size << '\n';
			cout << "\nGame is Starting Now\n";
            system("pause"); // Pause before starting the game.
            PlayGame(); // Start the Tower of Hanoi game.
        }
        else if (option == 3)
        {
            cout << "\nYou are playing a Random Puzzle Game";
            size = 3 + rand() % (7 - 3 + 1); // Generate a random number of disks between 3 and 7.
            ResetGame(); // Reset the game state with the new random number of disks.
            cout << "\nNumber of Disks are:\t" << size << '\n';
            cout << "\nGame is Starting Now\n";
            system("pause"); // Pause before starting the game.
            PlayGame(); // Start the Tower of Hanoi game with a random number of disks.
        }
        else if (option == 0)
        {
            
            cout << "\n\t\t\tTowers of Hanoi game is exiting now";
            cout << "\n\t\t\tGOODBYE "<< name << "!";
            cout << "\n\t\t\tThank you for playing...";
        }
        else
        {
            cout << "\nInvalid Option From User";
        }
    } while (option != 0);

   
}

// Function to display game instructions.
void Instructions ()
{
	system ("cls"); 
	cout << "                                                                                                                                 " << endl;
	cout << "                                                                                                                                 " << endl;
	cout << "                                                                                                                                 " << endl;	
	cout << "                                                                                                                                 " << endl;
	cout << "                                                                                                                                 " << endl;
	cout << "                                                                                                                                 " << endl;
	cout << "                _________________________________________________________________________________________________                " << endl;
    cout << "                |                                        INSTRUCTIONS                                           |                " << endl;
    cout << "                |_______________________________________________________________________________________________|                " << endl;
    cout << "                |        Your goal: Replicate the stack in rod A to rod C, using minimum number of moves.       |                " << endl;
    cout << "                |                                                                                               |                " << endl;
    cout << "                |        Rules;                                                                                 |                " << endl;
	cout << "                |           1. You can only move one number at a time.                                          |                " << endl;
	cout << "                |           2. You can't place a large number on top of a small number                          |                " << endl;
	cout << "                |           3. You can use the auxiliary rod as a helping rod                                   |                " << endl;
	cout << "                |           4. You should always use uppercase to names the rods                                |                " << endl;
	cout << "                |           5. To move the disks you type in two letters, where the first represents the        |                " << endl;    
	cout << "                |             current location and the second letter represents the preferred destination       |                " << endl;
	cout << "                |             of the disk.                                                                      |                " << endl;
	cout << "                |                                                                                               |                " << endl;
	cout << "                |        Keyboard keys you can use;                                                             |                " << endl;
	cout << "                |              Shift/Caps Lock - To capitalise                                                  |                " << endl;
	cout << "                |              A, B, C         - Rod names                                                      |                " << endl;
	cout << "                |              Enter           - To do the next move                                            |                " << endl;
    cout << "                 -----------------------------------------------------------------------------------------------                 " << endl;
    
	
    cout << "Press any key to go back to the menu..."<<endl;
    
	getch();
	ShowMenu();//calling the function
}

// Function to display the main menu
void ShowMenu()
{
	int option;
    int choice;
    do
    {
    
    
		system("CLS");  // Clear the console screen
		
		cout << "                                                                   " << endl;
		cout << "                                                                   " << endl;
		cout << "                                                                   " << endl;	
		cout << "                                                                   " << endl;
		cout << "                                                                   " << endl;
		cout << "                                                                   " << endl;
        cout << " \t\t\t               -----------------------------                " << endl;
        cout << " \t\t\t               |       TOWER OF HANOI      |                " << endl;
        cout << " \t\t\t               -----------------------------                " << endl;
        cout << " \t\t\t               |        1. New Game        |                " << endl;
        cout << " \t\t\t               |        2. Instructions    |                " << endl;
        cout << " \t\t\t               |        3. Quit            |                " << endl;
        cout << " \t\t\t               -----------------------------                " << endl << endl;
        cout << " \t\t\t    Enter your choice: ";
        cin >>choice;
        
        
      
    	system("cls");
    	
		cout << "                                                                            " << endl;
		cout << "                                                                            " << endl;
		cout << "                                                                            " << endl;	
		cout << "                                                                            " << endl;
		cout << "                                                                            " << endl;
		cout << "                                                                            " << endl;
		cout << "\t\t\t\t _____                            ___    _   _      _   _      _      " << endl;
		cout << "\t\t\t\t|_   _|   _   _      ____        |  _|  | | | |    | \\ | |    | |    " << endl;
		cout << "\t\t\t\t  | |____| | | |____| -- |   ____| |    | |_| |____|  \\| |____| |    " << endl;
		cout << "\t\t\t\t  | | __ | |_| | . _| --_|  | __ |  _|  |  _  | -  | |\\  | __ | |    " << endl;
		cout << "\t\t\t\t  |_|____|_/ \\_|____|_|\\_\\  |____|_|    |_| |_|__|_|_| \\_|____|_| " <<endl;
		cout << "                                                                            " << endl;
		cout << "                                                                            " << endl;
		cout << "                                                                            " << endl;
		cout<<"\tPress Enter..."<<endl;
    	getch();
    	
    
        
        switch(choice)
        {
        	case 1:
        		NewGame ();
        		break;
        	case 2:
        		Instructions ();
				break;
			case 3:
            
				cout << "\n\t\t\tTowers of Hanoi game is exiting now";
            	cout << "\n\t\t\tGOODBYE "<< name << "!";
				break;	
		}
    
	}while(option != 0);
}


int main()
{
	
    srand(time(0)); // Seed the random number generator with the current time.

    ShowMenu();//calling the function
    
	delete[] a; // Deallocate memory for tower arrays before exiting.
    delete[] b;
    delete[] c;
 return 0;
}
