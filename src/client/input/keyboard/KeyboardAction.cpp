#include "./KeyboardAction.h"

KeyboardAction::KeyboardAction(uint8_t key, int32_t state) {
    this->key = key;
    this->state = state;
}