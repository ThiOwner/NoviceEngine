#include "src/Shader.hpp"
#include "src/Window.hpp"
#include "src/GameObject.hpp"
#include "../components/MeshRenderer.hpp"

int main() {
    try {
        Window engineWindow;
        Shader defaultShaders("shaders/default.vert", "shaders/default.frag");

        GameObject teapot;
        teapot.addComponent<MeshRenderer>("models/utah_teapot.obj",&defaultShaders);

        while (!engineWindow.shouldClose()) {
            engineWindow.clear();
            teapot.render();
            engineWindow.swapBuffers();
            engineWindow.pollEvents();
        }
        return 0;

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}