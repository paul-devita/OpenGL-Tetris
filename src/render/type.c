#include "type.h"

void tp_drawChar(vec2 position, vec2 scale, vec3 color, unsigned int thickness, const char character) {
	char c = character;

	if (c >= 'A' && c <= 'Z')
		c += 32;

	switch (c) {
		case 'a':
			tp_drawA(position, scale, thickness, color);
			break;
		case 'b':
			tp_drawB(position, scale, thickness, color);
			break;
		case 'c':
			tp_drawC(position, scale, thickness, color);
			break;
		case 'd':
			tp_drawD(position, scale, thickness, color);
			break;
		case 'e':
			tp_drawE(position, scale, thickness, color);
			break;
		case 'f':
			tp_drawF(position, scale, thickness, color);
			break;
		case 'g':
			tp_drawG(position, scale, thickness, color);
			break;
		case 'h':
			tp_drawH(position, scale, thickness, color);
			break;
		case 'i':
			tp_drawI(position, scale, thickness, color);
			break;
		case 'j':
			tp_drawJ(position, scale, thickness, color);
			break;
		case 'k':
			tp_drawK(position, scale, thickness, color);
			break;
		case 'l':
			tp_drawL(position, scale, thickness, color);
			break;
		case 'm':
			tp_drawM(position, scale, thickness, color);
			break;
		case 'n':
			tp_drawN(position, scale, thickness, color);
			break;
		case 'o':
			tp_drawO(position, scale, thickness, color);
			break;
		case 'p':
			tp_drawP(position, scale, thickness, color);
			break;
		case 'q':
			tp_drawQ(position, scale, thickness, color);
			break;
		case 'r':
			tp_drawR(position, scale, thickness, color);
			break;
		case 's':
			tp_drawS(position, scale, thickness, color);
			break;
		case 't':
			tp_drawT(position, scale, thickness, color);
			break;
		case 'u':
			tp_drawU(position, scale, thickness, color);
			break;
		case 'v':
			tp_drawV(position, scale, thickness, color);
			break;
		case 'w':
			tp_drawW(position, scale, thickness, color);
			break;
		case 'x':
			tp_drawX(position, scale, thickness, color);
			break;
		case 'y':
			tp_drawY(position, scale, thickness, color);
			break;
		case 'z':
			tp_drawZ(position, scale, thickness, color);
			break;

	}
}

static void tp_drawA(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3, p4;
	vec2 s1, s2, s3, s4;

	p1.x = position.x;
	p1.y = position.y - thickness / 2;
	s1.x = scale.x - 2 * thickness;
	s1.y = thickness;

	p2.x = position.x;
	p2.y = position.y - scale.y / 2 + thickness / 2;
	s2.x = scale.x - 2 * thickness;
	s2.y = thickness;

	p3.x = position.x - scale.x / 2 + thickness / 2;
	p3.y = position.y;
	s3.x = thickness;
	s3.y = scale.y;

	p4.x = position.x + scale.x / 2 - thickness / 2;
	p4.y = position.y;
	s4.x = thickness;
	s4.y = scale.y;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
	qd_drawSolidRect(p4, s4, 0, color);
}

static void tp_drawB(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3, p4, p5, p6;
	vec2 s1, s2, s3, s4, s5, s6;

	//Horizontal Lines
	p1.x = position.x;
	p1.y = position.y + scale.y / 2 - thickness / 2;
	s1.x = scale.x - 2 * thickness;
	s1.y = thickness;
	
	p2.x = position.x;
	p2.y = position.y;
	s2.x = scale.x - 2 * thickness;
	s2.y = thickness;

	p3.x = position.x;
	p3.y = position.y - scale.y / 2 + thickness / 2;
	s3.x = scale.x - 2 * thickness;
	s3.y = thickness;

	//Vertical Lines
	p4.x = position.x - scale.x / 2 + thickness / 2;
	p4.y = position.y;
	s4.x = thickness;
	s4.y = scale.y;

	p5.x = position.x + scale.x / 2 - 3 * thickness / 2;
	p5.y = position.y - scale.y / 4;
	s5.x = thickness;
	s5.y = scale.y / 2 - thickness;

	p6.x = position.x + scale.x / 2 - thickness / 2;
	p6.y = position.y + scale.y / 4 - thickness / 4;
	s6.x = thickness;
	s6.y = scale.y / 2 + thickness / 2;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
	qd_drawSolidRect(p4, s4, 0, color);
	qd_drawSolidRect(p5, s5, 0, color);
	qd_drawSolidRect(p6, s6, 0, color);
}

