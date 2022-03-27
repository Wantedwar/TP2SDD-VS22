#include "utils.h"


int getrn() {
    //int temp;
    std::random_device rd;
    unsigned int seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    //std::mt19937 mt(rd());    
    static std::mt19937 mt{seed};
    std::uniform_int_distribution<int> dist(0, 256);
    return dist(mt);
}


noeud creerpop()
{
	//noeud temp;


	//return temp;
	return noeud(1, 2, 3);
};
