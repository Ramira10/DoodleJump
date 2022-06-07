#include "GameOver.h"
#include "Menu.h"
#include "Match.h"
#include "Game.h"
#include <fstream>
#include <SFML/Window/Keyboard.hpp>
#include "Scores.h"

GameOver::GameOver(int m_score) {
	m_fondo.loadFromFile("imagenes/fondo.png");
	s_fondo.setTexture(m_fondo);
	
	m_fuente.loadFromFile("fuentes/al-seana.ttf");
	gameoverText.setFont(m_fuente);
	gameoverText.setString("¡Game Over!");
	gameoverText.setPosition(40,150);
	gameoverText.setCharacterSize(100);
	gameoverText.setFillColor(Color::Red);
	
	Load(m_score);
	
	scoreText.setFont(m_fuente);
	scoreText.setString("Score: " + to_string(m_score));
	scoreText.setPosition(200,290);
	scoreText.setCharacterSize(40);
	scoreText.setFillColor(Color::Red);
	
	bestScore.setFont(m_fuente);
	bestScore.setString("La mejor puntación: ");
	bestScore.setFillColor(Color::Red);
	bestScore.setPosition(110,330);
	bestScore.setCharacterSize(40);
	
	m_text1 = to_string(puntajes[0]);
	bestScore2.setString(m_text1);
	bestScore2.setFont(m_fuente);
	bestScore2.setFillColor(Color::Red);
	bestScore2.setPosition(385,330);
	bestScore2.setCharacterSize(40);
	
	backMenu.setFont(m_fuente);
	backMenu.setString("<presione M para volver al menu principal>");
	backMenu.setPosition(35,430);
	backMenu.setCharacterSize(30);
	backMenu.setFillColor(Color::Black);
	
	backGame.setFont(m_fuente);
	backGame.setString("<Presione 'TAB' para volver a jugar>");
	backGame.setPosition(60,470);
	backGame.setCharacterSize(30);
	backGame.setFillColor(Color::Black);
	
	m_text3.setFont(m_fuente);
	m_text3.setString("<Presione 'P' para ver la tabla de posiciones>");
	m_text3.setFillColor(Color::Black);
	m_text3.setPosition(12,505);
	m_text3.setCharacterSize(30);
}

void GameOver::Update (Game & game) {
	if (Keyboard::isKeyPressed(Keyboard::Key::M))
		game.SetScene(new Menu());
	if(Keyboard::isKeyPressed(Keyboard::Key::Tab))
		game.SetScene(new Match()); 
	if(Keyboard::isKeyPressed(Keyboard::Key::P))
		game.SetScene(new Scores()); 
}

void GameOver::Draw (RenderWindow & window) {
	window.clear({0,0,0});
	window.draw(s_fondo);
	window.draw(gameoverText);
	window.draw(backMenu);
	window.draw(backGame);
	window.draw(scoreText);
	window.draw(bestScore);
	window.draw(bestScore2);
	window.draw(m_text3);
	window.display();
}

void GameOver::Load (int m_score) {
	ifstream archi("archivos/puntajes.txt");
	int aux;
	while(archi>>aux) {
		puntajes.push_back(aux);
	}
	archi.close();
	
	puntajes.push_back(m_score);
	sort(puntajes.begin(),puntajes.end(),std::greater<int>());
	puntajes.pop_back();
	
	ofstream archi2("archivos/puntajes.txt",ios::trunc);
	for(int i=0;i<puntajes.size();i++) {
		archi2 << puntajes[i] << endl;
	}
	archi2.close();
}