static void tp_drawC(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3;
	vec2 s1, s2, s3;

	p1.x = position.x - scale.x / 2 + thickness / 2;
	p1.y = position.y;
	s1.x = thickness;
	s1.y = scale.y - thickness / 2;

	p2.x = position.x + thickness / 2;
	p2.y = position.y - scale.y / 2 + thickness / 2;
	s2.x = scale.x - thickness;
	s2.y = thickness;

	p3.x = position.x + thickness / 2;
	p3.y = position.y + scale.y / 2 - thickness / 2;
	s3.x = scale.x - thickness;
	s3.y = thickness;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
}

static void tp_drawD(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3, p4;
	vec2 s1, s2, s3, s4;

	p1.x = position.x - scale.x / 2 + thickness / 2;
	p1.y = position.y;
	s1.x = thickness;
	s1.y = scale.y;

	p2.x = position.x + scale.x / 2 - thickness / 2;
	p2.y = position.y;
	s2.x = thickness;
	s2.y = scale.y - 2 * thickness;

	p3.x = position.x;
	p3.y = position.y - scale.y / 2 + thickness / 2;
	s3.x = scale.x - 2 * thickness;
	s3.y = thickness;

	p4.x = position.x;
	p4.y = position.y + scale.y / 2- thickness / 2;
	s4.x = scale.x - 2 * thickness;
	s4.y = thickness;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
	qd_drawSolidRect(p4, s4, 0, color);
}

void tp_drawE(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3, p4;
	vec2 s1, s2, s3, s4;

	p1.x = position.x;
	p1.y = position.y - scale.y / 2 + thickness / 2;
	s1.x = scale.x;
	s1.y = thickness;

	p2.x = position.x;
	p2.y = position.y;
	s2.x = scale.x - 2 * thickness;
	s2.y = thickness;

	p3.x = position.x;
	p3.y = position.y + scale.y / 2 - thickness / 2;
	s3.x = scale.x;
	s3.y = thickness;

	p4.x = position.x - scale.x / 2 + thickness / 2;
	p4.y = position.y;
	s4.x = thickness;
	s4.y = scale.y - 2 * thickness;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
	qd_drawSolidRect(p4, s4, 0, color);
}

static void tp_drawF(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3;
	vec2 s1, s2, s3;

	p1.x = position.x - scale.x / 2 + thickness / 2;
	p1.y = position.y;
	s1.x = thickness;
	s1.y = scale.y;

	p2.x = position.x + thickness / 2;
	p2.y = position.y - scale.y / 2 + thickness / 2;
	s2.x = scale.x - thickness;
	s2.y = thickness;

	p3.x = position.x - 3 * thickness / 2;
	p3.y = position.y - scale.y / 16;
	s3.x = scale.x - 3 * thickness;
	s3.y = thickness;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
}

static void tp_drawG(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3, p4, p5;
	vec2 s1, s2, s3, s4, s5;

	//Horizontal
	p1.x = position.x + thickness / 2;
	p1.y = position.y - scale.y / 2 + thickness / 2;
	s1.x = scale.x - thickness;
	s1.y = thickness;

	p2.x = position.x + scale.x / 4 - thickness / 2;
	p2.y = position.y;
	s2.x = scale.x / 2 + thickness;
	s2.y = thickness;

	p3.x = position.x + thickness / 2;
	p3.y = position.y + scale.y / 2 - thickness / 2;
	s3.x = scale.x - thickness;
	s3.y = thickness;

	//Vertical
	p4.x = position.x - scale.x / 2 + thickness / 2;
	p4.y = position.y;
	s4.x = thickness;
	s4.y = scale.y;

	p5.x = position.x + scale.x / 2 - thickness / 2;
	p5.y = position.y + scale.y / 4;
	s5.x = thickness;
	s5.y = scale.y / 2;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
	qd_drawSolidRect(p4, s4, 0, color);
	qd_drawSolidRect(p5, s5, 0, color);
}

