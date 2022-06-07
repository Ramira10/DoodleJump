#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "Scene.h"
#include <vector>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace std;
using namespace sf;

class GameOver : public Scene {
public:
	GameOver(int m_score);
	void Update (Game & game) override;
	void Draw (RenderWindow & window) override;
	void Load (int x);
private:
	Font m_fuente;
	Text gameoverText;
	Text backMenu;
	Text backGame;
	Text scoreText;
	Text bestScore;
	Text bestScore2;
	Text m_text3;
	string m_text1;
	std::vector<int> puntajes;
	Texture m_fondo;
	Sprite s_fondo;
	
};

#endif

