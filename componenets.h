#ifndef COMPONENETS_H_INCLUDED
#define COMPONENETS_H_INCLUDED



/**
      1  2   3
   a  --------
     | \ |  / |
     |  \| /  |
   b |--------|
     |   /\   |
     |  /| \  |
   c  --------
*/
//positions on board
/*
    Vector2typedef struct Vector2 {
    float x;                // Vector x component
    float y;                // Vector y component
} Vector2;
*/
const Vector2 b1={60,400};
const Vector2 b2={500,400};
const Vector2 b3={940,400};
const Vector2 c1={60,740};
const Vector2 c2={500,740};
const Vector2 c3={940,740};
const Vector2 a1={60,60};
const Vector2 a2={500,60};
const Vector2 a3={940,60};


void menu();
void play_dama_with_computer();
#define PHYSAC_IMPLEMENTATION
#define VELOCITY    0.5f

#endif // COMPONENETS_H_INCLUDED
