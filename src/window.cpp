#include "window.hpp"

namespace BS {
    Window::Window() : width{WIDTH}, height{HEIGHT}, windowName{TITLE} {
        
    }

    Window::~Window() {
    }

    void Window::run() {
        initWindow();
        update();
        cleanup();
    }

    bool Window::shouldClose() { 
        return glfwWindowShouldClose(window);
    }


    void Window::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    
        if(vulkanCore == nullptr) {
            vulkanCore = new Vulkan::Core();
            vulkanCore->init();
        }
    }

    void Window::update() {
        while(!shouldClose()) {
            glfwPollEvents();
        }
    }

    void Window::cleanup() {
        if(vulkanCore != nullptr) {
            vulkanCore->cleanup();
            std::cout << "vulkanCore delete" << std::endl;
            delete vulkanCore;
        }
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}