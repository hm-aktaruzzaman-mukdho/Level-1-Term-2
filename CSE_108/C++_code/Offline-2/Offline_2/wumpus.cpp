#include <iostream>
#include <cmath>
#include <ctime>
#include <sstream>

using namespace std;

#define GRIDSIZE 4
#define UP 0
#define DOWN 2
#define LEFT 3
#define RIGHT 1
#define MAX_SHOTS 3

string To_string(int x)
{
    string out_string;
    stringstream ss;
    ss << x;
    return ss.str();
}

class Position
{

    int x, y;

public:
    Position(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Position() {}

    // Modify the following four so that the resulting position does not leave the grid
    void moveRight()
    {
        if (x < GRIDSIZE - 1)
        {
            x++;
        }
    }

    void moveLeft()
    {
        if (x > 0)
        {
            x--;
        }
    }

    void moveUp()
    {
        if (y < GRIDSIZE - 1)
        {
            y++;
        }
    }

    void moveDown()
    {
        if (y > 0)
        {
            y--;
        }
    }

    bool isAdjacent(Position p)
    {
        // implement the function
        if (x == p.x)
        {
            if (abs(y - p.y) == 1)
            {
                return true;
            }
            else
                return false;
        }
        else if (y == p.y)
        {
            if (abs(x - p.x) == 1)
            {
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }

    bool isSamePoint(Position p)
    {
        // implement the function
        if ((x == p.x) && (y == p.y))
        {
            return true;
        }
        else
            return false;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }
};

class Wumpus
{

    bool killed;
    Position p;

public:
    Wumpus(int x, int y)
    {
        p = Position(x, y);
        killed = false;
    }

    Wumpus()
    {
        //...
        int tempx = 0, tempy = 0;
        while ((tempx == 0) && (tempx == 0))
        {
            tempx = rand() % GRIDSIZE;
            tempy = rand() % GRIDSIZE;
        }
        p = Position(tempx, tempy);
        killed = false;
    }

    void kill()
    {
        killed = true;
        p=Position(GRIDSIZE,GRIDSIZE);
    }



    Position getPosition()
    {
        return p;
    }



    // Code for debugging.Might delete later.
    // string getPositionInfo()
    // {
    //     return "Wumpus is now at " + To_string(p.getX()) + ", " + To_string(p.getY());
    // }

    bool iskilled()
    {
        return killed;
    }
};

// My implementation of class for pit
class Pit
{
    Position p;
    // pits are bottomless holes.So once fallen death is inevitable.

public:
    Pit(int x, int y)
    {
        p = Position(x, y);
    }

    Pit()
    {
        int tempx = 0, tempy = 0;
        while ((tempx == 0) && (tempx == 0))
        {
            tempx = rand() % GRIDSIZE;
            tempy = rand() % GRIDSIZE;
        }
        p = Position(tempx, tempy);
    };

    Position getPosition()
    {
        return p;
    }


    // Function for debugging.Delete later.
    // string getPositionInfo()
    // {
    //     return "Pit is now at " + To_string(p.getX()) + ", " + To_string(p.getY());
    // }
};

class Player
{

    int direction;
    int total_shots;
    bool killed;
    Position p;

public:
    Player()
    {
        //...
        p = Position(0, 0);
        direction = 0;
        total_shots = MAX_SHOTS;
        killed = false;
    }

    void turnLeft()
    {
        //...
        if (direction > 0)
            direction--;
        else
            direction = 3;
    }

    void turnRight()
    {
        if (direction < 3)
            direction++;
        else
            direction = 0;
        //...
    }

    void moveForward()
    {
        //...
        if (direction == RIGHT)
            p.moveRight();
        else if (direction == UP)
            p.moveUp();
        else if (direction == LEFT)
            p.moveLeft();
        else if (direction == DOWN)
            p.moveDown();
    }

    bool isAdjacent(Position pos)
    {
        return p.isAdjacent(pos);
    }

    bool isSamePoint(Position pos)
    {
        return p.isSamePoint(pos);
    }

    void kill()
    {
        killed = true;
    }

    string getPositionInfo()
    {
        return "Player is now at " + To_string(p.getX()) + ", " + To_string(p.getY());
    }

    string getDirectionInfo()
    {
        string s;
        if (direction == UP)
            s = "up";
        if (direction == DOWN)
            s = "down";
        if (direction == LEFT)
            s = "left";
        if (direction == RIGHT)
            s = "right";
        return "Player is moving at direction: " + s;
    }

    // Created extra functions
    //  int getDirection()
    //  {
    //      return direction;
    //  }
    // instead of getposition.Define a function to check the from wumpus.
    bool isinfront(Position p1)
    {
        if (direction == UP)
        {
            if ((this->p.getX() == p1.getX()) && (this->p.getY() < p1.getY()))
            {
                return true;
            }
        }
        if (direction == RIGHT)
        {
            if ((this->p.getY() == p1.getY()) && (this->p.getX() < p1.getX()))
            {
                return true;
            }
        }
        if (direction == DOWN)
        {
            if ((this->p.getX() == p1.getX()) && (this->p.getY() > p1.getY()))
            {
                return true;
            }
        }
        if (direction == LEFT)
        {
            if ((this->p.getY() == p1.getY()) && (this->p.getX() > p1.getX()))
            {
                return true;
            }
        }
        return false;
    }
    
    int shotsleft()
    {
        return total_shots;
    }

    void shot_fired()
    {
        if (shotsleft() > 0)
            total_shots--;
    }
};

class WumpusWorld
{

private:
    Player player;
    Wumpus wumpus;
    Pit pit;
    Position gold_position;
    bool ended;

public:
    WumpusWorld()
    {
        // Wumpus,pits and gold at random position
        int wumpus_x = 0, wumpus_y = 0, pit_x = 0, pit_y = 0, gold_x = 0, gold_y = 0;
        while ((wumpus_x == 0) && (wumpus_y == 0))
        {
            wumpus_x = (rand() % GRIDSIZE);
            wumpus_y = (rand() % GRIDSIZE);
        }

        while (((pit_x == 0) && (pit_y == 0)) || ((pit_x == wumpus_x) && (pit_y == wumpus_y)))
        {
            pit_x = rand() % GRIDSIZE;
            pit_y = rand() % GRIDSIZE;
        }

        while (((gold_x == 0) && (gold_y == 0)) || ((gold_x == pit_x) && (gold_y == pit_y)) || ((gold_x == wumpus_x) && (gold_y == wumpus_y)))
        {
            gold_x = rand() % GRIDSIZE;
            gold_y = rand() % GRIDSIZE;
        }
        wumpus = Wumpus(wumpus_x, wumpus_y);
        pit = Pit(pit_x, pit_y);
        gold_position = Position(gold_x, gold_y);
        ended = false;
    }

    WumpusWorld(int wumpus_x, int wumpus_y)
    {
        wumpus = Wumpus(wumpus_x, wumpus_y);
        gold_position=Position(rand()%GRIDSIZE,rand()%GRIDSIZE);//Gold position is randomly set
        ended = false;
    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y)
    {
        //...
        wumpus = Wumpus(wumpus_x, wumpus_y);
        gold_position = Position(gold_x, gold_y);
        ended = false;
    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y, int pit_x, int pit_y)
    {
        //...
        wumpus = Wumpus(wumpus_x, wumpus_y);
        pit = Pit(pit_x, pit_y);
        gold_position = Position(gold_x, gold_y);
        ended = false;
    }

    void moveForward()
    {
        player.moveForward();
        return showGameState();
    }

    void turnLeft()
    {
        player.turnLeft();
        return showGameState();
    }

    void turnRight()
    {
        player.turnRight();
        return showGameState();
    }

    void shoot()
    {
        if (player.shotsleft() > 0)
        {
            player.shot_fired();
            if(player.isinfront(wumpus.getPosition()))
            {
                wumpus.kill();
                //cout<<"   !!!Avada Kedavra!!!   "<<endl<<"     Wumpus is dead\n"<<endl;
            }
        }
        showGameState();

    }
    bool state=true;
    void showGameState()
    {
        system("cls");
        cout<<endl;
        cout << player.getPositionInfo() << endl;
        cout << player.getDirectionInfo() << endl;


        //Below 4 lines are for debugging.
        // cout << "Wumpus and pit position" << endl;
        // cout << wumpus.getPositionInfo() << endl;
        // cout << pit.getPositionInfo() << endl;
        // cout << "Position of gold:"+To_string(gold_position.getX())+","+To_string(gold_position.getY())<<endl;
        // cout<<"Is in front:"<<player.isinfront(wumpus.getPosition())<<endl;
        if (player.isAdjacent(wumpus.getPosition()))
        {
            cout << "stench!" << endl;
        }

        //Stench only when wumpus is adjacent in the moving direction.
        // if (player.isAdjacent(wumpus.getPosition())&&player.isinfront(wumpus.getPosition()))
        // {
        //     cout << "stench!" << endl;
        // }

        if (player.isSamePoint(wumpus.getPosition()))
        {
            cout << "Player is killed!" << endl;
            player.kill();
            cout << "Game over!" << endl;
            ended = true;
        }

        if (player.isAdjacent(pit.getPosition()))
        {
            cout << "Breeze!" << endl;
        }
        //Breeze only when pit is adjacent and in the moving direction
        // if (player.isAdjacent(pit.getPosition())&&player.isinfront(wumpus.getPosition()))
        // {
        //     cout << "Breeze!" << endl;
        // }

        if (player.isSamePoint(pit.getPosition()))
        {
            cout << "You will rot in this pit forever" << endl;
            player.kill();
            cout << "Game over!" << endl;
            ended = true;
        }

        if (player.isSamePoint(gold_position))
        {
            cout << "Got the gold!" << endl;
            cout << "Game ended, you won!" << endl;
            ended = true;
        }
        if(wumpus.iskilled()&&state)
        {
            cout<<"   !!!Avada Kedavra!!!   "<<endl<<"     Wumpus is dead\n"<<endl;;
            state=false;
        }
        if(player.shotsleft()==0)
        {
            cout<<"!!No ammo left"<<endl;
        }
    }

    bool isOver()
    {
        return ended;
    }
};

int main()
{
    srand(time(0));
    int c, wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y;

    // FILE *fpt=fopen("Positions.txt","r");
    // if (fpt == NULL) {
    //     printf("The file is not opened. The program will "
    //            "now exit.");
    //     exit(0);
    // }
    
    // fscanf(fpt,"%d",&wumpus_x);
    // fscanf(fpt,"%d",&wumpus_y);
    // fscanf(fpt,"%d",&gold_x);
    // fscanf(fpt,"%d",&gold_y);
    // fscanf(fpt,"%d",&pit_x);
    // fscanf(fpt,"%d",&pit_y);

    // take the six integers input from file

    cin>>wumpus_x>>wumpus_y>>gold_x>>gold_y>>pit_x>>pit_y;
    WumpusWorld w(wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y);
    //WumpusWorld w;
    w.showGameState();
    while (!w.isOver())
    {
        cout << "   1: move forward" << endl;
        cout << "   2: Turn left" << endl;
        cout << "   3: Turn right" << endl;
        cout << "   4: Shoot" << endl;
        cin >> c;
        if (c == 1)
        {
            w.moveForward();
        }
        else if (c == 2)
        {
            w.turnLeft();
        }
        else if (c == 3)
        {
            w.turnRight();
        }
        else if (c == 4)
        {
            w.shoot();
        }

    }
    return 0;
}
