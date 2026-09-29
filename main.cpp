#include "src/Mesh.hpp"
#include "src/Shaders.hpp"
#include "src/Window.hpp"
#include "utils/OBJLoader.hpp"

int main() {
    Window engineWindow;
    engineWindow.init();

    Shaders defaultShaders("shaders/default.vert", "shaders/default.frag");

    while (!engineWindow.shouldClose()) {
        engineWindow.clear();

        defaultShaders.use();

        engineWindow.swapBuffers();
        engineWindow.pollEvents();
    }

    engineWindow.terminate();
    return 0;
}