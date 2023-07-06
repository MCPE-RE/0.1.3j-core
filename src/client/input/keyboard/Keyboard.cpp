#include "Keyboard.h"

int32_t Keyboard::_index = -1;
int32_t Keyboard::_states[256];
std::vector<KeyboardAction> Keyboard::_inputs;

void Keyboard::feed(uint8_t key, int32_t state) {
    KeyboardAction action(key, state);
    Keyboard::_inputs.push_back(action);
    Keyboard::_states[key] = state;
}

uint8_t Keyboard::getEventKey() {
    return Keyboard::_inputs[Keyboard::_index].key;
}

int32_t Keyboard::getEventKeyState() {
    return Keyboard::_inputs[Keyboard::_index].state;
}

bool Keyboard::isKeyDown(int32_t key) {
    return Keyboard::_states[key] == 1;
}

bool Keyboard::next() {
    if (Keyboard::_index >= Keyboard::_inputs.size()) {
        return false;
    }
    ++Keyboard::_index;
    return true;
}

void Keyboard::reset() {
    Keyboard::_inputs.clear();
    Keyboard::_index = -1;
}