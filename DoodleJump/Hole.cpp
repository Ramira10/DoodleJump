#include "Hole.h"

Hole::Hole() {
	m_hole.loadFromFile("imagenes/hole.png");
	s_hole.setTexture(m_hole);
	
	for(int i=0;i<1;i++) {
		Punto p;
		p.x = rand() % 500;
		p.y = -700;
		v.push_back(p);
	}
}

void Hole::Draw(RenderWindow &window) {
	for(int i=0;i<v.size();i++) {
		if(v[i].x>435){
			v[i].x = v[i].x - (v[i].x-435);
		}
		s_hole.setPosition(v[i].x,v[i].y);
		window.draw(s_hole);
	}
}

bool Hole::CollideWith(Player &p){
	for(int i=0;i<v.size();i++) {
		if((p.GetX()+50>v[i].x) && (p.GetX()+20<v[i].x+68)
			&& (p.GetY()+70>v[i].y) && (p.GetY()+70<v[i].y+14) && (p.GetB()>0)) {
			return true;
		}
	}
}

void Hole::MoveCam(Player &p){
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
