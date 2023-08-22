#pragma once

#include "../Button.h"

namespace Touch {
    class TButton : public Button {
    public:
        TButton(int32_t buttonId, int32_t x, int32_t y, int32_t width, int32_t height, const std::string& name);

        TButton(int32_t buttonId, int32_t x, int32_t y, const std::string& name);

        TButton(int32_t buttonId, const std::string& name);
    };
}