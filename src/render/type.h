#ifndef _TYPE_H_
#define _TYPE_H_

#include "../math/vec2.h"
#include "../math/vec3.h"

#include "quad.h"

#define TP_NULL '\0'
#define TP_NEWLINE '\n'
#define TP_SPACE ' '

#define TP_ALIGNMENT_LEFT 0
#define TP_ALIGNMENT_CENTER 1
#define TP_ALIGNMENT_RIGHT 2

void tp_drawString(vec2 position, vec2 char_scale, vec3 color, unsigned int thickness, unsigned int char_spacing, unsigned int line_spacing, unsigned char alignment, const char* string);

void tp_drawChar(vec2 position, vec2 scale, vec3 color, unsigned int thickness, char character);

static void tp_drawA(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawB(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawC(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawD(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawE(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawF(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawG(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawH(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawI(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawJ(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawK(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawL(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawM(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawN(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawO(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawP(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawQ(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawR(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawS(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawT(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawU(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawV(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawW(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawX(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawY(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_drawZ(vec2 position, vec2 scale, unsigned int thickness, vec3 color);

static void tp_draw0(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_draw1(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_draw2(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_draw3(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_draw4(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_draw5(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_draw6(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_draw7(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_draw8(vec2 position, vec2 scale, unsigned int thickness, vec3 color);
static void tp_draw9(vec2 position, vec2 scale, unsigned int thickness, vec3 color);

#endif