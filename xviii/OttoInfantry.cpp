#include "stdafx.h"
#include "OttoInfantry.h"


OttoInfantry::OttoInfantry(World& _world, std::mt19937& _mt19937, Player* _belongsToPlayer, TextureManager& tm, FontManager& fm, UnitTile::Direction _dir) :
Infantry(_world, _mt19937, _belongsToPlayer, tm, fm, _dir, TextureManager::Unit::INF, UnitTile::UnitType::OINF)
{
	deploymentCost = 1;
	limit = 0;

	waterCrosser = false;
	mov = maxMov;
	hp = maxhp;
}

int OttoInfantry::getMaxHp() const{
	return maxhp;
}

int OttoInfantry::getMaxMov() const{
	return maxMov;
}

int OttoInfantry::getMaxRange() const{
	return maxRange;
}