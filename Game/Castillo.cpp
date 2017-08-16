
Castillo::Castillo(){};
Castillo::Castillo(std::string NAME,std::string DESC,int HP,int DEFENSE,int SIZE, int X, int Y){
    name = NAME;
    description = DESC;
    hp = HP;
    defense = DEFENSE;
    size = SIZE;

    sprite = new Sprite();
    sprite->agregarFrame(0,TILE_H,TILE_W*2,TILE_H*2);

    x = X;
    y = Y;
};
Castillo::~Castillo(){};


void Castillo::update(){

};