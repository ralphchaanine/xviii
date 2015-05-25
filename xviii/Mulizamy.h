#pragma once

#include "Lancer.h"

class Mulizamy : public Lancer
{
public:
	Mulizamy(World& _world, std::mt19937& _mt19937, Player* _belongsToPlayer, TextureManager& tm, FontManager& fm, UnitTile::Direction _dir);

	inline virtual int getMaxHp() const{ return maxhp; };
	inline virtual int getMaxMov() const{ return maxMov; };

private:
	static const int maxhp{14};
	static const int maxMov{9};
};

