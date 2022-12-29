
#include <iostream>

#include "Bomb.h"
#include "Visitor.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    MyTools::ScreenSingleton::getInstance().SetColor(CC_LightMagenta);
    ScreenSingleton::getInstance().GotoXY(x, y);
    cout << "*";
}

void __fastcall Bomb::Accept(Visitor& v)
{
    v.log(this);
}
