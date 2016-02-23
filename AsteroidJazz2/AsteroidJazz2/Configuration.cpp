#include <Configuration.hpp>
#include "Random.hpp"


ActionMap<int> Configuration::playerInputs;

ResourceManager<sf::Texture,int> Configuration::textures;
ResourceManager<sf::Font,int> Configuration::fonts;
ResourceManager<sf::SoundBuffer,int> Configuration::sounds;
ResourceManager<sf::Music,int> Configuration::musics;

int Configuration::level;
int Configuration::lives;

Player* Configuration::player = nullptr;

int Configuration::_score;
sf::Text   Configuration::_txt_score;
sf::Sprite Configuration::_spr_life;

    void Configuration::initialize()
    {
        initTextures();
        initFonts();
        initSounds();
        initMusics();
        
        initPlayerInputs();
        
        rand_init();
        _txt_score.setFont(fonts.get(Fonts::Gui));
        _txt_score.setCharacterSize(24);
        
        _spr_life.setTexture(textures.get(Textures::PlayerLife));
        
        musics.get(Musics::Theme).setLoop(true);
        musics.get(Musics::Theme).play();
        
        lives = level = _score = -1;
    }

void Configuration::reset()
{
    level = 1;
    lives = 3;
    
    _score = 0;
    _txt_score.setString("0");
}

bool Configuration::isGameOver()
{
    return lives < 0;
}

void Configuration::addScore(int s)
{
    int old_score = _score;
    _score += s*level;
    lives += _score/10000 - old_score/10000;
    _txt_score.setString(std::to_string(_score));
}

int Configuration::getScore()
{
    return _score;
}

void Configuration::draw(sf::RenderTarget& target)
{
    target.draw(_txt_score);
    for(int i = 0;i< lives;++i)
    {
        _spr_life.setPosition(40*i,40);
        target.draw(_spr_life);
    }
}


void Configuration::initTextures()
{
    //player
    textures.load(Textures::Player,"Player/Ship.png");
    textures.load(Textures::PlayerLife,"Player/life.png");
    //saucers
    textures.load(Textures::BigSaucer,"Saucer/Big.png");
    textures.load(Textures::SmallSaucer,"Saucer/Small.png");
    //meteors
    textures.load(Textures::BigMeteor1,"Meteor/Big1.png");
    textures.load(Textures::BigMeteor2,"Meteor/Big2.png");
    textures.load(Textures::BigMeteor3,"Meteor/Big3.png");
    textures.load(Textures::BigMeteor4,"Meteor/Big4.png");
    
    textures.load(Textures::MediumMeteor1,"Meteor/Medium1.png");
    textures.load(Textures::MediumMeteor2,"Meteor/Medium2.png");
    
    textures.load(Textures::SmallMeteor1,"Meteor/Small1.png");
    textures.load(Textures::SmallMeteor2,"Meteor/Small2.png");
    textures.load(Textures::SmallMeteor3,"Meteor/Small3.png");
    textures.load(Textures::SmallMeteor4,"Meteor/Small4.png");
    //lasers
    textures.load(Textures::ShootPlayer,"Shoot/Player.png");
    textures.load(Textures::ShootSaucer,"Shoot/Saucer.png");
}

void Configuration::initFonts()
{
    fonts.load(Fonts::Gui,"font/trs-million.ttf");
}

void Configuration::initSounds()
{
    //laser
    sounds.load(Sounds::LaserPlayer,"sounds/laser1.ogg");
    sounds.load(Sounds::LaserEnemy,"sounds/laser2.ogg");
    //saucers
    sounds.load(Sounds::SaucerSpawn1,"sounds/spawn1.flac");
    sounds.load(Sounds::SaucerSpawn2,"sounds/spawn2.flac");
    // Boom
    sounds.load(Sounds::Boom,"sounds/boom.flac");
    sounds.load(Sounds::Boom2,"sounds/boom2.flac");
    // Explosion
    sounds.load(Sounds::Explosion1,"sounds/explosion1.flac");
    sounds.load(Sounds::Explosion2,"sounds/explosion2.flac");
    sounds.load(Sounds::Explosion3,"sounds/explosion3.flac");
    //others
    sounds.load(Sounds::Jump,"sounds/hyperspace.flac");
}

void Configuration::initMusics()
{
    musics.load(Musics::Theme,"musics/theme.ogg");
}

void Configuration::initPlayerInputs()
{
    playerInputs.map(PlayerInputs::Up,Action(sf::Keyboard::Up));
    playerInputs.map(PlayerInputs::Right,Action(sf::Keyboard::Right));
    playerInputs.map(PlayerInputs::Left,Action(sf::Keyboard::Left));
    playerInputs.map(PlayerInputs::Hyperspace,Action(sf::Keyboard::Down,Action::Type::Released));
    playerInputs.map(PlayerInputs::Shoot,Action(sf::Keyboard::Space));
}


