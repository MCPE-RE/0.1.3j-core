#include "TouchscreenInput_TestFps.h"
#include "../../Minecraft.h"
#include "../renderer/Tesselator.h"
#include "../renderer/Textures.h"
#include "../gui/Gui.h"

TouchscreenInput_TestFps::TouchscreenInput_TestFps(Minecraft *minecraft, Options *options) :
    rectangleArea(0.0f, 0.0f, 1.0f, 1.0f) {
    this->options = options;
    this->uunknown1 = 0;
    this->uunknown2 = 0;
    this->minecraft = minecraft;
    this->button2PolygonArea = nullptr;
    this->button3PolygonArea = nullptr;
    this->button0PolygonArea = nullptr;
    this->button1PolygonArea = nullptr;
    this->button4PolygonArea = nullptr;
    for (int i = 0; i < 10; ++i) {
        this->uunknown0[i] = 0;
    }
    for (int i = 0; i < 8; ++i) {
        this->buttonStates[i] = 0;
    }
    this->setScreenSize(minecraft->width, minecraft->height);
}

RectangleArea TouchscreenInput_TestFps::getRectangleArea() {
    return this->rectangleArea;
}

bool TouchscreenInput_TestFps::isButtonDown(int32_t button) {
    return (char *)&this->y + 8 + button;
}

void TouchscreenInput_TestFps::releaseAllKeys() {
    this->x = 0;
    this->y = 0;
    for (int i = 0; i < 5; ++i) {
        this->buttonStates[i] = 0;
    }
}

/*
void __fastcall TouchscreenInput_TestFps::render(TouchscreenInput_TestFps *this, float a2)
{
  Textures *v2; // r5
  float v3; // [sp+0h] [bp-48h]
  int v4; // [sp+0h] [bp-48h]
  int v5; // [sp+0h] [bp-48h]
  int v6; // [sp+0h] [bp-48h]
  int v7; // [sp+0h] [bp-48h]
  TouchscreenInput_TestFps *v8; // [sp+4h] [bp-44h]
  char v9; // [sp+18h] [bp-30h]
  char v10; // [sp+1Ch] [bp-2Ch]

  v8 = this;
  v3 = a2;
  glDisable(0xB44u);
  glEnable(0xBE2u);
  glBlendFunc(0x302u, 0x303u);
  v2 = *(Textures **)(*((_DWORD *)v8 + 21) + 684);
  std::allocator<char>::allocator(&v9);
  std::string::string(&v10, "gui/gui.png", &v9);
  Textures::loadAndBindTexture(v2, (const std::string *)&v10);
  std::string::~string((std::string *)&v10);
  std::allocator<char>::~allocator(&v9);
  Tesselator::begin((Tesselator *)&Tesselator::instance);
  if ( TouchscreenInput_TestFps::isButtonDown(v8, 102) )
    Tesselator::color((Tesselator *)&Tesselator::instance, 12632256, 128);
  else
    Tesselator::color((Tesselator *)&Tesselator::instance, 0xFFFFFF, 128);
  sub_E35B8(&Tesselator::instance, *((_DWORD *)v8 + 22), 64, 112, LODWORD(v3));
  if ( TouchscreenInput_TestFps::isButtonDown(v8, 103) )
    Tesselator::color((Tesselator *)&Tesselator::instance, 12632256, 128);
  else
    Tesselator::color((Tesselator *)&Tesselator::instance, 0xFFFFFF, 128);
  sub_E35B8(&Tesselator::instance, *((_DWORD *)v8 + 23), 192, 112, v4);
  if ( TouchscreenInput_TestFps::isButtonDown(v8, 100) )
    Tesselator::color((Tesselator *)&Tesselator::instance, 12632256, 128);
  else
    Tesselator::color((Tesselator *)&Tesselator::instance, 0xFFFFFF, 128);
  sub_E35B8(&Tesselator::instance, *((_DWORD *)v8 + 24), 0, 112, v5);
  if ( TouchscreenInput_TestFps::isButtonDown(v8, 101) )
    Tesselator::color((Tesselator *)&Tesselator::instance, 12632256, 128);
  else
    Tesselator::color((Tesselator *)&Tesselator::instance, 0xFFFFFF, 128);
  sub_E35B8(&Tesselator::instance, *((_DWORD *)v8 + 25), 128, 112, v6);
  if ( TouchscreenInput_TestFps::isButtonDown(v8, 104) )
    Tesselator::color((Tesselator *)&Tesselator::instance, 12632256, 128);
  else
    Tesselator::color((Tesselator *)&Tesselator::instance, 0xFFFFFF, 128);
  sub_E35B8(&Tesselator::instance, *((_DWORD *)v8 + 26), 0, 176, v7);
  Tesselator::draw((Tesselator *)&Tesselator::instance);
  glDisable(0xBE2u);
  glEnable(0xB44u);
}
*/

