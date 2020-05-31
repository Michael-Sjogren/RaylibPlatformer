#include "Player.hpp"

void Player::Update(float delta){
    isGrounded = body->isGrounded;
    position = body->position;
    int x = (IsKeyDown(KEY_D)) - (IsKeyDown(KEY_A));
    bool jump = IsKeyPressed(KEY_SPACE) && isGrounded;
    //const int y = (IsKeyPressed(KEY_W)) - (IsKeyPressed(KEY_S));
    Vector2 moveDirection = {(float)x,0};
    if (!isGrounded){
        x = 0;
    }
    Vector2 velocity = Vector2Multiply(moveDirection , {.2*delta,.2*delta});
    body->velocity = velocity;
    if (jump){
        Jump();
    }
}
void Player::Jump(){
    body->force=Vector2{
        x:0,
        y:200
    };
}
void Player::Draw(){
    DrawRectangle(position.x , position.y , dimenstions.x , dimenstions.y , RED);
}
