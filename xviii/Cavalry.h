#pragma once

#include "UnitTile.h"

class Cavalry : public UnitTile
{
public:
	Cavalry(UnitLoader& _unitLoader, World& _world, std::mt19937& _mt19937, Player* _belongsToPlayer, TextureManager& _tm, FontManager& _fm, TextureManager::Unit _texture, std::string _name, UnitType _type, UnitFamily _familyType, Direction _dir);

	//The lancer bonus, here for convenience. Certain subclasses of Cavalry are meant to have this. The boolean lancer 
	//determines whether this code is run or not.
	bool lancerBonus(UnitTile* defender, float finalAttackerRoll, bool attackBonusReady, float& damageDealt);

	//Overloaded for the attackReady variable, used by lancers
	virtual void reset();
	virtual std::string rotate(Direction _dir);

	virtual std::string meleeAttack(UnitTile* _unit);

	virtual std::string meleeAttack(Infantry* inf);
	virtual std::string meleeAttack(Cavalry* cav);
	virtual std::string meleeAttack(Artillery* art);
	virtual std::string meleeAttack(Mortar* mor);

	virtual bool getUniqueVariable() const{ return attackBonusReady; };
	virtual void setUniqueVariable(bool _value){ attackBonusReady = _value; };

protected:
	bool attackBonusReady{true};
};

