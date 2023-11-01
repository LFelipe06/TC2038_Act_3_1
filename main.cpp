#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Variables contadoras para cada metodo de ordenamiento
int QSCounter = 0;
int HSCounter = 0;
int BSCounter = 0;

ofstream output;

// Para llenar el array loco
void arrayFiller(vector<int>& vector, int x){
    srand(time(0));
    int value;
    for (int i = 0 ; i < x; i++){
        value = rand() % 100000;
        vector.push_back(value);
    }
}

// Llenar el array loco en orden del 0 al 100,000
void arrayFillerInOrder(vector<int>& vector) {
    for (int i = 0 ; i <= 100000; i++){
        vector.push_back(i);
    } 
}

// Para imprimir el array loco
void printArray(vector<int>& vector){
    for (int i=0; i < vector.size(); i ++){
        cout<<vector[i]<<" ";
        output << vector[i] << " ";
    }
    output << endl;
    cout<<endl;
}

//QuickSort
// Particionar el arreglo loco
int partition(vector<int>& vector, int start, int end){
    int pivot = vector[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++) {
        QSCounter++;
        if (vector[i] <= pivot)
            count++;
    }
    // Moviendo el pivote a su posición loca
    int pivotIndex = start + count;
    swap(vector[pivotIndex], vector[start]);
 
    // Recorrer la derecha e izquierda del arreglo loco
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (vector[i] <= pivot) {
            i++;
            // Cada que se cumple la comparación del while se incrementa el contador
            QSCounter++;
        }

        while (vector[j] > pivot) {
            j--;
            QSCounter++;
        }

        // Comparación de indices, no se suma al contador
        if (i < pivotIndex && j > pivotIndex) {
            swap(vector[i++], vector[j--]);
            // QSCounter++;
        }
    }
    return pivotIndex;
}
 
 // Recorrer el arreglo loco
void quickSort(vector<int>& vector, int start, int end){
    if (start >= end)
        return;

    int p = partition(vector, start, end);
    // recorrer la parte izquierda
    quickSort(vector, start, p - 1);
    // recorrer la parte derecha
    quickSort(vector, p + 1, end);
}

// HeapSort
// Para heapizar el array loco
void heapify(vector<int>& array, int n, int root){
    int mayor = root;
    int izq = 2 * root + 1;
    int der = 2 * root + 2;
    
    // Para cada comparación se incrementa el contador, aunque no se cumpla el estatuto if
    HSCounter++;
    if (izq < n && array[izq] > array[mayor]) mayor = izq;
    HSCounter++;
    if (der < n && array[der] > array[mayor]) mayor = der;
    
    if (mayor != root) {
        swap(array[root], array[mayor]);
        // HSCounter++;
        heapify(array, n, mayor);
    }
}

// Para heapOrdenar el array loco
// Algoritmo consultado de https://www.geeksforgeeks.org/heap-sort/
void heapSort(vector<int>& array){
    int n = array.size();
 
    for (int root = n / 2 - 1; root >= 0; root--)
        heapify(array, n, root);
 
    for (int root = n - 1; root > 0; root--) {
        swap(array[0], array[root]);
        heapify(array, root, 0);
    }
}

// Para bubbleOrdenar el array loco
// Algoritmo consultado de https://www.geeksforgeeks.org/bubble-sort-in-cpp/
void bubbleSort(vector<int>& array){
    int n = array.size();

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            // Para cada comparación del if se suma el contador
            BSCounter++;
            if(array[j] > array[j + 1]) swap(array[j] , array[j + 1]);
        }
    }
}

// Funcion main loco
int main(){
    output.open("output.txt");

    // Se solicita un valor para opcion
    int option;
    cout<<"Selecciona el tamaño del arreglo por ordenar: \n1. 10 elementos\n2. 100 elementos\n3. 1,000 elementos\n4. 10,000 elementos\n5. 100,000 elementos\nSeleccion: ";
    cin>>option;

    int size;
    int sizes[] = {10, 100, 1000, 10000, 100000};

    // Se guarda el tamaño del vector
    if (option >= 1 && option <= 5) size = sizes[option - 1];

    // Inicializacion y llenado del vector original
    vector<int> nums;
    arrayFiller(nums, size);

    // Copias del vector original, para no sobre escribirlo
    vector<int> quickSortArray = nums;
    vector<int> heapSortArray = nums;
    vector<int> bubbleSortArray = nums;
    // Ordenamiento por Quick Sort
    quickSort(quickSortArray, 0, size - 1);
    cout<<"Numero de comparaciones Quick Sort: " << QSCounter << endl;

    // Ordenamiento por heapSort
    heapSort(heapSortArray);
    cout<<"Numero de comparaciones Heap Sort: " << HSCounter << endl;
    
    // Ordenamiento por bubbleSort
    bubbleSort(bubbleSortArray);
    cout<<"Numero de comparaciones Bubble Sort: " << BSCounter << endl;
    output <<"Numero de comparaciones Quick Sort: " << QSCounter << endl;
    output <<"Numero de comparaciones Heap Sort: " << HSCounter << endl;
    output <<"Numero de comparaciones Bubble Sort: " << BSCounter << endl;
    printArray(bubbleSortArray);

    // Correr el arreglo de 0 a 100,000 ya ordenado
    // Inicializacion y llenado del vector original
    vector<int> order;
    arrayFillerInOrder(order);

    // Copias del vector original, para no sobre escribirlo
    quickSortArray = order;
    heapSortArray = order;
    bubbleSortArray = order;

    QSCounter = 0;
    HSCounter = 0;
    BSCounter = 0;

    // Ordenamiento por QuickSort en un arreglo ordenado
    quickSort(quickSortArray, 0, 100000);
    cout<<"Numero de comparaciones Quick Sort en un arreglo ordenado: " << QSCounter << endl;

    // Ordenamiento por heapSort en un arreglo ordenado
    heapSort(heapSortArray);
    cout<<"Numero de comparaciones Heap Sort en un arreglo ordenado: " << HSCounter << endl;
    
    // Ordenamiento por bubbleSort en un arreglo ordenado
    bubbleSort(bubbleSortArray);
    cout <<"Numero de comparaciones Bubble Sort en un arreglo ordenado: " << BSCounter << endl;
    output <<"Numero de comparaciones Quick Sort en un arreglo ordenado: " << QSCounter << endl;
    output <<"Numero de comparaciones Heap Sort en un arreglo ordenado: " << HSCounter << endl;
    output <<"Numero de comparaciones Bubble Sort en un arreglo ordenado: " << BSCounter << endl;
    printArray(heapSortArray);


    output.close();
    return 0;
}

