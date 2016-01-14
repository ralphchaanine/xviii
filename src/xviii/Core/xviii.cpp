#include "xviii/Headers/stdafx.h"
#include "xviii/Core/Game.h"

/*
    TOFIX:

    (*) If there are too many saves, you can't scroll to see all of them

    TODO:

    (*) Seperate movement and attack logic so that classes can, for example, be given movement rules of CAV but
    attack rules of INF (TODO later, after the upcoming UI update)

    (*) At some point, perhaps create a function that returns every tile in between 2 given tiles, for less code
    repetition in places (UnitTile::distanceFrom(), UnitTile::moveTo(), UnitTile::rangedAttack()...). At the moment
    there are some complexities (and laziness) which prevent me from creating a unified solution, but it's something
    to look into sometime.

    (*) Implement a specialised HillAnt class (for slopes and hills)

	(*) Have a basic readable config file where several simple parameters can be set (resolution, deployment points, etc.)

*/

int main(int argc, char* argv[]){
	Game game;
	return 0;
}

