//javierAlvarezReyes
//Pablo cesar Yucra
#include <string>
#include <vector>
#include "matricesEscalaRotacionTraslacion.h"
#include <map>
#include <cstring>
#include <iostream>
using namespace std;



class Cubo
{
    public:
        std::map<int, std::pair<float*, unsigned int*>> Cubos;
        std::vector<std::vector<float>> igualarResultado;

    //prueba Condicion
        int condicion = 0;
    //funcion que reciba un int y sume a condicion
        void sumarCondicion(int condicionsuma)
        {
            condicion = condicion + condicionsuma;
            cout << "condicion: " << condicion << endl;
        }
   //______________traslacionPlano___________
    //plano1
    int Plano1[3][3] = {
            {8,7,6},
            {5,4,3},
            {2,1,0}
    };
     //plano1
    int Plano2[3][3] = {
        {17,16,15},
        {14,13,12},
        {11,10,9}
    };
    //plano1
    int Plano3[3][3] = {
        {26,25,24},
        {23,22,21},
        {20,19,18}
    };

    //______________traslacionPISO___________
    //piso1
    int Piso1[3][3] = {
        {20,19,18},
        {11,10,9},
        {2,1,0}
    };
    //piso2
    int Piso2[3][3] = {
        {23,22,21},
        {14,13,12},
        {5,4,3}
    };
    //piso3
    int Piso3[3][3] = {
        {26,25,24},
        {17,16,15},
        {8,7,6}
    };
    //____________________________________certices Temp
    float* TempVertices= new float[24] {-0.107f,-0.313f,-0.311f,-0.107f,-0.113f,-0.311f,-0.307f,-0.113f,-0.311f,-0.307f,-0.313f,-0.311f,-0.107f,-0.313f,-0.11f,-0.107f,-0.113f,-0.11f,-0.307f,-0.313f,-0.11f,-0.307f,-0.113f,-0.11f};
    float* TempVertices2= new float[24] {0.103f,-0.313f,-0.311f,0.103f,-0.113f,-0.311f,-0.097f,-0.113f,-0.311f,-0.097f,-0.313f,-0.311f,0.103f,-0.313f,-0.11f,0.103f,-0.113f,-0.11f,-0.097f,-0.313f,-0.11f,-0.097f,-0.113f,-0.11f};
    float* TempVertices3= new float[24] {0.313f,-0.313f,-0.311f,0.313f,-0.113f,-0.311f,0.113f,-0.113f,-0.311f,0.113f,-0.313f,-0.311f,0.313f,-0.313f,-0.11f,0.313f,-0.113f,-0.11f,0.113f,-0.313f,-0.11f,0.113f,-0.113f,-0.11f};
    float* TempVertices4= new float[24] {-0.107f,-0.103f,-0.311f,-0.107f,0.097f,-0.311f,-0.307f,0.097f,-0.311f,-0.307f,-0.103f,-0.311f,-0.107f,-0.103f,-0.11f,-0.107f,0.097f,-0.11f,-0.307f,-0.103f,-0.11f,-0.307f,0.097f,-0.11f};
    float* TempVertices5= new float[24] {0.103f,-0.103f,-0.311f,0.103f,0.097f,-0.311f,-0.097f,0.097f,-0.311f,-0.097f,-0.103f,-0.311f,0.103f,-0.103f,-0.11f,0.103f,0.097f,-0.11f,-0.097f,-0.103f,-0.11f,-0.097f,0.097f,-0.11f};
    float* TempVertices6= new float[24] {0.313f,-0.103f,-0.311f,0.313f,0.097f,-0.311f,0.113f,0.097f,-0.311f,0.113f,-0.103f,-0.311f,0.313f,-0.103f,-0.11f,0.313f,0.097f,-0.11f,0.113f,-0.103f,-0.11f,0.113f,0.097f,-0.11f};
    float* TempVertices7= new float[24] {-0.107f,0.107f,-0.311f,-0.107f,0.307f,-0.311f,-0.307f,0.307f,-0.311f,-0.307f,0.107f,-0.311f,-0.107f,0.107f,-0.11f,-0.107f,0.307f,-0.11f,-0.307f,0.107f,-0.11f,-0.307f,0.307f,-0.11f};
    float* TempVertices8= new float[24] {0.103f,0.107f,-0.311f,0.103f,0.307f,-0.311f,-0.097f,0.307f,-0.311f,-0.097f,0.107f,-0.311f,0.103f,0.107f,-0.11f,0.103f,0.307f,-0.11f,-0.097f,0.107f,-0.11f,-0.097f,0.307f,-0.11f};
    float* TempVertices9= new float[24] {0.313f,0.107f,-0.311f,0.313f,0.307f,-0.311f,0.113f,0.307f,-0.311f,0.113f,0.107f,-0.311f,0.313f,0.107f,-0.11f,0.313f,0.307f,-0.11f,0.113f,0.107f,-0.11f,0.113f,0.307f,-0.11f};
    float* TempVertices10= new float[24] {-0.107f,-0.313f,-0.101f,-0.107f,-0.113f,-0.101f,-0.307f,-0.113f,-0.101f,-0.307f,-0.313f,-0.101f,-0.107f,-0.313f,0.1f,-0.107f,-0.113f,0.1f,-0.307f,-0.313f,0.1f,-0.307f,-0.113f,0.1f};
    float* TempVertices11= new float[24] {0.103f,-0.313f,-0.101f,0.103f,-0.113f,-0.101f,-0.097f,-0.113f,-0.101f,-0.097f,-0.313f,-0.101f,0.103f,-0.313f,0.1f,0.103f,-0.113f,0.1f,-0.097f,-0.313f,0.1f,-0.097f,-0.113f,0.1f};
    float* TempVertices12= new float[24] {0.313f,-0.313f,-0.101f,0.313f,-0.113f,-0.101f,0.113f,-0.113f,-0.101f,0.113f,-0.313f,-0.101f,0.313f,-0.313f,0.1f,0.313f,-0.113f,0.1f,0.113f,-0.313f,0.1f,0.113f,-0.113f,0.1f};
    float* TempVertices13= new float[24] {-0.107f,-0.103f,-0.101f,-0.107f,0.097f,-0.101f,-0.307f,0.097f,-0.101f,-0.307f,-0.103f,-0.101f,-0.107f,-0.103f,0.1f,-0.107f,0.097f,0.1f,-0.307f,-0.103f,0.1f,-0.307f,0.097f,0.1f};
    float* TempVertices14= new float[24] {0.103f,-0.103f,-0.101f,0.103f,0.097f,-0.101f,-0.097f,0.097f,-0.101f,-0.097f,-0.103f,-0.101f,0.103f,-0.103f,0.1f,0.103f,0.097f,0.1f,-0.097f,-0.103f,0.1f,-0.097f,0.097f,0.1f};
    float* TempVertices15= new float[24] {0.313f,-0.103f,-0.101f,0.313f,0.097f,-0.101f,0.113f,0.097f,-0.101f,0.113f,-0.103f,-0.101f,0.313f,-0.103f,0.1f,0.313f,0.097f,0.1f,0.113f,-0.103f,0.1f,0.113f,0.097f,0.1f};
    float* TempVertices16= new float[24] {-0.107f,0.107f,-0.101f,-0.107f,0.307f,-0.101f,-0.307f,0.307f,-0.101f,-0.307f,0.107f,-0.101f,-0.107f,0.107f,0.1f,-0.107f,0.307f,0.1f,-0.307f,0.107f,0.1f,-0.307f,0.307f,0.1f};
    float* TempVertices17= new float[24] {0.103f,0.107f,-0.101f,0.103f,0.307f,-0.101f,-0.097f,0.307f,-0.101f,-0.097f,0.107f,-0.101f,0.103f,0.107f,0.1f,0.103f,0.307f,0.1f,-0.097f,0.107f,0.1f,-0.097f,0.307f,0.1f};
    float* TempVertices18= new float[24] {0.313f,0.107f,-0.101f,0.313f,0.307f,-0.101f,0.113f,0.307f,-0.101f,0.113f,0.107f,-0.101f,0.313f,0.107f,0.1f,0.313f,0.307f,0.1f,0.113f,0.107f,0.1f,0.113f,0.307f,0.1f};
    float* TempVertices19= new float[24] {-0.107f,-0.313f,0.109f,-0.107f,-0.113f,0.109f,-0.307f,-0.113f,0.109f,-0.307f,-0.313f,0.109f,-0.107f,-0.313f,0.31f,-0.107f,-0.113f,0.31f,-0.307f,-0.313f,0.31f,-0.307f,-0.113f,0.31f};
    float* TempVertices20= new float[24] {0.103f,-0.313f,0.109f,0.103f,-0.113f,0.109f,-0.097f,-0.113f,0.109f,-0.097f,-0.313f,0.109f,0.103f,-0.313f,0.31f,0.103f,-0.113f,0.31f,-0.097f,-0.313f,0.31f,-0.097f,-0.113f,0.31f};
    float* TempVertices21= new float[24] {0.313f,-0.313f,0.109f,0.313f,-0.113f,0.109f,0.113f,-0.113f,0.109f,0.113f,-0.313f,0.109f,0.313f,-0.313f,0.31f,0.313f,-0.113f,0.31f,0.113f,-0.313f,0.31f,0.113f,-0.113f,0.31f};
    float* TempVertices22= new float[24] {-0.107f,-0.103f,0.109f,-0.107f,0.097f,0.109f,-0.307f,0.097f,0.109f,-0.307f,-0.103f,0.109f,-0.107f,-0.103f,0.31f,-0.107f,0.097f,0.31f,-0.307f,-0.103f,0.31f,-0.307f,0.097f,0.31f};
    float* TempVertices23= new float[24] {0.103f,-0.103f,0.109f,0.103f,0.097f,0.109f,-0.097f,0.097f,0.109f,-0.097f,-0.103f,0.109f,0.103f,-0.103f,0.31f,0.103f,0.097f,0.31f,-0.097f,-0.103f,0.31f,-0.097f,0.097f,0.31f};
    float* TempVertices24= new float[24] {0.313f,-0.103f,0.109f,0.313f,0.097f,0.109f,0.113f,0.097f,0.109f,0.113f,-0.103f,0.109f,0.313f,-0.103f,0.31f,0.313f,0.097f,0.31f,0.113f,-0.103f,0.31f,0.113f,0.097f,0.31f};
    float* TempVertices25= new float[24] {-0.107f,0.107f,0.109f,-0.107f,0.307f,0.109f,-0.307f,0.307f,0.109f,-0.307f,0.107f,0.109f,-0.107f,0.107f,0.31f,-0.107f,0.307f,0.31f,-0.307f,0.107f,0.31f,-0.307f,0.307f,0.31f};
    float* TempVertices26= new float[24] {0.103f,0.107f,0.109f,0.103f,0.307f,0.109f,-0.097f,0.307f,0.109f,-0.097f,0.107f,0.109f,0.103f,0.107f,0.31f,0.103f,0.307f,0.31f,-0.097f,0.107f,0.31f,-0.097f,0.307f,0.31f};
    float* TempVertices27= new float[24] {0.313f,0.107f,0.109f,0.313f,0.307f,0.109f,0.113f,0.307f,0.109f,0.113f,0.107f,0.109f,0.313f,0.107f,0.31f,0.313f,0.307f,0.31f,0.113f,0.107f,0.31f,0.113f,0.307f,0.31f};

