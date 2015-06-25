#include "xviii/Headers/stdafx.h"
#include "xviii/Terrain/TBridge.h"

#include "xviii/Core/World.h"


TBridge::TBridge(TerrainLoader& _terrainLoader, World& _world, TextureManager& tm, sf::Vector2f _pos) :
TerrainTile(_terrainLoader, _world, tm, TextureManager::Terrain::TBRIDGE_VER, TerrainType::TBRIDGE, _pos),
hp{5}
{
}

void TBridge::takeDamage(int dmg){
    hp -= dmg;
    if(hp < 0.9){
        world.toggleTBridge(this);
    }
};


void TBridge::flip(Orientation _or){
    if(_or == Orientation::HORIZONTAL){
        sprite = world.tm.getSprite(TextureManager::Terrain::TBRIDGE_HOR);
    }
    else if(_or == Orientation::VERTICAL){
        sprite = world.tm.getSprite(TextureManager::Terrain::TBRIDGE_VER);
    }
}


std::string TBridge::callTerrainAttack(UnitTile* unit, int distance){
    return(unit->terrainAttack(this, distance));
}
