#include <GLFW/glfw3.h>
#include <bits/stdc++.h>

int main() {
    GLFWwindow* window;

    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    const std::pair<int, int> windowDim(640, 480);
    window = glfwCreateWindow(windowDim.first, windowDim.second, "asdf", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Make Context
    glfwMakeContextCurrent(window);

    // Print something
    std::cout << "Starting program" << std::endl;

    float ratio;
    int width, height;

    glfwGetFramebufferSize(window, &width, &height);
    ratio = (float)width / (float)height;
    std::cout << "framebuffer sizes: width " << width << ", height " << height << std::endl;

    // Loop
    while (!glfwWindowShouldClose(window)) {
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        // Begin mode: draw points
        glBegin(GL_POINTS);
        for (int i = 0; i < 2*width; i++) {
            for (int j = 0; j < 2*height; j++) {
                glColor3f((float)j/(float)height,(float)i/(float)width,1.f);
                glVertex2f((float)j/(float)height-1.f,(float)i/(float)width-1.f);
            }
        }
        glEnd();

        // Swap front/back buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
