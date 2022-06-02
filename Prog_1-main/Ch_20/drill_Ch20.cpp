#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

template<typename C>
void print(const C& c){
	for(auto& data : c){
		cout << data << ' ';
	}
	cout << endl;
}

template<typename C>
void inc(C& c, double n){
	for(auto& i : c){
		i += n;
	}
}


template<typename Iter1, typename Iter2>
Iter2 copy2(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 p = f1; p != e1; ++p){
		*f2++=*p; 
	}
	
	return f2;
}

int main(){

try{

	constexpr int size = 10;
	
	int arr[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	/*vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	  list<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};*/
	 
	array<int, size> ai;  //array osztálynak ai példánya
	copy(arr, arr+size, ai.begin());
	
	
	
	vector<int> vi(size);  
	copy(arr, arr+size, vi.begin());
	
	list<int> li(size);  
	copy(arr, arr+size, li.begin());
	
	//másolás:
	array<int, size> ai2 = ai;
	vector<int> vi2 = vi;
	list<int> li2 = li;
	
	print(ai);
	print(vi);
	print(li);
	
	inc(ai2, 2);
	inc(vi2, 3);
	inc(li2, 5);
	
	print(ai2);
	print(vi2);
	print(li2);
	
	copy2(ai2.begin(), ai2.end(), vi2.begin());
	copy2(li2.begin(), li2.end(), ai2.begin());
	
	print(ai2);
	print(vi2);
	print(li2);
	
	// 3 keresése a vectorban:
	
	auto res_v = find(vi2.begin(), vi2.end(), 3);
	if (res_v != vi2.end())
		cout << "vi2 contains 3 at position: " << distance(vi2.begin(), res_v) << endl;
		//distance: megadja az első és második paraméter közötti ugrások számát
	else
		cout << "vi2 does not contain 3" << endl;
		
	// 27 keresése a list-ben:
	auto res_l = find(li2.begin(), li2.end(), 27);
	if (res_l != li2.end())
		cout << "li2 contains 27 at position: " << distance(li2.begin(), res_l) << endl;
	else
		cout << "li2 does not contain 27" << endl;

}
catch(exception& e){
	cerr << e.what() << '\n';
}
catch(...){
	cerr << "Error" << '\n';
}

}
