#ifndef PONG_H
#define PONG_H
#include <iostream>
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

enum _moveState {
    MS_STOP,
    MS_UP,
    MS_DOWN,
  };


class Pong : public Test {

    private :
  
      //class member variables
      b2Body* rack1;
      b2Body* rack2;
      b2Body* ball;
      _moveState p1moveState;
      _moveState p2moveState;
  
  public :

      Pong() {
        //body definition
        b2BodyDef myBodyDef;
        myBodyDef.type = b2_dynamicBody;
        
        //shape definition
        b2PolygonShape polygonShape;
        polygonShape.SetAsBox(1, 7); //a 2x2 rectangle
      
        //fixture definition
        b2FixtureDef myFixtureDef;
        myFixtureDef.shape = &polygonShape;
        myFixtureDef.density = 1;
        
        //create dynamic body
        myBodyDef.position.Set(19, 10);
        rack1 = m_world->CreateBody(&myBodyDef);
        rack1->CreateFixture(&myFixtureDef);
        rack1->SetGravityScale(0);
        rack1->SetFixedRotation(true);

        myBodyDef.position.Set(-19,10);
        rack2=m_world->CreateBody(&myBodyDef);
        rack2->CreateFixture(&myFixtureDef);
        rack2->SetGravityScale(0);
        rack2->SetFixedRotation(true);
        
        //a static body
        myBodyDef.type = b2_staticBody;
        myBodyDef.position.Set(0, 0);
        b2Body* staticBody = m_world->CreateBody(&myBodyDef);
        
        //add four walls to the static body
        polygonShape.SetAsBox( 20, 1, b2Vec2(0, 0), 0);//ground
        staticBody->CreateFixture(&myFixtureDef);
        polygonShape.SetAsBox( 20, 1, b2Vec2(0, 40), 0);//ceiling
        staticBody->CreateFixture(&myFixtureDef);
        polygonShape.SetAsBox( 1, 20, b2Vec2(-20, 20), 0);//left wall
        staticBody->CreateFixture(&myFixtureDef);
        polygonShape.SetAsBox( 1, 20, b2Vec2(20, 20), 0);//right wall
        staticBody->CreateFixture(&myFixtureDef);
      
        //the ball
        myBodyDef.type = b2_dynamicBody;
        myBodyDef.position.Set(0,10);
        b2CircleShape circleShape;
        circleShape.m_p.Set(0, 0); //position, relative to body position
        circleShape.m_radius = 1;
        myFixtureDef.shape= &circleShape;
        myFixtureDef.density = 1;
        myFixtureDef.restitution=1;
        ball=m_world->CreateBody(&myBodyDef);
        ball->CreateFixture(&myFixtureDef);
        ball->SetLinearVelocity(b2Vec2(-50,0));

        p1moveState = MS_STOP;
        p2moveState = MS_STOP;
      }

        void Step(Settings * settings){
            Test::Step(settings);
            b2Vec2 p1vel = rack1->GetLinearVelocity();
            b2Vec2 p2vel = rack2->GetLinearVelocity();
            float desiredVel;

            switch ( p1moveState )
            {
              case MS_UP:  desiredVel = +25; break;
              case MS_STOP:
                {
                  desiredVel = 0;
                  rack1->SetLinearVelocity(b2Vec2(0,0));
                  break;
                }
              case MS_DOWN: desiredVel = -25; break;
            }
            float velChange = desiredVel - p1vel.x;
            float impulse = rack1->GetMass() * velChange; //disregard time factor
            rack1->ApplyLinearImpulse( b2Vec2(0,impulse), rack1->GetWorldCenter() );

            switch ( p2moveState )
            {
              case MS_UP:  desiredVel = +25; break;
              case MS_STOP:
                {
                  desiredVel = 0;
                  rack2->SetLinearVelocity(b2Vec2(0,0));
                  break;
                }
              case MS_DOWN: desiredVel = -25; break;
            }
            velChange = desiredVel - p2vel.x;
            impulse = rack2->GetMass() * velChange; //disregard time factor
            rack2->ApplyLinearImpulse( b2Vec2(0,impulse), rack2->GetWorldCenter() );
        }

        static Test* Create(){
            return new Pong();
        }


      void MouseDown(const b2Vec2& p)
      {
        ball->SetLinearVelocity(b2Vec2(-90,0));
        //do normal behaviour
        Test::MouseDown( p );
      }

      void Keyboard(unsigned char key)
      {
        switch (key)
        {
          case 'e': //move up p1
            p1moveState = MS_UP;
            break;
          case 'd': //move down p1
            p1moveState = MS_DOWN;
            break;
          case 'a': //move up p2
            p2moveState = MS_UP;
            break;
          case 'q': //mov down p2
            p2moveState = MS_DOWN;
            break;
          case 'l' : //gravity ++
            m_world->SetGravity(b2Vec2(0,m_world->GetGravity().x + 1));
            break;
          case 'm' : //gravity --
            m_world->SetGravity(b2Vec2(0,m_world->GetGravity().x - 1));
            break;
          default:
            //run default behaviour
            p1moveState=MS_STOP;
            p2moveState=MS_STOP;
            Test::Keyboard(key);
        }
      }

};

#endif