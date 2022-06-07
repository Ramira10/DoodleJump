#ifndef MENU_H
#define MENU_H
#include "Scene.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
using namespace sf;

class Menu : public Scene {
public:
	Menu();
	void Update (Game & game) override;
	void Draw (RenderWindow & window) override;
private:
	Font m_fuente;
	Text m_text1, m_text2, m_text3;
	Texture m_fondo;
	Sprite s_fondo;
};

#endif

