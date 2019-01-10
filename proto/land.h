struct Tile
{
    int x;
    int y;
    tiny *pressures;
    struct MU *Mu;
};

struct Land
{
    int size;
    tiny *worldPressure;
    struct Tile **tiles;
};
