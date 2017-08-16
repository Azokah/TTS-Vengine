
Aldea::Aldea(){};
Aldea::Aldea(std::string NAME,std::string DESC,int HP,int DEFENSE,int SIZE, int X, int Y){
    name = NAME;
    description = DESC;
    hp = HP;
    defense = DEFENSE;
    size = SIZE;

    sprite = new Sprite();
    sprite->agregarFrame(TILE_W*2,TILE_H,TILE_W*2,TILE_H*2);

    x = X;
    y = Y;
};
Aldea::~Aldea(){};


void Aldea::update(){

};