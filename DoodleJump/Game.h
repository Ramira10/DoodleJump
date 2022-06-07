#ifndef GAME_H
#define GAME_H
#include "Scene.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;

class Game {
public:
	Game();
	void Run();
	void ProcessEvents();
	void Update();
	void Draw();
	void SetScene(Scene *next_scene);
private:
	RenderWindow m_window;
	Scene *m_scene;
	Scene *m_next_scene = nullptr;
	Texture fondo;
	Sprite s_fondo;
};

#endif

