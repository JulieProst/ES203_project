#include <stdexcept>
#include <algorithm>
#define CONSTANTE_K_PPV 9

int distanceEuclidienne(Point a, Point b){
    int j=0;
    if (a.coord.size() != b.coord.size()) {
        throw std::runtime_error("Les deux points n'ont pas le même nombre de coordonnées, distance impossible à calculer");}
    for (int i=0, i<a.coord.size,i++) {
        j = j + (a.coord[i]-b.coord[i])*(a.coord[i]-b.coord[i]);
    }
    return j;
}

class Couple {
private:
    int distance;
    int etiquette;
public :
    Couple(int d, int e) {
        distance=d;
        etiquette=e;
    }
};

bool operator<(Couple a,Couple b) {
    return a.distance<b.distance
}

int kppv(const std::vector<Point >& graph, Point pt_rec) {
    std::vector<Couple> distances;
    std::vector<int> chiffres;
    for (int i=0; i<graph.size(); i++) {
        distances.push_back(distanceEuclidienne(graph[i], pt_rec));

    }
    std::sort(distances.begin(), distances.end());
    for (int i=0; i<CONSTANTE_K_PPV; i++) {
        chiffres.push_back(distances[i].etiquette);
        }
    std::sort(chiffres.begin(), chiffres.end());
    int chiffre =0; //ce qu'on va trouver comme résultat, le chiffre décrypté
    int maxi=0 ; //nombre d'occurence max
    int compteur=1; //nb de fois que chaque chiffre du tableau arrive
    int max_double =0; //si on a le meme nombre de fois l'occurence max
    for (int i=0; i<CONSTANTE_K_PPV; i++) {
        if (chiffres[i]==chiffres[i+1]){
                compteur ++;
        }
        else {
            if (compteur>maxi){
                maxi = compteur;
                chiffre = chiffres[i];
            }
            else { //compteur = max
                    if (compteur==maxi) {
                        max_double = compteur;
                    }
            }
            compteur=1;
        }

    }
    if (max_double== maxi) {
        return(-1);
    }
    return chiffre;
}
