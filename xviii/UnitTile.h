﻿#pragma once

#include "TerrainTile.h"
#include "FontManager.h"

#include <random>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <math.h>

#include "global.h"

#define UNITPROPERTIES\
	X(UnitTile::UnitType::ART, Artillery, "art")\
	X(UnitTile::UnitType::CAV, Cavalry, "cav")\
	X(UnitTile::UnitType::CUIR, Cuirassier, "cuir")\
	X(UnitTile::UnitType::DRAG, Dragoon, "drag")\
	X(UnitTile::UnitType::GEN, General, "gen")\
	X(UnitTile::UnitType::INF, Infantry, "inf")\
	X(UnitTile::UnitType::LCAV, LightCav, "lcav")\
	X(UnitTile::UnitType::MOR, Mortar, "mor")\
	X(UnitTile::UnitType::AKINCI, Akinci, "akinci")\
	X(UnitTile::UnitType::DELI, Deli, "deli")\
	X(UnitTile::UnitType::TIM, Timarioti, "tim")\
	X(UnitTile::UnitType::KAP, Kapikulu, "kap")\
	X(UnitTile::UnitType::GRE, Grenadier, "gre")\
	X(UnitTile::UnitType::JAN, Janissary, "jan")\
	X(UnitTile::UnitType::OINF, OttoInf, "o inf")\
	X(UnitTile::UnitType::LINF, LightInf, "linf")\
	X(UnitTile::UnitType::SAP, Sapper, "sap")\
	X(UnitTile::UnitType::CRICAV, CrimeanCav, "cr cav")\
	X(UnitTile::UnitType::COSINF, CossackInf, "cos inf")\
	X(UnitTile::UnitType::KMKH, KhevMkhedrebi, "khev mkh")\
	X(UnitTile::UnitType::PIT, PitsisKatsebi, "pit kat")\
	X(UnitTile::UnitType::DON, DonCossack, "don cos")\
	X(UnitTile::UnitType::AMKH, AbrMkhedrebi, "abr mkh")\
	X(UnitTile::UnitType::METTOP, MetTop, "met top")\
	X(UnitTile::UnitType::KACI, KudzeKaci, "kud kaci")\
	X(UnitTile::UnitType::FOOT, FootGuard, "footguard")

class Player;
class World;

class Infantry;
class Cavalry;
class Cuirassier;
class Dragoon;
class LightCav;
class Artillery;
class Mortar;
class General;
class Akinci;
class Deli;
class Timarioti;
class Kapikulu;
class Grenadier;
class Janissary;
class OttoInf;
class LightInf;
class Sapper;
class CrimeanCav;
class CossackInf;
class KhevMkhedrebi;
class PitsisKatsebi;
class DonCossack;
class AbrMkhedrebi;
class MetTop;
class KudzeKaci;
class FootGuard;


class UnitTile : public Tile
{
public:
	using unitPtr = std::unique_ptr<UnitTile>;
	enum class Direction{ N, E, S, W };
	enum class Modifier{NONE, ADDITIONAL, DISTANCE, FRONT_FLANK, SIDE_FLANK, REAR_FLANK};
	enum class UnitType{INF, CAV, CUIR, LCAV, DRAG, ART, MOR, GEN, AKINCI, DELI, TIM, KAP, GRE, JAN, OINF, LINF, SAP, CRICAV, COSINF, KMKH, AMKH, PIT, DON, METTOP, KACI, FOOT};
	enum class UnitFamily{INF_FAMILY, HINF_FAMILY, CAV_FAMILY, ART_FAMILY};

	//Used for storing modifier information

	struct ModifierReport{

		ModifierReport(Modifier _modType, float _modFloat) : 
		modType{_modType},
		modFloat{_modFloat}
		{
		}

		Modifier modType;
		float modFloat;
	};

	UnitTile(World& _world, std::mt19937&, Player* _belongsToPlayer, TextureManager& tm, FontManager& fm, TextureManager::Unit id, UnitType type, UnitFamily familyType, Direction _dir);
	//Create a virtual destructor, signifying this is an abstract class
	virtual ~UnitTile() = 0;

	//Very, very useful
	std::string roundFloat(const double x);

	UnitType getUnitType() const;
	UnitFamily getUnitFamilyType() const;

	int getCost() const;
	int getLimit() const;

	float gethp() const;
	int getMov() const;

	virtual void takeDamage(float _dmg);
	//Returns true if dead
	bool removeIfDead();

	UnitTile::Direction getDir() const;

	UnitTile::Direction opposite(UnitTile::Direction _dir);

