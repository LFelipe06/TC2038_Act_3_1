#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

// Variables contadoras para cada metodo de ordenamiento
int QSCounter = 0;
int HSCounter = 0;
int BSCounter = 0;

// Para llenar el array loco
void arrayFiller(vector<int>& vector, int x){
    int value;
    for (int i = 0 ; i < x; i++){
        value = rand() % 100000;
        vector.push_back(value);
    }
}

// Para imprimir el array loco
void printArray(vector<int>& vector){
    for (int i=0; i < vector.size(); i ++){
        cout<<vector[i]<<" ";
    }
    cout<<endl;
}

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
 
        heapify(array, n, mayor);
    }
}

// Para heapOrdenar el array loco
void heapSort(vector<int>& array){
    int n = array.size();
 
    for (int root = n / 2 - 1; root >= 0; root--)
        heapify(array, n, root);
 
    for (int root = n - 1; root > 0; root--) {
        swap(array[0], array[root]);
        heapify(array, root, 0);
    }
}

// Funcion main loco
int main(){
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

    // Ordenamiento por heapSort
    heapSort(heapSortArray);
    printArray(heapSortArray);
    cout<<"Numero de comparaciones Heap Sort: " << HSCounter << endl;

    

    return 0;
}