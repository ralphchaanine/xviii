#pragma once

#include "LightCav.h"

class CrimeanCav : public LightCav
{
public:
	CrimeanCav(World& _world, std::mt19937& _mt19937, Player* _belongsToPlayer, TextureManager& tm, FontManager& fm, UnitTile::Direction _dir);

	//Overloaded due to Crimean Cav's ability to fully rotate after firing, and have 2 movement points left over
	virtual std::string CrimeanCav::rotate(UnitTile::Direction _dir);

	inline virtual int getMaxHp() const{ return maxhp; };
	inline virtual int getMaxMov() const{ return maxMov; };
	inline virtual int getMaxRange() const{ return maxRange; };

	virtual std::string CrimeanCav::rangedAttack(UnitTile* unit, int distance);

private:
	static const int maxhp{7};
	static const int maxMov{17};
	static const int maxRange{8};
};

