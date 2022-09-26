#pragma once

#include "../common.hpp"
#include "window.hpp"

namespace BS {
    class Application {
        public:
            Application();
            ~Application();
            void run();


        private:
            Window* lveWindow;
    };
}