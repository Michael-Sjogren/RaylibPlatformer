#include "common.hpp"
class Player
{
private:
    /* data */
public:
    Vector2 position;
    Vector2 dimenstions = (Vector2){40,40};
    float density = 1;
    PhysicsBody body;
    Player(Vector2 pos);
    bool isGrounded = false;
    void Jump();
    void Update(float delta);
    void Draw();
    ~Player();
};

Player::Player(Vector2 pos) : position(pos)
{
    body = CreatePhysicsBodyRectangle(position,dimenstions.x , dimenstions.y,density);
    body->enabled = true;
    body->useGravity = true;
}

Player::~Player()
{
    DestroyPhysicsBody(body);
}