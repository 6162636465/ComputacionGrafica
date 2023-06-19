//javierAlvarezReyes
//Pablo cesar Yucra
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
struct MatrixHandler
{
    std::vector<std::vector<float>> matrizIdentidad = {
        {1,0,0}
        ,{0,1,0}
        ,{0,0,1}
    };
    std::vector<std::vector<float>> matrizIdentidadB = {
        {1,0,0}
        ,{0,1,0}
        ,{0,0,1}
    };
    std::vector<std::vector<float>> resultadoMultiplicacion = {
        {0,0,0}
        ,{0,0,0}
        ,{0,0,0}
    };

    std::vector<std::vector<float>> matrizTransformar = {
        {0}
        ,{0}
        ,{1}
    };

    std::vector<std::vector<float>> resultado = {
        {0}
        ,{0}
        ,{0}
    };
    void resetearMatrices()
    {
        matrizIdentidad = {
        {1,0,0}
        ,{0,1,0}
        ,{0,0,1}
        };
        matrizIdentidadB = {
        {1,0,0}
        ,{0,1,0}
        ,{0,0,1}
        };
        matrizTransformar = {
        {0}
        ,{0}
        ,{1}
        };
        resultado = {
        {0}
        ,{0}
        ,{0}
        };

    }


    std::vector<std::vector<float>> crearEstructura()
    {
        return resultado;
    }


    //_______________________________________________________PARA_matrizIdentidad_______
    void identidadTraslacion(float x, float y)
    {
        matrizIdentidad[0][2] = x;
        matrizIdentidad[1][2] = y;
    }

    void identidadRotacion(float angulo) {
        const float PI = 3.14159;
        float rad = angulo * PI / 180;
        float cosAng = std::cos(rad);
        float sinAng = std::sin(rad);

        matrizIdentidad[0][0] = cosAng;
        matrizIdentidad[0][1] = -sinAng;
        matrizIdentidad[1][0] = sinAng;
        matrizIdentidad[1][1] = cosAng;
    }

    void identidadEscala(float x, float y)
    {
        matrizIdentidad[0][0] = x;
        matrizIdentidad[1][1] = y;
    }
    //_______________________________________________________PARA_matrizIdentidadB_______

    void identidadTraslacionB(float x, float y)
    {
        matrizIdentidadB[0][2] = x;
        matrizIdentidadB[1][2] = y;
    }

    void identidadRotacionB(float angulo) {
        const float PI = 3.141592;
        float rad = angulo * PI / 180;
        float cosAng = std::cos(rad);
        float sinAng = std::sin(rad);

        matrizIdentidadB[0][0] = cosAng;
        matrizIdentidadB[0][1] = -sinAng;
        matrizIdentidadB[1][0] = sinAng;
        matrizIdentidadB[1][1] = cosAng;
    }

    void identidadEscalaB(float x, float y)
    {
        matrizIdentidadB[0][0] = x;
        matrizIdentidadB[1][1] = y;
    }

