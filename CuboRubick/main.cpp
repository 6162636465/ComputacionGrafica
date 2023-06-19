//javierAlvarezReyes
//Pablo cesar Yucra
#ifndef GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#endif
#ifndef GLAD_GL_IMPLEMENTATION
#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#endif
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader_m.h"
#include "Cubo.h"
#include "Camara.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window,Cubo* cubo);
// Compilar y enlazar los shaders
const char* vertexShaderSource = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    uniform mat4 view;
    uniform mat4 projection;
    out vec3 ourColor; // Variable ourColor agregada
    void main()
    {
        gl_Position = projection * view * vec4(aPos, 1.0);
        ourColor = aPos; // Ejemplo de asignación de ourColor basado en la posición del vértice
    }
)";

const char* fragmentShaderSource = R"(
    #version 330 core
    uniform vec3 triangleColor; // Nueva variable para el color 
    in vec3 ourColor; // Variable ourColor
    out vec4 FragColor;
    void main()
    {
        FragColor = vec4(triangleColor, 1.0);
    }
)";



const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

//Almacenamiento que se seteara con la estructura cubo
std::map<int, std::pair<float*, unsigned int*>> VerticesDeLosCubos;
//condicional Rotacion
bool CuboRotacion = false;
int Rotacion=0;
int Opcion=0;
bool RotacionPiso=false;
bool RotacionPlano=false;

//________________________________________________________________________________________________________________________
//colores
// Rojo
float triangleColor[] = { 1.0f, 0.0f, 0.0f };

// Verde
float triangleColor2[] = { 0.0f, 1.0f, 0.0f };

// Azul
float triangleColor3[] = { 0.0f, 0.0f, 1.0f };

// Amarillo
float triangleColor4[] = { 1.0f, 1.0f, 0.0f };

// Blanco
float triangleColor5[] = { 1.0f, 1.0f, 1.0f };

// Morado
float triangleColor6[] = { 1.0f, 0.0f, 1.0f };

// Negro
float blackColor[] = { 0.0f, 0.0f, 0.0f };

//_________________________________________________________________________________________________________________________________

//cara1
unsigned int indices1[] 
{
        0, 1, 2, 2, 3, 0
};
//cara2
unsigned int indices2[] 
{
        4, 5, 7, 7, 6, 4
};
//cara3
unsigned int indices3[] 
{
        0, 1, 5, 5, 4, 0
};
//cara4
unsigned int indices4[] 
{
        2, 3, 7, 7, 6, 3
};
//cara5
unsigned int indices5[] 
{
        0, 4, 6, 6, 3, 0
};
//cara6
unsigned int indices6[] 
{
        1, 2, 7, 7, 5, 1
};

//Lineas
unsigned int indices7[] 
{
        0, 1, 2, 3, 0, 4, 1, 5, 2, 6, 3, 7, 4, 5, 6, 7
};


void actualizarVertices(const std::map<int, std::pair<float*, unsigned int*>>& Cubos, unsigned int VAOs[200], unsigned int VBOs[200], unsigned int EBOs[200])
{
    //156
    int index = 0;
    for (const auto& elemento : Cubos)
    {
        const auto& datos = elemento.second;
        const float* vertices = datos.first;

        // cara 1
        glBindVertexArray(VAOs[index*7]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[index*7]);
        glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[index*7]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices1), indices1, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // cara 2
        glBindVertexArray(VAOs[index*7+1]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[index*7+1]);
        glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[index*7+1]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // cara 3
        glBindVertexArray(VAOs[index*7+2]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[index*7+2]);
        glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[index*7+2]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices3), indices3, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // cara 4
        glBindVertexArray(VAOs[index*7+3]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[index*7+3]);
        glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[index*7+3]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices4), indices4, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // cara 5
        glBindVertexArray(VAOs[index*7+4]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[index*7+4]);
        glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[index*7+4]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices5), indices5, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // cara 6
        glBindVertexArray(VAOs[index*7+5]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[index*7+5]);
        glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[index*7+5]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices6), indices6, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Lineas
        glBindVertexArray(VAOs[index*7+6]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[index*7+6]);
        glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[index*7+6]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices7), indices7, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        index=index+1;
    }
}

