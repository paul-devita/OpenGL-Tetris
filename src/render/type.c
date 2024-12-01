#include "type.h"

void tp_drawString(vec2 position, vec2 char_scale, vec3 color, float thickness, float char_spacing, float line_spacing, TPAlignment alignment, const char* string) {
	if (*string == TP_NULL) return;

	vec2 p;

	unsigned int numLines = 1;

	float dx = char_scale.x + char_spacing;
	float dy = char_scale.y + line_spacing;

	char* cur = (char*)string;

	for (char* c = (char*)string; *c != TP_NULL; c++)
		if (*c == TP_NEWLINE)
			numLines++;

	switch (alignment) {
		case TP_ALIGNMENT_LEFT: {
			float default_x = position.x + char_scale.x / (float)2;

			p.x = default_x;
			
			if (numLines > 1) {
				if (numLines % 2 != 0) {
					unsigned int nLd2 = numLines / 2;

					p.y = position.y - nLd2 * dy;
				}
				else {
					unsigned int nLd2m1 = (numLines / 2) - 1;

					p.y = position.y - ((char_scale.y - line_spacing) / (float)2) - nLd2m1 * dy;
				}

				for (unsigned int i = 0; i < numLines; i++) {
					for (; *cur != TP_NEWLINE && *cur != TP_NULL; cur++) {
						switch (*cur) {
							case TP_SPACE:
								//Do Nothing
								break;
							default:
								tp_drawChar(p, char_scale, color, thickness, *cur);
								break;
						}

						p.x += dx;
					}

					p.x = default_x;
					p.y += dy;

					cur++;
				}
			}
			else {
				p.y = position.y;

				for (; *cur != TP_NULL; cur++) {
					switch (*cur) {
						case TP_SPACE:
							//Do Nothing
							break;
						default:
							tp_drawChar(p, char_scale, color, thickness, *cur);
							break;
					}

					p.x += dx;
				}
			}
			break;
		}
		case TP_ALIGNMENT_CENTER: {
			if (numLines > 1) {
				if (numLines % 2 != 0) {
					unsigned int nLd2 = numLines / 2;

					p.y = position.y - nLd2 * dy;
				}
				else {
					unsigned int nLd2m1 = (numLines / 2) - 1;

					p.y = position.y - ((char_scale.y - line_spacing) / (float)2) - nLd2m1 * dy;
				}

				for (unsigned int i = 0; i < numLines; i++) {
					unsigned int strLen = 0;

					for (char* c = cur; *c != TP_NULL && *c != TP_NEWLINE; c++)
						strLen++;

					if (strLen % 2 != 0) {
						unsigned int sLd2 = strLen / 2;

						p.x = position.x - sLd2 * (char_scale.x + char_spacing);
					}
					else
					{
						unsigned int sLd2m1 = (strLen / 2) - 1;

						p.x = position.x - char_scale.x / (float)2 - line_spacing / (float)2 - sLd2m1 * (char_scale.x + char_spacing);
					}

					for (; *cur != TP_NEWLINE && *cur != TP_NULL; cur++) {
						switch (*cur) {
							case TP_SPACE:
								//Do Nothing
								break;
							default:
								tp_drawChar(p, char_scale, color, thickness, *cur);
								break;
						}

						p.x += dx;
					}

					p.y += dy;
					cur++;
				}
			}
			else {
				unsigned int strLen = 0;

				for (char* c = (char*)string; *c != TP_NULL; c++)
					strLen++;

				if (strLen % 2 != 0) {
					//farts

					p.x = position.x - ((strLen / 2) * (char_scale.x + char_spacing));
					p.y = position.y;
				}
				else
				{
					p.x = position.x - (char_spacing / (float)2) - (char_scale.x / (float)2) - (((strLen / 2) - 1) * (char_scale.x + char_spacing));
					p.y = position.y;
				}
				
				for ( ; *cur != TP_NULL; cur++) {
					switch (*cur) {
						case TP_SPACE: 
							//Do Nothing
							break;
						default:
							tp_drawChar(p, char_scale, color, thickness, *cur);
							break;
					}

					p.x += dx;
				}
			}

			break;
		}
		case TP_ALIGNMENT_RIGHT: {
			float default_x = position.x - char_scale.x / (float)2;

			if (numLines > 1) {
				if (numLines % 2 != 0) {
					unsigned int nLd2 = numLines / 2;

					p.y = position.y - nLd2 * dy;
				}
				else {
					unsigned int nLd2m1 = (numLines / 2) - 1;

					p.y = position.y - ((char_scale.y - line_spacing) / (float)2) - nLd2m1 * dy;
				}

				for (unsigned int i = 0; i < numLines; i++) {
					unsigned int strLen = 0;

					for (char* c = cur; *c != TP_NEWLINE && *c != TP_NULL; c++)
						strLen++;

					p.x = default_x - ((strLen - 1) * dx);

					for (; *cur != TP_NEWLINE && *cur != TP_NULL; cur++) {
						switch (*cur) {
							case TP_SPACE:
								//Do Nothing
								break;
							default:
								tp_drawChar(p, char_scale, color, thickness, *cur);
								break;
						}

						p.x += dx;
					}

					p.y += dy;

					cur++;
				}
			}
			else {
				unsigned int strLen = 0;

				for (char* c = (char*)string; *c != TP_NULL; c++)
					strLen++;

				p.x = default_x - (strLen - 1) * dx;
				p.y = position.y;

				for (; *cur != TP_NULL; cur++) {
					switch (*cur) {
						case TP_SPACE:
							//Do Nothing
							break;
						default:
							tp_drawChar(p, char_scale, color, thickness, *cur);
							break;
					}

					p.x += dx;
				}
			}

			break;
		}
	}
}

