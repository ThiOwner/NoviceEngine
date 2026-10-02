#include <iostream>
#include "../Engine/Core/Engine.hpp"

int main() {
    try {
        Engine engine;
        engine.run();

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}