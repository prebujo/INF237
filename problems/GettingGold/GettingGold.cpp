#include <iostream>
#include <algorithm>


using namespace std;

//oppretter feltvariabler
int gold;
int width;
int height;

//funksjon type dfs som blir kalt rekursivt
void dfs(int x, int y, char maze[]){
    //sjekker om man landet på gull og itererer da gull, bruker bredde*y + x for å representere en høyde*bredde matrise
    if (maze[width*(y) + x] == 'G')
        gold++;
    //oppdaterer denne ruten som en vegg slik at den ikke blir besøkt igjen.
    maze[width*(y) + (x)] = '#';

    //sjekker om noen av naboene gir spilleren en "draft", i så fall skal vi ikke gå videre. Hvis ikke kjører vi rekursivt på alle mulige ruter.
    if ((maze[width*(y+1) + x] == 'T') || (maze[width*(y-1) + x] =='T') || (maze[width*(y) + (x+1)] == 'T') || (maze[width*(y) + (x-1)] == 'T')){
        return;
    }
    else {
        if (maze[width*(y+1) + x] != '#')
            dfs(x, y+1, maze);
        if (maze[width*(y-1) + x] != '#')
            dfs(x, y-1, maze);
        if (maze[width*(y) + (x+1)] != '#')
            dfs(x+1, y, maze);
        if (maze[width*(y) + (x-1)] != '#')
            dfs(x-1, y, maze);
    }
    return;
}

int main() {
    //begynner med å ta input fra brukeren om størrelsen på maze'en og oppretter denne
    cin >> width;
    cin >> height;
    char maze [width*height + 1];

    //oppretter så startposisjon
    int startx;
    int starty;
    
    //oppretter deretter labyrinten og husker startpunktet
    for (int i = 0; i < height; ++i) {
        for (int j = 1; j <= width; ++j) {
            cin >> maze[width*i + j];
            if (maze[width*i + j] == 'P'){
                startx = j;
                starty = i;
            }
        }
    }
    //kjører dfs med startutgangspunkt og labyrinten. Deretter skriver man ut gold.
    dfs(startx, starty, maze);
    cout << gold;
    return 0;
}