static void tp_drawH(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3;
	vec2 s1, s2, s3;

	p1.x = position.x - scale.x / 2 + thickness / 2;
	p1.y = position.y;
	s1.x = thickness;
	s1.y = scale.y;

	p2.x = position.x + scale.x / 2 - thickness / 2;
	p2.y = position.y;
	s2.x = thickness;
	s2.y = scale.y;

	p3.x = position.x;
	p3.y = position.y;
	s3.x = scale.x - 2 * thickness;
	s3.y = thickness;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
}

static void tp_drawI(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3;
	vec2 s1, s2, s3;

	p1.x = position.x;
	p1.y = position.y - scale.y / 2 + thickness / 2;
	s1.x = scale.x;
	s1.y = thickness;

	p2.x = position.x;
	p2.y = position.y;
	s2.x = thickness;
	s2.y = scale.y - 2 * thickness;

	p3.x = position.x;
	p3.y = position.y + scale.y / 2 - thickness / 2;
	s3.x = scale.x;
	s3.y = thickness;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
}

static void tp_drawJ(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3;
	vec2 s1, s2, s3;

	p1.x = position.x - scale.x / 2 + thickness / 2;
	p1.y = position.y + 3 * scale.y / 8;
	s1.x = thickness;
	s1.y = scale.y / 4;

	p2.x = position.x + scale.x / 2 - thickness / 2;
	p2.y = position.y;
	s2.x = thickness;
	s2.y = scale.y;

	p3.x = position.x;
	p3.y = position.y + scale.y / 2 - thickness / 2;
	s3.x = scale.x - 2 * thickness;
	s3.y = thickness;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
}

static void tp_drawK(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3, p4;
	vec2 s1, s2, s3, s4;

	p1.x = position.x + thickness / 2;
	p1.y = position.y;
	s1.x = scale.x - thickness;
	s1.y = thickness;

	p2.x = position.x - scale.x / 2 + thickness / 2;
	p2.y = position.y;
	s2.x = thickness;
	s2.y = scale.y;

	p3.x = position.x + scale.x / 2 - 2 * thickness;
	p3.y = position.y - scale.y / 4 - thickness / 4;
	s3.x = thickness;
	s3.y = scale.y / 2 - thickness / 2;

	p4.x = position.x + scale.x / 2 - thickness / 2;
	p4.y = position.y + scale.y / 4 + thickness / 4;
	s4.x = thickness;
	s4.y = scale.y / 2 - thickness / 2;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
	qd_drawSolidRect(p4, s4, 0, color);
}

static void tp_drawL(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2;
	vec2 s1, s2;

	p1.x = position.x - scale.x / 2 + thickness / 2;
	p1.y = position.y;
	s1.x = thickness;
	s1.y = scale.y;

	p2.x = position.x + thickness / 2;
	p2.y = position.y + scale.y / 2 - thickness / 2;
	s2.x = scale.x - thickness;
	s2.y = thickness;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
}

static void tp_drawM(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3, p4, p5;
	vec2 s1, s2, s3, s4, s5;

	//Vertical
	p1.x = position.x - scale.x / 2 + thickness / 2;
	p1.y = position.y + thickness / 2;
	s1.x = thickness;
	s1.y = scale.y - thickness / 2;

	p2.x = position.x;
	p2.y = position.y - scale.y / 4 + thickness / 2;
	s2.x = thickness;
	s2.y = scale.y / 2 - thickness;

	p3.x = position.x + scale.x / 2 - thickness / 2;
	p3.y = position.y + thickness / 2;
	s3.x = thickness;
	s3.y = scale.y - thickness;

	//Horizontal
	p4.x = position.x - scale.x / 4 + thickness / 4;
	p4.y = position.y - scale.y / 2 + thickness / 2;
	s4.x = scale.x / 2 - 3 * thickness / 2;
	s4.y = thickness;

	p5.x = position.x + scale.x / 4 - thickness / 4;
	p5.y = position.y - scale.y / 2 + thickness / 2;
	s5.x = scale.x / 2 - 3 * thickness / 2;
	s5.y = thickness;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
	qd_drawSolidRect(p4, s4, 0, color);
	qd_drawSolidRect(p5, s5, 0, color);
}

