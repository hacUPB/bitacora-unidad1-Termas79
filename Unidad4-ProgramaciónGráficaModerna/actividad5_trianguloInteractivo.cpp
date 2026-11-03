#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char* vertexShaderSrc = R"glsl(
    #version 460 core
    layout(location = 0) in vec3 aPos;
    
    uniform vec2 offset; // Desplazamiento dinámico
    
    void main() {
        vec3 newPos = aPos;
        newPos.x += offset.x;
        newPos.y += offset.y;
        gl_Position = vec4(newPos, 1.0);
    }
)glsl";

const char* fragmentShaderSrc = R"glsl(
    #version 460 core
    out vec4 FragColor;
    
    uniform vec4 ourColor; // Color dinámico
    
    void main() {
        FragColor = ourColor;
    }
)glsl";

unsigned int VAO, VBO, shaderProg;

unsigned int buildShaderProgram(const char* vShader, const char* fShader) {
    int success;
    char log[512];

    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vShader, nullptr);
    glCompileShader(vs);
    glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vs, 512, nullptr, log);
        std::cerr << "ERROR VERTEX SHADER:\n" << log << "\n";
    }

    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fShader, nullptr);
    glCompileShader(fs);
    glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fs, 512, nullptr, log);
        std::cerr << "ERROR FRAGMENT SHADER:\n" << log << "\n";
    }

    unsigned int prog = glCreateProgram();
    glAttachShader(prog, vs);
    glAttachShader(prog, fs);
    glLinkProgram(prog);
    glGetProgramiv(prog, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(prog, 512, nullptr, log);
        std::cerr << "ERROR LINKING PROGRAM:\n" << log << "\n";
    }

    glDeleteShader(vs);
    glDeleteShader(fs);
    return prog;
}

void setupTriangle() {
    float vertices[] = {
        -0.2f, -0.2f, 0.0f,
         0.2f, -0.2f, 0.0f,
         0.0f,  0.2f, 0.0f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

int main() {
    // 1) Inicializar GLFW
    if (!glfwInit()) return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 2) Crear ventana
    GLFWwindow* mainWindow = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Actividad 5: Triangulo Animado", nullptr, nullptr);
    if (!mainWindow) {
        glfwTerminate();
        return -1;
    }

    // 3) Callbacks y contexto
    glfwMakeContextCurrent(mainWindow);
    glfwSetFramebufferSizeCallback(mainWindow, framebuffer_size_callback);

    // 4) Cargar GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) return -1;

    // 5) Preparar recursos
    glfwSwapInterval(1); // V-Sync
    shaderProg = buildShaderProgram(vertexShaderSrc, fragmentShaderSrc);
    setupTriangle();

    glUseProgram(shaderProg);
    int offsetLocation = glGetUniformLocation(shaderProg, "offset");
    int colorLocation = glGetUniformLocation(shaderProg, "ourColor");

    // Loop principal
    while (!glfwWindowShouldClose(mainWindow)) {
        glfwPollEvents();
        processInput(mainWindow);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProg);

        double xpos, ypos;
        glfwGetCursorPos(mainWindow, &xpos, &ypos);

        // 1. Normalizar de ventana a [0.0, 1.0] limitando los bordes
        float x = (float)xpos / (float)SCR_WIDTH;
        if (x < 0) x = 0.0f;
        if (x > 1) x = 1.0f;

        float y = (float)ypos / (float)SCR_HEIGHT;
        if (y < 0) y = 0.0f;
        if (y > 1) y = 1.0f;

        // 2. Enviar el color (basado en el rango 0 a 1)
        glUniform4f(colorLocation, x, y, 0.0f, 1.0f);

        // 3. Convertir de rango [0,1] a coordenadas NDC [-1, 1] y enviar el Offset
        // x*2 - 1 convierte X normal
        // 1 - y*2 invierte Y para que coincida con la pantalla de la computadora
        glUniform2f(offsetLocation, (x * 2.0f) - 1.0f, 1.0f - (y * 2.0f));

        // Dibujar
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(mainWindow);
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProg);
    glfwTerminate();
    return 0;
}