/*

Tesselator *__fastcall sub_E35B8(Tesselator *result, _DWORD *a2, signed int a3, signed int a4)
{
  _DWORD *v4; // [sp+10h] [bp-48h]
  Tesselator *v5; // [sp+14h] [bp-44h]
  float v6; // [sp+18h] [bp-40h]
  float v7; // [sp+1Ch] [bp-3Ch]
  float v8; // [sp+20h] [bp-38h]
  float v9; // [sp+24h] [bp-34h]
  float v10; // [sp+28h] [bp-30h]
  float v11; // [sp+2Ch] [bp-2Ch]
  float v12; // [sp+30h] [bp-28h]
  float v13; // [sp+34h] [bp-24h]
  int i; // [sp+38h] [bp-20h]
  int v15; // [sp+3Ch] [bp-1Ch]
  float v16; // [sp+40h] [bp-18h]
  float v17; // [sp+44h] [bp-14h]
  float v18; // [sp+48h] [bp-10h]
  float v19; // [sp+4Ch] [bp-Ch]
  float v20[1]; // [sp+50h] [bp-8h]

  v5 = result;
  v4 = a2;
  v19 = 0.0039062;
  v18 = 0.0039062 * 64.0;
  v17 = (float)a3 * 0.0039062;
  v16 = (float)a4 * 0.0039062;
  v6 = v17;
  v7 = (float)a4 * 0.0039062;
  v8 = v17 + (float)(0.0039062 * 64.0);
  v9 = (float)a4 * 0.0039062;
  v10 = v17 + (float)(0.0039062 * 64.0);
  v11 = v16 + (float)(0.0039062 * 64.0);
  v12 = (float)a3 * 0.0039062;
  v13 = v16 + (float)(0.0039062 * 64.0);
  v15 = 0;
  for ( i = 0; v4[4] > i; ++i )
    result = (Tesselator *)Tesselator::vertexUV(
                             v5,
                             *(float *)(4 * i + v4[2]) * Gui::InvGuiScale,
                             *(float *)(4 * i + v4[3]) * Gui::InvGuiScale,
                             0.0,
                             v20[(2 * (_BYTE)i & 7) - 14],
                             v20[((2 * (_BYTE)i + 1) & 7) - 14]);
  return result;
}
*/