static void tp_drawN(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3, p4, p5, p6, p7;
	vec2 s1, s2, s3, s4, s5, s6, s7;

	//Vertical
	p1.x = position.x - scale.x / 2 + thickness / 2;
	p1.y = position.y;
	s1.x = thickness;
	s1.y = scale.y;

	p2.x = position.x + scale.x / 2 - thickness / 2;
	p2.y = position.y;
	s2.x = thickness;
	s2.y = scale.y;

	//Horizontal
	p3.x = position.x - 2 * scale.x / 5 + 4 * thickness / 5;
	p3.y = position.y - 5 * thickness / 2;
	s3.x = scale.x / 5 - 2 * thickness / 5;
	s3.y = thickness;

	p4.x = position.x - scale.x / 5 + 2 * thickness / 5;
	p4.y = position.y - 3 * thickness / 2;
	s4.x = scale.x / 5 - 2 * thickness / 5;
	s4.y = thickness;

	p5.x = position.x;
	p5.y = position.y;
	s5.x = scale.x / 5 - 2 * thickness / 5;
	s5.y = thickness;

	p6.x = position.x + scale.x / 5 - 2 * thickness / 5;
	p6.y = position.y + 3 * thickness / 2;
	s6.x = scale.x / 5 - 2 * thickness / 5;
	s6.y = thickness;

	p7.x = position.x + 2 * scale.x / 5 - 4 * thickness / 5;
	p7.y = position.y + 5 * thickness / 2;
	s7.x = scale.x / 5 - 2 * thickness / 5;
	s7.y = thickness;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
	qd_drawSolidRect(p4, s4, 0, color);
	qd_drawSolidRect(p5, s5, 0, color);
	qd_drawSolidRect(p6, s6, 0, color);
	qd_drawSolidRect(p7, s7, 0, color);
}

static void tp_drawO(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3, p4;
	vec2 s1, s2, s3, s4;

	p1.x = position.x;
	p1.y = position.y - scale.y / 2 + thickness / 2;
	s1.x = scale.x - 2 * thickness;
	s1.y = thickness;

	p2.x = position.x;
	p2.y = position.y + scale.y / 2 - thickness / 2;
	s2.x = scale.x - 2 * thickness;
	s2.y = thickness;

	p3.x = position.x - scale.x / 2 + thickness / 2;
	p3.y = position.y;
	s3.x = thickness;
	s3.y = scale.y - 2 * thickness;

	p4.x = position.x + scale.x / 2 - thickness / 2;
	p4.y = position.y;
	s4.x = thickness;
	s4.y = scale.y - 2 * thickness;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
	qd_drawSolidRect(p4, s4, 0, color);
}

static void tp_drawP(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3, p4;
	vec2 s1, s2, s3, s4;

	p1.x = position.x - scale.x / 2 + thickness / 2;
	p1.y = position.y;
	s1.x = thickness;
	s1.y = scale.y;

	p2.x = position.x + thickness / 2;
	p2.y = position.y - scale.y / 2 + thickness / 2;
	s2.x = scale.x - thickness;
	s2.y = thickness;

	p3.x = position.x + thickness / 2;
	p3.y = position.y - scale.y / 8;
	s3.x = scale.x - thickness;
	s3.y = thickness;

	p4.x = position.x + scale.x / 2 - thickness / 2;
	p4.y = position.y - 5 * scale.y / 16 + thickness / 4;
	s4.x = thickness;
	s4.y = 3 * scale.y / 8 - 3 * thickness / 2;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
	qd_drawSolidRect(p4, s4, 0, color);
}

static void tp_drawQ(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3, p4, p5;
	vec2 s1, s2, s3, s4, s5;

	//Horizontal
	p1.x = position.x;
	p1.y = position.y - scale.y / 2 + thickness / 2;
	s1.x = scale.x - 2 * thickness;
	s1.y = thickness;

	p2.x = position.x;
	p2.y = position.y + scale.y / 2 - 3 * thickness / 2;
	s2.x = scale.x - 2 * thickness;
	s2.y = thickness;

	//Vertical
	p3.x = position.x - scale.x / 2 + thickness / 2;
	p3.y = position.y - thickness / 2;
	s3.x = thickness;
	s3.y = scale.y - 3 * thickness;

	p4.x = position.x + scale.x / 2 - thickness / 2;
	p4.y = position.y - thickness / 2;
	s4.x = thickness;
	s4.y = scale.y - 3 * thickness;

	//Dot
	p5.x = position.x + scale.x / 2 - thickness / 2;
	p5.y = position.y + scale.y / 2 - thickness / 2;
	s5.x = thickness;
	s5.y = thickness;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
	qd_drawSolidRect(p4, s4, 0, color);
	qd_drawSolidRect(p5, s5, 0, color);
}

