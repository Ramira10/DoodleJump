#include "Scores.h"
#include "Menu.h"
#include <sstream>
#include <fstream>
#include <SFML/Window/Keyboard.hpp>
using namespace sf;
using namespace std;

Scores::Scores() {
	m_fondo.loadFromFile("imagenes/fondo.png");
	s_fondo.setTexture(m_fondo);
	
	m_fuente.loadFromFile("fuentes/al-seana.ttf");
	m_text1.setFont(m_fuente);
	m_text2.setFont(m_fuente);
	m_score1.setFont(m_fuente);
	m_score2.setFont(m_fuente);
	m_score3.setFont(m_fuente);
	m_score4.setFont(m_fuente);
	m_score5.setFont(m_fuente);
	scores.setFont(m_fuente);
	
	m_text1.setString("TOP 5:");
	m_text1.setFillColor(Color::Red);
	m_text1.setPosition(210,30);
	m_text1.setCharacterSize(50);
	
	m_score1.setString("1°:");
	m_score2.setString("2°:");
	m_score3.setString("3°:");
	m_score4.setString("4°:");
	m_score5.setString("5°:");
	m_score1.setFillColor(Color::Red);
	m_score2.setFillColor(Color::Red);
	m_score3.setFillColor(Color::Red);
	m_score4.setFillColor(Color::Red);
	m_score5.setFillColor(Color::Red);
	m_score1.setPosition(170,108);
	m_score2.setPosition(170,224);
	m_score3.setPosition(170,341);
	m_score4.setPosition(170,457);
	m_score5.setPosition(170,572);
	m_score1.setCharacterSize(50);
	m_score2.setCharacterSize(50);
	m_score3.setCharacterSize(50);
	m_score4.setCharacterSize(50);
	m_score5.setCharacterSize(50);
	
	m_text2.setString("<Presione 'ESC' para volver al menú principal>");
	m_text2.setFillColor(Color::Black);
	m_text2.setPosition(14,660);
	m_text2.setCharacterSize(30);
	
	Load();
	stringstream ss;
	ss<<"  "<<puntajes[0]<<endl<<endl<<"  "<<puntajes[1]<<endl<<endl<<"  "<<puntajes[2]
	<<endl<<endl<<"  "<<puntajes[3]<<endl<<endl<<"  "<<puntajes[4]<<endl;
	scores.setFont(m_fuente);
	scores.setCharacterSize(50);
	scores.setFillColor(Color::Black);
	scores.setPosition(220,110);
	scores.setString(ss.str());
}

void Scores::Update (Game & game) {
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
		game.SetScene(new Menu());
	}
}

void Scores::Draw (RenderWindow & window) {
	window.clear(Color(255,255,255,255));
	window.draw(s_fondo);
	window.draw(m_text1);
	window.draw(m_text2);
	window.draw(m_score1);
	window.draw(m_score2);
	window.draw(m_score3);
	window.draw(m_score4);
	window.draw(m_score5);
	window.draw(scores);
	window.display();
}

void Scores::Load ( ) {
	int aux;
	ifstream puntos("archivos/puntajes.txt");
	while(puntos>>aux) {
		puntajes.push_back(aux);
	}
	puntos.close();
}