void PintarCarasCubo(const std::map<int, std::pair<float*, unsigned int*>>& Cubos, unsigned int VAOs[200], unsigned int shaderProgram)
{
    int index = 0;
    for (const auto& elemento : Cubos)
    {
        const auto& datos = elemento.second;
        const float* vertices = datos.first;

        // Cara roja
        glBindVertexArray(VAOs[index*7]);
        unsigned int triangleColorLoc = glGetUniformLocation(shaderProgram, "triangleColor");
        glUniform3f(triangleColorLoc, triangleColor[0], triangleColor[1], triangleColor[2]);
        glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
        
        // Cara verde
        glBindVertexArray(VAOs[index*7+1]);
        unsigned int triangleColorLoc2 = glGetUniformLocation(shaderProgram, "triangleColor");
        glUniform3f(triangleColorLoc2, triangleColor2[0], triangleColor2[1], triangleColor2[2]);
        glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
        
        // Cara azul
        glBindVertexArray(VAOs[index*7+2]);
        unsigned int triangleColorLoc3 = glGetUniformLocation(shaderProgram, "triangleColor");
        glUniform3f(triangleColorLoc3, triangleColor3[0], triangleColor3[1], triangleColor3[2]);
        glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
        
        // Cara amarilla
        glBindVertexArray(VAOs[index*7+3]);
        unsigned int triangleColorLoc4 = glGetUniformLocation(shaderProgram, "triangleColor");
        glUniform3f(triangleColorLoc4, triangleColor4[0], triangleColor4[1], triangleColor4[2]);
        glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
        // Cara blanca
        glBindVertexArray(VAOs[index*7+4]);
        unsigned int triangleColorLoc5 = glGetUniformLocation(shaderProgram, "triangleColor");
        glUniform3f(triangleColorLoc5, triangleColor5[0], triangleColor5[1], triangleColor5[2]);
        glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);

        // Cara morada
        glBindVertexArray(VAOs[index*7+5]);
        unsigned int triangleColorLoc6 = glGetUniformLocation(shaderProgram, "triangleColor");
        glUniform3f(triangleColorLoc6, triangleColor6[0], triangleColor6[1], triangleColor6[2]);
        glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
        /*
        // Líneas
        glBindVertexArray(VAOs[index*7+6]);
        unsigned int triangleColorLoc7 = glGetUniformLocation(shaderProgram, "triangleColor");
        glUniform3f(triangleColorLoc7, blackColor[0], blackColor[1], blackColor[2]);
        glLineWidth(9.0f);
        glDrawElements(GL_LINES, 24, GL_UNSIGNED_INT, 0);
        */
        // Restaurar el programa de shaders
        glUseProgram(shaderProgram);
        index=index+1;
    }
}


CamaraLast camera;

