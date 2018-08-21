#include "mini_meApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <random>
#include <ctime>
#include <iostream>


mini_meApp::mini_meApp()
{
	srand((unsigned int)time(nullptr));
}

mini_meApp::~mini_meApp() 
{

}

bool mini_meApp::startup()
{

	m_2dRenderer = new aie::Renderer2D();

	manPosX = getWindowWidth() * 0.5f;
	manPosY = getWindowHeight() * 0.5f;
	coinPosX = getWindowWidth() * 0.2f;
	coinPosY = getWindowHeight() * 0.2f;

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_walkingMan = new aie::Texture("../bin/textures/walkingMan.jpg");
	m_coinTexture = new aie::Texture("../bin/textures/coin.png");


	m_coin = new coin;
	m_coin->coinTex = m_coinTexture;



	return true;
}

void mini_meApp::shutdown() 
{

	delete m_font;
	delete m_2dRenderer;
}

void mini_meApp::update(float deltaTime) 
{

	// input example
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_W )||input->isKeyDown(aie::INPUT_KEY_UP))
	{
		manPosY += 0.3f;
	}

	if (input->isKeyDown(aie::INPUT_KEY_S) || input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		manPosY -= 0.3f;
	}

	if (input->isKeyDown(aie::INPUT_KEY_A)||input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		manPosX -= 0.3f;
	}
	if (input->isKeyDown(aie::INPUT_KEY_D)||input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		manPosX += 0.3f;
	}

	
	
	randomValueY = rand() % getWindowHeight();
	randomValueX = rand() % getWindowWidth();

	
	
		float coinTopRX = coinPosX + 25;
		float coinTopRY = coinPosY + 25;
		float coinBottomLX = coinPosX - 25;
		float coinBottomLY = coinPosY - 25;

		float manTopRX = manPosX + 25;
		float manTopRY = manPosY + 25;
		float manBottomLX = manPosX - 25;
		float manBottomLY = manPosY - 25;

		if (coinTopRX > manBottomLX && coinTopRY > manBottomLY &&
			coinBottomLX < manTopRX && coinBottomLY < manTopRY)
		{
			coinPosX = randomValueX;
			coinPosY = randomValueY;
			coinCounter++;
			std::cout << coinCounter << std::endl;
		}




	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void mini_meApp::draw()

{

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	// output some text, uses the last used colour
	m_2dRenderer->drawSprite(m_walkingMan, manPosX, manPosY, 50, 50);
	m_2dRenderer->drawSprite(m_coin->coinTex, coinPosX, coinPosY, 50, 50);
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	

	ImGui::Begin("Test", false);
	ImGui::Text("Coin Collected: (%i)", coinCounter);

	ImGui::End();


	m_2dRenderer->end();

}