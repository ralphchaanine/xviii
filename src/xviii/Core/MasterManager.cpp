#include "xviii/Headers/stdafx.h"
#include "xviii/Core/MasterManager.h"

#include "xviii/Core/FactionLoader.h"
#include "xviii/Core/UnitLoader.h"
#include "xviii/Core/TerrainLoader.h"

MasterManager::MasterManager():
randevice{},
randomEngine{randevice()},
mapSeedEngine{randevice()},
fontManager{std::unique_ptr<FontManager>(new FontManager())},
textureManager{std::unique_ptr<TextureManager>(new TextureManager(randomEngine))},
factionLoader{std::unique_ptr<FactionLoader>(new FactionLoader(*(textureManager.get())))},
unitLoader{std::unique_ptr<UnitLoader>(new UnitLoader(*(textureManager.get())))},
terrainLoader{std::unique_ptr<TerrainLoader>(new TerrainLoader())}
{
}

MasterManager::~MasterManager()
{
}