int main()
{
    // Inicializar GLFW y configurar la ventana
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Camera Example", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Cargar GLAD
    if (!gladLoadGL(glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    unsigned int vertexShader, fragmentShader, shaderProgram;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    shaderProgram = glCreateProgram();

    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);



    unsigned int VBOs[200], VAOs[200], EBOs[200];
    glGenVertexArrays(200, VAOs); // we can also generate multiple VAOs or buffers at the same time
    glGenBuffers(200, VBOs);
    glGenBuffers(200, EBOs);
    


// crear y vincular los VBOs para el primer triangulo

    Cubo cubo;
    cubo.insertarElementos(27);
    //cubo.imprimirCubos();
    cout << "_________________________________________________________________________________________________" << endl;
    cubo.ordenarCubos();
    cubo.imprimirCubos();
    VerticesDeLosCubos= cubo.retornarCubos();
    //cubo.sumarCondicion(25);
    actualizarVertices(VerticesDeLosCubos, VAOs, VBOs, EBOs);
    

    // Variable para controlar la velocidad del movimiento de la cámara
    float cameraSpeed = 0.05f;
    bool unaPrueba=true;

    // Habilitar el test de profundidad
    glEnable(GL_DEPTH_TEST);
    cout << "*********************************************************************************************************************" << endl;
    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        //cubo.imprimirEstructura(VerticesDeLosCubos);
        
        // Entrada de teclado
        processInput(window,&cubo);
        VerticesDeLosCubos= cubo.retornarCubos();
        actualizarVertices(VerticesDeLosCubos, VAOs, VBOs, EBOs);
        /*
        if(unaPrueba==true)
        {
            cubo.GirarPiso(4);
            unaPrueba=false;
            cubo.imprimirCubos();
        }*/
        // Limpiar el buffer de color y el buffer de profundidad
        //cubo.GirarPiso(1);

        if(Opcion>0)
        {
            if(Opcion==1 && RotacionPiso==true && RotacionPlano==false &&Rotacion<=90)
            {
                cubo.realizarAnimacion(1,true);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==1 && RotacionPiso==false && RotacionPlano==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(1,false);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==2 && RotacionPiso==true && RotacionPlano==false &&Rotacion<=90)
            {
                cubo.realizarAnimacion(2,true);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==2 && RotacionPiso==false && RotacionPlano==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(2,false);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==3 && RotacionPiso==true && RotacionPlano==false &&Rotacion<=90)
            {
                cubo.realizarAnimacion(3,true);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==3 && RotacionPiso==false && RotacionPlano==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(3,false);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==4 && RotacionPiso==true && RotacionPlano==false &&Rotacion<=90)
            {
                cubo.realizarAnimacion(4,true);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==4 && RotacionPiso==false && RotacionPlano==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(4,false);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==5 && RotacionPiso==true && RotacionPlano==false &&Rotacion<=90)
            {
                cubo.realizarAnimacion(5,true);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==5 && RotacionPiso==false && RotacionPlano==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(5,false);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==6 && RotacionPiso==true && RotacionPlano==false &&Rotacion<=90)
            {
                cubo.realizarAnimacion(6,true);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==6 && RotacionPiso==false && RotacionPlano==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(6,false);
                Rotacion=Rotacion+1;
            }
            else if (Rotacion>84)
            {
                Opcion==0;
                Rotacion=0;
                RotacionPiso = false;
                RotacionPlano = false;
                cout<<"*********************"<<endl;
                cubo.ImprimirTodasLasMatrices();
                cout<<"*********PosicionSet************"<<endl;
                //cubo.SetearPosiciones();
                cout<<"*********************"<<endl;
            }

        }



        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        camera.first(window);

        // Crear la matriz de vista
        
        glm::mat4 view = glm::lookAt(camera.cameraPos, camera.cameraPos + camera.cameraFront, camera.cameraUp);
        

        // Configurar las matrices de proyección y vista en los shaders
        
        glm::mat4 projection = glm::perspective(glm::radians(camera.fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        
        if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
        {
            const float radius = 1.5f;
            float camX = sin(glfwGetTime()) * radius;
            float camZ = cos(glfwGetTime()) * radius;
            view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
        }

        if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        {
            const float radius = 1.5f;
            float camY = sin(glfwGetTime()) * radius;
            float camZ = cos(glfwGetTime()) * radius;
            view = glm::lookAt(glm::vec3(0.0, camY, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
        }

        // Configurar las matrices de proyección y vista en los shaders
        glUseProgram(shaderProgram);

        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));


        // Dibujar el cubo

        PintarCarasCubo(VerticesDeLosCubos, VAOs, shaderProgram);

        // Intercambiar los buffers de color
        glfwSwapBuffers(window);

        // Verificar si se han activado eventos y llamar a las funciones de callback correspondientes
        glfwPollEvents();

    }


    // Terminar GLFW
    glfwTerminate();
    return 0;
}

// Función para manejar el cambio de tamaño de la ventana
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// Función para manejar la entrada de teclado y llamada por puntero a la clase cubo
void processInput(GLFWwindow* window, Cubo* cubo)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    camera.inputIfs(window);
    
    static bool qPresionado = false; // Variable de estado para la tecla Q
    static bool ePresionado = false; // Variable de estado para la tecla E

    static bool tecla1Presionada = false; // Variable de estado para la tecla 1
    static bool tecla2Presionada = false; // Variable de estado para la tecla 2
    static bool tecla3Presionada = false; // Variable de estado para la tecla 3
    static bool tecla4Presionada = false; // Variable de estado para la tecla 4
    static bool tecla5Presionada = false; // Variable de estado para la tecla 5
    static bool tecla6Presionada = false; // Variable de estado para la tecla 6

    // ...

    // Condicional si apreta q
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && !qPresionado)
    {
        CuboRotacion = true;
        qPresionado = true;
    }

    // Condicional si apreta e
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && !ePresionado)
    {
        CuboRotacion = false;
        ePresionado = true;
    }

    // Condicional si apreto 1
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS && !tecla1Presionada)
    {
        tecla1Presionada = true;

        // Condicional si CuboRotacion es true llamar a GirarPiso y si es false llamar a GirarPlano
        if (CuboRotacion == true)
        {
            cout << "se apreto  1 Q" << endl;
            cubo->GirarPiso(1);
            Opcion=1;
            RotacionPiso=true;
            RotacionPlano=false;
            cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
        else
        {
            cout << "se apreto  1 E" << endl;
            Opcion=1;
            RotacionPiso=false;
            RotacionPlano=true;
            cubo->GirarPlano(1);
            cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
    }

    // Condicional si apreto 2
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS && !tecla2Presionada)
    {
        tecla2Presionada = true;

        if (CuboRotacion == true)
        {
            cout << "se apreto  2 Q" << endl;
            Opcion=2;
            RotacionPiso=true;
            RotacionPlano=false;
            cubo->GirarPiso(2);
            cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
        else
        {
            cout << "se apreto  2 E" << endl;
            Opcion=2;
            RotacionPiso=false;
            RotacionPlano=true;
            cubo->GirarPlano(2);
            cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
    }

    // Condicional si apreto 3
    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS && !tecla3Presionada)
    {
        tecla3Presionada = true;

        if (CuboRotacion == true)
        {
            cout << "se apreto  3 Q" << endl;
            Opcion=3;
            RotacionPiso=true;
            RotacionPlano=false;
            cubo->GirarPiso(3);
            cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
        else
        {
            cout << "se apreto  3 E" << endl;
            Opcion=3;
            RotacionPiso=false;
            RotacionPlano=true;
            cubo->GirarPlano(3);
            cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
    }

    // Condicional si apreto 4
    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS && !tecla4Presionada)
    {
        tecla4Presionada = true;

        if (CuboRotacion == true)
        {
            cout << "se apreto  4 Q" << endl;
            Opcion=4;
            RotacionPiso=true;
            RotacionPlano=false;
            cubo->GirarPiso(4);
            cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
        else
        {
            cout << "se apreto  4 E" << endl;
            Opcion=4;
            RotacionPiso=false;
            RotacionPlano=true;
            cubo->GirarPlano(4);
            cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
    }

    // Condicional si apreto 5
    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS && !tecla5Presionada)
    {
        tecla5Presionada = true;

        if (CuboRotacion == true)
        {
            cout << "se apreto  5 Q" << endl;
            Opcion=5;
            RotacionPiso=true;
            RotacionPlano=false;
            cubo->GirarPiso(5);
            cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
        else
        {
            cout << "se apreto  5 E" << endl;
            Opcion=5;
            RotacionPiso=false;
            RotacionPlano=true;
            cubo->GirarPlano(5);
            cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
    }

    // Condicional si apreto 6
    if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS && !tecla6Presionada)
    {
        tecla6Presionada = true;

        if (CuboRotacion == true)
        {
            cout << "se apreto  6 Q" << endl;
            Opcion=6;
            RotacionPiso=true;
            RotacionPlano=false;
            cubo->GirarPiso(6);
            cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
        else
        {
            cout << "se apreto  6 E" << endl;
            Opcion=6;
            RotacionPiso=false;
            RotacionPlano=true;
            cubo->GirarPlano(6);
            cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
    }
    //condicional si apreto 9
    if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS)
    {
        cubo->ImprimirTodasLasMatrices();
        cubo->imprimirCubos();
    }

    // ...

    // Reiniciar el estado de las variables cuando se suelta la tecla correspondiente

    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_RELEASE)
    {
        qPresionado = false;
    }

    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_RELEASE)
    {
        ePresionado = false;
    }

    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_RELEASE)
    {
        tecla1Presionada = false;
    }

    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_RELEASE)
    {
        tecla2Presionada = false;
    }

    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_RELEASE)
    {
        tecla3Presionada = false;
    }

    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_RELEASE)
    {
        tecla4Presionada = false;
    }

    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_RELEASE)
    {
        tecla5Presionada = false;
    }

    if (glfwGetKey(window, GLFW_KEY_6) == GLFW_RELEASE)
    {
        tecla6Presionada = false;
    }
}
