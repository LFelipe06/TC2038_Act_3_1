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
    int value;
    for (int i = 0 ; i < x; i++){
        value = rand() % 100000;
        vector.push_back(value);
    }
}

// Llenar el array loco en orden del 0 al 100,000
void arrayFillerInOrder(vector<int>& vector) {
    int value;
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
        if (vector[i] <= pivot)
            count++;
            // QSCounter++;
    }
    // Moviendo el pivote a su posición loca
    int pivotIndex = start + count;
    swap(vector[pivotIndex], vector[start]);
 
    // Recorrer la derecha e izquierda del arreglo loco
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (vector[i] <= pivot) {
            i++;
            QSCounter++;
        }
        while (vector[j] > pivot) {
            j--;
            QSCounter++;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(vector[i++], vector[j--]);
            QSCounter++;
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
 
    if (izq < n && array[izq] > array[mayor]){
        mayor = izq;
        HSCounter++;
    }
 
    if (der < n && array[der] > array[mayor]){
        mayor = der;
        HSCounter++;
    }
        
 
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
            if(array[j] > array[j + 1]) swap(array[j] , array[j + 1]);
            BSCounter++;
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

    // // Correr el arreglo de 0 a 100,000 ya ordenado
    // // Inicializacion y llenado del vector original
    // vector<int> order;
    // arrayFillerInOrder(order);

    // // Copias del vector original, para no sobre escribirlo
    // vector<int> quickSortArray = order;
    // vector<int> heapSortArray = order;
    // vector<int> bubbleSortArray = order;

    // // Ordenamiento por QuickSort
    // quickSort(quickSortArray, 0, 100001);
    // cout<<"Numero de comparaciones Quick Sort: " << QSCounter << endl;

    // // Ordenamiento por heapSort
    // heapSort(heapSortArray);
    // cout<<"Numero de comparaciones Heap Sort: " << HSCounter << endl;
    
    // // Ordenamiento por bubbleSort
    // bubbleSort(bubbleSortArray);
    // cout <<"Numero de comparaciones Bubble Sort: " << BSCounter << endl;
    // output <<"Numero de comparaciones Quick Sort: " << QSCounter << endl;
    // output <<"Numero de comparaciones Heap Sort: " << HSCounter << endl;
    // output <<"Numero de comparaciones Bubble Sort: " << BSCounter << endl;
    // printArray(heapSortArray);


    output.close();
    return 0;
}


// ¿Cuál de los tres algoritmos hace, en promedio, menos comparaciones? 
// En promedio, el algoritmo que hace menos comparaciones es el QuickSort, debido a que es un algoritmo con complejidad nlog(n). 
// Sin embargo, en el peor de los casos su complejidad cambia a n^2, dependiendo de cómo esté acomodado el pivote, lo que generaría más procesamiento. 
// En este caso se pude observar

// ¿Cómo se relaciona el número de comparaciones con las complejidades asintóticas de cada uno de los algoritmos?
// Las comparaciones realizadas tienen una relación con las complejidades de los algoritmos, de tal manera entre mayor sea la complejidad, mayor serán las comparaciones realizadas.

// Ejecuten sus tres algoritmos con arreglos de tamaño 100,000 que ya estén ordenados 
// (esto es muy fácil de generar, o pueden usar alguno de los arreglos que ya ordenaron). 
// ¿Cómo se comparan los algoritmos entre sí con los arreglos ordenados?
//  Realizando una comparación con arreglos arreglos ordenados, se puede observar la diferencia en las comparaciones de los algoritmos. Se observa que mediante el QuickSort, se realizan 50000 comparaciones,
//  mediante el HeapSort se realizan 2303212 comparaciones y finalmente para el BubbleSort se realizan más de mil millones de comparaciones. 
// 

