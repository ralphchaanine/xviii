#include "stdafx.h"
#include "Grenadier.h"


Grenadier::Grenadier(World& _world, std::mt19937& _mt19937, Player* _belongsToPlayer, TextureManager& tm, FontManager& fm, UnitTile::Direction _dir) :
Infantry(_world, _mt19937, _belongsToPlayer, tm, fm, _dir, TextureManager::Unit::GRE, UnitTile::UnitType::GRE)
{
	deploymentCost = 1;
	limit = 0;

	waterCrosser = false;
	mov = maxMov;
	hp = maxhp;
}

int Grenadier::getMaxHp() const{
	return maxhp;
}

int Grenadier::getMaxMov() const{
	return maxMov;
}

int Grenadier::getMaxRange() const{
	return maxRange;
}