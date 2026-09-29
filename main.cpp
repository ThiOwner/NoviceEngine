#include "src/Shaders.hpp"
#include "src/Window.hpp"
#include "src/GameObject.hpp"
#include "../components/MeshRenderer.hpp"

int main() {
    Window engineWindow;
    engineWindow.init();

    GameObject teapot;
    teapot.addComponent<MeshRenderer>("models/utah_teapot.obj");

    Shaders defaultShaders("shaders/default.vert", "shaders/default.frag");

    while (!engineWindow.shouldClose()) {
        engineWindow.clear();

        defaultShaders.use();
        teapot.render();

        engineWindow.swapBuffers();
        engineWindow.pollEvents();
    }

    engineWindow.terminate();
    return 0;
}