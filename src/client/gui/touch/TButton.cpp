#include "TButton.h"

Touch::TButton::TButton(int32_t buttonId, int32_t x, int32_t y, int32_t width, int32_t height, const std::string& name) :
    Button(buttonId, x, y, width, height, name) {
    this->width = 66;
    this->height = 26;
}

Touch::TButton::TButton(int32_t buttonId, int32_t x, int32_t y, const std::string& name) :
    Button(buttonId, x, y, name) {
    this->width = 66;
    this->height = 26;
}

Touch::TButton::TButton(int32_t buttonId, const std::string& name) :
    Button(buttonId, name) {
    this->width = 66;
    this->height = 26;
}