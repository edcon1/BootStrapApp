#pragma once

#include "Application.h"
#include "Renderer2D.h"

class mini_meApp : public aie::Application {
public:

	struct coin
	{
		int possition = 0;
		float x;
		float y;
		aie::Texture* coinTex;

	 };

	

	mini_meApp();
	virtual ~mini_meApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Texture*       m_walkingMan;
	aie::Texture*       m_coinTexture;
	float manPosX;
	float manPosY;
	float coinPosX;
	float coinPosY;
	int coinCounter = 0;
	int randomValue = 0;

	coin* m_coin;
};