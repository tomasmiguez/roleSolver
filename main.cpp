#include <iostream>
#include <numeric>
#include <algorithm>

const int CANT_GAMERS = 5;

using namespace std;

bool checkearDistri(int roles[CANT_GAMERS][5], int curInd[5], int seJode) {
    bool rolesOcupados[5] = {0, 0, 0, 0, 0};
    for(int gamerAct=0; gamerAct<CANT_GAMERS; gamerAct++) {
        if(gamerAct != seJode) {
            if(rolesOcupados[roles[gamerAct][curInd[gamerAct]]]) {
                return false;
                break;
            }
            rolesOcupados[roles[gamerAct][curInd[gamerAct]]] = true;
        }
    }
    return true;
}

int main()
{
    const int seJode = -1;

    string rolName[CANT_GAMERS] = {"TOP", "JG", "MID", "ADC", "SUPP"};
    string gamerName[CANT_GAMERS] = {"GON", "KAI", "SEBA", "NATITO", "YO"};

    int roles[CANT_GAMERS][5] = { ///Los roles van top a supp empezando en 0.
                3, 4, 1, 0, 2, //Gon
                3, 2, 4, 1, 0, //Kai
                1, 2, 0, 3, 4, //Seba
                1, 4, 0, 2, 3, //Natito
                4, 2, 3, 0, 1  //Yo
                };

    int curInd[CANT_GAMERS];
    for(int i=0; i<CANT_GAMERS; i++) {
        curInd[i] = 0;
    }

    cout << "MAS JUSTO: \n\n";

    for(int desp=1; desp<5; desp++) {
        for(int prioIndex=0; prioIndex<5; prioIndex++) {\
            for(int gamerIndex=0; gamerIndex<CANT_GAMERS; gamerIndex++) {

                if(checkearDistri(roles, curInd, seJode)) {
                    for(int mostrarIndex=0; mostrarIndex<CANT_GAMERS; mostrarIndex++) {
                        if(mostrarIndex != seJode) cout << gamerName[mostrarIndex] << ": " << rolName[roles[mostrarIndex][curInd[mostrarIndex]]] << endl;
                    }
                    goto optimo; //XD
                }

                for(int gamerAct=0; gamerAct<5; gamerAct++) {
                    if(curInd[gamerAct]+desp < 5) {
                        curInd[gamerAct]+=desp;
                        if(checkearDistri(roles, curInd, seJode)) {
                            for(int mostrarIndex=0; mostrarIndex<CANT_GAMERS; mostrarIndex++) {
                                if(mostrarIndex != seJode) cout << gamerName[mostrarIndex] << ": " << rolName[roles[mostrarIndex][curInd[mostrarIndex]]] << endl;
                            }
                            goto optimo; //XD
                        }
                        curInd[gamerAct]-=desp;
                    }
                }

                curInd[gamerIndex]++;
            }
        }
    }

    //---------------------------
    optimo:

    for(int i=0; i<CANT_GAMERS; i++) {
        curInd[i] = 0;
    }
    int bestInd[CANT_GAMERS];
    for(int i=0; i<CANT_GAMERS; i++) {
        bestInd[i] = 0;
    }

    int minim = 16;

    for(int i0=0; i0<5; i0++) {
        for(int i1=0; i1<5; i1++) {
            for(int i2=0; i2<5; i2++) {
                for(int i3=0; i3<5; i3++) {
                    for(int i4=0; i4<5; i4++) {
                        if(checkearDistri(roles, curInd, seJode)) {
                            if(accumulate(curInd,curInd+5,0)<=minim) {
                                minim = accumulate(curInd,curInd+5,0);
                                copy(curInd, curInd+5, bestInd);
                            }
                        }
                        curInd[4]++;
                    }
                    curInd[4]=0;
                    curInd[3]++;
                }
                curInd[3]=0;
                curInd[2]++;
            }
            curInd[2]=0;
            curInd[1]++;
        }
        curInd[1]=0;
        curInd[0]++;
    }

    cout << "\n\nOPTIMO: \n";

    /*for(int mostrarIndex=0; mostrarIndex<CANT_GAMERS; mostrarIndex++) {
        if(mostrarIndex != seJode) cout << gamerName[mostrarIndex] << ": " << rolName[roles[mostrarIndex][bestInd[mostrarIndex]]] << endl;
    }*/

//----------------

    for(int i=0; i<CANT_GAMERS; i++) {
        curInd[i] = 0;
    }

    for(int i0=0; i0<5; i0++) {
        for(int i1=0; i1<5; i1++) {
            for(int i2=0; i2<5; i2++) {
                for(int i3=0; i3<5; i3++) {
                    for(int i4=0; i4<5; i4++) {
                        if(checkearDistri(roles, curInd, seJode)) {
                            if(accumulate(curInd,curInd+5,0)==minim) {
                                cout << endl;
                                for(int mostrarIndex=0; mostrarIndex<CANT_GAMERS; mostrarIndex++) {
                                    if(mostrarIndex != seJode) cout << gamerName[mostrarIndex] << ": " << rolName[roles[mostrarIndex][curInd[mostrarIndex]]] << endl;
                                }
                            }
                        }
                        curInd[4]++;
                    }
                    curInd[4]=0;
                    curInd[3]++;
                }
                curInd[3]=0;
                curInd[2]++;
            }
            curInd[2]=0;
            curInd[1]++;
        }
        curInd[1]=0;
        curInd[0]++;
    }
}