/*
Tesselator *__fastcall sub_E35B8(Tesselator *result, _DWORD *a2, signed int a3, signed int a4)
{
  _DWORD *v4; // [sp+10h] [bp-48h]
  Tesselator *v5; // [sp+14h] [bp-44h]
  float v6[8]; // [sp+18h] [bp-40h]
  int i; // [sp+38h] [bp-20h]
  int v8; // [sp+3Ch] [bp-1Ch]
  float v9; // [sp+40h] [bp-18h]
  float v10; // [sp+44h] [bp-14h]
  float v11; // [sp+48h] [bp-10h]
  float v12; // [sp+4Ch] [bp-Ch]
  float v13[1]; // [sp+50h] [bp-8h]

  v5 = result;
  v4 = a2;
  v12 = 0.0039062;
  v11 = 0.0039062 * 64.0;
  v10 = (float)a3 * 0.0039062;
  v9 = (float)a4 * 0.0039062;
  v6[0] = v10;
  v6[1] = (float)a4 * 0.0039062;
  v6[2] = v10 + (float)(0.0039062 * 64.0);
  v6[3] = (float)a4 * 0.0039062;
  v6[4] = v10 + (float)(0.0039062 * 64.0);
  v6[5] = v9 + (float)(0.0039062 * 64.0);
  v6[6] = (float)a3 * 0.0039062;
  v6[7] = v9 + (float)(0.0039062 * 64.0);
  v8 = 0;
  for ( i = 0; v4[4] > i; ++i )
    result = (Tesselator *)Tesselator::vertexUV(
                             v5,
                             *(float *)(4 * i + v4[2]) * Gui::InvGuiScale,
                             *(float *)(4 * i + v4[3]) * Gui::InvGuiScale,
                             0.0,
                             v13[(2 * (_BYTE)i & 7) - 14],
                             v13[((2 * (_BYTE)i + 1) & 7) - 14]);
  return result;
}
*/

static void renderHelper(Tesselator *tesselator, PolygonArea *area, int32_t uu, int32_t vv) {
    float arr[8] = {
        (float)uu * 0.0039062f,
        (float)vv * 0.0039062f,
        ((float)uu * 0.0039062f) + (0.0039062f * 64.0f),
        (float)vv * 0.0039062,
        ((float)uu * 0.0039062f) + (0.0039062f * 64.0f),
        ((float)vv * 0.0039062f) + (0.0039062f * 64.0f),
        (float)uu * 0.0039062f,
        ((float)vv * 0.0039062f) + (0.0039062f * 64.0f)
    };
    for (uint32_t i = 0; i < area->vertexCount; ++i) {
        float x = area->vertexArrayX[i] * Gui::InvGuiScale;
        float y = area->vertexArrayY[i] * Gui::InvGuiScale;
        float u = arr[(2 * i & 7)];
        float v = arr[(2 * i + 1) & 7];
        tesselator->vertexUV(x, y, 0.0f, u, v);
    }
}

void TouchscreenInput_TestFps::render(float unknown) {
    glDisable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    GLuint texture = this->minecraft->textures->loadAndBindTexture("gui/gui.png");
    Tesselator::instance.begin();
    if (this->isButtonDown(102)) {
        Tesselator::instance.color(0xc0c0c0, 128);
    } else {
        Tesselator::instance.color(0xffffff, 128);
    }
    renderHelper(&Tesselator::instance, this->button2PolygonArea, 64, 112);
    if (this->isButtonDown(103)) {
        Tesselator::instance.color(0xc0c0c0, 128);
    } else {
        Tesselator::instance.color(0xffffff, 128);
    }
    renderHelper(&Tesselator::instance, this->button3PolygonArea, 192, 112);
    if (this->isButtonDown(100)) {
        Tesselator::instance.color(0xc0c0c0, 128);
    } else {
        Tesselator::instance.color(0xffffff, 128);
    }
    renderHelper(&Tesselator::instance, this->button0PolygonArea, 0, 112);
    if (this->isButtonDown(101)) {
        Tesselator::instance.color(0xc0c0c0, 128);
    } else {
        Tesselator::instance.color(0xffffff, 128);
    }
    renderHelper(&Tesselator::instance, this->button1PolygonArea, 128, 112);
    if (this->isButtonDown(104)) {
        Tesselator::instance.color(0xc0c0c0, 128);
    } else {
        Tesselator::instance.color(0xffffff, 128);
    }
    renderHelper(&Tesselator::instance, this->button4PolygonArea, 0, 176);
    Tesselator::instance.draw();
    glDisable(GL_BLEND);
    glEnable(GL_CULL_FACE);
}

void TouchscreenInput_TestFps::setKey(int32_t key, bool isPressed) {}

