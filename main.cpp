#include <iostream>
#include <string>
using namespace std;

string arena[5][5]{  // Defining the map
    {"* ","* ","* ","* ","* ",},
    {"* ","* ","* ","* ","* ",},
    {"* ","* ","* ","* ","* ",},
    {"* ","* ","* ","* ","* ",},
    {"* ","* ","* ","* ","* ",}
};

int c {0}; // no of tries
int a {0}; // no of hp ships have 
int x {};
int y {};
int ex {};
int ey {};
int shots {};
int hits {};

bool battleship[5][5]{
    {0 , 1 , 0 , 0 , 0},    // 9 '1's
    {0 , 1 , 0 , 0 , 0},    // -- , --- , L--
    {1 , 1 , 0 , 0 , 1},
    {1 , 0 , 0 , 0 , 1},
    {0 , 0 , 0 , 1 , 1}
};

int display(){
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << arena[i][j] ;
            if (i==0 && j==4){
                cout << "\n" ;
            }else if(i==1 && j==4){
                cout << "\n" ;
            }else if(i==2 && j==4){
                cout << "\n" ;
            }else if(i==3 && j==4){
                cout << "\n" ;
            }else if(i==4 && j==4){
                cout << "\n" ;
            }    
        }       
    }
    return 0;
}

int nuke(){
    cout << "Coords to nuke: \nx coords:" ;
    cin >> ex ;
    cout << "y coords:";
    cin >> ey ;

    if ((ex > 5 || ex < 1) || (ey > 5 || ey < 1))
    {
        cout << "Coords invalid" ;
        exit(0) ;
    }else{
        x = 5-ey ;
        y = ex-1 ;
    }

    if (arena[x][y] == "x ")
    {
        cout << "Cant nuke same spot again \n" ;
        a--;
    }else if (arena[x][y] == "o ")
    {
        cout << "Cant nuke same spot again \n" ;
        a--;
    }else{
        shots++;
        cout << "\n" ;
    
        if (battleship[x][y] == true )
        {
            battleship[x][y] = false;
            arena[x][y] = "x ";
            hits++;
            c++;
            display();
        }else{
            arena[x][y] = "o " ;
            display();
        }
    }
    
    cout << "No of shots:" << shots << endl;
    cout << "Hits:" << hits ;
    cout << "\n" ;

    return 0;
}


int main(){
    /*
     for graph:

     00 01 02 03 04
     10 11 12 13 14
     20 21 22 23 24
     30 31 32 33 34
     40 41 42 43 44

     15 25 35 45 55
     14 24 34 44 54
     13 23 33 43 53
     12 22 32 42 52
     11 21 31 41 51
     
    */

    cout << "\n" ;
    cout << "Battleship Arena \n \n" ; 

    display();
    while (a < 15)
    {
        nuke();
        a++ ;
        if (c==9)
        {
            cout << "\n" ;
            cout << "Number one victory royale, yea fortnite about to get down";
            exit(0);
        }else if (a==15)
        {
            cout << "\n" ;
            cout << "NOOB \nGo play solitaire" ;
            exit(0);
        }  
    }
}




