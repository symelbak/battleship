#include <iostream>
#include <string>
using namespace std;

string map[5][5]{  // Defining the map
    {"* ","* ","* ","* ","* ",},
    {"* ","* ","* ","* ","* ",},
    {"* ","* ","* ","* ","* ",},
    {"* ","* ","* ","* ","* ",},
    {"* ","* ","* ","* ","* ",}
};

int hits {0}; // no of tri
int Tries {0}; // no of hp ships have 

int x {};
int y {};

int UserX {};
int UserY {};

int shots {};


bool placement[5][5]{
    {0 , 1 , 0 , 0 , 0},    // 9 '1's
    {0 , 1 , 0 , 0 , 0},    // -- , --- , L--
    {1 , 1 , 0 , 0 , 1},
    {1 , 0 , 0 , 0 , 1},
    {0 , 0 , 0 , 1 , 1}
};

int display(){
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << map[i][j] ;
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
    cin >> UserX ;
    cout << "y coords:";
    cin >> UserY ;

    if ((UserX > 5 || UserX < 1) || (UserY > 5 || UserY < 1))
    {
        cout << "Coords invalid" ;
        exit(0) ;
    }else{
        x = 5-UserY ;
        y = UserX-1 ;
    }

    if (map[x][y] == "x ")
    {
        cout << "Cant nuke same spot again \n" ;
        Tries--;
    }else if (map[x][y] == "o ")
    {
        cout << "Cant nuke same spot again \n" ;
        Tries--;
    }else{
        shots++;
        cout << "\n" ;
    
        if (placement[x][y] == true )
        {
            placement[x][y] = false;
            map[x][y] = "x ";
            hits++;
            display();
        }else{
            map[x][y] = "o " ;
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
    while (Tries < 15)
    {
        nuke();
        Tries++ ;
        if (hits==9)
        {
            cout << "\n" ;
            cout << "Number one victory royale, yea fortnite about to get down";
            exit(0);
        }else if (Tries==15)
        {
            cout << "\n" ;
            cout << "NOOB \nGo play solitaire" ;
            exit(0);
        }  
    }
}




