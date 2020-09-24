#include "Matrix.h"

Matrix::Matrix(int rowSize, int colSize){
    this->rowSize = rowSize;
    this->colSize = colSize;
    //create the space for the matrix 
    this->ptr = new int*[this->rowSize];
    for (int i {0}; i < this->rowSize; i++){
        this->ptr[i] = new int[this->colSize];
    }
}

Matrix::~Matrix(){ // need to creat destructor because we are dynammically allocating memory on the heap
    for(int i {0}; i < this->rowSize; i++){
        delete [] this->ptr[i];
    }
    delete [] this->ptr;
}

void Matrix::inputMatrix(){
    int n {};
    for (int i {0}; i<this->rowSize; i++){
        for (int j {0}; j<this->colSize; j++){
            cin >> n;
            this->ptr[i][j] = n;
        }
    }
}

void Matrix::print() const{
    for (int i {0}; i < this->rowSize; i++){
        for (int j {0}; j < this->colSize; j++){
            cout << this->ptr[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::add(const Matrix &second, Matrix &result) const{
    if ((this->colSize == second.colSize) && (this->rowSize == second.rowSize)){
        for (int i {0}; i < this->rowSize; i++){
            for (int j {0}; j < this->colSize; j++){
                result.ptr[i][j] = this->ptr[i][j] + second.ptr[i][j];
            }
        }
    }
    else{
        cout << "Operation not valid with given matrices" << endl;
    }
}

void Matrix::subtract(const Matrix &second, Matrix &result) const{
    if ((this->colSize == second.colSize) && (this->rowSize == second.rowSize)){
        for (int i{0}; i < this->rowSize; i++){
            for (int j{0}; j < this->colSize; j++){
                result.ptr[i][j] = this->ptr[i][j] - second.ptr[i][j];
            }
        }
    }
    else{
        cout << "Operation not valid with given matrices" << endl;
    }
}

void Matrix::multiply(const Matrix &second, Matrix &result) const{
    if ((this->colSize == second.rowSize)){
        for (int i {0}; i < this->rowSize; i++){
            for (int j {0}; j < second.colSize; j++){
                for (int k {0}; k < this->colSize; k++){
                    result.ptr[i][j] += this->ptr[i][k] * second.ptr[k][j];
                }
            }
        }
    }
    else{
        cout << "Operation not valid with given matrices" << endl;
    }
}