#pragma once

#include "boost/filesystem.hpp"
#include "boost/filesystem/fstream.hpp"

#include "xviii/Terrain/TerrainTile.h"
#include "xviii/Core/TextureManager.h"

#include <sstream>

class TerrainLoader
{
public:
	struct TerrainClassData{
		//This struct contains all the data needed to customise terrain bonuses from read
		//txt files

        std::vector<TerrainTile::UnitMainTypeBonus> unitMainBonuses;
        std::vector<TerrainTile::UnitFamilyTypeBonus> unitFamilyBonuses;
        std::vector<TerrainTile::UnitStringBonus> unitStringBonuses;

        //This map uses a unit's NAME as a key, and a pair of booleans as the value.
        //The first boolean specifies whether the unit is able to CROSS this terrain
        //tile, and the second whether it can STOP in it.

        //I opted to make this only possible through string entry in the interest of
        //avoiding too much overhead, taking into account this will be constantly accessed
        //by UnitTile::distanceFrom()
        std::map<std::string, std::pair<bool,bool>> unitStringMovementCapabilities;
	};

	TerrainLoader();
	void load();

	std::map<TerrainTile::TerrainType, std::unique_ptr<TerrainClassData>> customDefinitions;

private:
	void parse(boost::filesystem::path path);
};