// --------------------------
// Instrucciones de ejecución
// --------------------------
// g++ -o a.out main.cpp 
// ./a.out       
// Seleccionar el tamaño del arreglo a ordenar
// Las primeras impresiones corresponden al resultado del arreglo sin ordenar y finalizando la impresión del arreglo ordenado comienza la impresión del resultado del ordenamiento con el arreglo ordenado
// --------------------------
// Preguntas
// --------------------------
// ¿Cuál de los tres algoritmos hace, en promedio, menos comparaciones? 
// Para obtener el promedio, es necesario correr el programa varias veces comparando los resultados con las diferentes corridas y diferentes tamaños de arreglos. Obtuvimos los siguientes resultados:
// Seleccion: 10 elementos
// Numero de comparaciones Quick Sort: 31
// Numero de comparaciones Heap Sort: 60
// Numero de comparaciones Bubble Sort: 81
// Seleccion: 100 elementos
// Numero de comparaciones Quick Sort: 847
// Numero de comparaciones Heap Sort: 1260
// Numero de comparaciones Bubble Sort: 9801
// Seleccion: 1,000
// Numero de comparaciones Quick Sort: 21209
// Numero de comparaciones Heap Sort: 19160
// Numero de comparaciones Bubble Sort: 998001
// Seleccion: 10,000
// Numero de comparaciones Quick Sort: 245713
// Numero de comparaciones Heap Sort: 258522
// Numero de comparaciones Bubble Sort: 99980001
// Seleccion: 100,000
// Numero de comparaciones Quick Sort: 3127129
// Numero de comparaciones Heap Sort: 3250176
// Numero de comparaciones Bubble Sort: 1409865409
// En promedio, el algoritmo que hace menos comparaciones es el QuickSort, debido a que es un algoritmo con complejidad nlog(n). 
// Sin embargo, en el peor de los casos su complejidad cambia a n^2, dependiendo de cómo esté acomodado el pivote, lo que generaría mayor procesamiento. 
// En este caso se pude observar, como en promedio, el QuickSort es el que realiza menos comparaciones, sin embargo, en comparación del HeapSort, no resulta en una diferencia tan grande como con el BubbleSort
// --------------------------
// ¿Cómo se relaciona el número de comparaciones con las complejidades asintóticas de cada uno de los algoritmos?
// Para lograr comprender la relación entre las complejidades y el número de comparaciones, tenemos que conocer las complejidades de los algoritmos, para las cuales son las siguientes:
// QuickSort = n(logn), pero en el peor de los casos puede incrementar hasta n^2
// HeapSort = n(logn)
// BubbleSort = n^2
// Las comparaciones realizadas tienen una relación con las complejidades de los algoritmos, de tal manera entre mayor sea la complejidad, mayor serán las comparaciones realizadas.
// Debido a que la complejidad representa las veces en la que se itera a través de las funciones, por lo que, entre más funciones se tenga que iterar, mayor serán las comparaciones. 
// --------------------------
// Ejecuten sus tres algoritmos con arreglos de tamaño 100,000 que ya estén ordenados 
// (esto es muy fácil de generar, o pueden usar alguno de los arreglos que ya ordenaron). 
// ¿Cómo se comparan los algoritmos entre sí con los arreglos ordenados?
// Mediante la realización de los arreglos ordenados, se puede observar cómo el número de comparaciones supera el millón, debido a que se está tratando con un arreglo de 100,000.
// El BubbleSort supera los mil millones de comparaciones, el QuickSort supera los 700 millones y finalmente el heapSort supera los 3 millones. 
// Mediante el quickSort se puede observar que el acomodo del pivote probablemente no sea el óptimo y resulte en un peor caso, generando casi la mitad de comparaciones que el BubbleSort.
// De otra manera, el HeapSort resulta en el algoritmo más eficaz para el "ordenamiento" de arreglos ya ordenados. 
// De manera general, resulta más práctico utilizar el algoritmo QuickSort para el ordenamiento de pocos elementos, sin embargo, para un ordenamiento como el de 100,000 elementos, 
// puede resultar más efectivo utilizar el HeapSort, debido a que en muchas ocasiones resultará menor al quickSort y resulta en un algoritmo más constante en sus comparaciones.

