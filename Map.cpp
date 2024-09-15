#include "Map.h"
#include "texture_manager.h"

int lvl1[20][25] = {
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
    {2,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2},
    {2,1,0,2,0,1,2,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2},
    {2,1,0,2,0,1,2,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2},
    {2,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2},
    {2,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2},
    {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
    {2,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2},
    {2,1,0,2,0,1,2,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2},
    {2,1,0,2,0,1,2,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2},
    {2,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2},
    {2,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2},
    {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
    {2,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
};



Map::Map()
{
    dirt = TextureManager::LoadTexture("MapAssets/dirt.pmg.png");
    water = TextureManager::LoadTexture("MapAssets/water.png");
    grass = TextureManager::LoadTexture("MapAssets/grass_tile.png");
    LoadMap (lvl1);

    src.x=0;
    src.y=0;
    dest.x=0;
    dest.y=0;

    src.w=32;
    src.h=32;
    dest.w=32;
    dest.h=32;

}

void Map::LoadMap(int arr[20][25])
{
    for (int row = 0; row<20;row++)
    {
        for (int col =0; col<25; col++)
        {
            map[row][col] = arr[row][col];
        }
    }
}
void Map::DrawMap()
{
  int type =0;
  for (int row = 0; row<20;row++)
    {
        for (int col =0; col<25; col++)
        {
            type=map[row][col];
            dest.x=col*32;
            dest.y=row*32;

            switch (type)
            {
                case 0:
                    TextureManager::draw(water,src,dest);
                    break;

                case 1:
                    TextureManager::draw(grass,src,dest);
                    break;
                case 2:
                    TextureManager::draw(dirt,src,dest);
                    break;

                default:
                    break;
            }
        }
    }
}
bool Map::isWaterTile(int x, int y) {
    int row = y / 32;
    int col = x / 32;
    if (row >= 0 && row < 20 && col >= 0 && col < 25) {
        return map[row][col] == 0;  // Check if the tile is water (0)
    }
    return false;
}


