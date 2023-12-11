#include "lve_window.hpp"

//std
#include <stdexcept>

namespace lve {

	LveWindow::LveWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name } {
		initWindow();
	}

	LveWindow::~LveWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void LveWindow::initWindow() {

		//Initialize glfw-Library
		glfwInit();
		// tell glfw to not create a opengl-context (because we are using vulkan)
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		//disable resize because we need to handle rezises in another way(shown in tutorial 10)
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		//last parameter is used to relate to an opengl-context (we are not using opengl so we give a nullptr)
		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);



	}

	void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("failed to create window surface");
		}
	}
}

