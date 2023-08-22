#include "ImageDef.h"

ImageDef::ImageDef(const ImageDef& imageDef) {
    this->name = imageDef.name;
    this->x = imageDef.x;
    this->y = imageDef.y;
    this->width = imageDef.width;
    this->height = imageDef.height;
    this->rect.minX = imageDef.rect.minX;
    this->rect.minY = imageDef.rect.minY;
    this->rect.maxX = imageDef.rect.maxX;
    this->rect.maxY = imageDef.rect.maxY;
    this->doRender = imageDef.doRender;
}

ImageDef::ImageDef() {
    this->x = 0;
    this->y = 0;
    this->width = 16.0f;
    this->height = 16.0f;
    this->doRender = false;
}

void ImageDef::operator=(const ImageDef& imageDef) {
    this->name = imageDef.name;
    this->x = imageDef.x;
    this->y = imageDef.y;
    this->width = imageDef.width;
    this->height = imageDef.height;
    this->rect.minX = imageDef.rect.minX;
    this->rect.minY = imageDef.rect.minY;
    this->rect.maxX = imageDef.rect.maxX;
    this->rect.maxY = imageDef.rect.maxY;
    this->doRender = imageDef.doRender;
}