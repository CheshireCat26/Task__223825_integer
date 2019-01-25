#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void heapSort(vector<int> &mass);
void outMass(vector<int> &mass);

int main() {
    cout << "Enter full file name: ";
    string fileName;
    cin >> fileName;

    ifstream iFile(fileName);
    int num; //number of digits
    iFile >> num;

    vector<int> mass;
    for (int i = 0; i < num; i++){
        int temp;
        iFile >> temp;
        mass.push_back(temp);
    }

    cout << "Unsorted mass: ";
    outMass(mass);

    heapSort(mass);

    cout << "Sorted mass: ";
    outMass(mass);
    return 0;
}

void outMass(vector<int> &mass){
    for (int i : mass)
        cout << i << " ";
    cout << endl;
}

void buildTree(vector<int> &mass,int root, int size);
void heapSort(vector<int> &mass){
    unsigned long long int m = mass.size() / 2;//number of root
    unsigned long long int r = mass.size();

    while (m > 0) {
        buildTree(mass, m - 1, r);
        swap(mass[0], mass[r - 1]);
        r--;
        m = r / 2;
    }
}

void recBuildTree(vector<int> &mass,int root, int size);
void buildTree(vector<int> &mass,int root, int size){
    for (int i = root; i >= 0; i--){
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if ((mass[left] > mass[right] && mass[i] < mass[left]) || (right >= size && mass[i] < mass[left])){
            swap(mass[left], mass[i]);
            recBuildTree(mass, left, size);
        }
        else if (right < size && mass[right] > mass[left] && mass[i] < mass[right]){
            swap(mass[right], mass[i]);
            recBuildTree(mass, right, size);
        }
    }
}

void recBuildTree(vector<int> &mass,int root, int size){
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if ((right >= size && mass[root] < mass[left]) || (mass[left] > mass[right] && mass[root] < mass[left])){
        swap(mass[left], mass[root]);
        recBuildTree(mass, left, size);
    }
    else if (right < size && mass[right] > mass[left] && mass[root] < mass[right]){
        swap(mass[right], mass[root]);
        recBuildTree(mass, right, size);
    }
}