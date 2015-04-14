#include "stdafx.h"
#include "KudzeKaci.h"


KudzeKaci::KudzeKaci(World& _world, std::mt19937& _mt19937, Player* _belongsToPlayer, TextureManager& tm, FontManager& fm, UnitTile::Direction _dir) : 
LightInf(_world, _mt19937, _belongsToPlayer, tm, fm, _dir, TextureManager::Unit::LINF, UnitType::KACI)
{
	deploymentCost = 1;
	limit = 0;

	waterCrosser = true;
	mov = maxMov;
	hp = maxhp;
}

int KudzeKaci::getMaxHp() const{
	return maxhp;
}

int KudzeKaci::getMaxMov() const{
	return maxMov;
}

int KudzeKaci::getMaxRange() const{
	return maxRange;
}

std::string KudzeKaci::rangedAttack(UnitTile* unit, int distance){
	std::uniform_int_distribution<int> distribution(1, 6);

	int thisRoll_int{distribution(mt19937)};

	float thisRoll = thisRoll_int;

	float damageDealt{0};

	float distanceModifier{1};

	if (distance >= 4 && distance <= 7){
		distanceModifier = 0.5;
	}
	else if (distance >= 2 && distance <= 4){
		distanceModifier = 1;
	}
	else if (distance == 1){
		distanceModifier = 1.5;
	}

	modVector.emplace_back(Modifier::DISTANCE, distanceModifier);

	multRollByModifiers(thisRoll);
	damageDealt = thisRoll;
	unit->takeDamage(damageDealt);

	mov = 0;
	this->updateStats();
	unit->updateStats();
	hasRangedAttacked = true;

	return attackReport(distance, this, unit, thisRoll_int, 0, damageDealt, 0, modVector, unit->modVector);
}
