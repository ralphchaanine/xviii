#include "stdafx.h"
#include "UnitLoader.h"

UnitLoader::UnitLoader(TextureManager& _tm) : 
tm(_tm)
{
}

void UnitLoader::load(){
	boost::filesystem::recursive_directory_iterator end;

	for (boost::filesystem::recursive_directory_iterator it("assets/units"); it != end; ++it){
		parse(it->path());
	}
}

void UnitLoader::parse(boost::filesystem::path path){
	//Create a new UnitClassData; initialise its name as "temp" while we get it from the file itself
	std::unique_ptr<UnitClassData> newClass = std::move(std::unique_ptr<UnitClassData>(new UnitClassData("temp", path)));

	std::ifstream unitData;
	unitData.open(path.string());

	std::string currentLine;

	#define AFTERCOLON currentLine.substr(currentLine.find(":") + 1, currentLine.size() - 1)
	#define EXISTS != std::string::npos

	while (unitData && std::getline(unitData, currentLine)){

		if (currentLine.find("NATIONS:") EXISTS){
			std::getline(unitData, currentLine);

			while (currentLine.find("}") == std::string::npos){
				if (currentLine.find("DEFINE:") EXISTS){
					std::string str = AFTERCOLON;

					#define X(nationType, textureType, _str)\
					if(str == _str){\
						newClass->nations.emplace_back(nationType);\
					}
					NATIONPROPERTIES
					#undef X
				}

				std::getline(unitData, currentLine);
			}
		}

		else if (currentLine.find("STRING:") EXISTS){
			newClass->name = AFTERCOLON;
		}

		else if (currentLine.find("SPRITE:") EXISTS){
			std::string str = AFTERCOLON;

				#define X(_str, texType)\
				if(str == _str){\
					newClass->sprite = tm.getSprite(texType);\
				}
				TEXTUREPROPERTIES
				#undef X
		}

		else if (currentLine.find("MAIN TYPE:") EXISTS){
			std::string str = AFTERCOLON;

			#define X(_str, mainType, cl)\
			if(str == _str){\
				newClass->unitType = mainType;\
									}
			MAINTYPEPROPERTIES
			#undef X
		}

		else if (currentLine.find("FAMILY TYPE:") EXISTS){
			std::string str = AFTERCOLON;

			#define X(_str, familyType)\
			if(str == _str){\
				newClass->unitFamilyType = familyType;\
			}
			FAMILYTYPEPROPERTIES
			#undef X
		}

		else if (currentLine.find("HP:") EXISTS){
			newClass->maxHp = std::stoi(AFTERCOLON);
		}

		else if (currentLine.find("MOV:") EXISTS){
			newClass->maxMov = std::stoi(AFTERCOLON);
		}

		else if (currentLine.find("COST:") EXISTS){
			newClass->cost = std::stoi(AFTERCOLON);
		}

		else if (currentLine.find("MELEE:") EXISTS){
			newClass->melee = std::stoi(AFTERCOLON);
		}

		else if (currentLine.find("SKIRMISH:") EXISTS){
			newClass->skirmish = std::stoi(AFTERCOLON);
		}

		else if (currentLine.find("FRIGHTENING:") EXISTS){
			newClass->frightening = std::stoi(AFTERCOLON);
		}

		else if (currentLine.find("LANCER:") EXISTS){
			newClass->lancer = std::stoi(AFTERCOLON);
		}

		else if (currentLine.find("RANGED") EXISTS){
			std::getline(unitData, currentLine);

			while (currentLine.find("}") == std::string::npos){
				if (currentLine.find("DEFINE:") EXISTS){
					std::string str = AFTERCOLON;

					std::vector<float> rangeArgs;

					size_t pos = 0;

					//We do the whole mess with stringstream because regular stoi trunctuates
					//decimals, and we don't want that. We do an extra go at the end to catch the
					//last variable that isn't done in the loop.

					while ((pos = str.find(",")) != std::string::npos){
						std::string temp = str.substr(0, pos);
						std::stringstream ss(temp);
						float arg;
						ss >> arg;
						rangeArgs.push_back(arg);
						str.erase(0, pos + 1);
					}
					
					std::string temp = str.substr(0, pos);
					std::stringstream ss(temp);
					float arg;
					ss >> arg;
					rangeArgs.push_back(arg);

					newClass->rangedAttackDistValues.emplace_back(rangeArgs[0], rangeArgs[1], rangeArgs[2], rangeArgs[3], rangeArgs[4], rangeArgs[5]);

				}

				std::getline(unitData, currentLine);
			}
		}

		else if (currentLine.find("HEALING") EXISTS){
			std::getline(unitData, currentLine);

			while (currentLine.find("}") == std::string::npos){
				if (currentLine.find("DEFINE:") EXISTS){
					std::string str = AFTERCOLON;

					std::vector<float> healingArgs;

					size_t pos = 0;

					//We do the whole mess with stringstream because regular stoi trunctuates
					//decimals, and we don't want that. We do an extra go at the end to catch the
					//last variable that isn't done in the loop.

					while ((pos = str.find(",")) != std::string::npos){
						std::string temp = str.substr(0, pos);
						std::stringstream ss(temp);
						float arg;
						ss >> arg;
						healingArgs.push_back(arg);
						str.erase(0, pos + 1);
					}

					std::string temp = str.substr(0, pos);
					std::stringstream ss(temp);
					float arg;
					ss >> arg;
					healingArgs.push_back(arg);

					newClass->healingRangeValues.emplace_back(healingArgs[0], healingArgs[1], healingArgs[2]);

				}

				std::getline(unitData, currentLine);
			}
		}
	}

	unitData.close();
	customClasses.emplace(newClass->name, std::move(*newClass));
}