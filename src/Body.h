#ifndef BODY_H_INCLUDED
#define BODY_H_INCLUDED

#include <Box2D.h>
#include <Allegro.h>

#include "MathUtils.h"
#include "GameUtils.h"

class Body
{
public:
    b2Body *body;
    BITMAP *bmp;
    bool markedForDeletion, isBomb;

    Body(b2Body *_body)
    {
        body = _body;
        body->SetUserData(this);
        markedForDeletion = false;
        isBomb = false;
    }

    Body(b2Body *_body, BITMAP *_bmp)
    {
        body = _body;
        body->SetUserData(this);
        markedForDeletion = false;
        isBomb = false;
        bmp = _bmp;
    }

    ~Body(void)
    {
        destroy_bitmap(bmp);
        getWorld()->DestroyBody(body);
    }

    b2World* getWorld(void)
    {
        return body->GetWorld();
    }

    b2Vec2 getB2Position(void)
    {
        return body->GetWorldCenter();
    }

    Point getAllegPosition(void)
    {
        return coordB2ToAlleg(getB2Position());
    }

    bool operator==(Body *b)
    {
        return body == b->body;
    }
};

#endif // BODY_H_INCLUDED