/*
int __fastcall TouchscreenInput_TestFps::setScreenSize(TouchscreenInput_TestFps *this, int a2, int a3)
{
  int v3; // ST20_4
  int v4; // ST1C_4
  float v5; // s15
  PolygonArea *v6; // r4
  PolygonArea *v7; // r4
  PolygonArea *v8; // r4
  PolygonArea *v9; // r4
  PolygonArea *v10; // r4
  TouchscreenInput_TestFps *v12; // [sp+24h] [bp-8Ch]
  char v13; // [sp+2Ch] [bp-84h]
  float v14; // [sp+44h] [bp-6Ch]
  int v15; // [sp+48h] [bp-68h]
  int v16; // [sp+4Ch] [bp-64h]
  int v17; // [sp+50h] [bp-60h]
  float v18; // [sp+54h] [bp-5Ch]
  int v19; // [sp+58h] [bp-58h]
  int v20; // [sp+5Ch] [bp-54h]
  int v21; // [sp+60h] [bp-50h]
  int v22; // [sp+64h] [bp-4Ch]
  int v23; // [sp+68h] [bp-48h]
  float v24; // [sp+6Ch] [bp-44h]
  float v25; // [sp+70h] [bp-40h]
  int v26; // [sp+74h] [bp-3Ch]
  float v27; // [sp+78h] [bp-38h]
  float v28; // [sp+7Ch] [bp-34h]
  int v29; // [sp+80h] [bp-30h]
  float v30; // [sp+84h] [bp-2Ch]
  float v31; // [sp+88h] [bp-28h]
  PixelCalc *v32; // [sp+8Ch] [bp-24h]
  float v33; // [sp+90h] [bp-20h]
  float v34; // [sp+94h] [bp-1Ch]
  float v35; // [sp+98h] [bp-18h]
  float v36; // [sp+9Ch] [bp-14h]

  v12 = this;
  v3 = a2;
  v4 = a3;
  TouchAreaModel::clear((TouchscreenInput_TestFps *)((char *)this + 68));
  v36 = (float)v3;
  v35 = (float)v4;
  v34 = (float)v3 * 0.11;
  v33 = (float)v3 * 0.11;
  v32 = (PixelCalc *)(*((_DWORD *)v12 + 21) + 3396);
  if ( PixelCalc::pixelsToMillimeters(v32, v34) > 14.0 )
  {
    v33 = PixelCalc::millimetersToPixels(v32, 14.0);
    v34 = v33;
  }
  v26 = 0;
  v29 = 0;
  v27 = v34;
  v28 = v34;
  v22 = 0;
  v23 = 0;
  v24 = v33;
  v25 = v33;
  v18 = 0.0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v14 = 0.0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v31 = (float)(v35 - 8.0) + (float)(v33 * -3.0);
  if ( *(_BYTE *)(*((_DWORD *)v12 + 15) + 26) )
    v5 = (float)(v36 - 8.0) + (float)(v34 * -3.0);
  else
    v5 = 8.0;
  v30 = v5;
  RectangleArea::RectangleArea((RectangleArea *)&v13, v5, v31, (float)(v34 * 3.0) + v5, (float)(v33 * 3.0) + v31);
  RectangleArea::operator=((char *)v12 + 24, &v13);
  RectangleArea::~RectangleArea((RectangleArea *)&v13);
  sub_E2AB4(
    4,
    (int)&v26,
    COERCE_FLOAT(&v22),
    (int)&v18,
    COERCE_FLOAT(&v14),
    COERCE_INT(v30 + v34),
    COERCE_INT((float)(v31 - v33) + v33),
    1.0,
    1.0);
  v6 = (PolygonArea *)operator new(0x14u);
  PolygonArea::PolygonArea(v6, 4, &v18, &v14);
  *((_DWORD *)v12 + 24) = v6;
  TouchAreaModel::addArea((TouchscreenInput_TestFps *)((char *)v12 + 68), 100, *((IArea **)v12 + 24));
  sub_E2AB4(
    4,
    (int)&v26,
    COERCE_FLOAT(&v22),
    (int)&v18,
    COERCE_FLOAT(&v14),
    COERCE_INT(v30 + v34),
    COERCE_INT(v31 + v33),
    1.0,
    1.0);
  v7 = (PolygonArea *)operator new(0x14u);
  PolygonArea::PolygonArea(v7, 4, &v18, &v14);
  *((_DWORD *)v12 + 26) = v7;
  TouchAreaModel::addArea((TouchscreenInput_TestFps *)((char *)v12 + 68), 104, *((IArea **)v12 + 26));
  sub_E2AB4(
    4,
    (int)&v26,
    COERCE_FLOAT(&v22),
    (int)&v18,
    COERCE_FLOAT(&v14),
    COERCE_INT(v30 + v34),
    COERCE_INT((float)(v33 + v33) + v31),
    1.0,
    1.0);
  v8 = (PolygonArea *)operator new(0x14u);
  PolygonArea::PolygonArea(v8, 4, &v18, &v14);
  *((_DWORD *)v12 + 25) = v8;
  TouchAreaModel::addArea((TouchscreenInput_TestFps *)((char *)v12 + 68), 101, *((IArea **)v12 + 25));
  sub_E2AB4(
    4,
    (int)&v26,
    COERCE_FLOAT(&v22),
    (int)&v18,
    COERCE_FLOAT(&v14),
    COERCE_INT(v30 + 0.0),
    COERCE_INT(v31 + v33),
    1.0,
    1.0);
  v9 = (PolygonArea *)operator new(0x14u);
  PolygonArea::PolygonArea(v9, 4, &v18, &v14);
  *((_DWORD *)v12 + 22) = v9;
  TouchAreaModel::addArea((TouchscreenInput_TestFps *)((char *)v12 + 68), 102, *((IArea **)v12 + 22));
  sub_E2AB4(
    4,
    (int)&v26,
    COERCE_FLOAT(&v22),
    (int)&v18,
    COERCE_FLOAT(&v14),
    COERCE_INT((float)(v34 + v34) + v30),
    COERCE_INT(v31 + v33),
    1.0,
    1.0);
  v10 = (PolygonArea *)operator new(0x14u);
  PolygonArea::PolygonArea(v10, 4, &v18, &v14);
  *((_DWORD *)v12 + 23) = v10;
  return TouchAreaModel::addArea((TouchscreenInput_TestFps *)((char *)v12 + 68), 103, *((IArea **)v12 + 23));
}
*/

