#include "src/Mesh.hpp"
#include "src/Shaders.hpp"
#include "src/Window.hpp"


int main() {
    Window engineWindow;
    engineWindow.init();

    while (!engineWindow.shouldClose()) {
        engineWindow.clear();

        Shaders defaultShaders("shaders/default.vert", "shaders/default.frag");
        defaultShaders.use();

        engineWindow.swapBuffers();
        engineWindow.pollEvents();
    }

    engineWindow.terminate();
    return 0;
}