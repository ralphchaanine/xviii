#pragma once

#include "xviii/GameStates/GameState.h"

#include "boost/filesystem/fstream.hpp"

#include "xviii/Headers/global.h"
#include "xviii/Headers/keybinds.h"

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
//This class isn't meant to be used directly; it's rather meant to be a parent
//class for all the kinds of menu states
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

class GameState_MenuState : public GameState
{
public:
	GameState_MenuState(Game* game);
	virtual void getInput();
	virtual void update(float mFT);
	virtual void draw();
	virtual void onSwitch();
protected:
	enum class Action{NEW, LOAD, EXIT, SAVE, NONE};

	//If the action is not NONE, the game will perform that action upon choosing the object.
	//If the state is not null, the game will switch to that gamestate upon choosing the object.

	//Obviously, doing some stupid things like saving before players are even initialised, could
	//cause CTDs or strange behaviour, so don't do that.

	struct menuObject{
		menuObject(boost::filesystem::path _path, bool _highlightable, GameState* _state, Action _action, World::Era _era = World::Era::ALL) :
			path{_path}, highlightable{_highlightable}, state{_state}, action{_action}, era{_era}
		{
			text.setString(_path.filename().string());
		}

		boost::filesystem::path path;
		bool highlightable;
		sf::Text text;
		GameState* state;
		Action action;
		//This will only matter if the action is NEW; for loading games, this will be
		//loaded from the save file
		World::Era era;
	};

	std::vector<menuObject> menuList;

	//menuIterator will serve as an easy way to access the pointer to
	// the currently selected option that can be incremented and
	//decremented to move around the vector

	std::vector<menuObject>::iterator menuIterator;

	static sf::View menuSelectView;
	static sf::View backgroundView;

	static sf::Text titleText;
	static sf::Text quoteText;
	//Due to the massive amount of available backgrounds, and the fact that only one will be ever used,
	//this is the only place in the code where I won't handle a texture with TextureManager.
	static std::unique_ptr<sf::Texture> backgroundTexture;
	static sf::Sprite backgroundSprite;

	void lineUpObjects();


	bool scroll{false};

};