static void tp_drawR(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3, p4, p5;
	vec2 s1, s2, s3, s4, s5;

	p1.x = position.x - scale.x / 2 + thickness / 2;
	p1.y = position.y;
	s1.x = thickness;
	s1.y = scale.y;

	p2.x = position.x;
	p2.y = position.y - scale.y / 2 + thickness / 2;
	s2.x = scale.x - 2 * thickness;
	s2.y = thickness;

	p3.x = position.x;
	p3.y = position.y - scale.y / 8;
	s3.x = scale.x - 2 * thickness;
	s3.y = thickness;

	p4.x = position.x + scale.x / 2 - thickness / 2;
	p4.y = position.y - 5 * scale.y / 16 + thickness / 4;
	s4.x = thickness;
	s4.y = 3 * scale.y / 8 - 3 * thickness / 2;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
	qd_drawSolidRect(p4, s4, 0, color);
}

static void tp_drawS(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3, p4, p5;
	vec2 s1, s2, s3, s4, s5;

	//Horizontal
	p1.x = position.x;
	p1.y = position.y - scale.y / 2 + thickness / 2;
	s1.x = scale.x;
	s1.y = thickness;

	p2.x = position.x;
	p2.y = position.y;
	s2.x = scale.x;
	s2.y = thickness;

	p3.x = position.x;
	p3.y = position.y + scale.y / 2 - thickness / 2;
	s3.x = scale.x;
	s3.y = thickness;

	//Vertical
	p4.x = position.x + scale.x / 2 - thickness / 2;
	p4.y = position.y + scale.y / 4 - thickness / 4;
	s4.x = thickness;
	s4.y = scale.y / 2 + thickness / 2;

	p5.x = position.x - scale.x / 2 + thickness / 2;
	p5.y = position.y  - scale.y / 4 + thickness / 4;
	s5.x = thickness;
	s5.y = scale.y / 2 - thickness / 2;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
	qd_drawSolidRect(p4, s4, 0, color);
	qd_drawSolidRect(p5, s5, 0, color);
}

static void tp_drawT(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2;
	vec2 s1, s2;

	p1.x = position.x;
	p1.y = position.y + thickness / 2;
	s1.x = thickness;
	s1.y = scale.y - thickness;

	p2.x = position.x;
	p2.y = position.y - scale.y / 2 + thickness / 2;
	s2.x = scale.x;
	s2.y = thickness;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
}

static void tp_drawU(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {
	vec2 p1, p2, p3;
	vec2 s1, s2, s3;

	p1.x = position.x;
	p1.y = position.y + scale.y / 2 - thickness / 2;
	s1.x = scale.x - 2 * thickness;
	s1.y = thickness;

	p2.x = position.x - scale.x / 2 + thickness / 2;
	p2.y = position.y;
	s2.x = thickness;
	s2.y = scale.y;

	p3.x = position.x + scale.x / 2 - thickness / 2;
	p3.y = position.y;
	s3.x = thickness;
	s3.y = scale.y;

	qd_drawSolidRect(p1, s1, 0, color);
	qd_drawSolidRect(p2, s2, 0, color);
	qd_drawSolidRect(p3, s3, 0, color);
}

static void tp_drawV(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {

}

static void tp_drawW(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {

}

static void tp_drawX(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {

}

static void tp_drawY(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {

}

static void tp_drawZ(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {

}

static void tp_draw0(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {

}

static void tp_draw1(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {

}

static void tp_draw2(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {

}

static void tp_draw3(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {

}

static void tp_draw4(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {

}

static void tp_draw5(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {

}

static void tp_draw6(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {

}

static void tp_draw7(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {

}

static void tp_draw8(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {

}

static void tp_draw9(vec2 position, vec2 scale, unsigned int thickness, vec3 color) {

}