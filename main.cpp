#include "src/Shaders.hpp"
#include "src/Window.hpp"
#include "src/GameObject.hpp"
#include "../components/MeshRenderer.hpp"
#include "../components/Transform.hpp"

int main() {
    Window engineWindow;
    if (engineWindow.init() != 0) return -1;

    Shaders defaultShaders("shaders/default.vert", "shaders/default.frag");

    GameObject teapot;
    teapot.addComponent<MeshRenderer>("models/utah_teapot.obj",&defaultShaders);
    teapot.addComponent<Transform>();
    teapot.getComponent<Transform>()->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));

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