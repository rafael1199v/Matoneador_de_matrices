using System;

namespace calculadora;

    public static class Program
    {
        public static void Main(string[] args)
        {
            char reset;
            do{
                try
                {
                    title();
                    int eleccion = menu();
                    calculadoraMatricial(eleccion);
                    Console.Write("Quieres volver a hacer un nuevo calculo?: (S/N) :");
                    reset = Console.ReadKey().KeyChar;
                    Console.WriteLine();
                }
                catch(ArgumentNullException)
                {
                    Console.WriteLine("Entrada Nula.");
                    reset = 'N';
                }
                
            }while(reset == 'S' || reset == 's');
        }

        public static int[,] conseguirMatriz(int filas, int columnas)
        {
            int[,] matriz = new int[filas, columnas];
            Console.WriteLine("Ingresar Datos de la matriz:");

            for (int i = 0; i < filas; i++)
            {
                for (int j = 0; j < columnas; j++)
                {
                    Console.Write($"Elemento [{i + 1}][{j + 1}]:");
                    matriz[i, j] = Convert.ToInt32(Console.ReadLine());
                }
                Console.WriteLine("");
            }
            return matriz;
        }
        public static string mostrarMatriz(int[,] a, int filas, int columnas)
        {
            if(a == null){
                return "Hubo un error";
            }
            for (int i = 0; i < filas; i++)
            {
                for (int j = 0; j < columnas; j++)
                {
                    Console.Write(a[i, j] + "\t");
                }
                Console.WriteLine();
            }
            return "Matriz mostrada con exito";
        }

        public static int[,] sumaDeMatrices(int[,] a, int[,] b, int filas,  int columnas)
        {
            for(int i = 0; i < filas; i++)
            {
                for(int j = 0;j < columnas; j++)
                {
                    a[i,j] += b[i,j];
                }
            }

            return a;
        }

        public static int[,] restaDeMatrices(int[,] a, int[,]b, int filas, int columnas)
        {
            for (int i = 0; i < filas; i++)
            {
                for (int j = 0; j < columnas; j++)
                {
                    a[i, j] -= b[i, j];
                }
            }

            return a;
        }

        public static int[,] multiplicacionPorEscarlar(int[,] a, int escalar, int filas, int columnas)
        {
            for (int i = 0; i < filas; i++)
            {
                for (int j = 0; j < columnas; j++)
                {
                    a[i, j] *= escalar;
                }
            }

            return a;
        }

        public static int determinate2x2(int[,] matriz)
        {
            int diagonal_principal = 1, diagonal_secundaria = 1, determinante;

            for(int i = 0; i < 2; i++)
            {
                for(int j = 0; j < 2; j++)
                {
                    if(i == j)
                    {
                        diagonal_principal *= matriz[i, j];
                    }
                    else
                    {
                        diagonal_secundaria *= matriz[i, j];
                    }
                }
            }

            determinante = diagonal_principal - diagonal_secundaria;

            return determinante;
        }

        public static int menu()
        {
            int eleccion;
            Console.WriteLine("Bienvenido a la calculadora de matrices!!!");
            Console.WriteLine("Por favor, escoge tu calculo a realizar");
            Console.WriteLine("1) Suma de matrices");
            Console.WriteLine("2) Resta de matrices");
            Console.WriteLine("3) Multiplicacion por un escalar");
            Console.WriteLine("4) Determinante de matriz 2x2");
            Console.Write("Tu eleccion: ");
            do
            {
                eleccion = Convert.ToInt32(Console.ReadLine());
                if(eleccion < 1 || eleccion > 4){
                    Console.WriteLine("Numero introducido fuera de rango. Ingrese el valor nuevamaente:");
                }
            } while (eleccion < 1 || eleccion > 4);
            

            return eleccion;
        }

        public static void calculadoraMatricial(int eleccion)
        {
            int filas, columnas;
            int[,] matriz1, matriz2;
            Console.WriteLine("----------------------------------------------------------------------------");
            switch (eleccion)
            {
                case 1:

                    do
                    {
                        Console.WriteLine("Introduce el numero de filas y columnas");
                        Console.Write("Filas: ");
                        filas = Convert.ToInt32(Console.ReadLine());
                        Console.Write("Columnas: ");
                        columnas = Convert.ToInt32(Console.ReadLine());
                    } while (filas <= 0 || columnas <= 0 || filas > 30 || columnas > 30); 
                   
                    matriz1 = conseguirMatriz(filas, columnas);
                    Console.WriteLine("Primera Matriz");
                    mostrarMatriz(matriz1, filas, columnas);

                    matriz2 = conseguirMatriz(filas, columnas);
                    Console.WriteLine("Segunda Matriz");
                    mostrarMatriz(matriz2, filas, columnas);
                    Console.WriteLine("----------------------------------------------------------------------------");
                    Console.WriteLine("Resultado de la suma: ");
                    mostrarMatriz(sumaDeMatrices(matriz1, matriz2, filas, columnas), filas, columnas);

                    break;
                case 2:

                    do
                    {
                        Console.WriteLine("Introduce el numero de filas y columnas");
                        Console.Write("Filas: ");
                        filas = Convert.ToInt32(Console.ReadLine());
                        Console.Write("Columnas: ");
                        columnas = Convert.ToInt32(Console.ReadLine());
                    } while (filas <= 0 || columnas <= 0 || filas > 30 || columnas > 30);

                    matriz1 = conseguirMatriz(filas, columnas);
                    Console.WriteLine("Primera Matriz");
                    mostrarMatriz(matriz1, filas, columnas);

                    matriz2 = conseguirMatriz(filas, columnas);
                    Console.WriteLine("Segunda Matriz");
                    mostrarMatriz(matriz2, filas, columnas);
                    Console.WriteLine("----------------------------------------------------------------------------");
                    Console.WriteLine("Resultado de la resta: ");
                    mostrarMatriz(restaDeMatrices(matriz1, matriz2, filas, columnas), filas, columnas);

                    break;
                case 3:
                    int escalar;
                    do
                    {
                        Console.WriteLine("Introduce el numero de filas y columnas");
                        Console.Write("Filas: ");
                        filas = Convert.ToInt32(Console.ReadLine());
                        Console.Write("Columnas: ");
                        columnas = Convert.ToInt32(Console.ReadLine());
                    } while (filas <= 0 || columnas <= 0 || filas > 30 || columnas > 30);

                    Console.Write("Introduce el escalar: ");
                    escalar = Convert.ToInt32(Console.ReadLine());

                    matriz1 = conseguirMatriz(filas, columnas);
                    Console.WriteLine("Matriz Ingresada:");
                    mostrarMatriz(matriz1, filas, columnas);

                    Console.WriteLine("Resultado de la Multiplicacion por escalar: ");
                    mostrarMatriz(multiplicacionPorEscarlar(matriz1, escalar, filas, columnas), filas, columnas);
                    break;
                case 4:
                    matriz1 = conseguirMatriz(2, 2);
                    Console.WriteLine("Matriz ingresada");
                    mostrarMatriz(matriz1, 2, 2);
                    int determinante = determinate2x2(matriz1);
                    Console.WriteLine("El determinante de esa matriz 2x2 es: ");
                    Console.WriteLine(determinante);
                    break;
            }
        }
        public static void title()
        {
            Console.WriteLine("\n");
            Console.WriteLine("'       e    e           e      ~~~888~~~   ,88~-_   888b    | 888~~       e      888~-_     ,88~-_   888--_");
            Console.WriteLine("'      d8b  d8b         d8b        888     d888   \\  |Y88b   | 888___     d8b     888   \\   d888   \\  888   \\");
            Console.WriteLine("'     d888bdY88b       /Y88b       888    88888    | | Y88b  | 888       /Y88b    888    | 88888    | 888   ||");
            Console.WriteLine("'    / Y88Y Y888b     /  Y88b      888    88888    | |  Y88b | 888      /  Y88b   888    | 88888    | 888  //");
            Console.WriteLine("'   /   YY   Y888b   /____Y88b     888     Y888   /  |   Y88b| 888     /____Y88b  888   /   Y888   /  888_//");
            Console.WriteLine( "'  /          Y888b /      Y88b    888      `88_ /   |    Y888 888___ /      Y88b 888_-~     `88_ /   888 \\\\");
            Console.WriteLine("\n");
            Console.WriteLine("'  `7MM\"\"\"Yb.   `7MM\"\"\"YMM'");
            Console.WriteLine("'    MM    `Yb.   MM    ");
            Console.WriteLine("'    MM     `Mb   MM   ");
            Console.WriteLine("'    MM      MM   MMmmMM'");
            Console.WriteLine("'    MM     ,MP   MM");
            Console.WriteLine("'    MM    ,dP'   MM");
            Console.WriteLine("'  .JMMmmmdP'   .JMMmmmmMMM'");
            Console.WriteLine("\n");
            Console.WriteLine("'       e    e           e      ~~~888~~~ 888~-_   888  e88~-_   888---  ,d88~~\\");
            Console.WriteLine("'      d8b  d8b         d8b        888    888   \\  888 d888   \\  888___ 8888'");
            Console.WriteLine("'     d888bdY88b       /Y88b       888    888    | 888 8888      888    `Y88b'");
            Console.WriteLine("'    / Y88Y Y888b     /  Y88b      888    888   /  888 8888      888     `Y88b,'");
            Console.WriteLine("'   /   YY   Y888b   /____Y88b     888    888_-~   888 Y888      888       8888'");
            Console.WriteLine("'  /          Y888b /      Y88b    888    888 \\\\   888  \"88_ /   888___  \\__88P");
            Console.WriteLine("\n");
        }
    }