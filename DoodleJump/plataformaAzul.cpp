#include "plataformaAzul.h"

plataformaAzul::plataformaAzul() {
	m_platazul.loadFromFile("imagenes/platazul.png");
	s_platazul.setTexture(m_platazul);
	
	for(int i=0;i<1;i++) {
		Punto p;
		p.x = rand() % 500;
		p.y = rand() % 700;
		v.push_back(p);
	}
}

void plataformaAzul::Update ( ) {
	for(int i=0;i<v.size();i++) {
		if(v[i].x < 500){
			v[i].x += 6;
		}else if(v[i].x > 10){
			v[i].x = -68;
		}
	}
}

void plataformaAzul::Draw(RenderWindow &window) {
	for(int i=0;i<v.size();i++) {
		s_platazul.setPosition(v[i].x,v[i].y);
		window.draw(s_platazul);
	}
}

bool plataformaAzul::CollideWith(Player &p){
	for(int i=0;i<v.size();i++) {
		if((p.GetX()+50>v[i].x) && (p.GetX()+20<v[i].x+68)
			&& (p.GetY()+70>v[i].y) && (p.GetY()+70<v[i].y+14) && (p.GetB()>0)) {
			p.Bounce2();
		}
	}
}

void plataformaAzul::MoveCam(Player &p){
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