static void setScreenSizeHelper(int32_t vertexCount, float *vertexArrayXSrc, float *vertexArrayYSrc, float *vertexArrayXDest, float *vertexArrayYDest, float ax, float ay, float mx, float my)
{
    for (int32_t i = 0; i < vertexCount; ++i) {
        vertexArrayXDest[i] = vertexArrayXSrc[i];
        vertexArrayYDest[i] = vertexArrayYSrc[i];
    }
    for (int32_t i = 0; i < vertexCount; ++i) {
        vertexArrayXDest[i] *= mx;
        vertexArrayYDest[i] *= my;
    }
    for (int32_t i = 0; i < vertexCount; ++i) {
        vertexArrayXDest[i] += ax;
        vertexArrayYDest[i] += ay;
    }
}

/*
sub_E2AB4(
    4,
    (int)&v26,
    COERCE_FLOAT(&v22),
    (int)&v18,
    COERCE_FLOAT(&v14),
    COERCE_INT(x1 + widthMillimeters),
    COERCE_INT((float)(y1 - widthMillimeters) + widthMillimeters),
    1.0,
    1.0);
 sub_E2AB4(
    4,
    (int)&v26,
    COERCE_FLOAT(&v22),
    (int)&v18,
    COERCE_FLOAT(&v14),
    COERCE_INT(x1 + widthMillimeters),
    COERCE_INT(y1 + widthMillimeters),
    1.0,
    1.0);
sub_E2AB4(
    4,
    (int)&v26,
    COERCE_FLOAT(&v22),
    (int)&v18,
    COERCE_FLOAT(&v14),
    COERCE_INT(x1 + widthMillimeters),
    COERCE_INT((float)(widthMillimeters + widthMillimeters) + y1),
    1.0,
    1.0);
sub_E2AB4(
    4,
    (int)&v26,
    COERCE_FLOAT(&v22),
    (int)&v18,
    COERCE_FLOAT(&v14),
    COERCE_INT(x1 + 0.0),
    COERCE_INT(y1 + widthMillimeters),
    1.0,
    1.0);
sub_E2AB4(
    4,
    (int)&v26,
    COERCE_FLOAT(&v22),
    (int)&v18,
    COERCE_FLOAT(&v14),
    COERCE_INT((float)(widthMillimeters + widthMillimeters) + x1),
    COERCE_INT(y1 + widthMillimeters),
    1.0,
    1.0);
*/