    //_______________Tenpmatrices____________________
    //aser matrices temp de pisos y planos
    int PisoTemp[3][3];
    int PisoTemp2[3][3];
    int PisoTemp3[3][3];
    int PlanoTemp1[3][3];
    int PlanoTemp2[3][3];
    int PlanoTemp3[3][3];
    //_______________________________________________________________
    void imprimirMatriz(const int matriz[3][3]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << matriz[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    void funcionTransform(int matrizA[3][3], int matrizB[3][3], int valorA, int valorB) {
        // Reemplazar la fila de matrizA con la fila de matrizB
        for (int i = 0; i < 3; i++) {
            matrizA[valorA][i] = matrizB[valorB][i];
        }
    }
    void rotarMatriz(int matriz[3][3])
     {
        int matrizRotada[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrizRotada[j][2 - i] = matriz[i][j];
            }
        }

        // Copiar la matriz rotada a la matriz original
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matriz[i][j] = matrizRotada[i][j];
            }
        }
    }
    void rotarMatrizInversa(int matriz[3][3]) {
        int matrizRotada[3][3];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrizRotada[2 - j][i] = matriz[i][j]; // Girar en la dirección opuesta
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matriz[i][j] = matrizRotada[i][j];
            }
        }
    }
    float* obtenerVertices(int ID) {
        auto it = Cubos.find(ID);
        if (it != Cubos.end()) {
            return it->second.first;
        }
        else {
            return nullptr;
        }
    }
    //___________________________
    void ActualizarVertices(int key, float* vertices) 
    {
        auto it = Cubos.find(key);
        if (it != Cubos.end()) 
        {
            it->second.first = vertices;
            std::cout<<key << "," <<it->second.first <<std::endl;
        } else 
        {
            std::cout << "No se encontró la clave en el mapa." << std::endl;
        }
    }

        void modificarTraslacion3D(float* vertices2, int numVertices, float trasladarX, float trasladarY, float trasladarZ)
        {
            for (int i = 0; i < numVertices; i++)
            {
                MatrixHandler mh;
                float x, y, z;
                x = vertices2[i * 3];
                y = vertices2[i * 3 + 1];
                z = vertices2[i * 3 + 2];

                mh.trasladar3D(trasladarX, trasladarY, trasladarZ, x, y, z);
                igualarResultado = mh.crearEstructura3D();
                mh.resetearMatrices3D();

                vertices2[i * 3] = igualarResultado[0][0];
                vertices2[i * 3 + 1] = igualarResultado[1][0];
                vertices2[i * 3 + 2] = igualarResultado[2][0];

                if ((i * 3 + 2) >= numVertices - 1)
                {
                    break;
                }
            }
        }
        void modificarRotacionTraslacion(float* vertices2, int numVertices, float trasladarX, float trasladarY, float trasladarZ,string opcionRotacion,float angulo)
        {
            for (int i = 0; i < numVertices; i++)
            {
                MatrixHandler mh;
                float x, y, z;
                x = vertices2[i * 3];
                y = vertices2[i * 3 + 1];
                z = vertices2[i * 3 + 2];
                mh.trasladarRotar3D(trasladarX, trasladarY, trasladarZ, x, y, z,angulo,opcionRotacion);
                igualarResultado = mh.crearEstructura3D();
                mh.resetearMatrices3D();

                vertices2[i * 3] = igualarResultado[0][0];
                vertices2[i * 3 + 1] = igualarResultado[1][0];
                vertices2[i * 3 + 2] = igualarResultado[2][0];

                if ((i * 3 + 2) >= numVertices - 1)
                {
                    break;
                }
            }
        }
        void ModificarRotacion3D(float* vertices2, int numVertices,  string opcionRotacion, float angulo)
        {
            for (int i = 0; i < numVertices; i++)
            {
                MatrixHandler mh;
                float x, y, z;
                x = vertices2[i * 3];
                y = vertices2[i * 3 + 1];
                z = vertices2[i * 3 + 2];
                mh.Rotacion3D(angulo, x, y, z, opcionRotacion);
                igualarResultado = mh.crearEstructura3D();
                mh.resetearMatrices3D();

                vertices2[i * 3] = igualarResultado[0][0];
                vertices2[i * 3 + 1] = igualarResultado[1][0];
                vertices2[i * 3 + 2] = igualarResultado[2][0];

                if ((i * 3 + 2) >= numVertices - 1)
                {
                    break;
                }
            }
        }
        //_____________________________________________________________________________________________________________________
        //_____________________________________________________________________________________________________________________
        void interpolacionCircular(float* vertices, int numVertices, float puntoMedioX, float puntoMedioY, float angulo) 
        {
            ModificarRotacion3D(vertices, numVertices, "Z", -1.0f);
        }
        
        void interpolacionCircularPlanos(float* vertices, int numVertices, float puntoMedioX, float puntoMedioY, float angulo) 
        {
            ModificarRotacion3D(vertices, numVertices, "Y", -1.0f);
        }
        void interpolacionCircularB(float* vertices, int numVertices, float puntoMedioX, float puntoMedioY, float angulo) 
        {
            ModificarRotacion3D(vertices, numVertices, "Z", 1.0f);
        }
        void interpolacionCircularPlanoB(float* vertices, int numVertices, float puntoMedioX, float puntoMedioY, float angulo) 
        {
            ModificarRotacion3D(vertices, numVertices, "Y", 1.0f);
        }
        //_____________________________________________________________________________________________________________________
        void ImprimirTodasLasMatrices()
        {
            cout<<"Plano1"<<endl;
            imprimirMatriz(Plano1);
            cout<<"Plano2"<<endl;
            imprimirMatriz(Plano2);
            cout<<"Plano3"<<endl;
            imprimirMatriz(Plano3);
            cout<<"Piso1"<<endl;
            imprimirMatriz(Piso1);
            cout<<"Piso2"<<endl;
            imprimirMatriz(Piso2);
            cout<<"Piso3"<<endl;
            imprimirMatriz(Piso3);
            cout<<"__________________________"<<endl;
        }
        //_____________________________________________________________________________________________________________________
        
        void interpolacionCircularPlano(int PlanoModifico[3][3],bool condion) 
        {
            if (condion==true)
            {
                //cout<<"entro a la condicion verdadera"<<endl;
                // Valor del punto medio en x , y
                float puntoMedioX = 0.22f;
                float puntoMedioY = 0.31f;
                //igualar los 8 vertices de int matrizA[3][3]
                int cubo5 = PlanoModifico[1][1];
                float* verticesUsoPlano5 = obtenerVertices(cubo5);
                interpolacionCircular(verticesUsoPlano5, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo1 = PlanoModifico[0][0];
                float* verticesUsoPlano1 = obtenerVertices(cubo1);
                interpolacionCircular(verticesUsoPlano1, 24, puntoMedioX, puntoMedioY, 90.0f);
                
                int cubo2 = PlanoModifico[0][1];
                float* verticesUsoPlano2 = obtenerVertices(cubo2);
                interpolacionCircular(verticesUsoPlano2, 24, puntoMedioX, puntoMedioY, 90.0f);
                int cubo3 = PlanoModifico[0][2];
                float* verticesUsoPlano3 = obtenerVertices(cubo3);
                interpolacionCircular(verticesUsoPlano3, 24, puntoMedioX, puntoMedioY, 90.0f);
                int cubo4 = PlanoModifico[1][0];
                float* verticesUsoPlano4 = obtenerVertices(cubo4);
                interpolacionCircular(verticesUsoPlano4, 24, puntoMedioX, puntoMedioY, 90.0f);
                //int cubo5 = PlanoModifico[1][1];
                int cubo6 = PlanoModifico[1][2];
                float* verticesUsoPlano6 = obtenerVertices(cubo6);
                interpolacionCircular(verticesUsoPlano6, 24, puntoMedioX, puntoMedioY, 90.0f);
                int cubo7 = PlanoModifico[2][0];
                float* verticesUsoPlano7 = obtenerVertices(cubo7);
                interpolacionCircular(verticesUsoPlano7, 24, puntoMedioX, puntoMedioY, 90.0f);
                int cubo8 = PlanoModifico[2][1];
                float* verticesUsoPlano8 = obtenerVertices(cubo8);
                interpolacionCircular(verticesUsoPlano8, 24, puntoMedioX, puntoMedioY, 90.0f);
                int cubo9 = PlanoModifico[2][2];
                float* verticesUsoPlano9 = obtenerVertices(cubo9);
                interpolacionCircular(verticesUsoPlano9, 24, puntoMedioX, puntoMedioY, 90.0f);
                //cout<<"se esta moviendo estos cubos :"<<cubo1<<","<<cubo2<<","<<cubo3<<","<<cubo4<<","<<cubo6<<","<<cubo7<<","<<cubo8<<","<<cubo9<<endl;
            }
            else if(condion==false)
            {
                //cout<<"entro a la condicion falsa"<<endl;   
                // Valor del punto medio en x , y
                float puntoMedioX = 0.22f;
                float puntoMedioY = 0.31f;

                int cubo1 = PlanoModifico[0][0];
                float* verticesUsoPlano1 = obtenerVertices(cubo1);
                interpolacionCircularB(verticesUsoPlano1, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo2 = PlanoModifico[0][1];
                float* verticesUsoPlano2 = obtenerVertices(cubo2);
                interpolacionCircularB(verticesUsoPlano2, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo3 = PlanoModifico[0][2];
                float* verticesUsoPlano3 = obtenerVertices(cubo3);
                interpolacionCircularB(verticesUsoPlano3, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo4 = PlanoModifico[1][0];
                float* verticesUsoPlano4 = obtenerVertices(cubo4);
                interpolacionCircularB(verticesUsoPlano4, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo5 = PlanoModifico[1][1];
                float* verticesUsoPlano5 = obtenerVertices(cubo5);
                interpolacionCircularB(verticesUsoPlano5, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo6 = PlanoModifico[1][2];
                float* verticesUsoPlano6 = obtenerVertices(cubo6);
                interpolacionCircularB(verticesUsoPlano6, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo7 = PlanoModifico[2][0];
                float* verticesUsoPlano7 = obtenerVertices(cubo7);
                interpolacionCircularB(verticesUsoPlano7, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo8 = PlanoModifico[2][1];
                float* verticesUsoPlano8 = obtenerVertices(cubo8);
                interpolacionCircularB(verticesUsoPlano8, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo9 = PlanoModifico[2][2];
                float* verticesUsoPlano9 = obtenerVertices(cubo9);
                interpolacionCircularB(verticesUsoPlano9, 24, puntoMedioX, puntoMedioY, 90.0f);
            }
        }

        void interpolacionCircularPiso(int PlanoModifico[3][3],bool condicion) 
        {
            if(condicion==true)
            {
                //cout<<"entro a la condicion verdadera"<<endl;
                // Valor del punto medio en x , y
                float puntoMedioX = 0.22f;
                float puntoMedioY = 0.31f;
                //igualar los 8 vertices de int matrizA[3][3]
                int cubo1 = PlanoModifico[0][0];
                float* verticesUsoPlano1 = obtenerVertices(cubo1);
                interpolacionCircularPlanos(verticesUsoPlano1, 24, puntoMedioX, puntoMedioY, 90.0f);
                int cubo2 = PlanoModifico[0][1];
                float* verticesUsoPlano2 = obtenerVertices(cubo2);
                interpolacionCircularPlanos(verticesUsoPlano2, 24, puntoMedioX, puntoMedioY, 90.0f);
                int cubo3 = PlanoModifico[0][2];
                float* verticesUsoPlano3 = obtenerVertices(cubo3);
                interpolacionCircularPlanos(verticesUsoPlano3, 24, puntoMedioX, puntoMedioY, 90.0f);
                int cubo4 = PlanoModifico[1][0];
                float* verticesUsoPlano4 = obtenerVertices(cubo4);
                interpolacionCircularPlanos(verticesUsoPlano4, 24, puntoMedioX, puntoMedioY, 90.0f);
                int cubo5 = PlanoModifico[1][1];
                float* verticesUsoPlano5 = obtenerVertices(cubo5);
                interpolacionCircularPlanos(verticesUsoPlano5, 24, puntoMedioX, puntoMedioY, 90.0f);
                int cubo6 = PlanoModifico[1][2];
                float* verticesUsoPlano6 = obtenerVertices(cubo6);
                interpolacionCircularPlanos(verticesUsoPlano6, 24, puntoMedioX, puntoMedioY, 90.0f);
                int cubo7 = PlanoModifico[2][0];
                float* verticesUsoPlano7 = obtenerVertices(cubo7);
                interpolacionCircularPlanos(verticesUsoPlano7, 24, puntoMedioX, puntoMedioY, 90.0f);
                int cubo8 = PlanoModifico[2][1];
                float* verticesUsoPlano8 = obtenerVertices(cubo8);
                interpolacionCircularPlanos(verticesUsoPlano8, 24, puntoMedioX, puntoMedioY, 90.0f);
                int cubo9 = PlanoModifico[2][2];
                float* verticesUsoPlano9 = obtenerVertices(cubo9);
                interpolacionCircularPlanos(verticesUsoPlano9, 24, puntoMedioX, puntoMedioY, 90.0f);
                //cout<<"se esta moviendo estos cubos :"<<cubo1<<","<<cubo2<<","<<cubo3<<","<<cubo4<<","<<cubo6<<","<<cubo7<<","<<cubo8<<","<<cubo9<<endl;
            }
            else if(condicion==false)
            {
                cout<<"entro a la condicion falsa"<<endl;
                // Valor del punto medio en x , y
                float puntoMedioX = 0.22f;
                float puntoMedioY = 0.31f;
                //igualar los 8 vertices de int matrizA[3][3]
                int cubo1 = PlanoModifico[0][0];
                float* verticesUsoPlano1 = obtenerVertices(cubo1);
                interpolacionCircularPlanoB(verticesUsoPlano1, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo2 = PlanoModifico[0][1];
                float* verticesUsoPlano2 = obtenerVertices(cubo2);
                interpolacionCircularPlanoB(verticesUsoPlano2, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo3 = PlanoModifico[0][2];
                float* verticesUsoPlano3 = obtenerVertices(cubo3);
                interpolacionCircularPlanoB(verticesUsoPlano3, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo4 = PlanoModifico[1][0];
                float* verticesUsoPlano4 = obtenerVertices(cubo4);
                interpolacionCircularPlanoB(verticesUsoPlano4, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo5 = PlanoModifico[1][1];
                float* verticesUsoPlano5 = obtenerVertices(cubo5);
                interpolacionCircularPlanoB(verticesUsoPlano5, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo6 = PlanoModifico[1][2];
                float* verticesUsoPlano6 = obtenerVertices(cubo6);
                interpolacionCircularPlanoB(verticesUsoPlano6, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo7 = PlanoModifico[2][0];
                float* verticesUsoPlano7 = obtenerVertices(cubo7);
                interpolacionCircularPlanoB(verticesUsoPlano7, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo8 = PlanoModifico[2][1];
                float* verticesUsoPlano8 = obtenerVertices(cubo8);
                interpolacionCircularPlanoB(verticesUsoPlano8, 24, puntoMedioX, puntoMedioY, 90.0f);

                int cubo9 = PlanoModifico[2][2];
                float* verticesUsoPlano9 = obtenerVertices(cubo9);
                interpolacionCircularPlanoB(verticesUsoPlano9, 24, puntoMedioX, puntoMedioY, 90.0f);

            }
        }

        /*
            pre calculo para evitar perder el cubo
        */
        //aser funcion llamada Precalculo
        bool verificarElementosRepetidos(int matriz1[3][3], int matriz2[3][3], int matriz3[3][3]) 
        {
            bool elementosRepetidos[27] = {false}; // Array para marcar los elementos encontrados

            // Verificar elementos en la matriz1
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int elemento = matriz1[i][j];
                    if (elementosRepetidos[elemento]) {
                        return false; // Se encontró un elemento repetido
                    } else {
                        elementosRepetidos[elemento] = true;
                    }
                }
            }

            // Verificar elementos en la matriz2
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int elemento = matriz2[i][j];
                    if (elementosRepetidos[elemento]) {
                        return false; // Se encontró un elemento repetido
                    } else {
                        elementosRepetidos[elemento] = true;
                    }
                }
            }

            // Verificar elementos en la matriz3
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int elemento = matriz3[i][j];
                    if (elementosRepetidos[elemento]) {
                        return false; // Se encontró un elemento repetido
                    } else {
                        elementosRepetidos[elemento] = true;
                    }
                }
            }

            return true; // No se encontraron elementos repetidos
        }
        bool PrecalcularPiso(int caso)
        { 
            //iguala las matrices temp 
            memcpy(PisoTemp, Piso1, sizeof(PisoTemp));
            memcpy(PisoTemp2, Piso2, sizeof(PisoTemp2));
            memcpy(PisoTemp3, Piso3, sizeof(PisoTemp3));
            memcpy(PlanoTemp1, Plano1, sizeof(PlanoTemp1));
            memcpy(PlanoTemp2, Plano2, sizeof(PlanoTemp2));
            memcpy(PlanoTemp3, Plano3, sizeof(PlanoTemp3));
            //aser un switch para los casos
            switch (caso)
            {
            case 1:
                rotarMatriz(PisoTemp);
                funcionTransform(PlanoTemp1, PisoTemp, 2, 2);
                funcionTransform(PlanoTemp2, PisoTemp, 2, 1);
                funcionTransform(PlanoTemp3, PisoTemp, 2, 0);
                break;
            case 2:
                rotarMatriz(PisoTemp2);
                funcionTransform(PlanoTemp1, PisoTemp2, 1, 2);
                funcionTransform(PlanoTemp2, PisoTemp2, 1, 1);
                funcionTransform(PlanoTemp3, PisoTemp2, 1, 0);
                break;
            case 3:
                rotarMatriz(PisoTemp3);
                funcionTransform(PlanoTemp1, PisoTemp3, 0, 2);
                funcionTransform(PlanoTemp2, PisoTemp3, 0, 1);
                funcionTransform(PlanoTemp3, PisoTemp3, 0, 0);
                break;
            case 4:
                rotarMatrizInversa(PisoTemp);
                funcionTransform(PlanoTemp1, PisoTemp, 2, 2);
                funcionTransform(PlanoTemp2, PisoTemp, 2, 1);
                funcionTransform(PlanoTemp3, PisoTemp, 2, 0);
                break;
            case 5:
                rotarMatrizInversa(PisoTemp2);
                funcionTransform(PlanoTemp1, PisoTemp2, 1, 2);
                funcionTransform(PlanoTemp2, PisoTemp2, 1, 1);
                funcionTransform(PlanoTemp3, PisoTemp2, 1, 0);
                break;
            case 6:
                rotarMatrizInversa(PisoTemp3);
                funcionTransform(PlanoTemp1, PisoTemp3, 0, 2);
                funcionTransform(PlanoTemp2, PisoTemp3, 0, 1);
                funcionTransform(PlanoTemp3, PisoTemp3, 0, 0);
                GirarPiso(6);
                break;
            default:
                break;
            }

            bool pisos= verificarElementosRepetidos(PisoTemp,PisoTemp2,PisoTemp3);
            bool planos= verificarElementosRepetidos(PlanoTemp1,PlanoTemp2,PlanoTemp3);
            if(pisos==true && planos==true)
            {
                cout<<"no hay elementos repetidos"<<endl;
                return true;
            }
            else
            {
                cout<<"hay elementos repetidos"<<endl;
                return false;
            }

        }
        bool PrecalcularPlanos(int caso)
        { 
            //iguala las matrices temp 
            memcpy(PisoTemp, Piso1, sizeof(PisoTemp));
            memcpy(PisoTemp2, Piso2, sizeof(PisoTemp2));
            memcpy(PisoTemp3, Piso3, sizeof(PisoTemp3));
            memcpy(PlanoTemp1, Plano1, sizeof(PlanoTemp1));
            memcpy(PlanoTemp2, Plano2, sizeof(PlanoTemp2));
            memcpy(PlanoTemp3, Plano3, sizeof(PlanoTemp3));
            //aser un switch para los casos
            switch (caso)
            {
            case 1:
                rotarMatriz(PlanoTemp1);
                funcionTransform(PisoTemp, PlanoTemp1, 2, 2);
                funcionTransform(PisoTemp2, PlanoTemp1, 2, 1);
                funcionTransform(PisoTemp3, PlanoTemp1, 2, 0);
                break;
            case 2:
                rotarMatriz(PlanoTemp2);
                funcionTransform(PisoTemp, PlanoTemp2, 1, 2);
                funcionTransform(PisoTemp2, PlanoTemp2, 1, 1);
                funcionTransform(PisoTemp3, PlanoTemp2, 1, 0);
                break;
            case 3:
                rotarMatriz(PlanoTemp3);
                funcionTransform(PisoTemp, PlanoTemp3, 0, 2);
                funcionTransform(PisoTemp2, PlanoTemp3, 0, 1);
                funcionTransform(PisoTemp3, PlanoTemp3, 0, 0);
                break;
            case 4:
                rotarMatrizInversa(PlanoTemp1);
                funcionTransform(PisoTemp, PlanoTemp1, 2, 2);
                funcionTransform(PisoTemp2, PlanoTemp1, 2, 1);
                funcionTransform(PisoTemp3, PlanoTemp1, 2, 0);
                break;
            case 5:
                rotarMatrizInversa(PlanoTemp2);
                funcionTransform(PisoTemp, PlanoTemp2, 1, 2);
                funcionTransform(PisoTemp2, PlanoTemp2, 1, 1);
                funcionTransform(PisoTemp3, PlanoTemp2, 1, 0);
                break;
            case 6:
                rotarMatrizInversa(PlanoTemp3);
                funcionTransform(PisoTemp, PlanoTemp3, 0, 2);
                funcionTransform(PisoTemp2, PlanoTemp3, 0, 1);
                funcionTransform(PisoTemp3, PlanoTemp3, 0, 0);
                break;
            default:
                break;
            }

            bool pisos= verificarElementosRepetidos(PisoTemp,PisoTemp2,PisoTemp3);
            bool planos= verificarElementosRepetidos(PlanoTemp1,PlanoTemp2,PlanoTemp3);
            if(pisos==true && planos==true)
            {
                cout<<"no hay elementos repetidos"<<endl;
                return true;
            }
            else
            {
                cout<<"hay elementos repetidos"<<endl;
                return false;
            }

        }
        //__________________________________
        void SetearPosiciones() 
        {
            imprimirMatriz(Plano1);
            cout<<"__________________________"<<endl;
            imprimirMatriz(Plano2);
            cout<<"__________________________"<<endl;
            imprimirMatriz(Plano3);
            cout<<"__________________________"<<endl;
            //Plano1
            int cubo1 = Plano1[2][2];
            ActualizarVertices(cubo1,TempVertices);
            int cubo2 = Plano1[2][1];
            ActualizarVertices(cubo2,TempVertices2);
            int cubo3 = Plano1[2][0];
            ActualizarVertices(cubo3,TempVertices3);
            int cubo4 = Plano1[1][2];
            ActualizarVertices(cubo4,TempVertices4);
            int cubo5 = Plano1[1][1];
            ActualizarVertices(cubo5,TempVertices5);
            int cubo6 = Plano1[1][0];
            ActualizarVertices(cubo6,TempVertices6);
            int cubo7 = Plano1[0][2];
            ActualizarVertices(cubo7,TempVertices7);
            int cubo8 = Plano1[0][1];
            ActualizarVertices(cubo8,TempVertices8);
            int cubo9 = Plano1[0][0];
            ActualizarVertices(cubo9,TempVertices9);
            //Plano2
            int cubo10 = Plano2[2][2];
            ActualizarVertices(cubo10,TempVertices10);
            int cubo11 = Plano2[2][1];
            ActualizarVertices(cubo11,TempVertices11);
            int cubo12 = Plano2[2][0];
            ActualizarVertices(cubo12,TempVertices12);
            int cubo13 = Plano2[1][2];
            ActualizarVertices(cubo13,TempVertices13);
            int cubo14 = Plano2[1][1];
            ActualizarVertices(cubo14,TempVertices14);
            int cubo15 = Plano2[1][0];
            ActualizarVertices(cubo15,TempVertices15);
            int cubo16 = Plano2[0][2];
            ActualizarVertices(cubo16,TempVertices16);
            int cubo17 = Plano2[0][1];
            ActualizarVertices(cubo17,TempVertices17);
            int cubo18 = Plano2[0][0];
            ActualizarVertices(cubo18,TempVertices18);
            //Plano3
            int cubo19 = Plano3[2][2];
            ActualizarVertices(cubo19,TempVertices19);
            int cubo20 = Plano3[2][1];
            ActualizarVertices(cubo20,TempVertices20);
            int cubo21 = Plano3[2][0];
            ActualizarVertices(cubo21,TempVertices21);
            int cubo22 = Plano3[1][2];
            ActualizarVertices(cubo22,TempVertices22);
            int cubo23 = Plano3[1][1];
            ActualizarVertices(cubo23,TempVertices23);
            int cubo24 = Plano3[1][0];
            ActualizarVertices(cubo24,TempVertices24);
            int cubo25 = Plano3[0][2];
            ActualizarVertices(cubo25,TempVertices25);
            int cubo26 = Plano3[0][1];
            ActualizarVertices(cubo26,TempVertices26);
            int cubo27 = Plano3[0][0];
            ActualizarVertices(cubo27,TempVertices27);
            cout<<cubo1<<","<<cubo2<<","<<cubo3<<","<<cubo4<<","<<cubo5<<","<<cubo6<<","<<cubo7<<","<<cubo8<<","<<cubo9<<endl;
            cout<<cubo10<<","<<cubo11<<","<<cubo12<<","<<cubo13<<","<<cubo14<<","<<cubo15<<","<<cubo16<<","<<cubo17<<","<<cubo18<<endl;
            cout<<cubo19<<","<<cubo20<<","<<cubo21<<","<<cubo22<<","<<cubo23<<","<<cubo24<<","<<cubo25<<","<<cubo26<<","<<cubo27<<endl;
            cout<<"se setearon las posiciones"<<endl;
            //ImprimirTodasLasMatrices();
            cout<<"__________________________"<<endl;
        }
        //__________________________________
        void realizarAnimacion(int accion,bool condicion) 
        {
            switch (accion) {
                case 1: 
                {
                    if (condicion==false)
                    {
                        interpolacionCircularPlano(Plano1,true);
                    }
                    else
                    {
                        interpolacionCircularPiso(Piso1, true);
                    }
                    break;
                }
                case 2: 
                {
                    if (condicion==false)
                    {
                        interpolacionCircularPlano(Plano2,true);
                    }
                    else
                    {
                        interpolacionCircularPiso(Piso2, true);
                    }
                    break;
                }
                case 3: 
                {
                    if (condicion==false)
                    {
                        interpolacionCircularPlano( Plano3,true);
                    }
                    else
                    {
                        interpolacionCircularPiso(Piso3, true);
                    }
                    break;
                }
                case 4: 
                {
                    if (condicion==false)
                    {
                        interpolacionCircularPlano(Plano1,false);
                    }
                    else
                    {
                        interpolacionCircularPiso(Piso1, false);
                    }
                    break;
                }
                case 5: 
                {
                    if (condicion==false)
                    {
                        interpolacionCircularPlano(Plano2,false);
                    }
                    else
                    {
                        interpolacionCircularPiso(Piso2, false);
                    }
                    break;
                }
                case 6: 
                {
                    if (condicion==false)
                    {
                        interpolacionCircularPlano(Plano3,false);
                    }
                    else
                    {
                        interpolacionCircularPiso(Piso3, false);
                    }
                    break;
                }

                default:
                    // Acción no válida
                    break;
            }
        }
        void GirarPiso(int condicion) 
        {
            switch (condicion) {

                case 1:
                    if(PrecalcularPiso(1)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatriz(Piso1);
                        funcionTransform(Plano1, Piso1, 2, 2);
                        funcionTransform(Plano2, Piso1, 2, 1);
                        funcionTransform(Plano3, Piso1, 2, 0);
                        break;
                    }
                case 2:
                    if(PrecalcularPiso(2)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatriz(Piso2);
                        funcionTransform(Plano1, Piso2, 1, 2);
                        funcionTransform(Plano2, Piso2, 1, 1);
                        funcionTransform(Plano3, Piso2, 1, 0);
                        break;
                    }
                case 3:
                    if(PrecalcularPiso(3)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatriz(Piso3);
                        funcionTransform(Plano1, Piso3, 0, 2);
                        funcionTransform(Plano2, Piso3, 0, 1);
                        funcionTransform(Plano3, Piso3, 0, 0);
                        break;
                    }
                case 4:
                    if(PrecalcularPiso(4)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatrizInversa(Piso1);
                        funcionTransform(Plano1, Piso1, 2, 2);
                        funcionTransform(Plano2, Piso1, 2, 1);
                        funcionTransform(Plano3, Piso1, 2, 0);
                        break;
                    }
                case 5:
                    if(PrecalcularPiso(5)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatrizInversa(Piso2);
                        funcionTransform(Plano1, Piso2, 1, 2);
                        funcionTransform(Plano2, Piso2, 1, 1);
                        funcionTransform(Plano3, Piso2, 1, 0);
                        break;
                    }
                case 6:
                    if(PrecalcularPiso(6)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatrizInversa(Piso3);
                        funcionTransform(Plano1, Piso3, 0, 2);
                        funcionTransform(Plano2, Piso3, 0, 1);
                        funcionTransform(Plano3, Piso3, 0, 0);
                        break;
                    }
                default:
                    break;
            }
                
        }
        void GirarPlano(int condicion) 
        {
            switch (condicion) 
            {

                case 1:

                    cout<<"GirarPiso 1"<<endl;
                    if(PrecalcularPlanos(1)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatriz(Plano1);
                        funcionTransform(Piso1, Plano1, 2, 2);
                        funcionTransform(Piso2, Plano1, 2, 1);
                        funcionTransform(Piso3, Plano1, 2, 0);
                        break;
                    }

                    break;
                case 2:
                    cout<<"GirarPiso 2"<<endl;
                    if(PrecalcularPlanos(2)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatriz(Plano2);
                        funcionTransform(Piso1, Plano2, 1, 2);
                        funcionTransform(Piso2, Plano2, 1, 1);
                        funcionTransform(Piso3, Plano2, 1, 0);
                        break;
                    }
                case 3:
                    cout<<"GirarPiso 3"<<endl;
                    if(PrecalcularPlanos(3)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatriz(Plano3);
                        funcionTransform(Piso1, Plano3, 0, 2);
                        funcionTransform(Piso2, Plano3, 0, 1);
                        funcionTransform(Piso3, Plano3, 0, 0);
                        break;
                    }
                case 4:
                    cout<<"GirarPiso 4"<<endl;
                    if(PrecalcularPlanos(4)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatrizInversa(Plano1);
                        funcionTransform(Piso1, Plano1, 2, 2);
                        funcionTransform(Piso2, Plano1, 2, 1);
                        funcionTransform(Piso3, Plano1, 2, 0);
                        break;
                    }
                case 5:
                    cout<<"GirarPiso 5"<<endl;
                    if(PrecalcularPlanos(5)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatrizInversa(Plano2);
                        funcionTransform(Piso1, Plano2, 1, 2);
                        funcionTransform(Piso2, Plano2, 1, 1);
                        funcionTransform(Piso3, Plano2, 1, 0);
                        break;
                    }
                case 6:
                    cout<<"GirarPiso 6"<<endl;
                    if(PrecalcularPlanos(6)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatrizInversa(Plano3);
                        funcionTransform(Piso1, Plano3, 0, 2);
                        funcionTransform(Piso2, Plano3, 0, 1);
                        funcionTransform(Piso3, Plano3, 0, 0);
                        break;
                    }
                default:
                    break;
            }
        }
        void llenarDatos(int posicion)
        {
            float* vertices = new float[24] {
                //primer cuadrado
                -0.107f,-0.313f,-0.311f,//0
                -0.107f,-0.113f,-0.311f,//1
                -0.307f,-0.113f,-0.311f,//3
                -0.307f,-0.313f,-0.311f,//2
                
                -0.107f,-0.313f,-0.11f,//4
                -0.107f,-0.113f,-0.11f,//5
                -0.307f,-0.313f,-0.11f,//6
                -0.307f,-0.113f,-0.11f//7
            };
            unsigned int* indices = new unsigned int[12] {
                0, 1, 2, 2, 3, 1, 4, 5, 6, 6, 7, 5
            };

            Cubos[posicion] = std::make_pair(vertices, indices);
        }
        void imprimirCubos()
        {
            for (const auto& elemento : Cubos)
            {
                int clave = elemento.first;
                const auto& datos = elemento.second;
                const float* vertices = datos.first;
                const unsigned int* indices = datos.second;

                std::cout << "Cubo " << clave << ":" << std::endl;
                std::cout << "Vertices: ";
                for (int i = 0; i < 24; ++i)
                {
                    std::cout << vertices[i] << " ";
                }
                std::cout << std::endl;
                /*
                std::cout << "Indices: ";
                for (int i = 0; i < 12; ++i)
                {
                    std::cout << indices[i] << " ";
                }
                std::cout << std::endl << std::endl;*/
            }
        }
        void imprimirEstructura(std::map<int, std::pair<float*, unsigned int*>> Cubos)
        {
            cout << "Imprimiendo estructura" << endl;
            for (const auto& elemento : Cubos)
            {
                int clave = elemento.first;
                const auto& datos = elemento.second;
                const float* vertices = datos.first;
                const unsigned int* indices = datos.second;

                std::cout << "Cubo " << clave << ":" << std::endl;
                std::cout << "Vertices: ";
                for (int i = 0; i < 24; ++i)
                {
                    std::cout << vertices[i] << " ";
                }
                std::cout << std::endl;
                /*
                std::cout << "Indices: ";
                for (int i = 0; i < 12; ++i)
                {
                    std::cout << indices[i] << " ";
                }
                std::cout << std::endl << std::endl;*/
            }
        }
        void insertarElementos(int posicion)
        {
            for (int i = 0; i < posicion; ++i)
            {
                llenarDatos(i);
            }
        }
        std::map<int, std::pair<float*, unsigned int*>>& retornarCubos()
        {
            return Cubos;
        }
        void ordenarCubos()
        {
            //_________________________________________
            float MovimientoX = 0.21f;
            float MovimientoY = 0.0f;   
            float MovimientoYB = 0.21f;
            float MovimientoYC = 0.42f;
            //_________________________________________
            float Mov = 0.0f;
            float Mov2 = 0.0f;
            for (const auto& elemento : Cubos)
            {  
                int clave = elemento.first;
                const auto& datos = elemento.second;
                float* vertices = datos.first;
                const unsigned int* indices = datos.second;
                cout << "Cubo " << clave << ":" << endl;
                if (clave < 3)
                {
                    cout << "Movimiento en X :" <<Mov<< endl;
                    modificarTraslacion3D(vertices, 24, Mov, 0.0f, 0.0f);
                    Mov = Mov + MovimientoX;
                }
                else if (clave >= 3 && clave < 6)
                {
                    cout << "Movimiento en Y" << Mov << endl;
                    if (Mov2 == 0.0f)
                    {
                        Mov = 0.0f;
                        Mov2 = MovimientoYB;
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.0f);
                       Mov = Mov + MovimientoX;
                    }
                    else
                    {
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.0f);
                        Mov = Mov + MovimientoX;
                    }
                }
                else if (clave >= 6 && clave < 9)
                {
                    cout << "Movimiento en Z" << Mov << endl;
                    if (Mov2 == MovimientoYB)
                    {
                        Mov = 0.0f;
                        Mov2 = MovimientoYC;
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.0f);
                        Mov = Mov + MovimientoX;
                    }
                    else
                    {
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.0f);
                        Mov = Mov + MovimientoX;
                    }
                }
                else if (clave>=9 && clave < 12)
                {
                    cout << "Movimiento en X" << Mov << endl;
                    if (Mov2 == MovimientoYC)
                    {
                        Mov = 0.0f;
                        Mov2 = MovimientoY;
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.21f);
                        Mov = Mov + MovimientoX;
                    }
                    else
                    {
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.21f);
                       Mov = Mov + MovimientoX;
                    }
                }
                else if (clave >= 12 && clave < 15)
                {
                    cout << "Movimiento en Y" << Mov << endl;
                    if (Mov2 == MovimientoY)
                    {
                        Mov = 0.0f;
                        Mov2 = MovimientoYB;
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.21f);
                        Mov = Mov + MovimientoX;
                    }
                    else
                    {
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.21f);
                       Mov = Mov + MovimientoX;
                    }
                }
                else if (clave >= 15 && clave < 18)
                {
                    cout << "Movimiento en Z" << Mov << endl;
                    if (Mov2 == MovimientoYB)
                    {
                        Mov = 0.0f;
                        Mov2 =MovimientoYC;
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.21f);
                        Mov = Mov + MovimientoX;
                    }
                    else
                    {
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.21f);
                        Mov = Mov + MovimientoX;
                    }
                }
                else if(clave >= 18 && clave < 21)
                {
                    cout << "Movimiento en X" << Mov << endl;
                    if (Mov2 == MovimientoYC)
                    {
                        Mov = 0.0f;
                        Mov2 =MovimientoY;
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.42f);
                        Mov = Mov + MovimientoX;
                    }
                    else
                    {
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.42f);
                       Mov = Mov + MovimientoX;
                    }
                }
                else if (clave >= 21 && clave < 24)
                {
                    cout << "Movimiento en Y" << Mov << endl;
                    if (Mov2 == MovimientoY)
                    {
                        Mov = 0.0f;
                        Mov2 =MovimientoYB;
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.42f);
                        Mov = Mov + MovimientoX;
                    }
                    else
                    {
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.42f);
                        Mov = Mov + MovimientoX;
                    }
                }
                else if (clave >= 24 && clave < 27)
                {
                    cout << "Movimiento en Z" << Mov << endl;
                    if (Mov2 == MovimientoYB)
                    {
                        Mov = 0.0f;
                        Mov2 = MovimientoYC;
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.42f);
                        Mov = Mov + MovimientoX;
                    }
                    else
                    {
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.42f);
                        Mov = Mov + MovimientoX;
                    }
                }
            }
        }
        //________________________________________________________________
        //SOLVE
        /*
        // Capa Inferior (Bottom Layer)
        void resolverCruzCapaInferior(int Plano1[3][3], int Plano2[3][3], int Plano3[3][3], int Piso1[3][3], int Piso2[3][3], int Piso3[3][3]) {
            // Buscar el color central de la cruz en la capa inferior
            int colorCentral = Plano2[1][1];

            // Comprobar si la cruz está formada correctamente en la capa inferior
            bool cruzCorrecta = (Plano1[1][1] == colorCentral) &&
                                (Plano2[0][1] == colorCentral) &&
                                (Plano2[1][0] == colorCentral) &&
                                (Plano2[1][2] == colorCentral) &&
                                (Plano2[2][1] == colorCentral) &&
                                (Plano3[1][1] == colorCentral);

            // Si la cruz está formada correctamente, no se requiere ninguna acción adicional
            if (cruzCorrecta) {
                return;
            }

            // Si el color central de la cruz no está en el piso inferior,
            // se realiza una rotación del piso inferior para alinearlo
            if (Piso2[2][1] != colorCentral) {
                rotarMatriz(Piso1);
                rotarMatriz(Piso2);
                rotarMatriz(Piso3);
            }

            // Si el color central de la cruz está en el piso inferior pero no
            // se encuentra en la posición correcta, se realiza una rotación
            // del piso inferior para alinearlo
            while (Piso2[2][1] != colorCentral) {
                rotarMatriz(Piso1);
                rotarMatriz(Piso2);
                rotarMatriz(Piso3);
            }

            // Si la cruz no está formada correctamente en la capa inferior,
            // se realizan movimientos para posicionar los colores correctos
            while (!cruzCorrecta) {
                // Realizar los movimientos necesarios para corregir la cruz
                // en la capa inferior
                // ...

                // Actualizar la variable cruzCorrecta
                cruzCorrecta = (Plano1[1][1] == colorCentral) &&
                            (Plano2[0][1] == colorCentral) &&
                            (Plano2[1][0] == colorCentral) &&
                            (Plano2[1][2] == colorCentral) &&
                            (Plano2[2][1] == colorCentral) &&
                            (Plano3[1][1] == colorCentral);
            }
        }


        void resolverEsquinasCapaInferior(int Plano1[3][3], int Plano2[3][3], int Plano3[3][3], int Piso1[3][3], int Piso2[3][3], int Piso3[3][3]) {
            // Implementa la lógica para colocar las esquinas de la capa inferior
            // en sus posiciones correctas utilizando tus funciones y lógica existente
            // ...
        }

        // Capa Intermedia (Middle Layer)
        void moverBordesCapaIntermedia(int Plano1[3][3], int Plano2[3][3], int Plano3[3][3], int Piso1[3][3], int Piso2[3][3], int Piso3[3][3]) {
            // Implementa la lógica para mover los bordes de la capa intermedia
            // a sus posiciones correctas sin afectar la capa inferior
            // utilizando algoritmos específicos
            // ...
        }

        // Capa Superior (Top Layer)
        void formarCruzCapaSuperior(int Plano1[3][3], int Plano2[3][3], int Plano3[3][3], int Piso1[3][3], int Piso2[3][3], int Piso3[3][3]) {
            // Implementa la lógica para formar la cruz en la capa superior
            // utilizando tus funciones y lógica existente
            // ...
        }

        void orientarEsquinasCapaSuperior(int Plano1[3][3], int Plano2[3][3], int Plano3[3][3], int Piso1[3][3], int Piso2[3][3], int Piso3[3][3]) {
            // Implementa la lógica para orientar las esquinas de la capa superior
            // hacia arriba utilizando tus funciones y lógica existente
            // ...
        }

        // Colocación de Esquinas en la Capa Superior
        void permutarEsquinasCapaSuperior(int Plano1[3][3], int Plano2[3][3], int Plano3[3][3], int Piso1[3][3], int Piso2[3][3], int Piso3[3][3]) {
            // Implementa la lógica para permutar las esquinas de la capa superior
            // hasta que todas estén en su lugar utilizando algoritmos específicos
            // ...
        }

        // Función principal para resolver el cubo usando el método de solución por capas
        void solve(int Plano1[3][3], int Plano2[3][3], int Plano3[3][3], int Piso1[3][3], int Piso2[3][3], int Piso3[3][3]) {
            // Capa Inferior (Bottom Layer)
            resolverCruzCapaInferior(Plano1, Plano2, Plano3, Piso1, Piso2, Piso3);
            resolverEsquinasCapaInferior(Plano1, Plano2, Plano3, Piso1, Piso2, Piso3);

            // Capa Intermedia (Middle Layer)
            moverBordesCapaIntermedia(Plano1, Plano2, Plano3, Piso1, Piso2, Piso3);

            // Capa Superior (Top Layer)
            formarCruzCapaSuperior(Plano1, Plano2, Plano3, Piso1, Piso2, Piso3);
            orientarEsquinasCapaSuperior(Plano1, Plano2, Plano3, Piso1, Piso2, Piso3);

            // Colocación de Esquinas en la Capa Superior
            permutarEsquinasCapaSuperior(Plano1, Plano2, Plano3, Piso1, Piso2, Piso3);

            // El cubo ha sido resuelto
        }

        // Llamada a la función solve con los datos del cubo
        solve(Plano1, Plano2, Plano3, Piso1, Piso2, Piso3);

        */
};
