#include "plataformaVerde.h"
#include "Player.h"
#include <vector>
using namespace std;

plataformaVerde::plataformaVerde() {
	m_plataverde.loadFromFile("imagenes/plataforma.png");
	s_plataverde.setTexture(m_plataverde);
	
	for(int i=0;i<1;i++) {
		Punto p;
		p.x = rand() % 500;
		p.y = 600;
		v.push_back(p);
		p.x = rand() % 500;
		p.y = 500;
		v.push_back(p);
		p.x = rand() % 500;
		p.y = 400;
		v.push_back(p);
		p.x = rand() % 500;
		p.y = 300;
		v.push_back(p);
		p.x = rand() % 500;
		p.y = 200;
		v.push_back(p);
		p.x = rand() % 500;
		p.y = 100;
		v.push_back(p);
		p.x = rand() % 500;
		p.y = 0;
		v.push_back(p);
	}
}

void plataformaVerde::Update ( ) {
	
}

void plataformaVerde::Draw(RenderWindow &window) {
	for(int i=0;i<v.size();i++) {
		if(v[i].x>435){
			v[i].x = v[i].x - (v[i].x-435);
		}
		s_plataverde.setPosition(v[i].x,v[i].y);
		window.draw(s_plataverde);
	}
}

bool plataformaVerde::CollideWith(Player &p){
	for(int i=0;i<v.size();i++) {
		if((p.GetX()+50>v[i].x) && (p.GetX()+20<v[i].x+68)
			&& (p.GetY()+70>v[i].y) && (p.GetY()+70<v[i].y+14) && (p.GetB()>0)) {
			p.Bounce();
		}
	}
}

void plataformaVerde::MoveCam(Player &p){
	for(int i=0;i<v.size();i++) {
		int auxY = p.GetY();
		int auxH = p.GetH();
		auxY = auxH;
		p.SetY(auxY);
		p.SetH(auxH);
		v[i].y = v[i].y - p.GetB();
		if(v[i].y>700) {
			v[i].y = 0;
			v[i].x = rand()%500;
		}
	}
}

