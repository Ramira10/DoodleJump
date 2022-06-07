#include "Score.h"
#include "Player.h"

Score::Score() {
	m_fuente.loadFromFile("fuentes/arial.ttf");
	scoreText.setFont(m_fuente);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor({255,0,0,255});
	scoreText.setPosition(5,0);
}

void Score::Update () {
	score += 1;
	scoreText.setString("Score: " + std::to_string(score));
}

int Score::GetScore ( ) {
	return score;
}

void Score::Draw(RenderWindow &window) { 
	window.draw(scoreText);
}