	//Spawn is very similar to moveTo, but is only used during the setup phase; it costs no movement 
	void spawn(TerrainTile* terrainTile);

	//MAIN VIRTUAL FUNCTIONS:
	//They return strings for the output log...

    virtual std::string moveTo(TerrainTile* _terrainTile);
	//Called at the end of every turn;
	virtual void reset();
	virtual std::string rotate(Direction _dir);
	//Mainly used for the general to invoke the heal() function, but could be used for other things as well
	//hence the name
	virtual std::string interactWithFriendly(UnitTile* _unit);
	virtual std::string heal(float num);

	virtual int getMaxHp() const;
	virtual int getMaxMov() const;
	virtual int getMaxRange() const;

	//This function is in charge of initiating combat by determining distance, flank, etc. and calling either
	//meleeAttack() or rangedAttack()
	std::string attack(UnitTile* _unit);

	//Needed for double dispatch
	virtual std::string meleeAttack(UnitTile* _unit) = 0;

	virtual std::string meleeAttack(Infantry* inf);
	virtual std::string meleeAttack(FootGuard* foot);
	virtual std::string meleeAttack(Cavalry* cav);
	virtual std::string meleeAttack(Artillery* art);
	virtual std::string meleeAttack(Mortar* mor);

	virtual std::string rangedAttack(UnitTile* unit, int distance);

	//Each class will have an overloaded definition returning its specific flank modifier for either 
	//INF or CAV family units. In the interest of keeping the modifiers static, each class will have 
	//its own implementation of essentially the same function.
	virtual float getFlankModifier(UnitFamily _family, Modifier _flank) const;

	TerrainTile* getTerrain() const;
	Player* getPlayer() const;
	
	bool isHostile(UnitTile* _tile);
	//void highlightEnemy();

    //Manages the position of the sf::Text numbers (hp and movement)
	void updateStats();

	//Further documented in UnitTile.cpp
	virtual int distanceFrom(TerrainTile* _terrain, bool& _validMovDirection, bool& _validAttackDirection, bool& _obstructionPresent, bool& _inMovementRange, bool& _inRangedAttackRange, bool canShootOverUnits = false, int coneWidth = 1);
	//Overloaded version that only gets the distance and doesn't take in bools
	int distanceFrom(Tile* _tile);

	std::string dirToString();
	std::string modToString(ModifierReport _mod);
	std::string typeToString();

	std::string attackReport(int distance, UnitTile* attacker, UnitTile* defender, int attackerRoll, int defenderRoll, float attackerInflicted, float defenderInflicted, std::vector<ModifierReport>& thisModifiers, std::vector<ModifierReport>& enemyModifiers);

	bool getHasMoved() const;
	bool getHasRotated() const;
	bool getHasMeleeAttacked() const;
	bool getHasRangedAttacked() const;
	virtual bool getHasHealed() const;

	void sethp(float _hp);
	void setMov(float _mov);
	void setHasMoved(bool _hasMoved);
	void setHasRotated(bool _hasRotated);
	void setHasMeleeAttacked(bool _value);
	void setHasRangedAttacked(bool _value);

	//The following are applicable only for some children; the definition in UnitTile will be
	//blank
	virtual void setHasHealed(bool _hasHealed);

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	std::vector<ModifierReport> modVector;

	//Only ever needs to be used internally; making these so I don't have to copy and paste the same
	//code 20 times
	void multRollByModifiers(float &originalRoll);

protected:
	std::string outOfRange();

	World& world;
	std::mt19937& mt19937;

	//Pointer to the player the unit belongs to
	Player* player;

	//The unit's current direction (NESW)
	Direction dir;

	//In addition to each player having a flag, each unit itself must have a flag sprite too
	sf::Sprite unitFlag;
	
	//Pointer to the terrain tile that the unit is on. This is only to be used for units, to indicate
	//where they are easily and efficiently, since a unit must always be on a terrain tile
	TerrainTile* terrain;

	UnitType unitType;
	UnitFamily unitFamilyType;

	int deploymentCost;

	//0 represents no limit
	int limit;

	float hp;
	int mov;

	//For (yellow) outlining
	sf::RectangleShape yellowOutline;
	//For (red) outlining
	sf::RectangleShape redOutline;

	//The visual representations of the stats
    sf::Text dirText;
	sf::Text hpText;
	sf::Text movText;

	bool hasMoved{false};
	bool hasRotated{false};
	bool hasMeleeAttacked{false};
	bool hasRangedAttacked{false};

	bool waterCrosser{false};
};

