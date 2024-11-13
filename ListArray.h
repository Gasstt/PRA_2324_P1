#include <ostream>
#include "List.h"
using namespace std;

template <typename T>
class ListArray : public List<T> {

private:
	
	T* arr; 	//puntero al array de elementos de tipo T
	int max;	//tamaño max. actual del array
	int n;		//num. de elementos en la lista
	static const int MINSIZE = 2;	//tamaño min. del array

	void resize(int new_size){	//redimensionar el array
	
		T* new_arr = new T[new_size];
		for(int i = 0; i < n; ++i){
			new_arr[i] = arr[i];
		}
		delete[] arr;
		arr = new_arr;
		max = new_size;
	}
public:

	ListArray() : arr(new T[MINSIZE]), max(MINSIZE) , n(0){}	//constructor
	
	~ListArray(){	//destructor

		delete[] arr;	//libera la memoria asignada al array dinamico	
	}

	//implementación de los métodos públicos heredados de la interfaz List
	
	void insert(int pos, T e){
		if(pos < 0 || pos > n){
			throw out_of_range("posicion invalida");
		}

		//redimensionar si el array esta lleno
		if(n == max){
			resize(max * 2);
		}

		//desplazar elementos para hacer eswpacio en la posicion 'pos'
		for(int i = n; i > pos; i--){
			arr[i] = arr[i - 1];
		}

		arr[pos] = e;
		++n;
	}	
	

	void append(T e){
		insert(n, e);
	}

	void prepend(T e){
		insert(0, e);
	}

	T remove(int pos){
		if(pos < 0 || pos>= n){
			throw out_of_range("posicion invalida");
		}

		T removed_element = arr[pos];
		
		for(int i = pos; i < n - 1; i++){
			arr[i] = arr[i + 1];
		}
		--n;

		if(n < max / 4 && max / 2 >= 2 * MINSIZE){
			resize(max / 2);
		}

	return removed_element;

	}	

	T get(int pos){
		if(pos < 0 || pos >= n){
			throw out_of_range ("posicion invalida");
		}
		return arr[pos];
	}

	int search(T e){
		for(int i = 0; i < n; ++i){
			if(arr[i] == e){
				return i;
			}
		}
		return -1;
	}

	bool empty(){
		return n == 0;
	}

	int size(){
		return n;
	
	}

	T operator[](int pos){	//sobrecarga del operador []

		if(pos < 0 || pos >= n){
			throw out_of_range("posicion invalida");
		}
		return arr[pos];
	}
	
	friend ostream& operator<<(ostream& out, const ListArray<T>& list){
	
		out<< "[";
		for(int i = 0; i < list.n; i++){
		
			out << list.arr[i];

			if(i < list.n - 1){
			
				out << ", ";
			}
		}
		out << "]";
		return out;

	
	}
	
	


};
