#pragma once

#define TEXTUREPROPERTIES\
	X("INF", TextureManager::Unit::INF)\
	X("CAV", TextureManager::Unit::CAV)\
	X("CUIR", TextureManager::Unit::CUIR)\
	X("LCAV", TextureManager::Unit::LCAV)\
	X("DRAG", TextureManager::Unit::DRAG)\
	X("ART", TextureManager::Unit::ART)\
	X("MOR", TextureManager::Unit::MOR)\
	X("GEN", TextureManager::Unit::GEN)\
	X("GRE", TextureManager::Unit::GRE)\
	X("LINF", TextureManager::Unit::LINF)\
	X("SAP", TextureManager::Unit::SAP)\
	X("HINF", TextureManager::Unit::HINF)\
	X("ARTGUARD", TextureManager::Unit::ARTGUARD)\
	X("PIKE", TextureManager::Unit::PIKE)\
	X("LAN", TextureManager::Unit::LAN)\
	X("ARMLAN", TextureManager::Unit::ARMLAN)\
	X("IRR", TextureManager::Unit::IRR)\
	X("HARCH", TextureManager::Unit::HARCH)\
	X("LART", TextureManager::Unit::LART)\
	X("LDRAG", TextureManager::Unit::LDRAG)

class TextureManager : public sf::NonCopyable
{
public:
	using texturePtr = std::unique_ptr<sf::Texture>;

	enum class Terrain{MEADOW, HILLS, MUD, ROAD, SLOPES, URBAN, WATER, WOODS, BRIDGE_VER, BRIDGE_HOR, TBRIDGE_VER, TBRIDGE_HOR, BLANK};
	enum class UI{RECTANGLE, BUTTON};

	TextureManager();

	sf::Sprite getUnitSprite(std::string _textureID);
	sf::Sprite getFlagSprite(std::string _textureID);
	sf::Sprite getSprite(Terrain type);
	sf::Sprite getSprite(UI type);

	inline sf::Vector2i getSize() const{ return size; };
	inline sf::Vector2i getCounterSize() const{ return counterSize; };
    //Used for the vertex array (for terrain tiles)
	inline sf::Texture& getTerrainTexture() const{ return *terrain; };

private:
	std::map<std::string, texturePtr> units;
	std::map<std::string, texturePtr> flags;
	texturePtr terrain;

	//The rectangular UI bar at the bottom
	texturePtr ui;
	//Ready/next turn button
	texturePtr button;

	//This should correspond to the FULL size of each [Terrain] tile
	//for everything to work properly
	sf::Vector2i size;

	//The size of the unit counters (ideally smaller than the full terrain tile size)
	sf::Vector2i counterSize;

};