void TouchscreenInput_TestFps::setScreenSize(int32_t width, int32_t height) {
    this->touchAreaModel.clear();
    float widthMillimeters = width * 0.11;
    if (this->minecraft->guiPixelCalc.pixelsToMillimeters(widthMillimeters) > 14.0f) {
        widthMillimeters = this->minecraft->guiPixelCalc.millimetersToPixels(14.0f);
    }
    float y1 = ((float)height - 8.0f) + (widthMillimeters * (-3.0));
    float x1 = 8.0f;
    if (this->options->isLeftHanded) {
        x1 = ((float)width - 8.0f) + (widthMillimeters * (-3.0));
    }
    float x2 = (widthMillimeters * 3.0f) + x1;
    float y2 = (widthMillimeters * 3.0f) + y1;
    this->rectangleArea = RectangleArea(x1, y1, x2, y2);
    float vertexArrayX[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    float vertexArrayY[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    float vertexArrayXSrc[4] = {0.0f, widthMillimeters, widthMillimeters, 0.0f};
    float vertexArrayYSrc[4] = {0.0f, 0.0f, widthMillimeters, widthMillimeters};
    setScreenSizeHelper(4, vertexArrayXSrc, vertexArrayYSrc, vertexArrayX, vertexArrayY, x1 + widthMillimeters, y1, 1.0f, 1.0f);
    this->button0PolygonArea = new PolygonArea(4, vertexArrayX, vertexArrayY);
    this->touchAreaModel.addArea(100, this->button0PolygonArea);
    setScreenSizeHelper(4, vertexArrayXSrc, vertexArrayYSrc, vertexArrayX, vertexArrayY, x1 + widthMillimeters, y1 + widthMillimeters, 1.0f, 1.0f);
    this->button4PolygonArea = new PolygonArea(4, vertexArrayX, vertexArrayY);
    this->touchAreaModel.addArea(104, this->button4PolygonArea);
    setScreenSizeHelper(4, vertexArrayXSrc, vertexArrayYSrc, vertexArrayX, vertexArrayY, x1 + widthMillimeters, y1 + (2 * widthMillimeters), 1.0f, 1.0f);
    this->button1PolygonArea = new PolygonArea(4, vertexArrayX, vertexArrayY);
    this->touchAreaModel.addArea(101, this->button1PolygonArea);
    setScreenSizeHelper(4, vertexArrayXSrc, vertexArrayYSrc, vertexArrayX, vertexArrayY, x1, y1 + widthMillimeters, 1.0f, 1.0f);
    this->button2PolygonArea = new PolygonArea(4, vertexArrayX, vertexArrayY);
    this->touchAreaModel.addArea(102, this->button2PolygonArea);
    setScreenSizeHelper(4, vertexArrayXSrc, vertexArrayYSrc, vertexArrayX, vertexArrayY, x1 + (2 * widthMillimeters), y1 + widthMillimeters, 1.0f, 1.0f);
    this->button3PolygonArea = new PolygonArea(4, vertexArrayX, vertexArrayY);
    this->touchAreaModel.addArea(103, this->button3PolygonArea);
}

/*
int __fastcall TouchscreenInput_TestFps::tick(TouchscreenInput_TestFps *this, Player *a2)
{
  int result; // r0
  int v3; // r1
  int v4; // ST14_4
  int v5; // r1
  __int16 v6; // r0
  Player *v7; // [sp+0h] [bp-38h]
  TouchscreenInput_TestFps *v8; // [sp+4h] [bp-34h]
  signed int v9; // [sp+Ch] [bp-2Ch]
  Multitouch *v10; // [sp+18h] [bp-20h]
  int j; // [sp+1Ch] [bp-1Ch]
  int v12; // [sp+20h] [bp-18h]
  int v13; // [sp+24h] [bp-14h]
  int i; // [sp+28h] [bp-10h]
  char v15; // [sp+2Eh] [bp-Ah]
  char v16; // [sp+2Fh] [bp-9h]

  v8 = this;
  v7 = a2;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_BYTE *)this + 13) = 0;
  v16 = 0;
  v15 = 0;
  for ( i = 0; i <= 4; ++i )
    *((_BYTE *)this + i + 108) = 0;
  result = Multitouch::getActivePointerIds((Multitouch *)&v13, (const int **)a2);
  v12 = result;
  for ( j = 0; j < v12; ++j )
  {
    v10 = *(Multitouch **)(4 * j + v13);
    v4 = (signed __int16)Multitouch::getX(*(Multitouch **)(4 * j + v13), v3);
    v6 = Multitouch::getY(v10, v5);
    result = TouchAreaModel::getPointerId((TouchscreenInput_TestFps *)((char *)v8 + 68), v4, v6, (int)v10);
    v9 = result;
    if ( result > 99 )
      *((_BYTE *)v8 + result + 8) = 1;
    if ( result == 105 )
    {
      result = (*(int (__fastcall **)(Player *))(*(_DWORD *)v7 + 76))(v7);
      if ( result )
        *((_BYTE *)v8 + 13) = 1;
      else
        v15 = 1;
      v9 = 100;
    }
    if ( v9 == 104 )
    {
      result = (*(int (__fastcall **)(Player *))(*(_DWORD *)v7 + 76))(v7);
      if ( result )
      {
        *((_BYTE *)v8 + 13) = 1;
      }
      else
      {
        result = Multitouch::isPressed(v10, v3);
        if ( result )
        {
          *((_BYTE *)v8 + 13) = 1;
        }
        else if ( *((_BYTE *)v8 + 64) )
        {
          v9 = 100;
          v15 = 1;
          *((float *)v8 + 2) = *((float *)v8 + 2) + 1.0;
        }
      }
    }
    switch ( v9 )
    {
      case 100:
        result = (*(int (__fastcall **)(Player *))(*(_DWORD *)v7 + 76))(v7);
        if ( result )
          *((_BYTE *)v8 + 13) = 1;
        else
          v16 = 1;
        *((float *)v8 + 2) = *((float *)v8 + 2) + 1.0;
        break;
      case 101:
        *((float *)v8 + 2) = *((float *)v8 + 2) - 1.0;
        break;
      case 102:
        *((float *)v8 + 1) = *((float *)v8 + 1) + 1.0;
        break;
      case 103:
        *((float *)v8 + 1) = *((float *)v8 + 1) - 1.0;
        break;
    }
  }
  *((_BYTE *)v8 + 64) = v16;
  if ( v15 )
  {
    if ( *((_BYTE *)v8 + 65) ^ 1 )
      *((_BYTE *)v8 + 13) = 1;
    *((_BYTE *)v8 + 65) = 1;
  }
  else
  {
    *((_BYTE *)v8 + 65) = 0;
  }
  return result;
}
*/
void TouchscreenInput_TestFps::tick(void *player) {

}