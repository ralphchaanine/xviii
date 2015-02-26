#pragma once

#include "UnitTile.h"


class Infantry : public UnitTile
{
public:
	Infantry(World& _world, std::mt19937& _mt19937, Player* _belongsToPlayer, TextureManager& tm, FontManager& fm, UnitTile::Direction _dir);
	
	//Infantry's moveTo is overloaded because of the rule: INF can either MOVE, PARTIALLY ROTATE, or FULLY ROTATE in addition to attacking.
	std::string moveTo(TerrainTile* terrainTile);
	
	virtual std::string rotate(Direction _dir);
	virtual std::string interactWithFriendly(UnitTile* _unit);

	virtual int getMaxHp() const;
	virtual int getMaxMov() const;
	virtual int getMaxRange() const;

	virtual std::string attack(Infantry* inf, int distance, UnitTile::Modifier flank);
	virtual std::string attack(Cavalry* cav, int distance, UnitTile::Modifier flank);
	virtual std::string attack(Cuirassier* cuir, int distance, UnitTile::Modifier flank);
	virtual std::string attack(LightCav* lcav, int distance, UnitTile::Modifier flank);
	virtual std::string attack(Artillery* art, int distance, UnitTile::Modifier flank);
	virtual std::string attack(Mortar* mor, int distance, UnitTile::Modifier flank);
	virtual std::string attack(General* gen, int distance, UnitTile::Modifier flank);
	
	virtual std::string rangedAttack(UnitTile* unit, int distance);

private:
	static const int maxhp{18};
	static const int maxMov{6};
	static const int maxRange{6};
};