void tp_drawChar(vec2 position, vec2 scale, vec3 color, float thickness, char character) {

	if (character >= 'A' && character <= 'Z')
		character += 32;

	switch (character) {
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
		case '0':
			tp_draw0(position, scale, thickness, color);
			break;
		case '1':
			tp_draw1(position, scale, thickness, color);
			break;
		case '2':
			tp_draw2(position, scale, thickness, color);
			break;
		case '3':
			tp_draw3(position, scale, thickness, color);
			break;
		case '4':
			tp_draw4(position, scale, thickness, color);
			break;
		case '5':
			tp_draw5(position, scale, thickness, color);
			break;
		case '6':
			tp_draw6(position, scale, thickness, color);
			break;
		case '7':
			tp_draw7(position, scale, thickness, color);
			break;
		case '8':
			tp_draw8(position, scale, thickness, color);
			break;
		case '9':
			tp_draw9(position, scale, thickness, color);
			break;
	}
}

static void tp_drawA(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float tm2 = 2 * thickness;

	float dx = scale.x / (float)2 - td2;

	p.x = position.x;
	p.y = position.y - td2;
	s.x = scale.x - tm2;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y - scale.y / (float)2 + td2;
	s.x = scale.x - tm2;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x - dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawB(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float tm2 = thickness * 2;

	float sxd2 = scale.x / (float)2;
	float syd2 = scale.y / (float)2;
	float syd4 = scale.y / (float)4;

	float dy = syd2 - td2;

	//Horizontal Lines
	p.x = position.x;
	p.y = position.y + dy;
	s.x = scale.x - tm2;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);
	
	p.x = position.x;
	p.y = position.y;
	s.x = scale.x - tm2;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y - dy;
	s.x = scale.x - tm2;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	//Vertical Lines
	p.x = position.x - sxd2 + td2;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + sxd2 - (float)3 * td2;
	p.y = position.y - syd4;
	s.x = thickness;
	s.y = syd2 - thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + sxd2 - td2;
	p.y = position.y + syd4 - thickness / (float)4;
	s.x = thickness;
	s.y = syd2 + td2;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawC(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float dy = scale.y / (float)2 - thickness / (float)2;

	p.x = position.x - scale.x / (float)2 + td2;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + td2;
	p.y = position.y - dy;
	s.x = scale.x - thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + td2;
	p.y = position.y + dy;
	s.x = scale.x - thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawD(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float tm2 = thickness * 2;

	float dx = scale.x / (float)2 - td2;
	float dy = scale.y / (float)2 - td2;

	p.x = position.x - dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y - tm2;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y - dy;
	s.x = scale.x - tm2;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y + dy;
	s.x = scale.x - tm2;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);
}

void tp_drawE(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float sxd2 = scale.x / (float)2;

	float dy = scale.y / (float)2 - td2;

	p.x = position.x;
	p.y = position.y - dy;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x - scale.x / (float)4 + td2;
	p.y = position.y;
	s.x = sxd2 + thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y + dy;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x - sxd2 + td2;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y - (float)2 * thickness;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawF(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float sxd2 = scale.x / (float)2;

	p.x = position.x - sxd2 + td2;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + td2;
	p.y = position.y - scale.y / (float)2 + td2;
	s.x = scale.x - thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x - scale.x / (float)4 + td2;
	p.y = position.y - scale.y / (float)16;
	s.x = sxd2 + thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawG(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float sxd2 = scale.x / (float)2;
	float syd2 = scale.y / (float)2;

	float dx = sxd2 - td2;

	float dy = syd2 - td2;

	//Horizontal
	p.x = position.x + td2;
	p.y = position.y - dy;
	s.x = scale.x - thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x -= td2;
	p.y = position.y + dy;
	s.x -= thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + scale.x / (float)4;
	p.y = position.y + td2;
	s.x = scale.x / (float)2;
	qd_drawSolidRect(p, s, 0, color);

	//Vertical
	p.x = position.x - dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y + scale.y / (float)4 + thickness / (float)2;
	s.y = scale.y / (float)2 - thickness;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawH(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float dx = scale.x / (float)2 - thickness / (float)2;

	p.x = position.x - dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	s.x = scale.x - 2 * thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawI(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float dy = scale.y / (float)2 - thickness / (float)2;

	p.x = position.x;
	p.y = position.y - dy;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y - 2 * thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y + dy;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawJ(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float dx = scale.x / (float)2 - td2;

	p.x = position.x - dx;
	p.y = position.y + 3 * scale.y / (float)8;
	s.x = thickness;
	s.y = scale.y / (float)4;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y + scale.y / (float)2 - td2;
	s.x = scale.x - 2 * thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawK(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float sxd2 = scale.x / (float)2;

	float sy = scale.y / (float)2 - td2;

	float dx = sxd2 - td2;
	float dy = scale.y / (float)2 + thickness / (float)4;

	p.x = position.x + td2;
	p.y = position.y;
	s.x = scale.x - thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x - dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + sxd2 - 2 * thickness;
	p.y = position.y - dy;
	s.x = thickness;
	s.y = sy;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y + dy;
	s.x = thickness;
	s.y = sy;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawL(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	p.x = position.x - scale.x / (float)2 + td2;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + td2;
	p.y = position.y + scale.y / (float)2 - td2;
	s.x = scale.x - thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawM(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float sxd2 = scale.x / (float)2;

	float syd2 = scale.y / (float)2;

	float dx1 = sxd2 - td2;
	float dx2 = scale.x / (float)4 - thickness / (float)4;

	//Vertical
	p.x = position.x;
	p.y = position.y - scale.y / (float)4;
	s.x = thickness;
	s.y = syd2;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx1;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x - dx1;
	qd_drawSolidRect(p, s, 0, color);

	//Horizontal
	p.x = position.x + dx2;
	p.y = position.y - syd2 + td2;
	s.x = sxd2 - 3 * td2;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x - dx2;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawN(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float dx = scale.x / (float)2 - td2;

	p.x = position.x - dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	unsigned int numLines = (unsigned int)((scale.x - 2 * thickness) / thickness);
	unsigned int nLd2 = numLines / 2;

	float sy = scale.y / (float)numLines;

	float dy;

	s.x = thickness;
	s.y = sy;

	if (numLines % 2 != 0) {
		p.x = position.x;
		p.y = position.y;

		qd_drawSolidRect(p, s, 0, color);

		dx = thickness;
		dy = sy;
	}
	else {
		dx = td2;
		dy = sy / (float)2;
	}

	for (unsigned int i = 0; i < nLd2; i++) {
		p.x = position.x - dx;
		p.y = position.y - dy;

		qd_drawSolidRect(p, s, 0, color);

		p.x = position.x + dx;
		p.y = position.y + dy;

		qd_drawSolidRect(p, s, 0, color);

		dx += thickness;
		dy += sy;
	}
}

static void tp_drawO(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float tm2 = thickness * 2;

	float dx = scale.x / (float)2 - td2;
	float dy = scale.y / (float)2 - td2;

	p.x = position.x;
	p.y = position.y - dy;
	s.x = scale.x - tm2;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y + dy;
	s.x = scale.x - tm2;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x - dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y - tm2;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y - tm2;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawP(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float dx = scale.x / (float)2 - td2;

	float syd8 = scale.y / (float)8;

	p.x = position.x - dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + td2;
	p.y = position.y - scale.y / (float)2 + td2;
	s.x = scale.x - thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + td2;
	p.y = position.y - syd8;
	s.x = scale.x - thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y - (float)5 * scale.y / (float)16 + thickness / (float)4;
	s.x = thickness;
	s.y = 3 * (syd8 - td2);
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawQ(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float tm2 = thickness * 2;
	float tm3 = thickness * 3;

	float syd2 = scale.y / (float)2;

	float dx = scale.x / (float)2 - td2;
	float dy = syd2 - td2;

	//Horizontal
	p.x = position.x;
	p.y = position.y - dy;
	s.x = scale.x - tm2;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y + syd2 - 3 * td2;
	s.x = scale.x - tm2;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	//Vertical
	p.x = position.x - dx;
	p.y = position.y - td2;
	s.x = thickness;
	s.y = scale.y - tm3;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y - td2;
	s.x = thickness;
	s.y = scale.y - tm3;
	qd_drawSolidRect(p, s, 0, color);

	//Dot
	p.x = position.x + dx;
	p.y = position.y + dy;
	s.x = thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawR(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;
	float td8 = thickness / (float)8;

	float sxd2 = scale.x / (float)2;
	float syd8 = scale.y / (float)8;
	float syd32 = scale.y / (float)32;

	float sy = 5 * scale.y / (float)16 - thickness / (float)4;

	float dx = sxd2 - td2;

	//Vertical
	p.x = position.x - dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y - sy;
	s.x = thickness;
	s.y = 3 * syd8 - 3 * td2;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + sxd2 - 3 * td2;
	p.y = position.y + syd32 + 3 * td8;
	s.x = thickness;
	s.y = sy;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y + (float)11 * syd32 + td8;
	s.x = thickness;
	s.y = sy;
	qd_drawSolidRect(p, s, 0, color);

	//Horizontal
	p.x = position.x + td2;
	p.y = position.y - scale.y / (float)2 + td2;
	s.x = scale.x - thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + td2;
	p.y = position.y - syd8;
	s.x = scale.x - thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawS(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float syd2 = scale.y / (float)2;

	float dx = scale.x / (float)2 - td2;
	float dy1 = syd2 - td2;
	float dy2 = scale.y / (float)4 - thickness / (float)4;

	//Horizontal
	p.x = position.x;
	p.y = position.y - dy1;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y + dy1;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	//Vertical
	p.x = position.x + dx;
	p.y = position.y + dy2;
	s.x = thickness;
	s.y = syd2 + td2;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x - dx;
	p.y = position.y - dy2;
	s.x = thickness;
	s.y = dy1;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawT(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	p.x = position.x;
	p.y = position.y + td2;
	s.x = thickness;
	s.y = scale.y - thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y - scale.y / (float)2 + td2;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawU(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float dx = scale.x / (float)2 - td2;

	p.x = position.x;
	p.y = position.y + scale.y / (float)2 - td2;
	s.x = scale.x - 2 * thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x - dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawV(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float syd2 = scale.y / (float)2;

	p.x = position.x;
	p.y = position.y + syd2 - td2;
	s.x = thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	unsigned int numLines = (unsigned int)((scale.x / (float)2 - td2) / thickness);

	float length = (scale.y - thickness) / (float)numLines;

	float px = 0;
	float py = 0;

	s.x = thickness;
	s.y = length;

	for (unsigned int i = 0; i < numLines; i++) {
		p.x = px + position.x + thickness;
		p.y = py + position.y + syd2 - thickness - length / (float)2;

		px += thickness;
		py -= length;

		qd_drawSolidRect(p, s, 0, color);

		p.x -= 2 * (i + 1) * thickness;

		qd_drawSolidRect(p, s, 0, color);
	}
}

static void tp_drawW(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float sxd2 = scale.x / (float)2;
	float syd2 = scale.y / (float)2;

	float sx = sxd2 - td2 * 3;

	float dx1 = sxd2 - td2;
	float dx2 = scale.x / (float)4 - thickness / (float)4;
	float dy = syd2 - td2;

	//Horizontal
	p.x = position.x - dx1;
	p.y = position.y - td2;
	s.x = thickness; 
	s.y = scale.y - thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx1;
	p.y = position.y - td2;
	s.x = thickness;
	s.y = scale.y - thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y + scale.y / (float)4 - td2;
	s.x = thickness;
	s.y = syd2 - thickness;
	qd_drawSolidRect(p, s, 0, color);

	//Vertical
	p.x = position.x - dx2;
	p.y = position.y + dy;
	s.x = sx;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx2;
	p.y = position.y + dy;
	s.x = sx;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_drawX(vec2 position, vec2 scale, float thickness, vec3 color) {
	float td2 = thickness / (float)2;

	float sxd2 = scale.x / (float)2;

	unsigned int numLines = (unsigned int)((sxd2 - td2) / thickness);
	float rx = sxd2 - numLines * thickness;

	float sy = (scale.y / (float)2 - td2) / (float)numLines;

	vec2 p, s;

	p.x = position.x;
	p.y = position.y;
	s.x = thickness + rx;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	float dx = thickness + rx / (float)2;
	float dy = td2 + sy / (float)2;

	s.x = thickness;
	s.y = sy;

	for (unsigned int i = 0; i < numLines; i++) {
		p.x = position.x + dx;
		p.y = position.y - dy;

		qd_drawSolidRect(p, s, 0, color);

		p.x = position.x - dx;

		qd_drawSolidRect(p, s, 0, color);

		p.y = position.y + dy;

		qd_drawSolidRect(p, s, 0, color);

		p.x = position.x + dx;

		qd_drawSolidRect(p, s, 0, color);

		dx += thickness;
		dy += sy;
	}
}

static void tp_drawY(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	p.x = position.x;
	p.y = position.y + scale.y / (float)4;
	s.x = thickness;
	s.y = scale.y / (float)2;
	qd_drawSolidRect(p, s, 0, color);

	unsigned int numLines = (unsigned int)((scale.x / (float)2 - thickness / (float)2) / thickness);

	float sy = (scale.y / (float)2) / (float)thickness;

	float dx = thickness;
	float dy = sy / (float)2;

	s.x = thickness;
	s.y = sy;

	for (unsigned int i = 0; i < numLines; i++) {
		p.x = position.x + dx;
		p.y = position.y - dy;

		qd_drawSolidRect(p, s, 0, color);

		p.x = position.x - dx;

		qd_drawSolidRect(p, s, 0, color);

		dx += thickness;
		dy += sy;
	}
}

static void tp_drawZ(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float dy = scale.y / (float)2 - td2;

	p.x = position.x;
	p.y = position.y - dy;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y + dy;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	unsigned int numLines = (unsigned int)((scale.x / (float)2 - td2) / thickness);

	float sy = (scale.y - 2 * thickness) / (float)(2 * numLines);

	float dx;

	s.x = thickness;
	s.y = sy;

	if (numLines % 2 != 0) {
		p.x = position.x;
		p.y = position.y;

		qd_drawSolidRect(p, s, 0, color);

		dx = thickness;
		dy = sy;
	}
	else {
		dx = td2;
		dy = sy / (float)2;
	}

	for (unsigned int i = 0; i < numLines; i++) {

		p.x = position.x + dx;
		p.y = position.y - dy;

		qd_drawSolidRect(p, s, 0, color);

		p.x = position.x - dx;
		p.y = position.y + dy;

		qd_drawSolidRect(p, s, 0, color);

		dx += thickness;
		dy += sy;
	}
}

static void tp_draw0(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float tm2 = thickness * 2;

	float dx = scale.x / (float)2 - td2;
	float dy = scale.y / (float)2 - td2;

	//Horizontal
	p.x = position.x;
	p.y = position.y - dy;
	s.x = scale.x - tm2;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y + dy;
	s.x = scale.x - tm2;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	//Vertical
	p.x = position.x - dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y - tm2;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y - tm2;
	qd_drawSolidRect(p, s, 0, color);

	//Dot
	p.x = position.x;
	p.y = position.y;
	s.x = scale.x / (float)5;
	s.y = scale.y / (float)5;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_draw1(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float syd2 = scale.y / (float)2;

	//Horizontal
	p.x = position.x;
	p.y = position.y + syd2 - td2;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x - td2 - scale.x / (float)16;
	p.y = position.y - syd2 + 3 * td2;
	s.x = scale.x / (float)8;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	//Vertical
	p.x = position.x;
	p.y = position.y - td2;
	s.x = thickness;
	s.y = scale.y - thickness;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_draw2(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float syd2 = scale.y / (float)2;

	float dx = scale.x / (float)2 - td2;
	float dy1 = syd2 - td2;
	float dy2 = scale.y / (float)4 - thickness / (float)4;

	//Horizontal
	p.x = position.x;
	p.y = position.y - dy1;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y + dy1;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	//Vertical
	p.x = position.x - dx;
	p.y = position.y + dy2;
	s.x = thickness;
	s.y = syd2 + td2;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y - dy2;
	s.x = thickness;
	s.y = dy1;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_draw3(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float dy = scale.y / (float)2 - td2;

	//Horizontal
	p.x = position.x;
	p.y = position.y - dy;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x - td2;
	p.y = position.y;
	s.x = scale.x - thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y + dy;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	//Vertical
	p.x = position.x + scale.x / (float)2 - td2;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y - 2 * thickness;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_draw4(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float dx = scale.x / (float)2 - td2;

	//Horizontal
	p.x = position.x - td2;
	p.y = position.y;
	s.x = scale.x - thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	//Vertical
	p.x = position.x - dx;
	p.y = position.y - scale.y / (float)4 + thickness / (float)4;
	s.x = thickness;
	s.y = scale.y / (float)2 - td2;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_draw5(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float syd4 = scale.y / (float)4;
	float syd8 = scale.y / (float)8;

	float dy = scale.y / (float)2 - td2;
	float dx = scale.x / (float)2 - td2;

	//Horizontal
	p.x = position.x;
	p.y = position.y - dy;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y - syd4 + td2;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x;
	p.y = position.y + dy;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	//Vertical
	p.x = position.x - dx;
	p.y = position.y - 3 * syd8 + td2;
	s.x = thickness;
	s.y = syd4 - thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y + syd8;
	s.x = thickness;
	s.y = 3 * syd4 - 2 * thickness;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_draw6(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float syd2 = scale.y / (float)2;
	float syd4 = scale.y / (float)4;

	float dy = syd2 - td2;
	float dx = scale.x / (float)2 - td2;

	//Horizontal
	p.x = position.x;
	p.y = position.y - dy;
	s.x = scale.x;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.y = position.y;
	qd_drawSolidRect(p, s, 0, color);

	p.y = position.y + dy;
	qd_drawSolidRect(p, s, 0, color);

	//Vertical
	p.x = position.x - dx;
	p.y = position.y - syd4;
	s.x = thickness;
	s.y = syd2 - thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.y = position.y + syd4;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_draw7(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float dx = scale.x / (float)2 - td2;

	p.x = position.x;
	p.y = position.y - scale.y / (float)2 + td2;
	s.x = scale.x - 2 * thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x - dx;
	p.y = position.y - 3 * scale.y / (float)8;
	s.x = thickness;
	s.y = scale.y / (float)4;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_draw8(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float syd2 = scale.y / (float)2;

	float dx = scale.x / (float)2 - td2;
	float dy1 = syd2 - td2;
	float dy2 = scale.y / (float)4 - td2;

	//Horizontal
	p.x = position.x;
	p.y = position.y - dy1;
	s.x = scale.x - 2 * thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.y = position.y;
	qd_drawSolidRect(p, s, 0, color);

	p.y = position.y + dy1;
	qd_drawSolidRect(p, s, 0, color);

	//Vertical
	p.x = position.x - dx;
	p.y = position.y - dy2;
	s.x = thickness;
	s.y = syd2 - 3 * td2;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y - dy2;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x - dx;
	p.y = position.y + dy2;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x + dx;
	p.y = position.y + dy2;
	qd_drawSolidRect(p, s, 0, color);
}

static void tp_draw9(vec2 position, vec2 scale, float thickness, vec3 color) {
	vec2 p, s;

	float td2 = thickness / (float)2;

	float dx = scale.x / (float)2 - td2;

	float syd8 = scale.y / (float)8;

	//Vertical
	p.x = position.x + dx;
	p.y = position.y;
	s.x = thickness;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x - dx;
	p.y = position.y - (float)5 * scale.y / (float)16 + thickness / (float)4;
	s.x = thickness;
	s.y = 3 * (syd8 - td2);
	qd_drawSolidRect(p, s, 0, color);

	//Horizontal
	p.x = position.x - td2;
	p.y = position.y - scale.y / (float)2 + td2;
	s.x = scale.x - thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);

	p.x = position.x - td2;
	p.y = position.y - syd8;
	s.x = scale.x - thickness;
	s.y = thickness;
	qd_drawSolidRect(p, s, 0, color);
}