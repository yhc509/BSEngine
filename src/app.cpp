#include "app.hpp"

namespace BS {
    Application::Application() {

    }

    Application::~Application() {

    }

    void Application::run() {
        lveWindow = new Window();
        lveWindow->run();
        delete lveWindow;
    }
}