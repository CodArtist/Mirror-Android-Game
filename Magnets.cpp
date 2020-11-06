#include <SFML/Graphics.hpp>
#include <sstream>
#include <string.h>
#include <iostream>
#include<fstream>
#include <cmath>
using namespace sf;
using namespace std;
int main()
{	float touchscale = sf::VideoMode::getDesktopMode().height * 1.f / 1080;
	float aspect = sf::VideoMode::getDesktopMode().width * 1.f / sf::VideoMode::getDesktopMode().height;
	const int width = (int)(1080 * aspect);
	
	
	sf::RenderWindow window(sf::VideoMode(50, 100, 32), "SFML Pong",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    
    
    sf::RectangleShape rec2,rec3,rec4,rec5,back,back2;
    sf::Color skyblue,maroon,dgreen,dgrey;
    skyblue.b = 100;
    skyblue.r= 100;
    skyblue.g = 100;
    maroon.r = 150;
    maroon.b = 0;
    maroon.g = 0;
    dgreen.g = 170;
    dgreen.b = 0;
    dgreen.r = 0;
    dgrey.g = 50;
    dgrey.b = 50;
    dgrey.r = 50;
   
    sf:: CircleShape rec,cir;
    	rec.setRadius(0.7);
	rec.setPosition(25,60);
	rec.setOutlineThickness(0.3);
	rec.setFillColor(sf::Color::White);
	rec.setOutlineColor(sf::Color::Red);
	rec.setOrigin(10,0);
		cir.setRadius(0.7);
	cir.setPosition(25,60);
	cir.setOutlineThickness(0.3);
	cir.setFillColor(sf::Color::White);
	cir.setOutlineColor(sf::Color::Red);
	cir.setOrigin(-10,0);
		rec2.setSize(sf::Vector2f(40,3));
	rec2.setPosition(33,-4);
	rec2.setOutlineThickness(0.1);
	rec2.setFillColor(maroon);
	rec2.setOutlineColor(maroon);
	rec2.setOrigin(5,0);
 back.setSize(sf::Vector2f(50,100));
		back.setPosition(0,0);
	back.setOutlineThickness(0.1);
	back.setFillColor(skyblue);
	back.setOutlineColor(sf::Color::Red);
	back.setOrigin(0,0);
	sf::Font font;
		rec3.setSize(sf::Vector2f(26,3));
	rec3.setPosition(0,-6);
	rec3.setOutlineThickness(0.1);
	rec3.setFillColor(maroon);
	rec3.setOutlineColor(maroon);
	rec3.setOrigin(5,0);
	rec4.setSize(sf::Vector2f(24,3));
	rec4.setPosition(0,-6);
	rec4.setOutlineThickness(0.1);
	rec4.setFillColor(dgreen);
	rec4.setOutlineColor(dgreen);
	rec4.setOrigin(5,0);
rec5.setSize(sf::Vector2f(40,3));
	rec5.setPosition(35,-11);
	rec5.setOutlineThickness(0.1);
	rec5.setFillColor(dgreen);
	rec5.setOutlineColor(dgreen);
	rec5.setOrigin(5,0);
	back2.setSize(sf::Vector2f(50,100));
	back2.setPosition(0,0);
	back2.setOutlineThickness(0.1);
	back2.setFillColor(dgrey);
	back2.setOutlineColor(dgreen);
	back2.setOrigin(0,0);

	font.loadFromFile("Sen/OpenSans-ExtraBold.ttf");
    
	
    float t =0,m=0.6;
     float angle = 0,x,y=0,theta= 0,x1,y1;
     bool lost = true ,recmove =false;
     int score = 0,highscore =0,s;
     ifstream read;
     read.open("Highscore.html");
     read>>highscore;
     read.close();
    while(window.isOpen())
    {
    	sf::Event event;
    	while(window.pollEvent(event))
  {     if (event.type == sf::Event::Closed)
            {
                window.close();}
  
   
     if(sf::Touch::isDown(0))
    {    if(lost)
        {recmove = false;
        	rec2.setPosition(33,-4);
        rec3.setPosition(0,-20);
        rec4.setPosition(0,-6);
        rec5.setPosition(35,-11);
        score =0;
        	
        	sf::Vector2i relativePos = sf::Touch::getPosition(0,window);
        	 if(relativePos.x>5&&relativePos.x<(sf::VideoMode::getDesktopMode().width)/1.8)
    {    if(relativePos.y>50&&relativePos.y<(sf::VideoMode::getDesktopMode().height)/8.53)
        lost=false;}}
    	if(!lost)
    {
    sf::Vector2i relativePos = sf::Touch::getPosition(0,window);
    if(relativePos.y>=(sf::VideoMode::getDesktopMode().height)/2.56)
    recmove=true;
    cir.rotate(relativePos.y-t);
    	rec.rotate((relativePos.y -t));
    	angle +=-relativePos.y +t ; 
    	x=29-(10*cos(angle/57.34));
    	y=60+(10*sin(angle/57.34));
    	x1=29+(10*cos(angle/57.34));
    	y1=60-(10*sin(angle/57.34));
   
    		t = relativePos.y;
    	theta = atan(y/x);
    	theta = theta*57.52;
    }
    }
    	
    	
    }
    
    	window.clear();
    	if(!lost)
   {if(score%5 == 0&&score!=0)
  { m=m +0.1;
  score++;}
  if(recmove)
   	{	rec2.move(0,m);
   	rec3.move(0,m);
   	rec4.move(0,m);
   	rec5.move(0,m);}
   	if(rec2.getPosition().y>100)
   {rec2.setPosition(34,rand()%30);}
   	if(rec3.getPosition().y>100)
   {rec3.setPosition(0,rand()%20);
   }
   	if(rec4.getPosition().y>100)
   {rec4.setPosition(0,-(rand()%9));}
   	if(rec5.getPosition().y>100)
   {rec5.setPosition(35,-(rand()%14));}

   		
 if(x>=33&&((rec2.getPosition().y >=(int) (y))&&(rec2.getPosition().y )<=y+4)||(x1>=33&&((rec2.getPosition().y+4 >=(int) (y1))&&(rec2.getPosition().y)<=y1+4)))
 
   	{	rec2.setPosition(33,0);
   	lost = true;
   	}
   	
   	
 if(x<=26&&((rec3.getPosition().y >=(int) (y))&&(rec3.getPosition().y )<=y+4)||(x1<=26&&((rec3.getPosition().y+4 >=(int) (y1))&&(rec3.getPosition().y )<=y1+4)))
 
   	{	rec3.setPosition(0,0);
   	lost = true;
   	}
   	
   	
   if(x<=24&&((rec4.getPosition().y >=(int) (y))&&(rec4.getPosition().y )<=y+4)||(x1<=24&&((rec4.getPosition().y+4 >=(int) (y1))&&(rec4.getPosition().y )<=y1+4)))
   
 
   	{	rec4.setPosition(0,-(rand()%8));
   	score ++;
   }
   if(x>=35&&((rec5.getPosition().y >=(int) (y))&&(rec5.getPosition().y )<=y+4)||(x1>=35&&((rec5.getPosition().y+4 >=(int) (y1))&&(rec5.getPosition().y)<=y1+4)))
 
   	{	rec5.setPosition(35,-(rand()%14));
   score++;
   	}
   	
   sf::Text points;
  points.setFont(font);
   	std:: stringstream s;
  	s<<score;
  	std::string mess = s.str();
  	points.setString(mess);
  	 points.setCharacterSize(7.5);
    	sf::FloatRect pointsrec = points.getLocalBounds();	
	points.setOrigin(6,9);
  	points.setPosition(40,20);

sf::Vector2i relativePos = sf::Touch::getPosition(0,window);
   std::stringstream ss;
    //ss<<sf::VideoMode::getDesktopMode().height;
    	std::string ang = ss.str();
    sf::Text Angle;
    Angle.setFont(font);
    Angle.setCharacterSize(10);
    Angle.setFillColor(sf::Color::White);
    Angle.setPosition(4,70);
  Angle.setString(ang);
  window.draw(back);
   	window.draw(rec);
   	window.draw(rec2);
   	window.draw(rec3);
   	window.draw(rec4);
   	window.draw(rec5);
   	window.draw(cir);
   window.draw(Angle);
   //	window.draw(Angle);
   	window.draw(points);
   }
   if(lost)
   {m=0.6;
   window.draw(back2);
   	if(highscore<score)
   	highscore =score;
   std::stringstream h;
   h<<highscore;
   string high = h.str();
   	score =0;
   		sf::Text pauseMessage,highs,scor;
  highs.setFont(font);
    highs.setCharacterSize(10);
    highs.setFillColor(sf::Color::White);
    highs.setPosition(20, 75);
    scor.setFont(font);
    scor.setCharacterSize(14);
    scor.setFillColor(sf::Color::White);
    scor.setPosition(4, 50);
   pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(9);	scor.setString("High\nScore");
    pauseMessage.setFillColor(sf::Color::White);
    pauseMessage.setString(
 "Start\nGame By\nHarsh Jain\n\nHigh\nScore");
 highs.setString(high);
 //pauseMessage.setString(high);
   
    	sf::FloatRect pauseRect = pauseMessage.getLocalBounds();	
	pauseMessage.setOrigin(6,9);
    pauseMessage.setPosition(4.5, 10);
   window.draw(pauseMessage);
   	window.draw(highs);
   	
   
   }
   ifstream read;
   read.open("Highscore.html");
   read>>s;
   read.close();
   if(highscore>s)
  { ofstream write;
   write.open("Highscore.html");
   write<<highscore;
   write.close();
  }
   	window.display();
    }
    
    return 0;
}