    //________________________________________________________________________
    void imprimirMatriz(string opcion) {
        if (opcion == "A") {

            std::cout << "Matriz A (Identidad):" << std::endl;
            for (const auto& row : matrizIdentidad) {
                for (float element : row) {
                    std::cout << element << " ";
                }
                std::cout << std::endl;
            }
        }
        else if (opcion == "E") {

            std::cout << "Matriz A (identidad2):" << std::endl;
            for (const auto& row : matrizIdentidadB) {
                for (float element : row) {
                    std::cout << element << " ";
                }
                std::cout << std::endl;
            }
        }
        else if (opcion == "B") {

            std::cout << "Matriz B (Transformar):" << std::endl;
            for (const auto& row : matrizTransformar) {
                for (float element : row) {
                    std::cout << element << " ";
                }
                std::cout << std::endl;
            }
        }
        else if (opcion == "C") {

            std::cout << "Matriz C (Resultado):" << std::endl;
            for (const auto& row : resultado) {
                for (float element : row) {
                    std::cout << element << " ";
                }
                std::cout << std::endl;
            }
            // Imprimir matriz resultado (vacía en este caso)
        }
        else if (opcion == "D") {

            std::cout << "Matriz resultadoMULT:" << std::endl;
            for (const auto& row : resultadoMultiplicacion) {
                for (float element : row) {
                    std::cout << element << " ";
                }
                std::cout << std::endl;
            }
            // Imprimir matriz resultado (vacía en este caso)
        }
        else {
            std::cout << "Opción inválida. Por favor, elija A, B o C." << std::endl;
        }
    }
    //______________________________________________________________________________________
    void multiplicarMatricesFinal()
    {
        for (size_t i = 0; i < resultadoMultiplicacion.size(); i++) {
            for (size_t j = 0; j < matrizTransformar[0].size(); j++) {
                for (size_t k = 0; k < resultadoMultiplicacion[0].size(); k++) {
                    resultado[i][j] += resultadoMultiplicacion[i][k] * matrizTransformar[k][j];
                }
            }
        }
    }
    //_____________________________________________________________________________________
    void multiplicarMatricesGlobales()
    {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    resultadoMultiplicacion[i][j] += matrizIdentidad[i][k] * matrizIdentidadB[k][j];

                    cout << "multA :" << matrizIdentidadB[i][k] << " |multB:" << matrizIdentidad[k][j] << endl;
                }
                cout << "resultadoFinal :" << resultadoMultiplicacion[i][j] << endl;
            }
        }
    }
    //_________________________________________________________________________________
    void multiplicarMatricesResultado()
    {
        for (size_t i = 0; i < resultadoMultiplicacion.size(); i++) {
            for (size_t j = 0; j < matrizTransformar[0].size(); j++) {
                for (size_t k = 0; k < resultadoMultiplicacion[0].size(); k++) {
                    resultado[i][j] += resultadoMultiplicacion[i][k] * matrizTransformar[k][j];
                }
            }
        }
    }
    //_____________________________________________________________________________________
    void multiplicarMatrices()
    {
        for (size_t i = 0; i < matrizIdentidad.size(); i++) {
            for (size_t j = 0; j < matrizTransformar[0].size(); j++) {
                for (size_t k = 0; k < matrizIdentidad[0].size(); k++) {
                    resultado[i][j] += matrizIdentidad[i][k] * matrizTransformar[k][j];
                }
            }
        }
    }
    //_____________________________________________________________________________________
    void elementoModificar(float x, float y) {
        // Modificar la matriz en sus respectivos lugares
        matrizTransformar[0][0] = x;
        matrizTransformar[1][0] = y;
    }
    //_____________________________________________________________________________________
    void trasladar2D(float trasladarx, float trasladarY, float X, float Y)
    {
        identidadTraslacion(trasladarx, trasladarY);
        //imprimirMatriz("A");
        elementoModificar(X, Y);
        //imprimirMatriz("B");
        multiplicarMatrices();
        imprimirMatriz("C");

    }
    void rotar2D(float angulo, float X, float Y)
    {
        identidadRotacion(angulo);
        imprimirMatriz("A");
        elementoModificar(X, Y);
        imprimirMatriz("B");
        multiplicarMatrices();
        imprimirMatriz("C");

    }
    void escala2D(float trasladarx, float trasladarY, float X, float Y)
    {
        identidadEscala(trasladarx, trasladarY);
        imprimirMatriz("A");
        elementoModificar(X, Y);
        imprimirMatriz("B");
        multiplicarMatrices();
        imprimirMatriz("C");

    }
    void trasladarRotar(float trasladarx, float trasladarY, float X, float Y, float angulo)
    {
        identidadTraslacion(trasladarx, trasladarY);
        identidadRotacionB(angulo);
        elementoModificar(X, Y);
        imprimirMatriz("A");
        imprimirMatriz("E");
        multiplicarMatricesGlobales();
        imprimirMatriz("D");

        imprimirMatriz("B");

        multiplicarMatricesResultado();
        //multiplicarMatricesFinal();
        imprimirMatriz("C");
    }
    //______________________________________________________aca funciones para 3d______________________________
    std::vector<std::vector<float>> matrizIdentidad3D = {
        {1,0,0,0}
        ,{0,1,0,0}
        ,{0,0,1,0}
        ,{0,0,0,1}
    };
    std::vector<std::vector<float>> matrizIdentidadB3D = {
        {1,0,0,0}
        ,{0,1,0,0}
        ,{0,0,1,0}
        ,{0,0,0,1}
    };
    std::vector<std::vector<float>> resultadoMultiplicacion3D = {
        {0,0,0,0}
        ,{0,0,0,0}
        ,{0,0,0,0}
        ,{0,0,0,0}
    };

    std::vector<std::vector<float>> matrizTransformar3D = {
        {0}
        ,{0}
        ,{1}
        ,{1}
    };

    std::vector<std::vector<float>> resultado3D = {
        {0}
        ,{0}
        ,{0}
        ,{1}
    };
    std::vector<std::vector<float>> resultadoMultiplicacion3DMatrices =
    {
        {0,0,0,0}
        ,{0,0,0,0}
        ,{0,0,0,0}
        ,{0,0,0,0}
    };
    std::vector<std::vector<float>> crearEstructura3D()
    {
        return resultado3D;
    }
    void resetearMatrices3D()
    {
        std::vector<std::vector<float>> matrizIdentidad3D = {
        {1,0,0,0}
        ,{0,1,0,0}
        ,{0,0,1,0}
        ,{0,0,0,1}
        };
        matrizIdentidadB3D = {
            {1,0,0,0}
            ,{0,1,0,0}
            ,{0,0,1,0}
            ,{0,0,0,1}
        };
        resultadoMultiplicacion3D = {
            {0,0,0,0}
            ,{0,0,0,0}
            ,{0,0,0,0}
            ,{0,0,0,0}
        };

        matrizTransformar3D = {
            {0}
            ,{0}
            ,{1}
            ,{1}
        };

        resultado3D = {
            {0}
            ,{0}
            ,{0}
            ,{1}
        };
        resultadoMultiplicacion3DMatrices =
        {
            {0,0,0,0}
            ,{0,0,0,0}
            ,{0,0,0,0}
            ,{0,0,0,0}
        };
    }

    //_________________________________TRASLACION3D______________________
    void identidadTraslacion3D(std::vector<std::vector<float>>& matrizIdentidadB3D, float x, float y, float z)
    {
        // Comprobamos si la matriz de traslación tiene el tamaño correcto
        if (matrizIdentidadB3D.size() != 4 || matrizIdentidadB3D[0].size() != 4) {
            // La matriz no es de tamaño 4x4, no podemos realizar la operación
            return;
        }

        // Realizamos la identidad de traslación
        matrizIdentidadB3D[0][3] = x;
        matrizIdentidadB3D[1][3] = y;
        matrizIdentidadB3D[2][3] = z;
    }
    void identidadEscala3D(std::vector<std::vector<float>>& matrizIdentidadEscala3D, float scaleX, float scaleY, float scaleZ) {
        // Comprobamos si la matriz de escala tiene el tamaño correcto
        if (matrizIdentidadEscala3D.size() != 4 || matrizIdentidadEscala3D[0].size() != 4) {
            // La matriz no es de tamaño 4x4, no podemos realizar la operación
            return;
        }

        // Realizamos la identidad de escala
        matrizIdentidadEscala3D[0][0] = scaleX;
        matrizIdentidadEscala3D[1][1] = scaleY;
        matrizIdentidadEscala3D[2][2] = scaleZ;
    }
    void identidad3DRotacion(std::vector<std::vector<float>>& matriz, float angulo, const std::string& opcion) {
        // Comprobamos si la matriz tiene el tamaño correcto
        if (matriz.size() != 4 || matriz[0].size() != 4) {
            // La matriz no es de tamaño 4x4, no podemos realizar la operación
            return;
        }

        // Convertimos el ángulo a radianes
        float radianes = angulo * 3.14159 / 180.0f;

        // Realizamos la identidad según la opción especificada
        if (opcion == "X") {
            matriz[1][1] = cos(radianes);
            matriz[1][2] = -sin(radianes);
            matriz[2][1] = sin(radianes);
            matriz[2][2] = cos(radianes);
        }
        else if (opcion == "Y") {
            matriz[0][0] = cos(radianes);
            matriz[0][2] = sin(radianes);
            matriz[2][0] = -sin(radianes);
            matriz[2][2] = cos(radianes);
        }
        else if (opcion == "Z") {
            matriz[0][0] = cos(radianes);
            matriz[0][1] = -sin(radianes);
            matriz[1][0] = sin(radianes);
            matriz[1][1] = cos(radianes);
        }
    }
    void multiplicar3D(const std::vector<std::vector<float>>& matriz1, const std::vector<std::vector<float>>& matriz2) {
        // Verificar que las dimensiones de las matrices sean correctas
        if (matriz1.size() != 4 || matriz1[0].size() != 4 || matriz2.size() != 4 || matriz2[0].size() != 1 || resultado3D.size() != 4 || resultado3D[0].size() != 1) {
            std::cout << "Error: Las dimensiones de las matrices no son correctas." << std::endl;
            return;
        }

        // Realizar la multiplicación de matrices
        for (int i = 0; i < 4; i++) {
            float sum = 0.0;
            for (int j = 0; j < 4; j++) {
                sum += matriz1[i][j] * matriz2[j][0];
            }
            resultado3D[i][0] = sum;
        }
    }
    //esta funcion guardara en resultadoMultiplicacion3DMatrices el resultado de la multiplicacion de las matrices
    void multiplicar2matricesTransformacion(const std::vector<std::vector<float>>& matriz1, const std::vector<std::vector<float>>& matriz2)
    {
        // Verificar que las dimensiones de las matrices sean correctas
        if (matriz1.size() != 4 || matriz1[0].size() != 4 || matriz2.size() != 4 || matriz2[0].size() != 4 || resultadoMultiplicacion3DMatrices.size() != 4 || resultadoMultiplicacion3DMatrices[0].size() != 4) {
            std::cout << "Error: Las dimensiones de las matrices no son correctas." << std::endl;
            return;
        }

        // Realizar la multiplicación de matrices
        for (int i = 0; i < 4; i++) {
            float sum = 0.0;
            for (int j = 0; j < 4; j++) {
                sum += matriz1[i][j] * matriz2[j][0];
            }
            resultadoMultiplicacion3DMatrices[i][0] = sum;
        }
    }
    void imprimirMatriz3D(const std::vector<std::vector<float>>& matriz) {
        for (const auto& fila : matriz) {
            for (const auto& elemento : fila) {
                std::cout << elemento << " ";
            }
            std::cout << std::endl;
        }
    }
    void elementoModificar3D(float x, float y, float z) {
        // Modificar la matriz en sus respectivos lugares
        matrizTransformar3D[0][0] = x;
        matrizTransformar3D[1][0] = y;
        matrizTransformar3D[2][0] = z;
    }
    //____________________________________________________________FUNCIONES PARA LAS OPERACIONES___________________
    void trasladar3D(float trasladarx, float trasladarY, float trasladarZ, float X, float Y, float Z)
    {
        identidadTraslacion3D(matrizIdentidad3D, trasladarx, trasladarY, trasladarZ);
        //imprimirMatriz3D(matrizIdentidad3D);
        elementoModificar3D(X, Y, Z);
        //imprimirMatriz3D(matrizTransformar3D);
        multiplicar3D(matrizIdentidad3D, matrizTransformar3D);
        //cout << "resultado" << endl;
       // imprimirMatriz3D(resultado3D);

    }
    void Rotacion3D(float angulo, float X, float Y, float Z, string opcion)
    {
        identidad3DRotacion(matrizIdentidad3D, angulo, opcion);
        //imprimirMatriz3D(matrizIdentidad3D);
        elementoModificar3D(X, Y, Z);
        //imprimirMatriz3D(matrizTransformar3D);
        multiplicar3D(matrizIdentidad3D, matrizTransformar3D);
        //cout << "resultado" << endl;
        //imprimirMatriz3D(resultado3D);

    }
    void Escala3D(float trasladarx, float trasladarY, float trasladarZ, float X, float Y, float Z)
    {
        //identidadEscala3D(matrizIdentidad3D, trasladarx, trasladarY, trasladarZ);
        //imprimirMatriz3D(matrizIdentidad3D);
        elementoModificar3D(X, Y, Z);
        multiplicar3D(matrizIdentidad3D, matrizTransformar3D);
        //imprimirMatriz3D(resultado3D);

    }
    void trasladarRotar3D(float trasladarx, float trasladarY, float trasladarZ, float X, float Y, float Z, float angulo, string opcion)
    {
        identidadTraslacion3D(matrizIdentidad3D, trasladarx, trasladarY, trasladarZ);
        identidad3DRotacion(matrizIdentidadB3D, angulo, opcion);
        elementoModificar3D(X, Y, Z);
        //imprimirMatriz3D(matrizIdentidad3D);
        //imprimirMatriz3D(matrizIdentidadB3D);
        multiplicar2matricesTransformacion(matrizIdentidad3D, matrizIdentidadB3D);
        multiplicar3D(resultadoMultiplicacion3DMatrices, matrizTransformar3D);
        //imprimirMatriz3D(resultado3D);
    }
};