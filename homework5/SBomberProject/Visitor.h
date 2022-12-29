#pragma once

#include "Plane.h"
#include "Bomb.h"
#include "MyTools.h"

class Visitor {
public:
	virtual void log(Plane* e) = 0;
	virtual void log(Bomb* e) = 0;
};

class LogVisitor : public Visitor {
	void log(Plane* e) override {
		MyTools::FileLoggerSingletone::getInstance().WriteToLog("Plane: xDirection = " + std::to_string(e->GetDirectionX())
			+ "; yDirection = " + std::to_string(e->GetDirectionY()) + "; Speed = " + std::to_string(e->GetSpeed()));
	}

	void log(Bomb* e) override {
		MyTools::FileLoggerSingletone::getInstance().WriteToLog("Bomb: xDirection = " + std::to_string(e->GetDirectionX())
			+ "; yDirection = " + std::to_string(e->GetDirectionY()) + "; Speed = " + std::to_string(e->GetSpeed()));
	}
};

